/*
  *******************************************************************************
  * @Project  ascii to hex 
  * @author   Swapnil Chougule
  * @version  V_01
  * @date     21-Nov-2021
  * @brief    
  ******************************************************************************
*/ 
//online compiler: https://www.onlinegdb.com/online_c_compiler
//Tutorials-point: https://www.tutorialspoint.com/cprogramming/index.htm
//Javat-t-point  : https://www.javatpoint.com/c-programming-language-tutorial 
/***************************** Includes *****************************************************/
#include<stdio.h>    // The header file stdio.h stands for Standard Input Output. It has the information related to input/output functions. i.e.:printf(),scanf(),getc(),putc() etc.
#include<stdint.h>   // it declare sets of integer types having specified widths, and shall define corresponding sets of macros.i.e.: int8_t,int16_t,int32_t,uint8_t,uint16_t,uint32_t
/***************************** globals *****************************************************/
#define UART_BuffSize            10                   // macro: size of UART data buffer
const int8_t hextab[] 		= "0123456789ABCDEF";  // Character array Hex Table for hexadecimal representation
volatile uint16_t StartAddr	= 0xABCD;      	// vartiable StartAddr with ascii value ABCD(i.e. consider StartAddr = memory address location )
uint8_t UART_Buffer [UART_BuffSize];			// UART_Buffer to store data
uint8_t Tx_Indx		= 0;                   // TX Write pointer
/***************************** Application Functions *****************************************************/
/* ascii to hex: */
void hexout (volatile uint16_t* Addr)
{
 UART_Buffer[Tx_Indx++] = (hextab[((volatile uint16_t) *Addr & 0xf000) >>12]);  // (A)1010 & (F)1111 = A; 1010 0000 0000 0000; RS 12 ->  0000 0000 0000 1010 : hex[10]
 UART_Buffer[Tx_Indx++] = (hextab[((volatile uint16_t) *Addr & 0x0f00) >>8]);   // (B)1011 & (F)1111 = B; 0000 1011 0000 0000; RS  8 ->  0000 0000 0000 1011 : hex[11]
 UART_Buffer[Tx_Indx++] = (hextab[((volatile uint16_t) *Addr & 0x00f0) >>4]);   // (C)1100 & (F)1111 = C; 0000 0000 1100 0000; RS  4 ->  0000 0000 0000 1100 : hex[12]
 UART_Buffer[Tx_Indx++] = (hextab[ (volatile uint16_t) *Addr & 0x000f     ]);   // (D)1011 & (F)1111 = D; 0000 0000 0000 1101; RS  0 ->  0000 0000 0000 1101 : hex[13]
 Tx_Indx=0;
 for (int i=0;i<4;i++)               						   // Iterating from 0 to 4th element of UART_Buffer                        
 { 
  printf("Hex value at index %d is : %c\n",i,UART_Buffer[i]);                   // print hex char value at i'th index in UART_Buffer  
  printf("Hex value at index %d is : %d\n\n",i,UART_Buffer[i]);                 // print hex decimal value at i'th index in UART_Buffer  
 }
 printf("\nHEX address in UART_Buffer is : %s\n",UART_Buffer);                  // print hex values in UART_Buffer
}
/***************************** Main function ******************************************/
int main(void)
{
 hexout(&StartAddr);                                                            // hexout function call, pass parameter as StartAddr address
}

