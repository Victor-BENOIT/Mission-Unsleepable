/**
 * @file mp3_player.c
 * @brief Fichier pour utiliser le lecteur MP3
 *
 * @date 29/11/2022
 * @author Maxence Bigot
 */

#include "Actionneur/MP3Player/mp3_player.h"


/**
 * @fn void initPlayer(void)
 * @brief Initialiser le lecteur MP3
 * @date 29/11/2022
 * @author Victor Benoit
 */
void initPlayer(){
	static char storage[8] = {0x7E, 0xFF, 0x06, 0x09, 0x00, 0x00, 0x02, 0xEF};

	HAL_Delay(500);
	UART_puts(UART1_ID, storage, 8);
	HAL_Delay(500);
}


/**
 * @fn void playMusic(uint8_t index)
 * @brief Jouer une musique
 * @date 29/11/2022
 * vauthor Maxence Bigot
 * vparam Index de la musique (entier non signé 8bits)
 */

void playMusic(uint8_t index){
	static char playCommand[8] = {0x7E, 0xFF, 0x06, 0x03, 0x00, 0x00, 0x00, 0xEF};
	playCommand[6] = index;

	HAL_Delay(500);
	UART_puts(UART1_ID, playCommand, 8);
	HAL_Delay(500);
}


/**
 * @fn void stopMusic(void)
 * @brief Arrêter la musique sur le lecteur
 * @date 29/11/2022
 * @author Maxence Bigot
 */
void stopMusic(){
	static char stopCommand[8] = {0x7E, 0xFF, 0x06, 0x16, 0x00, 0x00, 0x00, 0xEF};

	HAL_Delay(500);
	UART_puts(UART1_ID, stopCommand, 8);
	HAL_Delay(500);
}

