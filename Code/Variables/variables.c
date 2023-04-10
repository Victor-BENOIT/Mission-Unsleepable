/**
 * @file variables.c
 * @brief Fichier pour utiliser les variables globales du système
 * @date 13/12/2022
 * @author Maxence Bigot
 */

#include "Variables/variables.h"
#include <stdio.h>

//INITIALISATION DES MUSIQUES
static Music ListMusic[10] = {
		{.Number = 1, .Title = "Boule de mec - Fatal"},
		{.Number = 2, .Title = "Fruit de Passion - Francky"},
		{.Number = 3, .Title = "ALLEZ RODEZ - Les Ultras"},
		{.Number = 4, .Title = "Rick Rolled - Rick Astley"},
		{.Number = 5, .Title = "Baby Shark - Disney"},
		{.Number = 6, .Title = "Ouin Ouin - Camion Bip Bip"},
		{.Number = 7, .Title = "Wii Sport Theme - Nintendog"},
		{.Number = 8, .Title = "Presentation Oral - Chiese"}
};


//INITIALISATION DE L'ALARME
static Alarme alarm = {.Hours = 0, .Minutes = 0, .Seconds = 0, .Set = 0, .Musique = {.Number = 1, .Title = "Formula 1 - Brian Tyler"}};


//GETTER AND SETTER


/**
 * @fn Alarme getAlarm(void)
 * @brief Recupérer les données de l'alarme
 * @date 13/12/2022
 * @author Maxence Bigot
 * @return Alarme variable alarm de structure Alarme
 */
Alarme getAlarm(){
	return alarm;
}


/**
 * @fn Alarme getAlarm(void)
 * @brief Modifier l'attribut Hours de la variable Alarm
 * @date 13/12/2022
 * @author Maxence Bigot
 * @param value Nouvelle valeur de l'attribut (entier non signé 8bits)
 */
void setAlarmHours(uint8_t value){
	alarm.Hours = value;
}


/**
 * @fn void setAlarmMinutes(uint8_t value)
 * @brief Modifier l'attribut Minutes de la variable Alarm
 * @date 13/12/2022
 * @author Maxence Bigot
 * @param value Nouvelle valeur de l'attribut (entier non signé 8bits)
 */
void setAlarmMinutes(uint8_t value){
	alarm.Minutes = value;
}



/**
 * @fn void setAlarmMusic(uint8_t value)
 * @brief Modifier l'attribut Music de la variable Alarm
 * @date 13/12/2022
 * @author Maxence Bigot
 * @param value Nouvelle valeur de l'attribut (entier non signé 8bits)
 */
void setAlarmMusic(uint8_t value){
	alarm.Musique = ListMusic[value-1];
}


/**
 * @fn void setAlarmSet(uint8_t value)
 * @brief Modifier l'attribut Set de la variable Alarm
 * @date 13/12/2022
 * @author Maxence Bigot
 * @param value Nouvelle valeur de l'attribut (entier non signé 8bits)
 */
void setAlarmSet(uint8_t value){
	alarm.Set = value;
}


/**
 * @fn Music* getListMusic(void)
 * @brief Récupérer un tableau de Musique contenu dans le lecteur MP3
 * @date 13/12/2022
 * @author Maxence Bigot
 * @return Alarme Tableau de musique (Structure Musique)
 */
Music* getListMusic(){
	return ListMusic;
}
