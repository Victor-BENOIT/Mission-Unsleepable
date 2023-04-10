/*
 * screen_music.h
 * Purpose : Affiche la page Music de l'Alarme du tft
 *
 *  Created on: 17/11/2022
 *  Author: Bigot
 */

#ifndef SCREEN_MUSIC_H_
#define SCREEN_MUSIC_H_

#include "Variables/variables.h"
#include "Actionneur/Buttons/buttons.h"

#include "tft_ili9341/stm32f1_ili9341.h"
#include "config.h"

void screen_musics(Alarme alarm);

void setMusicString(uint8_t index, Alarme alarm);
void changeMusicVariable();

#endif
