#include "ElectricClock.h"
#include "StarField.h"
#include "TextPrinter.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <windows.h>

void clearScreen() {
    system("cls");
}

int main() {
    const int screenWidth = 121;
    const int screenHeight = 29;
    const int numStars = 100;
    const int textScrollDelay = 100;

    std::string title = "SPACE VOID TRAVELER SIMULATOR";
    std::string startMessage = "Press any key to start";

    TextPrinter textPrinter(screenWidth);
    textPrinter.printTextWithScroll(title, textScrollDelay);
    textPrinter.waitForKeypress();

    ElectricClock clock;
    StarField starField(screenWidth, screenHeight);

    while (true) {
        clearScreen();
        clock.tick();
        clock.display();

        starField.placeRandomStars(numStars);
        starField.display();

        std::this_thread::sleep_for(std::chrono::seconds(1)); // Wait for 1 second

        starField.clear();
    }

    return 0;
}
