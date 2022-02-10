/*******************************************************
 * @file   RTC.h
 * @brief  User interface of the `RTC`. 
 *         Contains the common data structures and function
 *         prototypes for the various RTCs
 * @author Abdulrahman Aboghanima
 * @date   Wed Feb  9 12:03:45 2022
 *******************************************************/

#ifndef _RTC_H_
#define _RTC_H_
#include "../../LIB/STD_TYPES.h"

enum days{
  Sunday=1,
  Monday,
  Tuesday,
  Wednesday,
  Thursday,
  Friday,
  Saturday
};

enum format{
  AM=0,
  PM=1
};

typedef struct
{
  uint8_t seconds;
  uint8_t minutes;
  uint8_t hours;
  uint8_t time_format;
  
} RTC_time_t;

typedef struct
{
  uint8_t day;
  uint8_t date;
  uint8_t month;
  uint8_t year;

} RTC_date_t;

 /**
 * @brief Initialization of the `RTC` (Real Time Clock) Module
 * 
 */
void RTC_init(void);
 
 
 /**
 * @brief Sets the current time, takes the time stucture
 * @param time 
 */
void RTC_set_current_time(const RTC_time_t * const time);

 /**
 * @brief Sets the current date
 * @param date 
 */
void RTC_set_current_date(const RTC_date_t * const date);

 /**
 * @brief Gets the current time structure
 * @return RTC_time_t 
 */
RTC_time_t RTC_get_current_time(void);

 /**
 * @brief Gets the current date
 * @return RTC_date_t 
 */
RTC_date_t RTC_get_current_date(void);

 /**
 * @brief Sets the current date 
 * @param date 
 * @note The range of the date is from 1-31 days
 * @note I mean by `date` here the number of the day in the month
 */
void RTC_set_date(const uint8_t date);

 /**
 * @brief Sets the Month
 * @param month 
 */
void RTC_set_month(const uint8_t month);
 
 /**
 * @brief Sets the year 
 * @param year 
 */
void RTC_set_year(const uint8_t year);

 /**
 * @brief Sets the second 
 * @param year 
 */
void RTC_set_second(const uint8_t seconds);

 /**
 * @brief Sets the minute 
 * @param year 
 */
void RTC_set_minute(const uint8_t minute);

 /**
 * @brief Sets the hour 
 * @param year 
 */
void RTC_set_hour(const uint8_t hour);

 /**
 * @brief Gets the current second
 * @return uint8_t 
 */
uint8_t RTC_get_second(void);

 /**
 * @brief Gets the current minute
 * @return uint8_t 
 */
uint8_t RTC_get_minute(void);

 /**
 * @brief Gets the current hour
 * @return uint8_t 
 */
uint8_t RTC_get_hour(void);


 /**
 * @brief Gets the current date(day)
 * @return uint8_t 
 */
uint8_t RTC_get_date(void);

 /**
 * @brief Gets the current month
 * @return uint8_t 
 */
uint8_t RTC_get_month(void);

 /**
 * @brief Gets the current year
 * @return uint8_t 
 */
uint8_t RTC_get_year(void);


#endif /* _RTC_H_ */
