/**
 * @file main.c
 */

 #include <inttypes.h>

 #include <zephyr/kernel.h>
 #include <zephyr/sys/printk.h>

 #include "BTN.h"
 #include "LED.h"

 #define SLEEP_MS 1

  static uint8_t number = 0;
  static uint8_t var_pwm_number = 1;

 int main(void){
  if (0 > BTN_init()){
    return 0;
  }
  if (0 > LED_init()){
    return 0;
  }

  while (1) {

    if (var_pwm_number == 100){
      var_pwm_number = 0;
      LED_set(LED0,var_pwm_number);
    }

    if (number > 16) {
      LED_set(LED0,LED_OFF);
      LED_set(LED1,LED_OFF);
      LED_set(LED2,LED_OFF);
      LED_set(LED3,LED_OFF);
      number = 0;
    }

    if (BTN_check_clear_pressed(BTN0)) {

      printk("Button Pressed\n");


      if ((number & (1 << 0)) != 0){
        printk("LED1 ON\n");
        LED_set(LED0,LED_ON);
      } else {
        printk("LED1 OFF\n");
        LED_set(LED0,LED_OFF);
      }

      if ((number & (1 << 1)) !=0){
        printk("LED2 ON\n");
        LED_set(LED1,LED_ON);
      } else {
        printk("LED2 OFF\n");
        LED_set(LED1,LED_OFF);
      }

      if ((number & (1 << 2)) != 0){
        printk("LED3 ON\n");
        LED_set(LED2,LED_ON);
      } else {
        printk("LED3 OFF\n");
        LED_set(LED2,LED_OFF);
      }

      if ((number & (1 << 3)) != 0){
        printk("LED4 ON\n");
        LED_set(LED3,LED_ON);
      } else {
        printk("LED4 OFF\n");
        LED_set(LED3,LED_OFF);
      }

      number++;

    } 

    if (BTN_check_clear_pressed(BTN1)){
      LED_pwm(LED0,var_pwm_number);
      var_pwm_number++;
    }

  }
  return 0;
 }

