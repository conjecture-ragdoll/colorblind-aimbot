/*

gcc aimbot.c -o aimbot.exe

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

struct target_pixel {	// init_x and init_y = coordinates of pixel selected
	int init_x;
	int init_y;
	Uint8 red, green, blue, alpha;
} selected_pix;


    void grab_opponent_color(int xpos, int ypos, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {	// Input param from selected_pix struct.
	Uint32 pixel = ((Uint32*)surface->pixels)[ypos * surface->w + xpos];
	SDL_GetRGBA(pixel, surface->format, &r, &g, &b, &a);	
    }


// Process color from user selected pixel
    void set_opponent_color() {  	// User must make sure colorblind mode is enabled






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
	set_opponent_color(950,380);	// test

    if(argc > 1) {
        set_shots_per_minute(atoi(argv[1]));
        
	printf("** %d\n", *auto_shooting_frequency);
    }
	while(*is_running) {
		toggle_state(is_running);		

	}
	
	clean_up_time();




    return 0;
}
