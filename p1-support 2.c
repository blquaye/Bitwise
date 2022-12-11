#include "p1-support.h"
#include <stdio.h>
#include <string.h>

////////////////////////////////////////////////////////////////////////
//
// File           : p1support.c
// Description    : This is a set of general-purpose utility functions 
//                  we use for the 257 project #1. Fall 2022
// Author         : ***Type Author Name ***
// Date           : ***Type the date Date you completed***
// Notes          : ***Type bug fixes/other with dates for your records 


////////////////////////////////////////////////////////////////////////
// Function Definitions
////////////////////////////////////////////////////////////////////////

//Function definitions as decribed in the project manual 

//This function prints out the array of integer values
void display_array(unsigned int* arr, int size){
  int i;
  printf("{");
  for(i = 0;i<size;i++){
    printf("%4d%s",arr[i],(i==9)?"":",");
  }
  printf("}\n");
  
}


//Additional function definitions for helper functions
//Shortly describe each function above the function definition.

//add short description
int bitwise_add(int num1, int num2)
{
//we'll make static global
 static  int transfer = 0;
//complete the definition
//we'll initialize a loop until num2 reaches 0
//
  while(num2 != 0){
  // we'll carry the bit using and operator
  transfer = num1 & num2;
 // we'll then use the xor operator for assigning a 
  num1 ^= num2;
   //left shift operator only once so that  transfer is multiplied by 2
  num2 = transfer <<1;

}  
  return transfer;
}

//add short description
int bitwise_shift_left(int num1, int num2)
{
//complete the definition 
//performs a left shift operation for function
  int result = 0;
   result = num1 << num2;
  return result;  
}

//add short description
int count_set_bits(int num){
//complete the definition 
  if(num ==0){
    return 0;
  }else{
    return (num & 1) + count_set_bits(num >> 1);
 }
}

//add short description
void binary_string(unsigned int num, char str[BUFSZ]){
//complete the definition
   // we need to first store char 0 at the first index
   // proceeding with char b so each time the variable prints these two integers will always print first
   // we'll use the bit get function and take the num and the index of i and add '0' to turn the binary value into a char for the array
   str[0] = '0';
   str[1] = 'b';
   // at the index right before the last digit insert
   // \0
   str[35] = '\0';
   for(int i  =0;i<32;i++){
    str[33-i] =  bit_get(num,i) + '0';
  }
} 

//add short descriptions
int bitwise_mod32(int num){
//complete the definition 
//In the case num is 0 we'll return 0;
//else we'll store the num and we'll return the mod of 32  
  if (num < 0){
    return 0;
  }
  int x =num & 31;
  return x; 

}

//add short description
//this function will return the absolute value of any integer
int bitwise_abs(int num){
//complete the definition    
   int abs =  (num >> 31);
  abs = (num ^ abs) - abs;
  return abs;
}

//add short description
int bit_get(int num,int offset){
//complete the definition 
// we need the variable move_int to store 1   
  int move_int = 1;
//we'll shift equals num over to offset
//and then using it bitwise operator we'll num & the value 1 stored in move_int
  num >>= offset;
  return(num & move_int);
}

//add short description
int odd_or_even(unsigned int num){
//complete the definition 
//if result is equal to 0 
//the result is odd
//else the result is even 
  int result = bit_get(num,0);
    if(result == 0){
      return 0;
    }else{
      return 1;
    }
} 

//add short description
void swap_ints(int *a,int *b){
//complete the definition 
//first we swap a variable with b
  *a ^= *b;
//then we will store b variable in a
  *b ^= *a;
//official swap varaible we follow similar case in swapping variables with a and b
  *a ^= *b;
 
}



