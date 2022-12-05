#include <ncurses.h>

#include "array.h"

void makeArrayFunc(int highlight, DynamicArray &array, WINDOW *w, int xMax);
void clearWindow(WINDOW *w, int xMax);
void printNcurses(WINDOW *w, DynamicArray array, int length, int xMax);
void startTest();
bool isCorrectArrayLength(int a);
