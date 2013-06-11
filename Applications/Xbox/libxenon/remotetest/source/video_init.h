#include <stdio.h>
#include <xenos/xenos.h>
#include <console/console.h>

void mainInit(){
	xenos_init(VIDEO_MODE_AUTO);
	console_init();

	kmem_init();
	usb_init();
	usb_do_poll();
}
