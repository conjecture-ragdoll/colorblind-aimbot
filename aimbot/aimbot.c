/*

gcc aimbot.c -o aimbot.exe -lX11

(Right now designed to compile for UNIX)

Have fun!
(Currently in progress, 
run at your own risk.)

By Flora Afroza

*/

// TODO: Set up windows instructions later

#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h> // Unix library


int *is_running, *auto_shooting_frequency;

XColor pix_color;
 

    void set_opponent_color() {  	// User must make sure colorblind mode is enabled
	    Display *display = XOpenDisplay(NULL);
	    Window root = DefaultRootWindow(display);

	    XGrabPointer(display, root, False, ButtonPress, GrabModeAsync, GrabModeAsync, None, None, CurrentTime);
	    XEvent event;
	    do {
		XNextEvent(display, &event);
		if (event.type == ButtonPress) {
		    XQueryColor(display, DefaultColormap(display, DefaultScreen(display)), &pix_color);
		    break;
		}
	    }  while(1);
	        XCloseDisplay(display);

    }

    void clean_up_time() {
            free(is_running);
            free(auto_shooting_frequency);
    }

    	

		




    void setup_default() {
	    is_running = malloc(sizeof(int));
	    *is_running = 1;	// auto-aim enabled


	    auto_shooting_frequency = malloc(sizeof(int));
	    *auto_shooting_frequency = 0;   // 0 means manual shooting mode
    }

    void set_shots_per_minute(int spm) {
	*auto_shooting_frequency = spm;
    }


    void target_opponent() {       // cursor functions here

    }

    void toggle_state(int *state) {
        *state = abs(*state - 1);
    }


int main(int argc, char *argv[]) {

    	setup_default();    
	set_opponent_color();	// test

    if(argc > 1) {
        set_shots_per_minute(atoi(argv[1]));
        
	printf("** %d\n", *auto_shooting_frequency);
    }
	while(*is_running) {
		toggle_state(is_running);		

	}
	printf("Red: %u, Green: %u, Blue: %u\n", pix_color.red, pix_color.green, pix_color.blue);	
	clean_up_time();




    return 0;
}
