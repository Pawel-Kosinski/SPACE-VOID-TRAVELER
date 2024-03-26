#ifndef TEXT_PRINTER_H
#define TEXT_PRINTER_H

#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>

class TextPrinter {
private:
    int screenWidth;

public:
    TextPrinter(int screen_width) : screenWidth(screen_width) {}

    void printTextWithScroll(const std::string& text, int delay) {
        int initialPosition = (screenWidth - text.length()) / 2;

        for (int col = 0; col < text.length(); col++) {
            system("cls");

            for (int i = 0; i < initialPosition; i++) {
                std::cout << " ";
            }

            if (col < text.length())
                std::cout << text.substr(text.length() - col - 1) << std::endl;

            Sleep(delay);
        }
    }

    void waitForKeypress() {
        int spaces = (screenWidth - strlen("Press any key to start")) / 2;
        for (int i = 0; i < spaces; i++) {
            std::cout << " ";
        }
        std::cout << "Press any key to start";
        _getch();
    }
};

#endif
