/*
 * rtc.h
 * Purpose : Gerer le module rtc
 *
 *  Created on: 17/11/2022
 *  Author: Bigot
 */

#ifndef RTC_H_
#define RTC_H_

#include "stdint.h"
#include "stm32f1_rtc.h"

void initModuleRTC(uint8_t Year, uint8_t Month, uint8_t Date, uint8_t Hour, uint8_t Minute, uint8_t Second);

#endif
