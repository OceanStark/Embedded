#ifndef  _MAIN_H
#define  _MAIN_H
/* 
 * CCM相关寄存器地址  所有时钟的寄存器地址
 */
/*  传统写法 */
/*  
  #define CCM_CCGR0 			*((volatile unsigned int *)0X020C4068)
  #define CCM_CCGR1 			*((volatile unsigned int *)0X020C406C)
  
  #define CCM_CCGR2 			*((volatile unsigned int *)0X020C4070)
  #define CCM_CCGR3 			*((volatile unsigned int *)0X020C4074)
  #define CCM_CCGR4 			*((volatile unsigned int *)0X020C4078)
  #define CCM_CCGR5 			*((volatile unsigned int *)0X020C407C)
  #define CCM_CCGR6 			*((volatile unsigned int *)0X020C4080)
*/ 
#define CCM_CCGR_BASE_ADDR 0x020C4068   //定义一个基地址
        volatile unsigned int *CCM_CCGR[] = {
            (volatile unsigned int *)CCM_CCGR_BASE_ADDR,
            (volatile unsigned int *)(CCM_CCGR_BASE_ADDR + 0x4),
            (volatile unsigned int *)(CCM_CCGR_BASE_ADDR + 0x8),
            (volatile unsigned int *)(CCM_CCGR_BASE_ADDR + 0xC),
            (volatile unsigned int *)(CCM_CCGR_BASE_ADDR + 0x10),
            (volatile unsigned int *)(CCM_CCGR_BASE_ADDR + 0x14),
            (volatile unsigned int *)(CCM_CCGR_BASE_ADDR + 0x18)
        };
 


/* 
 * IOMUX相关寄存器地址   定义复用IO功能的寄存器地址与电气特性寄存器地址
 */
#define SW_MUX_GPIO1_IO03 	*((volatile unsigned int *)0X020E0068)
#define SW_PAD_GPIO1_IO03 	*((volatile unsigned int *)0X020E02F4)

/* 
 * GPIO1相关寄存器地址，用于配置GPIO功能
 */
#define GPIO1_DR 			*((volatile unsigned int *)0X0209C000)   
/* 该寄存器有32位，每一位代表一个IO 在输入时，表示读取的高低电平，在输出时，表示输出的高低电平 */

#define GPIO1_GDIR 			*((volatile unsigned int *)0X0209C004)
/* 表示输入输出的方向 */

#define GPIO1_PSR 			*((volatile unsigned int *)0X0209C008)  /* 状态寄存器 */
#define GPIO1_ICR1 			*((volatile unsigned int *)0X0209C00C)  
/* 与ICR2配合使用  用于设置中断触发状态 每个IO用两位来表示 ，ICR1设置低16位IO，ICR2设置高16位IO*/
#define GPIO1_ICR2 			*((volatile unsigned int *)0X0209C010)

#define GPIO1_IMR 			*((volatile unsigned int *)0X0209C014)  
/* 中断掩码寄存器 控制GPIO中断是时能或关闭 */

#define GPIO1_ISR 			*((volatile unsigned int *)0X0209C018)  
/* 中断状态寄存器 判断这个GPIO 他的中断有没有发生 */

#define GPIO1_EDGE_SEL 		*((volatile unsigned int *)0X0209C01C)
/* 用于覆盖ICR的使用 只要有边沿 就会触发中断 */

#endif  //
