/**
 * @file screen_home.c
 * @brief Afficher les elements unique de l'Ècran Home
 * @date 15/12/2022
 * @author Maxence Bigot
 */

#include "Screens/Home/screen_home.h"


/**
 * @fn void screen_home(Alarme alarm)
 * @brief Afficher les ÈlÈments unique de l'Ècran Home
 * @date 15/12/2022
 * @author Maxence Bigot
 * @param alarm Variable alarm de scructure Alarme
 */
void screen_home(Alarme alarm){



	//Cr√©ation des variables
	char alarmString[8];
	sprintf(alarmString, "%d:%d:%d", alarm.Hours, alarm.Minutes, alarm.Seconds);


	//Couleur de fond
	ILI9341_Fill(ILI9341_COLOR_BLUE);

	//Affichage du temps
	ILI9341_Puts(15, 20, "GOOD MORNING, IT'S", &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE);

	//if(getTime().Hours >= 12){
		//ILI9341_Puts(185, 51, "AM", &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE);
	//}
	//else{
		//ILI9341_Puts(185, 51, "PM", &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE);
	//}

	ILI9341_Puts(185, 55, "AM", &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE);

	//Affichage de l'alarme
	if(alarm.Set){
		ILI9341_Puts(273, 22, "ON", &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE);
	}
	else {
		ILI9341_Puts(273, 22, "OFF", &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE);
	}


	//Bordure de s√©paration
	ILI9341_DrawFilledRectangle(0, 80, 320, 82, ILI9341_COLOR_BLACK);
	//


	//Affichage de la ligne 1
	ILI9341_Puts(21, 95, "DATE", &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE);

	//Affichage de la ligne 2
	ILI9341_Puts(21, 144, "ALARME", &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE);
	ILI9341_Puts(21, 164, alarmString, &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE);


	//Affichage de la ligne 3
	ILI9341_Puts(21, 193, "MUSIC", &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE);
	ILI9341_Puts(21, 213, alarm.Musique.Title, &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE);
}
