/**
 * @file EXTI_interface.h
 * @author Abdulrahman Aboghanima (abdoaboganima@icloud.com)
 * @brief User interface of the EXTI(External Interrupt)
 * @version 0.1
 * @copyright Copyright (c) 2022
 * \code #include "EXTI_interface.h" \endcode
 */


#ifndef _EXTI_INTERFACE_H_
#define _EXTI_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"


#define FALLING_EDGE       1
#define RISING_EDGE        2
#define LOW_LEVEL          3
#define ANY_LOGICAL_CHANGE 4


#define INT0               6  
#define INT1               7
#define INT2               5

/**
 * @brief Diasble An external Interrupt by passing its ID
 * @param INT_ID
 */
#define EXTI_enableInterrupt(INT_ID) SET_BIT(GICR, INT_ID)

/**
 * @brief Disable An external Interrupt by passing its ID
 * @param INT_ID
 */
#define EXTI_disableInterrupt(INT_ID) CLEAR_BIT(GICR, INT_ID)




/**
 * @brief Initializes the External interrupt INT0 based on the configurations defined
 * in the `EXTI_config.h`    
 * @return void
 */
extern void EXTI_Int0_init(void);



/**
 * @brief Initializes the External interrupt INT1 based on the configurations defined
 * in the `EXTI_config.h`    
 * @return void
 */
extern void EXTI_Int1_init(void);



/**
 * @brief Initializes the External interrupt INT2 based on the configurations defined
 * in the `EXTI_config.h`    
 * @return void
 */
extern void EXTI_Int2_init(void);


/**
 * @brief Sets the callback function that will be called when there INT0 happens
 * @param Int0Func
 * @return void
 */
extern void EXTI_Int0SetCallBack(void (*Int0Func)(void));



/**
 * @brief Sets the callback function that will be called when there INT1 happens
 * @param Int1Func
 * @return void
 */
extern void EXTI_Int1SetCallBack(void (*Int1Func)(void));



/**
 * @brief Sets the callback function that will be called when there INT2 happens
 * @param Int2Func
 * @return void
 */
void EXTI_Int2SetCallBack(void (*Int2Func)(void));



/**
 * @brief Sets the required Sense Control of INT0.  
 * @param sense
 * @return void
 * @note This function is a post build configuration for the EXTI module, 
 * you can use pre-build configuration also from the `EXTI_config.h` file
 */
extern void EXTI_Int0SetSenseControl(const uint8_t sense);


/**
 * @brief Sets the required Sense Control of INT1.  
 * @param sense
 * @return void
 * @note This function is a post build configuration for the EXTI module, 
 * you can use pre-build configuration also from the `EXTI_config.h` file
 * @todo implementation
 */
extern void EXTI_Int1SetSenseControl(const uint8_t sense);


/**
 * @brief Sets the required Sense Control of INT2.  
 * @param sense
 * @return void
 * @note This function is a post build configuration for the EXTI module, 
 * you can use pre-build configuration also from the `EXTI_config.h` file
 * @todo implementation
 * @note Changing the ISC2 can cause an interrupt, it's recommended to
 * disable the INT2 flag (By writing one to INTF2 flag).
 */
extern void EXTI_Int2SetSenseControl(const uint8_t sense);

#endif /* _EXTI_INTERFACE_H_ */
