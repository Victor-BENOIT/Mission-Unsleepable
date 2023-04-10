/**
 * @file hcsr04.c
 * @brief Gérer l'utilisation du capteur HCSR04
 * @date 29/11/2022
 * @author Victor Benoit
 */

#include "Actionneur/HCSR04/hcsr04.h"
#include "tft_ili9341/stm32f1_ili9341.h"

//INITIALISATION DU CAPTEUR HCSR04
#define ID_PORT_HCSR04  1
#define DIST_MAX 		20
#define PERIOD_MEASURE	100



/**
 * @fn hcsr04_state_machine()
 * @brief Machine à état pour utiliser le capteur
 * @date 29/11/2022
 * @author Victor Benoit
 */
void hcsr04_state_machine(){


	/**
	 * @enum state_e
	 * @brief Structure Enum des états du capteur
	 * @date 29/11/2022
	 * @author Victor Benoit
	 */
	typedef enum {
		INIT,
		FAIL,
		LAUNCH_MEASURE,
		RUN,
		WAIT_DURING_MEASURE,
		WAIT_BEFORE_NEXT_MEASURE
	}state_e;


	static state_e state = INIT;
	static uint32_t tlocal;
	static uint8_t id_sensor = ID_PORT_HCSR04;
	uint16_t distance;

	HCSR04_process_main();

	switch(state){
		case INIT:
			if(HCSR04_add(&id_sensor, GPIOB, GPIO_PIN_5, GPIOB, GPIO_PIN_4) != HAL_OK){
				state = FAIL;
			}
			else{
				state = LAUNCH_MEASURE;
			}
			break;

		case LAUNCH_MEASURE:
			HCSR04_run_measure(id_sensor);
			tlocal = HAL_GetTick();
			state = WAIT_DURING_MEASURE;
			break;

		case WAIT_DURING_MEASURE:
			switch(HCSR04_get_value(id_sensor, &distance)){
				case HAL_BUSY:
					//rien à faire... on attend...
					break;

				case HAL_OK: ;
					/*if(distance <= DIST_MAX){
						return 0;
					}
					else {
						return 1;
					}*/

					char distanceString[10];
					sprintf(distanceString, "%d", distance);

					ILI9341_Puts(21, 115, distanceString, &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE);

					state = WAIT_BEFORE_NEXT_MEASURE;
					break;

				case HAL_ERROR:
					state = WAIT_BEFORE_NEXT_MEASURE;
					break;

				case HAL_TIMEOUT:
					state = WAIT_BEFORE_NEXT_MEASURE;
					break;
			}
			break;

		case WAIT_BEFORE_NEXT_MEASURE:
			if(HAL_GetTick() > tlocal + PERIOD_MEASURE)
				state = LAUNCH_MEASURE;
			break;

		default:
			break;
	}
}
