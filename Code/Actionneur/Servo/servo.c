/**
 * @file servo.c
 * @brief Fichier pour utiliser le servomoteur
 *
 * @date 29/11/2022
 * @author Victor Benoit
 */

#include "Actionneur/Servo/servo.h"

static uint16_t current_position;


/**
 * @fn int getCurrentPosition(void)
 *  @date 29/11/2022
 *  @author Victor Benoit
 *  @return Position courante du servomoteur
 */
int getCurrentPosition(){
	return current_position;
}


/**
 * @fn void SERVO_init(void)
 * @brief Intialisation du servomoteur
 * @date 29/11/2022
 * @author Victor Benoit
 */
void SERVO_init(){
	TIMER_run_us(TIMER1_ID, 10*1000, FALSE);
	TIMER_enable_PWM(TIMER1_ID, TIM_CHANNEL_1, 150, FALSE, FALSE);
}


/**
 * @fn void SERVO_set_position(uint16_t position)
 * @brief R�glage du servomoteur � une postion donn�e
 *
 * @date 29/11/2022
 * @author Victor Benoit
 * @param position Position (entier non sign� 16 bits)
 */

void SERVO_set_position(uint16_t position){
	current_position = position;
	if(position > 100){
		position = 100;
	}

	position += 100;
	TIMER_set_duty(TIMER1_ID, TIM_CHANNEL_1, position);
}
