#include"main.h"
#include<stdio.h>
#include<unistd.h>

/* 时能时钟 */
void clk_enable(void){
    int i = 0;
    for(i = 0; i < 7;i++){
        //CCM_CCGR[i] = 0xFFFFFFFF;   
        *CCM_CCGR[i] = 0xFFFFFFFF;  //这两种写法都是可以的
    }
}

/* 初始化LED */
void led_init(void){
    SW_MUX_GPIO1_IO03 = 0x5;  /* 复用为GPOI1_IO03 */
    SW_PAD_GPIO1_IO03 = 0X10B0;  /* 设置GPIO1_IO03的电气属性 */

    /* GPIO初始化 */
    GPIO1_GDIR = 0X8;   /* 设置GPIO1_IO03为输出 */
    GPIO1_DR = 0x0;   /* 打开LED灯 */
}

/* 短延时 */
void delay_short(volatile unsigned int n){
    while(n--){

    }
}


/* 延时，一次循环大概1ms,在主频396MHz
 * n: 延时ms数   
 */
void delay(volatile unsigned int n){
     while(n--){
        delay_short(0x7ff);  /* 这个是每次延时1ms */
     }
}

/* LED open */
void led_on(void){
    GPIO1_DR &= ~(1<<3); /* bit3清零 这个&用的很精髓*/
    //GPIO1_DR = 0x0; 这两者写法经过验证，功能是等效的
}

/* LED close */
void led_off(void){
    GPIO1_DR |= (1<<3);/* bit3置位为1 这个|用的很精髓*/
    //GPIO1_DR = 0x8;  同理，也是将第4为置1
}


int main(void){
   
   /* 时能外设时钟 */
   clk_enable(); 

   /* 初始化LED */
    led_init();

   /* 设置LED闪烁 */
    while(1){
        led_on();
        delay(500);
        led_off();
        delay(500);
    }  
    return 0; 
   
}