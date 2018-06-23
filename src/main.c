#include "stm32f10x.h"
#include "stm32f10x_flash.h"
#include "stm32f10x_rcc.h"
#include "misc.h"

#include "usb_lib.h"
#include "hw_config.h"
#include "usb_pwr.h"

extern volatile uint8_t Receive_Buffer[64];
extern volatile uint32_t Receive_length ;
extern volatile uint32_t length ;
uint8_t Send_Buffer[64];
uint32_t packet_sent=1;
uint32_t packet_receive=1;

int main(void)
{
	Set_System();
	Set_USBClock();
	USB_Interrupts_Config();
	USB_Init();
	while (bDeviceState != CONFIGURED);

	while (1)
	{
		if (bDeviceState == CONFIGURED)
			{
				CDC_Receive_DATA();
				// Check to see if we have data yet
				if (Receive_length  != 0)
				{
					// If received symbol '1' then LED turn on, else LED turn off
					if (Receive_Buffer[0]=='1') {
						GPIO_ResetBits(GPIOC, GPIO_Pin_13);
					}
					else {
						GPIO_SetBits(GPIOC, GPIO_Pin_13);
					}

					// Echo
					if (packet_sent == 1) {
						CDC_Send_DATA ((uint8_t*)Receive_Buffer,Receive_length);
					}

					Receive_length = 0;
				}
			}
	}
}
