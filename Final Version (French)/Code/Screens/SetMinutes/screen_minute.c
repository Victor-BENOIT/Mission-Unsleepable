/**
 * @file screen_minute.c
 * @brief Afficher les éléments unique de l'écran SetMinutes
 * @date 15/12/2022
 * @author Maxence Bigot
 */

#include <Screens/SetHour/screen_hour.h>


/**
 * @fn void screen_minutes(Alarme alarm)
 * @brief Afficher les éléments unique de l'écran SetHour
 * @date 15/12/2022
 * @author Maxence Bigot
 * @param alarm Variable alarm de scructure Alarme
 */
void screen_minutes(Alarme alarm){

	//Creation des variables
	char alarmString[8];
	sprintf(alarmString, "%d:%d:%d", alarm.Hours, alarm.Minutes, alarm.Seconds);

	//Couleur de fond
	ILI9341_Fill(ILI9341_COLOR_BLUE);
	ILI9341_Puts(15, 20, "ALARM SETTINGS : MINUTE", &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE);

	//Affichage de l'alarme
	if(alarm.Set){
		ILI9341_Puts(273, 55, "ON", &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE);
	}
	else {
		ILI9341_Puts(273, 55, "OFF", &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE);
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
 * @fn void setMinuteString(Alarme alarm)
 * @brief Afficher l'attribut Hour de l'écran SetHour
 * @date 15/12/2022
 * @author Maxence Bigot
 * @param alarm Variable alarm de scructure Alarme
 */
void setMinuteString(Alarme alarm){
	char alarmString[12];
	sprintf(alarmString, "%d : < %d >", alarm.Hours, alarm.Minutes);

	ILI9341_DrawFilledRectangle(20, 55, 320, 88, ILI9341_COLOR_BLUE);
	ILI9341_Puts(110, 55, alarmString, &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE);
}


/**
 * @fn changeAlarmMinuteVariable(void)
 * @brief Gérer l'augmentation et la diminution de l'attribut Hours
 * @date 15/12/2022
 * @author Maxence Bigot
 */
void changeAlarmMinuteVariable(){

	//Diminution d'une unite de la Variable
	if(button_left_press_event()){
		if(getAlarm().Minutes <= 0){
			setAlarmMinutes(59);
		}
		else {
			setAlarmMinutes((uint8_t) (getAlarm().Minutes - 1));
		}
		setMinuteString(getAlarm());
	}


	//Augmentation d'une unite de la Variable
	if(button_right_press_event()){
		if(getAlarm().Minutes >= 59){
			setAlarmMinutes(0);
		}
		else {
			setAlarmMinutes((uint8_t) (getAlarm().Minutes + 1));
		}
		setMinuteString(getAlarm());
	}
}



