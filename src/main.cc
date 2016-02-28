#include <stdexcept>
#include "logger.h"
#include "app.h"

int main(int argc, char *args[]) {

    try {
        App &app = App::getInstance();
        app.loop();
    } catch (std::runtime_error &e) {
        LOG_FATAL << e.what();
        return 1;
    }

    return 0;
}