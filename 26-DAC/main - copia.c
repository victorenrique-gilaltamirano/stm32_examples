 /**********************************************************************
  * Project Name: DAC
  * File Name: main.c
  * Revision:
  * Microcontroller name:STM32F103xxxx ARM
  * Compiler: Keil MDK_ARM 4 - 5
  * Author:   Jesus Pestano
  * E-mail:   jmpestanoh@gmail.com
  * Date :    2018.01.08
  * Select in "Options for Target" the option
  *           (x) Use MicroLib
  * ===================================================================
  * 
  *  PROGRAMA DE EJEMPLO DE CONFIGURACION DEL DAC
  *
  *  En el ejemplo se configura el canal 1 del DAC en 
  *  el pin PA4 por donde se generara una señal analogica
  *  de diente de sierra.
  *   
  ********************************************************************/
  
// Libreria principal del micro
#include "stm32f10x.h"

// Librerias de los perifericos
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h" 
#include "stm32f10x_dac.h" 

/*  Funcion que configura el DAC     */
//---------------------------------------
void DAC_Config (void)     
{
  /* Configuracion del GPIO de PA4  */
  GPIO_InitTypeDef GPIO_InitStructure;  
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);  
  GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_4;
  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AIN;  
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);  
  
  /* Configuracion del DAC          */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC, ENABLE);
  DAC_InitTypeDef DAC_InitStructure;
  DAC_InitStructure.DAC_OutputBuffer  = DAC_OutputBuffer_Enable;
  DAC_InitStructure.DAC_Trigger       = DAC_Trigger_None;
  DAC_InitStructure.DAC_WaveGeneration= DAC_WaveGeneration_None;
  DAC_Init(DAC_Channel_1, &DAC_InitStructure); 
  DAC_Init(DAC_Channel_2, &DAC_InitStructure);
  
  // Habilitamos el canal 1 del DAC
  DAC_Cmd(DAC_Channel_1, ENABLE);     
}


/*          Modulo principal      */
//========================================
int main ()  
{                    
  DAC_Config();   // Inicializamos el DAC
  
  while (1) {
    
    for (int valor=0; valor< 4000; valor++)
      {

      DAC_SetChannel1Data(DAC_Align_12b_R, valor);
      }
  }
}

///////////////////   Fin del programa    ///////////////////////

