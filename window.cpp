#include "window.h"

void makeArrayFunc(int highlight, DynamicArray &array, WINDOW *w)
{
    int length = array.getLength();
    int el;
    switch (highlight)
    {
        case 0:
            mvwprintw(w, 1, 14, "Input lenght of array");
            mvwscanw(w, 2, 14, "%i", &length);
            while (!isCorrectArrayLength(length))
            {
                clearWindow(w);
                mvwprintw(w, 1, 14, "Incorrect size of array");
                mvwscanw(w, 2, 14, "%i", &length);
            }
            clearWindow(w);
            array.createArray(length);
            printNcurses(w, array, length);
            break;
        case 1:
            if (array.getLength() != 0)
            {
                array.deleteArray();
                mvwprintw(w, 1, 14, "Array has been deleted");
            }
            else
            {
                mvwprintw(w, 1, 14, "Nothing to delete");
            }
            break;
        case 2:
            if (array.getLength() == 0)
            {
                mvwprintw(w, 1 , 14, "There is no array to resize");
                break;
            }
            else
            {
                mvwprintw(w, 1, 14, "Input new lenght of array");
                mvwscanw(w, 2, 14, "%i", &length);
                while (!isCorrectArrayLength(length))
                {
                    clearWindow(w);
                    mvwprintw(w, 1, 14, "Incorrect size of array");
                    mvwscanw(w, 2, 14, "%i", &length);
                }

                clearWindow(w);
                array.resizeArray(length);
                printNcurses(w, array, length);
            }
            break;
        case 3:
            if (length > 0)
            {
                for (int i = 0; i < length; ++i)
                {
                    mvwprintw(w, 1, 14, "Input %i element of array" , i);
                    mvwscanw(w, 2, 14, "%i", &el);
                    array.readEl(i, el);
                    clearWindow(w);
                }
                printNcurses(w, array, length);
            }
            else
            {
                clearWindow(w);
                mvwprintw(w, 1, 14, "There is no array to read");
            }
            break;
        case 4:
        if (length > 0)
            {
                printNcurses(w, array, length);
            }
            else
            {
                clearWindow(w);
                mvwprintw(w, 1, 14, "There is no array to print");
            }
            break;
        case 5:
            if (length > 0)
            {
                mvwprintw(w, 1, 14, "Input type of sort");
                mvwprintw(w, 2, 14, "1 - to min");
                mvwprintw(w, 3, 14, "2 - to max");
                mvwscanw(w, 2, 14, "%i", &el);
                if (el % 2 == 1)
                {
                    array.sortArray(DynamicArray::SORT_MIN);
                }
                else
                {
                    array.sortArray(DynamicArray::SORT_MAX);
                }
            }
            else
            {
                clearWindow(w);
                mvwprintw(w, 1, 14, "There is no array to sort");
            }           
            break;
        case 6:
            if (length > 0)
            {
                int max = array.maxArray();
                mvwprintw(w, 1, 14, "%i is the bigest number", max);
            }
            else
            {
                clearWindow(w);
                mvwprintw(w, 1, 14, "There is no array");
            }                       
            break;
    }
}

void clearWindow(WINDOW *w)
{
    for (int y = 1; y < 10; ++y)
    {
        for (int x = 14; x < 50; ++x)
        {
            mvwprintw(w, y , x, " ");
        }
    }
}

void printNcurses(WINDOW *w, DynamicArray array, int length)
{
    int k = 1;
    for (int i = 0; i < length; ++i)
    {
        if (i % 10 == 0)
        {
            wmove(w, k, 14);
            k += 1;
        }
        wprintw(w, "%i ", array.get(i));
    }
}

void startTest()
{
    int xMax, yMax;
    getmaxyx(stdscr, yMax, xMax);

    WINDOW *funcWin = newwin(yMax / 5, xMax / 4, 0, 0);

    std::string choices[8] = {"Create", "Delete", "Resize", "Read", "Print", "Sort", "Max", "Exit"};
    
    int highlight = 0;
    int choice;

    DynamicArray array;

    while (1)
    {
        keypad(funcWin, true);
        noecho();
        box(funcWin, 0, 0);
        for (int i = 0; i < 8; ++i)
        {
            if (i == highlight)
            {
                wattron(funcWin, A_REVERSE);
            }
            mvwprintw(funcWin, i + 1, 1, choices[i].c_str());
            wattroff(funcWin, A_REVERSE);
        }

        for (int i = 1; i < yMax / 5 - 1; ++i)
        {
            mvwprintw(funcWin, i, xMax / 16 + 1, "|");
        }

        choice = wgetch(funcWin);

        switch (choice)
        {
            case KEY_UP:
                highlight--;
                highlight = (highlight + 8) % 8;
                break;

            case KEY_DOWN:
                highlight++;
                highlight = (highlight + 8) % 8;
                break;
            
            default:
                break;
        }
        if (choice == 10)
        {
            if (highlight == 7)
            {
                break;
            }
            else
            {
                clearWindow(funcWin);
                makeArrayFunc(highlight, array, funcWin);
            }
        }
    }
}

bool isCorrectArrayLength(int a)
{
    if (a < 0)
        return false;
    return true;
}
