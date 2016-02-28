#include <SDL2/SDL.h>
#include <stdexcept>
#include <string>
#include "logger.h"
#include "app.h"

App::App() {

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::string err = "SDL could not initialize! SDL_Error: ";
        err += SDL_GetError();
        throw std::runtime_error(err);
    }

    window = SDL_CreateWindow(
        "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 0, 0,
        SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN_DESKTOP);
    if (window == NULL) {
        std::string err = "Window could not be created! SDL_Error: ";
        err += SDL_GetError();
        throw std::runtime_error(err);
    }

    // Get window surface
    SDL_Surface *screenSurface = SDL_GetWindowSurface(window);

    // Fill the surface white
    SDL_FillRect(screenSurface, NULL,
                 SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

    // Update the surface
    SDL_UpdateWindowSurface(window);

    //    // Declare display mode structure to be filled in.
    //    SDL_DisplayMode current;

    //    // Get current display mode of all displays.
    //    for (int i = 0; i < SDL_GetNumVideoDisplays(); ++i) {
    //
    //        int should_be_zero = SDL_GetCurrentDisplayMode(i, &current);
    //
    //        if (should_be_zero != 0)
    //            // In case of error...
    //            SDL_Log(
    //                "Could not get display mode for video display #%d: %s",
    //                i, SDL_GetError());
    //
    //        else
    //            // On success, print the current display mode.
    //            SDL_Log("Display #%d: current display mode is %dx%dpx @ "
    //                    "%dhz. \n",
    //                    i, current.w, current.h, current.refresh_rate);
    //    }

    // Wait two seconds
    SDL_Delay(2000);
}

void App::loop() { ; }

App::~App() {

    // Destroy window
    SDL_DestroyWindow(window);

    SDL_Quit();
}