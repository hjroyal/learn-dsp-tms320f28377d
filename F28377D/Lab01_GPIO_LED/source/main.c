#include "F28x_Project.h"
#include "F2837xD_Ipc_drivers.h"

void GPIO_Setup(void);
//方便编程，对LED置高置低进行宏定义；
#define LED1_ON  GpioDataRegs.GPASET.bit.GPIO0 = 1      //GPIO0置高
#define LED1_OFF GpioDataRegs.GPACLEAR.bit.GPIO0 = 1    //GPIO置低
#define LED2_ON  GpioDataRegs.GPASET.bit.GPIO1 = 1
#define LED2_OFF GpioDataRegs.GPACLEAR.bit.GPIO1 = 1
#define LED3_ON  GpioDataRegs.GPASET.bit.GPIO2 = 1
#define LED3_OFF GpioDataRegs.GPACLEAR.bit.GPIO2 = 1
#define LED4_ON  GpioDataRegs.GPASET.bit.GPIO3 = 1
#define LED4_OFF GpioDataRegs.GPACLEAR.bit.GPIO3 = 1
#define LED5_ON  GpioDataRegs.GPASET.bit.GPIO4 = 1
#define LED5_OFF GpioDataRegs.GPACLEAR.bit.GPIO4 = 1
#define LED6_ON  GpioDataRegs.GPASET.bit.GPIO5 = 1
#define LED6_OFF GpioDataRegs.GPACLEAR.bit.GPIO5 = 1


void main(void)
{
// Step 1.  初始化系统，锁相环,看门狗，外设时钟
   InitSysCtrl();

#ifdef _STANDALONE
#ifdef _FLASH
// CPU2运行程序
IPCBootCPU2(C1C2_BROM_BOOTMODE_BOOT_FROM_FLASH);
#else
// CPU2运行程序
IPCBootCPU2(C1C2_BROM_BOOTMODE_BOOT_FROM_RAM);
#endif
#endif

// FALSH烧写配置
#ifdef _FLASH
   InitFlash();
#endif

// Step 2. 初始化GPIO:
    InitGpio();
    GPIO_Setup();
// Step 3. 清除所有中断；初始化中断向量表；禁止CPU中断。
    DINT;

// 初始化PIE控制寄存器至默认状态，默认状态所有PIE中断被禁止；所有标志位被清除。
    InitPieCtrl();

// 禁止所有CPU中断，清除CPU中断相关标志位。
    IER = 0x0000;
    IFR = 0x0000;

// 初始化中断向量表，中断向量表就是采用指针指向中断服务程序入口地址
    InitPieVectTable();

// Enable global Interrupts and higher priority real-time debug events:
    EINT;  //使能全局中断
    ERTM;  // 使能全局中断实时调试

// Step 6. 循环
    for(;;)
    {
        //
        // 开LED
        //
    	LED1_ON;
    	LED2_ON;
    	LED3_ON;
    	LED4_ON;
    	LED5_ON;
    	LED6_ON;
        //
        // 延迟0.5S
        //
    	DELAY_US(1000 * 500);

        //
        // 关LED
        //
        LED1_OFF;
        LED2_OFF;
        LED3_OFF;
        LED4_OFF;
        LED5_OFF;
        LED6_OFF;
        //
        // 延迟0.5s.
        //
    	DELAY_US(1000 * 500);
    }
}

void GPIO_Setup() //配置GPIO的功能
{
    GPIO_SetupPinMux(0, GPIO_MUX_CPU1, 0);//对引脚0设置；选择CPU1为内核，选择外设功能0
    GPIO_SetupPinOptions(0, GPIO_OUTPUT, GPIO_PUSHPULL);//GPIO0，作为输出，上拉
    GPIO_SetupPinMux(1, GPIO_MUX_CPU1, 0);
    GPIO_SetupPinOptions(1, GPIO_OUTPUT, GPIO_PUSHPULL);
    GPIO_SetupPinMux(2, GPIO_MUX_CPU1, 0);
    GPIO_SetupPinOptions(2, GPIO_OUTPUT, GPIO_PUSHPULL);
    GPIO_SetupPinMux(3, GPIO_MUX_CPU1, 0);
    GPIO_SetupPinOptions(3, GPIO_OUTPUT, GPIO_PUSHPULL);
    GPIO_SetupPinMux(4, GPIO_MUX_CPU1, 0);
    GPIO_SetupPinOptions(4, GPIO_OUTPUT, GPIO_PUSHPULL);
    GPIO_SetupPinMux(5, GPIO_MUX_CPU1, 0);
    GPIO_SetupPinOptions(5, GPIO_OUTPUT, GPIO_PUSHPULL);
}
