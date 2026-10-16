/**
 * @file main.c
 */

#include <zephyr/kernel.h>
#include "LED.h"

int main(void){

    LED_init();
    
  while(1){
  }
  return 0;
}


