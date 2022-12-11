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
  int transfer = 0;
//complete the definition
  while(num2 != 0){
  
  transfer = num1 & num2;

  num1 ^= num2;
  
  num2 = transfer <<1;

}  
  return transfer;
}

//add short description
int bitwise_shift_left(int num1, int num2)
{
//complete the definition
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
  if (num < 0){
    return 0;
  }
  int x =num & 31;
  return x; 

}

//add short description
int bitwise_abs(int num){
//complete the definition    
   int abs =  (num >> 31);
  abs = (num ^ abs) - abs;
  return abs;
}

//add short description
int bit_get(int num,int offset){
//complete the definition    
  int move_int = 1;

  num >>= offset;
  return(num & move_int);
}

//add short description
int odd_or_even(unsigned int num){
//complete the definition  
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
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
 
}



