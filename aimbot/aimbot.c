/*

gcc aimbot.c -o aimbot.exe

Have fun!
(Currently in progress)

By Flora Afroza

*/

#include <stdio.h>
#include <stdlib.h>
#include <curses.h>


int *is_running, *auto_shooting_frequency;
unsigned char *opponent_color;


    void select_opponent_color() {

    }

    void set_opponent_color(unsigned char pixel_color) {  // After player selects colorblind mode
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

    is_running = malloc(sizeof(int));
    *is_running = 1;

    auto_shooting_frequency = malloc(sizeof(int));
    *auto_shooting_frequency = 0;   // 0 means manual mode

    if(argc > 0) {
        set_shooting_frequency(atoi(argv[0]));
    }
    

    free(is_running);
    free(auto_shooting_frequency);

    return 0;
}