/*
 * screen_ring.h
 * Purpose : Affiche la page Alarm en marche du tft
 *
 *  Created on: 17/11/2022
 *  Author: Bigot
 */

#ifndef SCREEN_RING_H_
#define SCREEN_RING_H_

#include "Variables/variables.h"
#include "tft_ili9341/stm32f1_ili9341.h"
#include "config.h"

void screen_alarm_ring(Alarme alarm);

#endif
