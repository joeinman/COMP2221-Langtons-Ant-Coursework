#include <ncurses.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    initscr();
    curs_set(FALSE);
    int max_x = getmaxx(stdscr);
    int max_y = getmaxy(stdscr);

    for (int y = 0; y < max_y; y++)
    {
        for (int x = 0; x < max_x; x++)
        {
            mvprintw(y, x, x==0 && y==0 ? "1" : "0");
        }
    }

    refresh();

    getch();
    endwin();
    return EXIT_SUCCESS;
}