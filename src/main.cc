#include <stdio.h>
#include <memory>
#include <SDL2/SDL.h>

#include "logger.h"
#include "gui/window.h"

#define WIN_TITLE "SimCTC"

/*
void print_resolution() {
    SDL_DisplayMode current;
    for (int i = 0; i < SDL_GetNumVideoDisplays(); ++i) {
        int should_be_zero = SDL_GetCurrentDisplayMode(i, &current);

        if (should_be_zero != 0) {
            SDL_Log("Could not get display mode for video display #%d: %s", i,
                    SDL_GetError());
        } else {
            SDL_Log("Display #%d: current display mode is %dx%dpx @ %dhz. \n",
                    i, current.w, current.h, current.refresh_rate);
        }
    }
}

bool init() {

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    }

    print_resolution();
    return true;
}

void destroy() { SDL_Quit(); }


// process_event();
// draw()

int main(int argc, char *argv[]) {

    LOG_INFO << "simCTC";

    if (!init()) {
        destroy();
        return 1;
    }

//        bool done = false;
//        while (!done) {
//            done = !process_event();
//            draw();
//        }

    destroy();
    return 0;
}
*/

int main(int argc, char *args[]) {
    // The window we'll be rendering to
    SDL_Window *window = NULL;

    // The surface contained by the window
    SDL_Surface *screenSurface = NULL;

    // Declare display mode structure to be filled in.
    SDL_DisplayMode current;

    LOG_INFO << "Start";

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    } else {
        // Create window
        window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED,
                                  SDL_WINDOWPOS_UNDEFINED, 0, 0,
                                  SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL |
                                      SDL_WINDOW_FULLSCREEN_DESKTOP);
        if (window == NULL) {
            printf("Window could not be created! SDL_Error: %s\n",
                   SDL_GetError());
        } else {

            // Get window surface
            screenSurface = SDL_GetWindowSurface(window);

            // Fill the surface white
            SDL_FillRect(screenSurface, NULL,
                         SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

            // Update the surface
            SDL_UpdateWindowSurface(window);

            // Get current display mode of all displays.
            for (int i = 0; i < SDL_GetNumVideoDisplays(); ++i) {

                int should_be_zero = SDL_GetCurrentDisplayMode(i, &current);

                if (should_be_zero != 0)
                    // In case of error...
                    SDL_Log(
                        "Could not get display mode for video display #%d: %s",
                        i, SDL_GetError());

                else
                    // On success, print the current display mode.
                    SDL_Log("Display #%d: current display mode is %dx%dpx @ "
                            "%dhz. \n",
                            i, current.w, current.h, current.refresh_rate);
            }

            // Wait two seconds
            SDL_Delay(2000);
        }
    }

    // Destroy window
    SDL_DestroyWindow(window);

    // Quit SDL subsystems
    SDL_Quit();

    return 0;
}