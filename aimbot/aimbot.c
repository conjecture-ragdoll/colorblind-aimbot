/*

gcc aimbot.c -o aimbot.exe -lSDL2

(Right now designed to compile for UNIX)

Have fun!
(Currently in progress, 
run at your own risk.)

By Flora Afroza

*/

// TODO: Set up windows instrutions
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>


int *is_running, *auto_shooting_frequency;
SDL_Window* window;
SDL_Renderer* renderer;
SDL_Surface* screenshot;

    void grab_opponent_color() {	// User should select coordinates of a pixel of opponent color

    }

    void set_opponent_color(int xpos, int ypos) {  	// User must make sure colorblind mode is enabled
   	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        	printf("SDL Error: %s\n", SDL_GetError());
        	return;
        }

	SDL_DisplayMode screen;
	if (SDL_GetCurrentDisplayMode(0, &screen) != 0) {
		printf("Could not get display mode! SDL_Error: %s\n", SDL_GetError());
		return;
	}


    	window = SDL_CreateWindow(
				    "_Select Color of Target_", 
				    SDL_WINDOWPOS_CENTERED, 
				    SDL_WINDOWPOS_CENTERED, 
				    screen.w, 
				    screen.h, 
				    SDL_WINDOW_SHOWN);

    	renderer = SDL_CreateRenderer(window, -1, 0);

	size_t computer_bits = 8 * sizeof(void*);	// ??? check VM
	screenshot = SDL_CreateRGBSurface(
					0, 
					screen.w, 
					screen.h, 
					computer_bits, 
					0,0,0,0);
        void *pixels;
	int pitch;
// TODO: error at function call below
	SDL_RenderReadPixels(renderer, NULL, SDL_PIXELFORMAT_ARGB8888, screenshot->pixels, screenshot->pitch);

	//TODO: After opponent color is seleted, find coordinates in screenshot of that color in array
/*	Uint8 red, green, blue;
        Uint32 pixel = ((Uint32*)screenshot->pixels)[ypos * screenshot->w + xpos];
        SDL_GetRGB(pixel, screenshot->format, &red, &green, &blue);
*/

    }

    void plots_of_pixelcolor() {

    }

    void clean_up_time() {
	    free(is_running);
	    free(auto_shooting_frequency);

	    SDL_FreeSurface(screenshot);
	    SDL_DestroyWindow(window);

	    SDL_DestroyRenderer(renderer);
/*	   
	    SDL_Quit();
	    */
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
	set_opponent_color(500,500);	// test

    if(argc > 1) {
        set_shots_per_minute(atoi(argv[1]));
        printf("%d\n", *auto_shooting_frequency);
    }
	while(*is_running) {
		*is_running = 0;		

	}
	
    clean_up_time();





    return 0;
}
