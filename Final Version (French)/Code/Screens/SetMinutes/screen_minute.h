/*
 * screen_minute.h
 * Purpose : Affiche la page Minute de l'Alarme du tft
 *
 *  Created on: 17/11/2022
 *  Author: Bigot
 */

#ifndef SCREEN_MINUTE_H_
#define SCREEN_MINUTE_H_

#include "Variables/variables.h"
#include "Actionneur/Buttons/buttons.h"

#include "tft_ili9341/stm32f1_ili9341.h"
#include "config.h"

void screen_minutes(Alarme alarm);

void setMinuteString(Alarme alarm);
void changeAlarmMinuteVariable();

#endif
