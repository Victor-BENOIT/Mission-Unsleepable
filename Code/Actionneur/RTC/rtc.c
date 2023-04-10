/**
 * @file rtc.c
 * @brief Afficher les éléments unique de l'écran SetHour
 * @date 22/11/2022
 * @author Maxence Bigot
 */

#include "Actionneur/RTC/rtc.h"


/**
 * @fn void initModuleRTC(uint8_t Year, uint8_t Month, uint8_t Date, uint8_t Hour, uint8_t Minute, uint8_t Second)
 * @brief Initialiser l'heure et la date du capteur RTC
 * @date 22/11/2022
 * @author Maxence Bigot
 * @param Year Entier non signé 8bits
 * @param Month Entier non signé 8bits
 * @param Date Entier non signé 8bits
 * @param Hour Entier non signé 8bits
 * @param Minute Entier non signé 8bits
 * @param Second Entier non signé 8bits
 */
void initModuleRTC(uint8_t Year, uint8_t Month, uint8_t Date, uint8_t Hour, uint8_t Minute, uint8_t Second){
	//Initialiser la date et l'heure du capteur RTC

	RTC_TimeTypeDef currentTime;
	RTC_DateTypeDef currentDate;

	currentTime.Hours = Hour;
	currentTime.Minutes = Minute;
	currentTime.Seconds = Second;

	currentDate.Year = Year;
	currentDate.Month = Month;
	currentDate.Date = Date;

	RTC_set_time_and_date(&currentTime, &currentDate);
}
