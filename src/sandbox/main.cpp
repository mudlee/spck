#include "sandbox.hpp"

int main(int argc, char **argv) {
    SPCK_LOG_INFO("Hello. Starting Spck Engine...");

    sandbox app;
    app.run();

    return 0;
}
