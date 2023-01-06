/**********************************************************************
  * Project Name: USART_1
  * File Name: usart.h
  * Revision:
  * Microcontroller name:STM32F103xxxx ARM
  * Compiler: Keil MDK_ARM 4 - 5
  * Author:   Jesus Pestano
  * E-mail:   jmpestanoh@gmail.com
  * Date :    2018.01.08
  * Important:Select in "Options for Target" the option
  *           (x) Use MicroLib
  * =====================================================================
  * 
  * PROGRAMA DE PRUEBA PUERTO USARTx
  * 
  * Enviamos por el puerto USART1 del microcontrolador un texto
  * de prueba.
  *
  *  Pines del USART1:   Tx PA9
  *                      Rx PA10
  *
  **********************************************************************/
 

#ifndef __USART1_H
#define	__USART1_H

#include "stm32f10x.h"

void USART1_Config(void);

#endif /* __USART1_H */
