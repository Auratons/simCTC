#ifndef _APP_H_
#define _APP_H_

#include <SDL2/SDL.h>

class App {
  public:
    static App &getInstance() {
        static App instance;
        return instance;
    }

  private:
    SDL_Window *window;

    App();
    ~App();

  public:
    void loop();

    App(App const &) = delete;            // Copy construct
    App(App &&) = delete;                 // Move construct
    App &operator=(App const &) = delete; // Copy assign
    App &operator=(App &&) = delete;      // Move assign
};

#endif // _APP_H_