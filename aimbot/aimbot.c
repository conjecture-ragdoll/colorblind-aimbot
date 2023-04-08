/*

Have fun!
(Currently in progress)

By Flora Afroza

*/

#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

int *auto_mode;    // Auto-shooting mode
int *is_running;

unsigned char *opponent_color;
double *shooting_frequency;

    void select_opponent_color() {

    }

    void set_opponent_color(unsigned char pixel_color) {  // After player selects colorblind mode
        *opponent_color = pixel_color;
    }

    void set_shooting_frequency(double shots_per_minute) {
        *shooting_frequency = shots_per_minute;
    }

    void target_opponent() {

    }

    void enable_auto_shoot() {      // May enable auto-shooting at the begining of runtime
        *auto_mode = 1;
    }

    void toggle_auto_shooting() {       // Toggled via hot-key shortcut
        *auto_mode = abs(*auto_mode - (-1));
    }

int main(int argc, char *argv[]) {

    auto_mode = malloc(sizeof(int));
    *auto_mode = 0;

    shooting_frequency = malloc(sizeof(double));
    *shooting_frequency = 50; // default

    if(argc > 0) {
        set_shooting_frequency(atoi(argv[0]));
        if(argc > 1) {
            if(argv[1] == "auto") {
                enable_auto_shoot();
            }
        }
    }

    return 0;
}