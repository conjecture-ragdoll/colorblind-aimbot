/*

gcc aimbot.c -o aimbot.exe -lSDL2

Have fun!
(Currently in progress)

By Flora Afroza

*/

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>



int *is_running, *auto_shooting_frequency;

    void grab_opponent_color() {

    }

    void set_opponent_color() {  	// User must make sure colorblind mode is enabled
   	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        	printf("SDL Error: %s\n", SDL_GetError());
        	return;
        }

	SDL_DisplayMode screen;
	if (SDL_GetCurrentDisplayMode(0, &screen) != 0) {
		printf("Could not get display mode! SDL_Error: %s\n", SDL_GetError());
		return;
	}

    	SDL_Window* window = SDL_CreateWindow(
				    "_Select Color of Target_", 
				    SDL_WINDOWPOS_CENTERED, 
				    SDL_WINDOWPOS_CENTERED, 
				    screen.w, 
				    screen.h, 
				    SDL_WINDOW_SHOWN);

    	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

	size_t computer_bits = 8 * sizeof(void*);	// ??? check VM

	SDL_Surface* screenshot = SDL_CreateRGBSurfaceWithFormat(
					0, 
					screen.w, 
					screen.h, 
					computer_bits, 
					SDL_PIXELFORMAT_RGBA32);
    	
	SDL_RenderReadPixels(renderer, NULL, SDL_PIXELFORMAT_RGBA32, screenshot->pixels, screenshot->pitch);

	//TODO: After opponent color is seleted, find coordinates in screenshot of that color in array


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


    
    is_running = malloc(sizeof(int));
    *is_running = 1;	// auto-aim enabled


    auto_shooting_frequency = malloc(sizeof(int));
    *auto_shooting_frequency = 0;   // 0 means manual shooting mode

    if(argc > 1) {
        set_shots_per_minute(atoi(argv[1]));
    }

	while(*is_running == 1) {
		

	}
	

    printf("%d\n", *auto_shooting_frequency);

    free(is_running);
    free(auto_shooting_frequency);

    return 0;
}
