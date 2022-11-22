#include "window.h"

int main()
{
    initscr();
    noecho();
    curs_set(0);

    startTest();

    endwin();
    return 0;
}
