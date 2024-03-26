#ifndef STAR_FIELD_H
#define STAR_FIELD_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <cstdlib>
#include <ctime>

class StarField {
private:
    std::vector<std::vector<bool>> screen;
    int width;
    int height;

public:
    StarField(int w, int h) : width(w), height(h) {
        screen.resize(height, std::vector<bool>(width, false));
    }

    bool czyMoznaUmiescicGwiazdke(int x, int y) const {
        const int marginesZegara = 3; // Margines na zegar
        if (y < marginesZegara) return false; // Pomiñ obszar zegara
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                int sprawdzX = x + i;
                int sprawdzY = y + j;
                if (sprawdzX >= 0 && sprawdzX < width && sprawdzY >= marginesZegara && sprawdzY < height) {
                    if (screen[sprawdzY][sprawdzX]) return false;
                }
            }
        }
        return true;
    }

    void placeRandomStars(int numStars) {
        const int marginesZegara = 3; // Margines na zegar
        srand(static_cast<unsigned int>(time(0)));
        for (int i = 0; i < numStars; ++i) {
            int x, y;
            do {
                x = rand() % width;
                y = rand() % (height - marginesZegara) + marginesZegara;
            } while (!czyMoznaUmiescicGwiazdke(x, y));

            screen[y][x] = true;
        }
    }

    void display() const {
        const int marginesZegara = 3; // Margines na zegar
        for (int y = marginesZegara; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                HANDLE hConsoleOutput;
                COORD dwCursorPosition;

                dwCursorPosition.X = x;
                dwCursorPosition.Y = y;
                hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleCursorPosition(hConsoleOutput, dwCursorPosition);

                if (screen[y][x]) {
                    char znak = (rand() % 2) ? '*' : '.';
                    std::cout << znak;
                }
                else {
                    std::cout << ' ';
                }
            }
        }
    }

    void clear() {
        for (int y = 0; y < height; ++y) {
            screen[y].assign(width, false);
        }
    }
};

#endif
