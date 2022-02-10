/*******************************************************
 *
 * @file   RTC.c
 * @brief  Contains common functions definitions
 * @author Abdulrahman Aboghanima
 * @date   Wed Feb  9 12:05:07 2022
 *
 *******************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/TWI/TWI_interface.h"
#include "RTC_private.h"
#include "RTC_config.h"
#include "RTC_interface.h"

#if USED_DEVICE==DS1307
#include "ds1307.h"
#define RTC_ADDRESS DS1307_ADDRESS 
#endif

static  uint8_t bcdOf(uint8_t num)
{
  uint8_t i=0, temp=0;
  while(num>0){
    temp|=((num%10)<<i);
    i+=4;
    num/=10;
  } 
  return temp;
}

static  uint8_t intOf(uint8_t num)
{
  uint8_t i=1, temp=0;
  while(num>0){
    temp+=(num%16)*i;
    i*=10;
    num/=16;
  }
  return temp;
}

void RTC_init()
{
  TWI_initMaster(); //Initialize the TWI interface peripheral
  TWI_sendStartCondition();
  TWI_sendSlaveAddressWithWrite(RTC_ADDRESS);
  TWI_masterWrite(PTR_CONTORL);
  TWI_masterWrite(0x00);
  TWI_sendStopCondition();
}

void RTC_set_current_time(const RTC_time_t * const time)
{
  TWI_sendStartCondition();
  TWI_sendSlaveAddressWithWrite(RTC_ADDRESS);

  TWI_masterWrite(PTR_SECONDS); //Set the register pointer to the first address

  TWI_masterWrite( bcdOf(time->seconds) );
  TWI_masterWrite( bcdOf(time->minutes)  );
  TWI_masterWrite( bcdOf(time->hours)    );

  TWI_sendStopCondition();
  
}
void RTC_set_current_date(const RTC_date_t * const date)
{
  TWI_sendStartCondition();
  TWI_sendSlaveAddressWithWrite(RTC_ADDRESS);

  TWI_masterWrite(PTR_DAY); //Moving the register pointer to the the fourth memory location

  TWI_masterWrite(date->day);
  TWI_masterWrite(bcdOf(date->date));
  TWI_masterWrite(bcdOf(date->month));
  TWI_masterWrite(bcdOf(date->year));

  TWI_sendStopCondition();
}
RTC_time_t RTC_get_current_time(void)
{
  RTC_time_t current_time;
  uint8_t holder;

  TWI_sendStartCondition();
  TWI_sendSlaveAddressWithWrite(RTC_ADDRESS);
  TWI_masterWrite(PTR_SECONDS);

  TWI_sendRepeatedStartCondition();

  TWI_sendSlaveAddressWithRead(RTC_ADDRESS);

  TWI_masterRead(&holder, 3);
  current_time.seconds=intOf(holder);

  TWI_masterRead(&holder, 2);
  current_time.minutes=intOf(holder);

  TWI_masterRead(&holder, 1);
  current_time.hours=intOf(holder);

  TWI_sendStopCondition();

  return current_time;
}

RTC_date_t RTC_get_current_date(void)
{
  RTC_date_t current_date;
  uint8_t holder;

  TWI_sendStartCondition();
  TWI_sendSlaveAddressWithWrite(RTC_ADDRESS);
  TWI_masterWrite(PTR_DAY);

  TWI_sendRepeatedStartCondition();
  TWI_sendSlaveAddressWithRead(RTC_ADDRESS);

  TWI_masterRead(&holder, 4);
  current_date.date=intOf(holder);
  
  TWI_masterRead(&holder, 3);
  current_date.date=intOf(holder);

  TWI_masterRead(&holder, 2);
  current_date.month=intOf(holder);

  TWI_masterRead(&holder, 1);
  current_date.year=intOf(holder);

  TWI_sendStopCondition();
  return current_date;
}

void RTC_set_date(const uint8_t date)
{
  TWI_sendStartCondition();
  TWI_sendSlaveAddressWithWrite(RTC_ADDRESS);
  TWI_masterWrite(PTR_DATE);
  TWI_masterWrite(bcdOf(date));
  TWI_sendStopCondition();
}
void RTC_set_month(const uint8_t month)
{
  TWI_sendStartCondition();
  TWI_sendSlaveAddressWithWrite(RTC_ADDRESS);
  TWI_masterWrite(PTR_MONTH);
  TWI_masterWrite(bcdOf(month));
  TWI_sendStopCondition();
}
void RTC_set_year(const uint8_t year)
{
  TWI_sendStartCondition();
  TWI_sendSlaveAddressWithWrite(RTC_ADDRESS);
  TWI_masterWrite(PTR_YEAR);
  TWI_masterWrite(bcdOf(year));
  TWI_sendStopCondition();
}


uint8_t RTC_get_date(void)
{
  uint8_t current=0;
  TWI_sendStartCondition();
  TWI_sendSlaveAddressWithWrite(RTC_ADDRESS);
  TWI_masterWrite(PTR_DATE); //pointer to date
  TWI_sendRepeatedStartCondition();
  TWI_sendSlaveAddressWithRead(RTC_ADDRESS);
  TWI_masterRead(&current, 1);
  TWI_sendStopCondition();

  return intOf(current);
  
}
uint8_t RTC_get_month(void)
{
  uint8_t current=0;
  TWI_sendStartCondition();
  TWI_sendSlaveAddressWithWrite(RTC_ADDRESS);
  TWI_masterWrite(PTR_MONTH); //pointer to month
  TWI_sendRepeatedStartCondition();
  TWI_sendSlaveAddressWithRead(RTC_ADDRESS);
  TWI_masterRead(&current, 1);
  TWI_sendStopCondition();

  return intOf(current);
}
uint8_t RTC_get_year(void)
{
  uint8_t current=0;
  TWI_sendStartCondition();
  TWI_sendSlaveAddressWithWrite(RTC_ADDRESS);
  TWI_masterWrite(PTR_YEAR); //pointer to
  TWI_sendRepeatedStartCondition();
  TWI_sendSlaveAddressWithRead(RTC_ADDRESS);
  TWI_masterRead(&current, 1);
  TWI_sendStopCondition();

  return intOf(current);
}

void RTC_set_second(const uint8_t seconds)
{
  TWI_sendStartCondition();
  TWI_sendSlaveAddressWithWrite(RTC_ADDRESS);
  TWI_masterWrite(PTR_SECONDS);
  TWI_masterWrite(bcdOf(seconds));
  TWI_sendStopCondition();
}
void RTC_set_minute(const uint8_t minute)
{
  TWI_sendStartCondition();
  TWI_sendSlaveAddressWithWrite(RTC_ADDRESS);
  TWI_masterWrite(PTR_MINUTES);
  TWI_masterWrite(bcdOf(minute));
  TWI_sendStopCondition();
}
void RTC_set_hour(const uint8_t hour)
{
  TWI_sendStartCondition();
  TWI_sendSlaveAddressWithWrite(RTC_ADDRESS);
  TWI_masterWrite(PTR_HOURS);
  TWI_masterWrite(bcdOf(hour));
  TWI_sendStopCondition();
}

uint8_t RTC_get_second(void)
{
  uint8_t current=0;
  TWI_sendStartCondition();
  TWI_sendSlaveAddressWithWrite(RTC_ADDRESS);
  TWI_masterWrite(PTR_SECONDS); //pointer to
  TWI_sendRepeatedStartCondition();
  TWI_sendSlaveAddressWithRead(RTC_ADDRESS);
  TWI_masterRead(&current, 1);
  TWI_sendStopCondition();
  return intOf(current&0x7F); //For clearing the CH, clock halt, bit
}
uint8_t RTC_get_minute(void)
{
  uint8_t current=0;
  TWI_sendStartCondition();
  TWI_sendSlaveAddressWithWrite(RTC_ADDRESS);
  TWI_masterWrite(PTR_MINUTES); //pointer to
  TWI_sendRepeatedStartCondition();
  TWI_sendSlaveAddressWithRead(RTC_ADDRESS);
  TWI_masterRead(&current, 1);
  TWI_sendStopCondition();

  return intOf(current);
}
uint8_t RTC_get_hour(void)
{
  uint8_t current=0;
  TWI_sendStartCondition();
  TWI_sendSlaveAddressWithWrite(RTC_ADDRESS);
  TWI_masterWrite(PTR_HOURS); //pointer to
  TWI_sendRepeatedStartCondition();
  TWI_sendSlaveAddressWithRead(RTC_ADDRESS);
  TWI_masterRead(&current, 1);
  TWI_sendStopCondition();
  return intOf(current&0x3f);//for clearing them 2 MSBs
}

