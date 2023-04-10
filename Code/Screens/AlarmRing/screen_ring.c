/*
 * @file screen_home.c
 * @brief Afficher les éléments unique de l'écran Alarme
 * @date 15/12/2022
 * @author Maxence Bigot
 */

#include "Screens/AlarmRing/screen_ring.h"


/*
 * @fn void screen_alarm_ring(Alarme alarm)
 * @brief Afficher les éléments unique de l'écran Alarme
 * @date 15/12/2022
 * @author Maxence Bigot
 * @param alarm Variable alarm de scructure Alarme
 */
void screen_alarm_ring(Alarme alarm){
	//Creation des variables
	char alarmString[8];
	sprintf(alarmString, "%d:%d:%d", alarm.Hours, alarm.Minutes, alarm.Seconds);

	//Couleur de fond
	ILI9341_Fill(ILI9341_COLOR_BLUE);

	//Affichage de l'alarme
	ILI9341_Puts(15, 20, "RING RING IT'S TIME", &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE);
	ILI9341_Puts(120, 51, alarmString, &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE);
	ILI9341_Puts(15,91, alarm.Musique.Title, &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE);

	//Bordure de separation
	ILI9341_DrawFilledRectangle(0, 130, 320, 132, ILI9341_COLOR_BLACK);


	//Affichage de la ligne 1
	ILI9341_Puts(21, 175, "HOLD TO STOP", &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE);
}
