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
Uint32 *opponent_color;


    void set_opponent_color() {  // After player selects colorblind mode
        *opponent_color = pixel_color;
    }

    void set_shooting_frequency(double shots_per_minute) {
        *auto_shooting_frequency = shots_per_minute;
    }

    void target_opponent() {       // cursor functions here

    }

    void toggle_state(int *state) {
        *state = abs(*state - 1);
    }


int main(int argc, char *argv[]) {

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL Error: %s\n", SDL_GetError());
        return 1;
    }

    is_running = malloc(sizeof(int));
    *is_running = 1;

    opponent_color = malloc(sizeof(Uint32));

    auto_shooting_frequency = malloc(sizeof(int));
    *auto_shooting_frequency = 0;   // 0 means manual mode

    if(argc > 0) {
        set_shooting_frequency(atoi(argv[0]));
    }
    

    printf("test\n");

    free(is_running);
    free(auto_shooting_frequency);

    return 0;
}
