/*
 * servo.h
 * Purpose : Gérer le servomoteur
 *
 *  Created on: 17/11/2022
 *  Author: Bigot
 */

#ifndef SERVO_H_
#define SERVO_H_

#include "stm32f1_timer.h"

void SERVO_init(void);
void SERVO_set_position(uint16_t position);

int getCurrentPosition(void);

#endif
