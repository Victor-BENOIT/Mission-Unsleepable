/**
 * @file state.c
 * @brief Fichier qui gère la machine à  etats du reveil
 *
 *  @date 17/11/2022
 *  @author Maxence Bigot
 *  @bug Capteur ultrason HCSR04 ne fonctionne pas
 */

#include <Screens/SetHour/screen_hour.h>
#include "states.h"
#include "tft_ili9341/stm32f1_ili9341.h"
#include "stm32f1_rtc.h"
#include "stm32f1_uart.h"
#include "stm32f1_timer.h"
#include "stm32f1xx_hal.h"

#include "Variables/variables.h"
#include "Actionneur/Buttons/buttons.h"
#include "Actionneur/MP3Player/mp3_player.h"
#include "Actionneur/Servo/servo.h"
#include "Actionneur/RTC/rtc.h"
#include "Actionneur/HCSR04/hcsr04.h"

#include "Screens/Home/screen_home.h"
#include "Screens/SetHour/screen_hour.h"
#include "Screens/SetMinutes/screen_minute.h"
#include "Screens/SetMusic/screen_music.h"
#include "Screens/AlarmRing/screen_ring.h"


//Récupération de l'heure et de la date
RTC_DateTypeDef currentDate;
RTC_TimeTypeDef currentTime;


/**
 * @fn void state_machine(void)
 * @brief Gerer la machine à  états du reveil
 *
 * @date 17/11/2022
 * @author Maxence Bigot
 */
void state_machine(void){

	/**
	 * @enum state_e
	 * @brief Création des différents états du système
	 *
	 * @date 17/11/2022
	 * @author Maxence Bigot
	 */
	typedef enum{
		INIT = 0,
		HOME,
		SETHOUR,
		SETMINUTE,
		SETMUSIC,
		ALARMRING,
		SERVOMOTOR
	}state_e;

	static state_e state = INIT;
	static state_e previous_state = INIT;
	bool_e entrance;

	entrance = (state!=previous_state)?TRUE:FALSE;
	previous_state = state;


	switch(state){
		case INIT:
			// INITIALISATION DE L'ECRAN
			ILI9341_Init();
			ILI9341_Rotate(ILI9341_Orientation_Landscape_2);

			// INITIALISATION DES MODULES
			RTC_init(TRUE); //RTC
			initModuleRTC(23, 1, 20, 8, 32, 0);

			state = HOME;
			break;

		case HOME:
			if(entrance){
				screen_home(getAlarm()); //Affichage unique sur l'ecran
			}

			//Ecriture et Affichage en String de l'heure et date
			RTC_get_time(&currentTime);
			RTC_get_date(&currentDate);

			char timeString[5];
			char dateString[10];
			sprintf(timeString, "%d:%d", currentTime.Hours, currentTime.Minutes);
			sprintf(dateString, "%d/%d/%d", currentDate.Date, currentDate.Month, currentDate.Year + 2000);

			ILI9341_Puts(120, 55, timeString, &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE);
			ILI9341_Puts(21, 115, dateString, &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE);

			//Passage a l'etat suivant
			if(button_center_press_event()){
				state = SETHOUR;
			}

			if(getAlarm().Set){
				if(getAlarm().Hours == currentTime.Hours){
					if(getAlarm().Minutes == currentTime.Minutes){
						state = ALARMRING;
					}
				}
			}

			ILI9341_Delay(1000);
			break;


		case SETHOUR:
			if(entrance){
				screen_hours(getAlarm()); //Affichage unique sur l'ecran
				setHourString(getAlarm());
			}

			//Changer la valeur des minutes
			changeAlarmHourVariable(0);


			//Passage a  l'etat suivant
			if(button_center_press_event()){
				state = SETMINUTE;
			}

			break;


		case SETMINUTE:
			if(entrance){
				screen_minutes(getAlarm()); //Affichage unique sur l'ecran
				setMinuteString(getAlarm());
			}

			//Changer la valeur des minutes
			changeAlarmMinuteVariable();


			//Passage Ã  l'Ã©tat suivant
			if(button_center_press_event()){
				state = SETMUSIC;
			}

			break;

		case SETMUSIC:
			if(entrance){
				screen_musics(getAlarm()); //Affichage unique sur l'ecran
				setMusicString(getAlarm().Musique.Number, getAlarm()); //Affichage du titre sur l'ecran
			}

			changeMusicVariable();

			//Passage Ã  l'etat suivant
			if(button_center_press_event()){
				setAlarmSet(1);
				state = HOME;
			}

			break;


		case ALARMRING:
			if(entrance){
				screen_alarm_ring(getAlarm()); //Affichage de l'ecran

				initPlayer(); //Initialisation de la carte SD du lecteur MP3
				playMusic(getAlarm().Musique.Number); //Play la musique de l'alarme

				SERVO_init(); //Servomoteur
				SERVO_set_position(0); //Servo moteur a  0%
				HAL_Delay(2000);
			}

			/*//Capteur Ultrason et Servomoteur
			hcsr04_state_machine();

			/*if(HCSR04_get_value(id_sensor, &distance) < DIST_MAX){
				SERVO_set_position(100); //Servo moteur a  100%
				HAL_Delay(2000);
			}
			else if(getCurrentPosition() != 100){
				SERVO_set_position(0); //Servo moteur a  0%
				HAL_Delay(2000);
			}*/


			SERVO_set_position(100); //Servo moteur a  100%
			HAL_Delay(2000);
			SERVO_set_position(0); //Servo moteur a  0%
			HAL_Delay(2000);

			//Fin de l'alarme
			if(button_center_press_event()){
				setAlarmSet(0);
				stopMusic(); //Stop la musique
				state = HOME;
			}

			break;


		default:
			break;
	}
}
