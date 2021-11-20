/*
  *******************************************************************************
  * @Project  Arrays 
  * @author   Swapnil Chougule
  * @version  V_01
  * @date     02-Nov-2021
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
uint8_t TX_Buffer[10] = {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff}; // Arrya of fixed size
/***************************** Main function ******************************************/
int main(void)
{
 printf("contents of TX_Buffer array\n");  // print it on o/p consol
 for(uint8_t i = 0 ; i < 10 ; i++)         // Iterating from 0 to 9th element of TX_Buffer
 {
  printf("%x\t",TX_Buffer[i]);             // print i'th element of TX_Buffer
 }
 printf("\n");                             // go to the new line 
 for(uint8_t i = 0 ; i < 10 ; i++)         // Iterating from 0 to 9th element of TX_Buffer
 {
  TX_Buffer[i] = 0x33;                     // change the value of i'th element 
  printf("%x\t",TX_Buffer[i]);             // print i'th element of TX_Buffer
 }
 return 0;                                 // 'return 0' means that the function doesn't return any value. It is used when the void return type is used with the function. It is not mandatory to add a 'return 0' statement to the function which doesn't return any value, the compiler adds it virtually
}
