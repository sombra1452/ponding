/*
 *
 *  AUTHOR: JUAN CAMILO CASTAÑO SERNA - 1701010664
 *  DATE: Nov. 26 - 2014
 *
 *
 */


// ncurses libraries
#include <ncurses.h>
#include <unistd.h>

// Declarations
#define DELAY 30000

int main(int argc, char *argv[]) {
    
    int axe_x = 0, axe_y = 2;  
    int axe_max_x = 0, axe_max_y = 0;  
    int next_x = 0;
    int direction = 1;

    char letter = 'O';
    int c;

    initscr();
    noecho();
    curs_set(FALSE);

    
    /*
     *  Keys:
     *  key I : 105
     *  key J : 106
     *  key K : 107
     *  key L : 108
     *
     *  Capture Keys:
     *  getch();
     */

/*
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    
    attron(COLOR_PAIR(1));
*/

    // mvprintw(axe_y,axe_x, "%c", letter);
    while(1) {

        getmaxyx(stdscr, axe_max_y, axe_max_x);

        clear();
        mvprintw(0,0, "My: %d - y: %d - Mx: %d - x: %d", axe_max_y, axe_y, axe_max_x, axe_x);    
        mvprintw(axe_y, axe_x, "%c",letter);
/*
        if (axe_x < 0) {
            axe_x = 0;
        } 
        else if (axe_x > axe_max_x) {
            axe_x = axe_max_x-1;
        } 
        else if (axe_y < 1) {
            axe_y = 1;
        } 
        else if (axe_y > axe_max_y){
            axe_y = axe_max_y-1;
        }
*/
        refresh();

        int char_number;

        switch (char_number=getch()){
            
            // UP : key I
            case 105:
                axe_y -= direction;
                break;

            // LEFT : key J
            case 106:
                axe_x -= direction;
                break;

            // DOWN : key K
            case 107:
                axe_y += direction;
                break;

            // RIGHT : key L
            case 108:
                axe_x += direction;
                break;

            default:
                break;
        }   


        // refresh();
        
        usleep(DELAY);
      
        // NON OUT OF WINDOW
        
        if (axe_x < 0) {
            axe_x = 0;
        }
        else if (axe_x > axe_max_x) {
            axe_x = axe_max_x-1;
        }
        
        else if (axe_y < 1) {
            axe_y = 1;
        }
        else if (axe_y > axe_max_y){
            axe_y = axe_max_y-1;
        }
        
        
        mvprintw(axe_y,axe_x, "%c", letter);
        refresh();



        // next_x = axe_x + direction;
/*
        if (axe_x > (axe_max_x/2)){
           letter = 'P';
        } else if( axe_x < (axe_max_x/2)){
           letter = 'O';
        }

        if (next_x >= axe_max_x || next_x < 0) {
            direction *= -1;
        } else {
            axe_x += direction;
        }
        
        refresh();
*/
        

    }

/*
    attroff(COLOR_PAIR(1));
    stop_color();
*/
    endwin();

    return 0;
}
