#include <stdio.h>
#include "sudoku.h"

int main()
{
    int board[9][9] = {{1, 2, 3, 4, 5, 6, 9, 8, 9}, //board = 9x9 Matrix
                       {4, 5, 6, 7, 8, 9, 1, 2, 3},
                       {7, 8, 9, 1, 2, 3, 4, 5, 6},
                       {2, 3, 4, 5, 6, 7, 8, 9, 1},
                       {5, 6, 7, 8, 9, 1, 2, 3, 4},
                       {8, 9, 1, 2, 3, 4, 5, 6, 7},
                       {3, 4, 5, 6, 7, 8, 9, 1, 2},
                       {6, 7, 8, 9, 1, 2, 3, 4, 5},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0}}; 
    int e;
    int running = 1;

         printf("SUDOKU\n\n");
         
       while(running)
       {
            printf("Menue:\n");
            printf(" 1 - Spiel laden\n 2 - Spiel anzeigen\n 3 - Spiel beenden\n\n");
            scanf("%d", &e);

                switch (e)
                {
                case 1:
                    while(1)
                    {
                        printBoard(board);
                        set_board_element(board);
                    }
                case 2:
                    printBoard(board);
                    break;
                case 3:
                    running = 0;
                    break;
                default:
                    printf("Falsche Eingabe, versuchen Sie es erneut!\n");
                    break;
                }

       }
        


    /*    
    int board[9][9]; 
    erstelleNullBoard(board);       //board = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                                    //        {0, 0, 0, 0, 0, 0, 0, 0, 0},
                                    //        {0, 0, 0, 0, 0, 0, 0, 0, 0},
                                    //        {0, 0, 0, 0, 0, 0, 0, 0, 0},
                                    //        {0, 0, 0, 0, 0, 0, 0, 0, 0},
                                    //        {0, 0, 0, 0, 0, 0, 0, 0, 0},
                                    //        {0, 0, 0, 0, 0, 0, 0, 0, 0},
                                    //        {0, 0, 0, 0, 0, 0, 0, 0, 0},
                                    //        {0, 0, 0, 0, 0, 0, 0, 0, 0}};
    
    printBoard(board);
    


    printBoard(board);

    set_board_element(board); 
    printBoard(board);
*/
    return 0;
}
