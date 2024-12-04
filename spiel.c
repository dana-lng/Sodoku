#include <stdio.h>
#include "sudoku.c"
#include "dateiarbeit.c"

int main()
{
    FILE *fp;
    char dateiname[50] = "data.txt";
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
    int continuePlaying;

    printf("WiLLKOMMEN ZUM SUDOKU\n");
    printf("-----------------------\n");
         
    while(running)
    {
        printf("Menue:\n");
        printf(" 1 - Spiel laden\n 2 - Spiel anzeigen\n 3 - Spiel speichern\n 4 - Spiel beenden\n 5 - Datei laden\n 6 - löse Sudoku\n 7 - Undo\n");

        if (scanf("%d", &e) != 1) // Prüft ob die Eingabe eine Zahl ist oder ein Buchstabe
        {
            printf("Falsche Eingabe\n");
            while (getchar() != '\n'); // Eingabepuffer leeren
            continue; // Gehe zurück zum Menü
        } 

        switch (e)
        {
        case 1:
            while(1)
            {
                printBoard(board);
                set_board_element(board);
                printBoard(board);
                // Möglichkeit hinzufügen, die Schleife zu verlassen
                printf("Moechten Sie das Spiel fortsetzen? (1 fuer Ja, 0 fuer Nein): ");
                scanf("%d", &continuePlaying);
                system("cls");
                if (continuePlaying != 1) 
                {
                    while (getchar() != '\n'); // Eingabepuffer leeren
                    break; // verlässt die Schleife
                }
            }
            break; 
        case 2:
            printBoard(board);
            break;
        case 3: break;
        case 4:
            running = 0;
            break;
        case 5: 
            open_file(&fp, dateiname);
            load_file(fp, board);
            printBoard(board);
            close_file(fp, dateiname);
            break;
        case 6:
            solve(board, 0, 0);
            system("cls");
            printBoard(board);
            break; 
        case 7:
            undo(board);
            printBoard(board);
            break;


        default:
            printf("Falsche Eingabe, versuchen Sie es erneut!\n");
            break;


        }
    }
    

}

       


