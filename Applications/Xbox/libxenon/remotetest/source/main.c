/* This program will print the system hardware temperatures, by
\  messaging the SMC, using mathematical operations, and printing
\  to the screen.
*/

#include <stdio.h>
#include <console/console.h>
#include <xenos/xenos.h>
#include <xenos/xe.h>
#include <xenos_smc/xenon_smc.h>
#include "video_init.h"

int f_xenon_smc_receive_response(unsigned char *msg)
{
	while (1)
	{
		if (xenon_smc_receive_message(msg))
			continue;

		if (msg[0] == 0x83)
		{
			//xenon_smc_handle_bulk(msg);
			printf("I hope this worked msg = %02X%02X\n", msg[2],  msg[3]);
			switch (msg[3])
			{
			case 0x1E:
				printf("up\n");
				break;
			case 0x1F:
				printf("down\n");
				break;
			case 0x20:
				printf("right\n");
				break;
			case 0x21:
				printf("left\n");
				break;
			default:
				break;
			}
			continue;
		}
		return 0;
	}
}

int main(){

	printf("Xenos/console init!");
	mainInit();

	uint8_t msg[16];
   
   while(1)
   {
      memset(msg, 0, 16);
   
      msg[0] = 0x16;
   
      xenon_smc_send_message(msg);
      f_xenon_smc_receive_response(msg);
   }

	return 0;
}

