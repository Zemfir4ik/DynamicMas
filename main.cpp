#include "window.h"

int main()
{
    initscr();
    curs_set(0);

    startTest();

    endwin();
    return 0;
}
