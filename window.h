#include <ncurses.h>

#include "array.h"

void makeArrayFunc(int highlight, DynamicArray &array, WINDOW *w);
void clearWindow(WINDOW *w);
void printNcurses(WINDOW *w, DynamicArray array, int length);
void startTest();
bool isCorrectArrayLength(int a);
