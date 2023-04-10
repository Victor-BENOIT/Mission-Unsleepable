/*
 * screen_home.h
 * Purpose : Affiche la page Home de l'écran tft
 *
 *  Created on: 17/11/2022
 *  Author: Bigot
 */

#ifndef SCREEN_HOME_H_
#define SCREEN_HOME_H_

#include "Variables/variables.h"
#include "Actionneur/RTC/rtc.h"
#include "tft_ili9341/stm32f1_ili9341.h"
#include "config.h"

void screen_home(Alarme alarm);

#endif
