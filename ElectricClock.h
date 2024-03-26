#ifndef ELECTRIC_CLOCK_H
#define ELECTRIC_CLOCK_H

#include <iostream>
#include <iomanip>
#include <windows.h>

class ElectricClock {
private:
    int hours;
    int minutes;
    int seconds;

public:
    ElectricClock() : hours(0), minutes(0), seconds(0) {}

    void tick() {
        seconds++;
        if (seconds >= 60) {
            seconds = 0;
            minutes++;
            if (minutes >= 60) {
                minutes = 0;
                hours++;
                if (hours >= 24) {
                    hours = 0;
                }
            }
        }
    }

    void display() {
        int screenWidth;
        HANDLE hConsoleOutput;
        COORD dwCursorPosition;

        // Pobieranie szerokoœci konsoli
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
        if (GetConsoleScreenBufferInfo(consoleHandle, &csbi)) {
            screenWidth = csbi.dwSize.X;
        }
        else {
            screenWidth = 80; // Domyœlna szerokoœæ, jeœli nie uda³o siê pobraæ
        }

        int pozycjaX = (screenWidth - 8) / 2; // Wycentrowanie zegara
        dwCursorPosition.X = pozycjaX;
        dwCursorPosition.Y = 1;
        hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(hConsoleOutput, dwCursorPosition);

        std::cout << std::setw(2) << std::setfill('0') << hours << ":"
            << std::setw(2) << std::setfill('0') << minutes << ":"
            << std::setw(2) << std::setfill('0') << seconds << std::endl;
    }
};

#endif
