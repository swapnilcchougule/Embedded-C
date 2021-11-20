/*
  *******************************************************************************
  * @Project  Pointer 
  * @author   Swapnil Chougule
  * @version  V_01
  * @date     20-Nov-2021
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
uint64_t long_data = 0xFFFEABCD11112345;                       // 64 bit data stored in variable long_data 
/***************************** Main *****************************************************/
int main(void)
{
 char data = 100;                                              // char type variable and initialized to value 10
 char*ptr  = &data;                                            // Create a pointer variable and store the address of the "data" variable
 
 printf("Value of data is                : %d\n",data);        // Value in variable data 
 printf("Address of the variable data is : %p\n \n", &data );  // Address of the variable data

 printf("value of pointer ptr is         : %p\n",ptr);         // value in variable pointer ptr
 printf("Address of the variable ptr is  : %p\n",&ptr);        // Address of the variable pointer ptr
 printf("fetched data from pointer ptr   : %d\n\n",*ptr);      // fetched data from the pointer
 
 char value1 = *ptr;                				 // Perform read operation on the pointer variable to fetch 1 byte of data from the pointer
 printf("read value1 is : %d\n\n",value1);                     // fetched value from pointer ptr
	
 *ptr =96;                                                     // Perform write operation on the pointer to store the value 96
 printf("New value of data is            : %d\n",data);    	 // new value in variable data 
 printf("Address of the variable data is : %p\n \n", &data );  // Address of the variable data

 printf("value of pointer ptr is         : %p\n",ptr);         // value in variable pointer ptr
 printf("Address of the variable ptr is  : %p\n",&ptr);        // Address of the variable pointer ptr
 printf("New fetched data from pointer ptr: %d\n\n",*ptr);     // new fetched data from the pointer
 
 char value2 = *ptr;                				 // Perform read operation on the pointer variable to fetch 1 byte of data from the pointer
 printf("read value2 is 		   : %d\n\n",value2);   // fetched value from pointer ptr
 
 int *pAddress = (int*)&long_data;                             // type cast 'long'(64) to 'int' (Converting uint64_t into int)  
 
 printf("value of pointer pAddress is %p\n",pAddress);         // LSB value in variable pointer pAddress
 printf("Value at address %p is %x\n", pAddress, *pAddress);   // fetched LSB value(11112345) from pointer ptr

 pAddress = pAddress + 1;                                      // increment the pointer

 printf("value of pAddress %p\n",pAddress);                    // MSB value in variable pointer pAddress
 printf("Value at address %p is %x", pAddress, *pAddress);     // fetched MSB value(FFFEABCD) from pointer ptr
 
 return 0;
}







