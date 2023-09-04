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

XColor target_color;


void clean_up_time() {
    free(is_running);
    free(auto_shooting_frequency);
}


void take_screenshot() {
    int flagE = 1;
    XEvent event;
    while (flagE) {
        XNextEvent(Display, &event);

        if (event.type == MotionNotify) {
            XImage *screenshot = XGetImage(display,
                                           RootWindow,
                                           event.xmotion.x,
                                           event.xmotion.y,
                                           1,
                                           1,
                                           AllPlanes,
                                           ZPixmap);

            XColor pixelColor;
            pixelColor.pixel = XGetPixel(screenshot, 0, 0);
            XQueryColor(display, DefaultColormap(display,
                                                 DefaultScreen(display)),
                        &pixelColor);

            if (pixelColor.red == target_color.red && pixelColor.green == target_color.green && pixelColor.blue == target_color.blue) {
                // cursor functions here
                //
                //
                //
                //


                printf("Cursor at (%d, %d) is over the target color.\n", event.xmotion.x, event.xmotion.y);
            }

            XDestroyImage(screenshot);
            flagE = 0;
        }
    }
}



void set_opponent_color() {  	// User must make sure colorblind mode is enabled
    Display *display = XOpenDisplay(NULL);
    if(!display) {
        fprintf(stderr, "Unable to open display.\n");
        return 1;
    }

    Window selected_win = DefaultRootWindow(display);

    target_color.red = 0;
    target_color.green = 0;
    target_color.blue = 0;

    XGrabPointer(display,
                 RootWindow,
                 False,
                 PointerMotionMask | ButtonPressMask,
                 GrabModeAsync,
                 GrabModeAsync,
                 None,
                 None,
                 CurrentTime);

    take_screenshot();

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


void target_opponent() {
    // cursor functions here

}

void shoot_opponent() {
    // cursor click function from auto_shooting_frequency

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
    //while(*is_running) {
    //	toggle_state(is_running);

    //}
    printf("Red: %u, Green: %u, Blue: %u\n", pix_color.red, pix_color.green, pix_color.blue);
    clean_up_time();




    return 0;
}
