/**
 * @file screen_music.c
 * @brief Afficher les éléments unique de l'écran SetMusics
 * @date 15/12/2022
 * @author Victor Benoit
 */

#include <Screens/SetMusic/screen_music.h>


/**
 * @fn void screen_musics(Alarme alarm)
 * @brief Afficher les éléments unique de l'écran SetMusics
 * @date 15/12/2022
 * @author Victor Benoit
 * @param alarm Variable alarm de scructure Alarme
 */
void screen_musics(Alarme alarm){

	//Creation des variables
	char alarmString[8];
	sprintf(alarmString, "%d:%d:%d", alarm.Hours, alarm.Minutes, alarm.Seconds);

	//Couleur de fond
	ILI9341_Fill(ILI9341_COLOR_BLUE);
	ILI9341_Puts(15, 20, "ALARM SETTINGS : MUSIC", &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE);

	//Affichage de l'alarme
	if(alarm.Set){
		ILI9341_Puts(273, 20, "ON", &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE);
	}
	else {
		ILI9341_Puts(273, 20, "OFF", &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE);
	}


	//Bordure de sÃ©paration
	ILI9341_DrawFilledRectangle(0, 90, 320, 92, ILI9341_COLOR_BLACK);
	//


	//Affichage de la ligne 1
	ILI9341_Puts(21, 115, "PREVIOUS ALARM", &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE);
	ILI9341_Puts(21, 145, alarmString, &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE);

	//Affichage de la ligne 1
	ILI9341_Puts(21, 184, "PREVIOUS MUSIC", &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE);
	ILI9341_Puts(21, 214, alarm.Musique.Title, &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE);
}


//------------- FONCTIONS -------------//

/**
 * @fn void setMusicString(uint8_t index, Alarme alarm)
 * @brief Afficher et modifier l'attribut Musique de l'écran SetMusics
 * @date 15/12/2022
 * @author Victor Benoit
 * @param alarm Variable alarm de scructure Alarme
 * @param index Numéron de la musique choisie (Entier non signé 8bits)
 */
void setMusicString(uint8_t index, Alarme alarm){
	Music* musics = getListMusic();
	alarm.Musique = musics[index - 1];

	ILI9341_DrawFilledRectangle(20, 55, 320, 88, ILI9341_COLOR_BLUE);
	ILI9341_Puts(20, 55, alarm.Musique.Title, &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE);
}


/**
 * @fn void changeMusicVariable(void)
 * @brief Gérer l'augmentation et la diminution de l'attribut Musics
 * @date 15/12/2022
 * @author Victor Benoit
 */
void changeMusicVariable(){

	//Diminution d'une unite de la Variable
	if(button_left_press_event()){
		if(getAlarm().Musique.Number <= 1){
			setAlarmMusic(8);
		}
		else {
			setAlarmMusic((uint8_t) (getAlarm().Musique.Number - 1 ));
		}
		setMusicString(getAlarm().Musique.Number, getAlarm());
	}


	//Augmentation d'une unite de la Variable
	if(button_right_press_event()){
		if(getAlarm().Musique.Number >= 8){
			setAlarmMusic(1);
		}
		else {
			setAlarmMusic((uint8_t) (getAlarm().Musique.Number + 1 ));
		}
		setMusicString(getAlarm().Musique.Number, getAlarm());
	}
}
