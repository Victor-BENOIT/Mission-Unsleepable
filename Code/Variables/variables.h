/*
 * variables.h
 * Purpose : Créer les variables globales du systeme
 *
 *  Created on: 17/11/2022
 *  Author: Bigot
 */

#ifndef VARIABLES_H_
#define VARIABLES_H_

#include "stdint.h"
#include <stdio.h>

typedef struct {
	/*
	 * \struct Music
	 * \brief Cr�ation d'une structure de Musique
	 * \date 13/12/2022
	 * \author Maxence Bigot
	 * \param Number Entier non sign� 8bits
	 * \param Title Tableau de caract�re (Longueur max : 30)
	 */

	uint8_t Number;
	char Title[30];
}Music;

typedef struct {
	/*
	 * \struct Alarme
	 * \brief Cr�ation d'une structure d'Alarme
	 * \date 13/12/2022
	 * \author Maxence Bigot
	 * \param Hours Entier non sign� 16bits
	 * \param Minutes Entier non sign� 16bits
	 * \param Seconds Entier non sign� 16bits
	 * \param Set Entier non sign� 16bits
	 * \param Musique Structure Music
	 */

	uint16_t Hours;
	uint16_t Minutes;
	uint16_t Seconds;
	uint16_t Set;
	Music Musique;
} Alarme;


Alarme getAlarm(void);
void setAlarmHours(uint8_t value);
void setAlarmMinutes(uint8_t value);
void setAlarmMusic(uint8_t value);
void setAlarmSet(uint8_t value);

Music* getListMusique(void);

#endif
