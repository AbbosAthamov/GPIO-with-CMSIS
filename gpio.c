#include "gpio.h"


GPIO_TypeDef *getPinPort(uint8_t pin);
int16_t getPinOffset(uint8_t pin);

void pinSet(uint8_t pin) {
  GPIO_TypeDef *port = getPinPort(pin);
  SET_BIT(port->BSRR, GPIO_BSRR_BS0 << (pin % 0x10));
}

void pinReset(uint8_t pin) {
  GPIO_TypeDef *port = getPinPort(pin);
  SET_BIT(GPIOB->BSRR, GPIO_BSRR_BS0 | 0x00010000 << pin % 0x10);
}

int32_t pinRead(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) {
  if ((GPIOx->IDR & GPIO_Pin) != (uint32_t)0) {
    return 1;
  } else {
    return 0;
  }
}

void gpioPortInit(GPIO_TypeDef *gpio) {
  gpio->CRH = GPIO_CRL_CRH_RESET;
  gpio->CRL = GPIO_CRL_CRH_RESET;
}


void gpioSetConfig(uint8_t pin, uint8_t mode) {

  GPIO_TypeDef *port = getPinPort(pin);
  int16_t pinOffset = pin % 0x10;

  SET_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPAEN << getPinOffset(pin) / 0x10);


  volatile uint32_t *portReg;
  if (pinOffset >= 8) {
    portReg = &port->CRH;
  } else {
    portReg = &port->CRL;
  }


  switch (mode) {
    case GPIO_MODE_OUTPUT_GP_PUSH_PULL:
      CLEAR_BIT(*portReg, GPIO_CRL_CNF0 << 4 * (pinOffset % 8));
      CLEAR_BIT(*portReg, GPIO_CRL_MODE0 << 4 * (pinOffset % 8));
      SET_BIT(*portReg, GPIO_CRL_MODE0_1 << 4 * (pinOffset % 8));
    break;
        
    case GPIO_MODE_OUTPUT_GP_OPEN_DRAIN:
      SET_BIT(*portReg, GPIO_CRL_CNF0_0 << 4 * (pinOffset % 8));
      CLEAR_BIT(*portReg, GPIO_CRL_CNF0_1 << 4 * (pinOffset % 8));
      CLEAR_BIT(*portReg, GPIO_CRL_MODE0 << 4 * (pinOffset % 8));
      SET_BIT(*portReg, GPIO_CRL_MODE0_1 << 4 * (pinOffset % 8));
    break;
      
    case GPIO_MODE_OUTPUT_AF_PUSH_PULL:
      SET_BIT(*portReg, GPIO_CRL_CNF0_1 << 4 * (pinOffset % 8));
      CLEAR_BIT(*portReg, GPIO_CRL_CNF0_0 << 4 * (pinOffset % 8));
      CLEAR_BIT(*portReg, GPIO_CRL_MODE0 << 4 * (pinOffset % 8));
      SET_BIT(*portReg, GPIO_CRL_MODE0_1 << 4 * (pinOffset % 8));
    break;
        
    case GPIO_MODE_OUTPUT_AF_OPEN_DRAIN:
      SET_BIT(*portReg, GPIO_CRL_CNF0 << 4 * (pinOffset % 8));
      CLEAR_BIT(*portReg, GPIO_CRL_MODE0 << 4 * (pinOffset % 8));
      SET_BIT(*portReg, GPIO_CRL_MODE0_1 << 4 * (pinOffset % 8));
    break;
  }
}

GPIO_TypeDef *getPinPort(uint8_t pin) {
  if (pin <= PA15) return GPIOA;
  else if (pin >= PB0 && pin <= PB15) return GPIOB;
  else if (pin >= PC0 && pin <= PC15) return GPIOC;
  else if (pin >= PD0 && pin <= PD15) return GPIOD;
  else if (pin >= PE0 && pin <= PE15) return GPIOE;
  else if (pin >= PF0 && pin <= PF15) return GPIOF;
  else if (pin >= PG0 && pin <= PG15) return GPIOG;
  
  return 0; 
}

int16_t getPinOffset(uint8_t pin) {
  if (pin <= PA15) return PORTA;
  else if (pin >= PB0 && pin <= PB15) return PORTB;
  else if (pin >= PC0 && pin <= PC15) return PORTC;
  else if (pin >= PD0 && pin <= PD15) return PORTD;
  else if (pin >= PE0 && pin <= PE15) return PORTE;
  else if (pin >= PF0 && pin <= PF15) return PORTF;
  else if (pin >= PG0 && pin <= PG15) return PORTG;
  
  return -1;
}
