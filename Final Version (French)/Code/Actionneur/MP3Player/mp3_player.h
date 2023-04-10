/*
 * mp3_player.h
 * Purpose : Gérer le lecteur MP3
 *
 *  Created on: 17/11/2022
 *  Author: Bigot
 */

#ifndef MP3_PLAYER_H_
#define MP3_PLAYER_H_

#include "stm32f1_uart.h"

void initPlayer(void);
void playMusic(uint8_t index);
void stopMusic(void);

#endif
