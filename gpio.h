#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>
#include "stm32f10x.h"

#ifdef __cplusplus
extern "C" {
#endif

extern void pinSet(uint8_t pin);
extern void pinReset(uint8_t pin);
extern int32_t pinRead(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
extern void gpioSetConfig(uint8_t pin, uint8_t mode);
extern void gpioPortInit(GPIO_TypeDef *gpio);


#define GPIO_CRL_CRH_RESET  0x44444444

/********** Bit definition for PORT A **********************************/
#define PA0         ((uint8_t)0x00)
#define PA1         ((uint8_t)0x01)
#define PA2         ((uint8_t)0x02)
#define PA3         ((uint8_t)0x03)
#define PA4         ((uint8_t)0x04)
#define PA5         ((uint8_t)0x05)
#define PA6         ((uint8_t)0x06)
#define PA7         ((uint8_t)0x07)
#define PA8         ((uint8_t)0x08)
#define PA9         ((uint8_t)0x09)
#define PA10        ((uint8_t)0x0A)
#define PA11        ((uint8_t)0x0B)
#define PA12        ((uint8_t)0x0C)
#define PA13        ((uint8_t)0x0D)
#define PA14        ((uint8_t)0x0E)
#define PA15        ((uint8_t)0x0F)

/********** Bit definition for PORT B **********************************/
#define PB0         ((uint8_t)0x10)
#define PB1         ((uint8_t)0x11)
#define PB2         ((uint8_t)0x12)
#define PB3         ((uint8_t)0x13)
#define PB4         ((uint8_t)0x14)
#define PB5         ((uint8_t)0x15)
#define PB6         ((uint8_t)0x16)
#define PB7         ((uint8_t)0x17)
#define PB8         ((uint8_t)0x18)
#define PB9         ((uint8_t)0x19)
#define PB10        ((uint8_t)0x1A)
#define PB11        ((uint8_t)0x1B)
#define PB12        ((uint8_t)0x1C)
#define PB13        ((uint8_t)0x1D)
#define PB14        ((uint8_t)0x1E)
#define PB15        ((uint8_t)0x1F)

/********** Bit definition for PORT C **********************************/
#define PC0         ((uint8_t)0x20)
#define PC1         ((uint8_t)0x21)
#define PC2         ((uint8_t)0x22)
#define PC3         ((uint8_t)0x23)
#define PC4         ((uint8_t)0x24)
#define PC5         ((uint8_t)0x25)
#define PC6         ((uint8_t)0x26)
#define PC7         ((uint8_t)0x27)
#define PC8         ((uint8_t)0x28)
#define PC9         ((uint8_t)0x29)
#define PC10        ((uint8_t)0x2A)
#define PC11        ((uint8_t)0x2B)
#define PC12        ((uint8_t)0x2C)
#define PC13        ((uint8_t)0x2D)
#define PC14        ((uint8_t)0x2E)
#define PC15        ((uint8_t)0x2F)

/********** Bit definition for PORT D **********************************/
#define PD0         ((uint8_t)0x30)
#define PD1         ((uint8_t)0x31)
#define PD2         ((uint8_t)0x32)
#define PD3         ((uint8_t)0x33)
#define PD4         ((uint8_t)0x34)
#define PD5         ((uint8_t)0x35)
#define PD6         ((uint8_t)0x36)
#define PD7         ((uint8_t)0x37)
#define PD8         ((uint8_t)0x38)
#define PD9         ((uint8_t)0x39)
#define PD10        ((uint8_t)0x3A)
#define PD11        ((uint8_t)0x3B)
#define PD12        ((uint8_t)0x3C)
#define PD13        ((uint8_t)0x3D)
#define PD14        ((uint8_t)0x3E)
#define PD15        ((uint8_t)0x3F)

/********** Bit definition for PORT E **********************************/
#define PE0         ((uint8_t)0x40)
#define PE1         ((uint8_t)0x41)
#define PE2         ((uint8_t)0x42)
#define PE3         ((uint8_t)0x43)
#define PE4         ((uint8_t)0x44)
#define PE5         ((uint8_t)0x45)
#define PE6         ((uint8_t)0x46)
#define PE7         ((uint8_t)0x47)
#define PE8         ((uint8_t)0x48)
#define PE9         ((uint8_t)0x49)
#define PE10        ((uint8_t)0x4A)
#define PE11        ((uint8_t)0x4B)
#define PE12        ((uint8_t)0x4C)
#define PE13        ((uint8_t)0x4D)
#define PE14        ((uint8_t)0x4E)
#define PE15        ((uint8_t)0x4F)

/********** Bit definition for PORT F **********************************/
#define PF0         ((uint8_t)0x50)
#define PF1         ((uint8_t)0x51)
#define PF2         ((uint8_t)0x52)
#define PF3         ((uint8_t)0x53)
#define PF4         ((uint8_t)0x54)
#define PF5         ((uint8_t)0x55)
#define PF6         ((uint8_t)0x56)
#define PF7         ((uint8_t)0x57)
#define PF8         ((uint8_t)0x58)
#define PF9         ((uint8_t)0x59)
#define PF10        ((uint8_t)0x5A)
#define PF11        ((uint8_t)0x5B)
#define PF12        ((uint8_t)0x5C)
#define PF13        ((uint8_t)0x5D)
#define PF14        ((uint8_t)0x5E)
#define PF15        ((uint8_t)0x5F)

/********** Bit definition for PORT G **********************************/
#define PG0         ((uint8_t)0x60)
#define PG1         ((uint8_t)0x61)
#define PG2         ((uint8_t)0x62)
#define PG3         ((uint8_t)0x63)
#define PG4         ((uint8_t)0x64)
#define PG5         ((uint8_t)0x65)
#define PG6         ((uint8_t)0x66)
#define PG7         ((uint8_t)0x67)
#define PG8         ((uint8_t)0x68)
#define PG9         ((uint8_t)0x69)
#define PG10        ((uint8_t)0x6A)
#define PG11        ((uint8_t)0x6B)
#define PG12        ((uint8_t)0x6C)
#define PG13        ((uint8_t)0x6D)
#define PG14        ((uint8_t)0x6E)
#define PG15        ((uint8_t)0x6F)

/********** GPIO ports offset ******************************************/
#define PORTA       ((uint8_t)0x00)
#define PORTB       ((uint8_t)0x10)
#define PORTC       ((uint8_t)0x20)
#define PORTD       ((uint8_t)0x30)
#define PORTE       ((uint8_t)0x40)
#define PORTF       ((uint8_t)0x50)
#define PORTG       ((uint8_t)0x60)


/********** GPIO modes *************************************************/
#define GPIO_MODE_INPUT_ANALOG                ((uint8_t)0x00)
#define GPIO_MODE_INPUT_FLOATING              ((uint8_t)0x01)
#define GPIO_MODE_INPUT_PULLUP                ((uint8_t)0x02)
#define GPIO_MODE_INPUT_PULLDOWN              ((uint8_t)0x03)
#define GPIO_MODE_INPUT_RESERVED              ((uint8_t)0x04)
#define GPIO_MODE_IT_RISING                   ((uint8_t)0x05)
#define GPIO_MODE_IT_FALLING                  ((uint8_t)0x06)
#define GPIO_MODE_IT_RISING_FALLING           ((uint8_t)0x07)
#define GPIO_MODE_EVT_RISING                  ((uint8_t)0x08)
#define GPIO_MODE_EVT_FALLING                 ((uint8_t)0x09)
#define GPIO_MODE_RISING_FALLING              ((uint8_t)0x0A)
#define GPIO_MODE_OUTPUT_PUSH_PULL_PULLUP     ((uint8_t)0x10)
#define GPIO_MODE_OUTPUT_PUSH_PULL_PULLDOWN   ((uint8_t)0x11)
#define GPIO_MODE_OUTPUT_PUSH_PULL            ((uint8_t)0x12)
#define GPIO_MODE_OUTPUT_OPEN_DRAIN_PULLUP    ((uint8_t)0x13)
#define GPIO_MODE_OUTPUT_OPEN_DRAIN           ((uint8_t)0x14)

#define GPIO_MODE_OUTPUT_GP_PUSH_PULL           ((uint8_t)0x20)
#define GPIO_MODE_OUTPUT_GP_OPEN_DRAIN          ((uint8_t)0x21)
#define GPIO_MODE_OUTPUT_AF_PUSH_PULL           ((uint8_t)0x22)
#define GPIO_MODE_OUTPUT_AF_OPEN_DRAIN          ((uint8_t)0x23)


#ifdef __cplusplus
}
#endif

#endif //GPIO_H
