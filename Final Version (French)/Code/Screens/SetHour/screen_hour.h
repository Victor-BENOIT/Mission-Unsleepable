/*
 * screen_hour.h
 * Purpose : Affiche la page Hour de l'Alarme du tft
 *
 *  Created on: 17/11/2022
 *  Author: Bigot
 */

#ifndef SCREEN_HOUR_H_
#define SCREEN_HOUR_H_

#include "Variables/variables.h"
#include "Actionneur/Buttons/buttons.h"

#include "tft_ili9341/stm32f1_ili9341.h"
#include "config.h"

void screen_hours(Alarme alarm);

void setHourString(Alarme alarm);
void changeAlarmHourVariable();

#endif
