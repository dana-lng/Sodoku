#include <stdio.h>
#include "sudoku.c"

int main()
{
    FILE *fp;
    char easy[50] = "easy.txt";
    char medium[50] = "medium.txt";
    char hard[50] = "hard.txt";

    char dateiname[50] = "data.txt";
    int board[9][9];
    int e;
    int running = 1;
    int continuePlaying;

    printf("WiLLKOMMEN ZUM SUDOKU\n");
    printf("-----------------------\n");
         
    while(running)
    {
        printf("Menue:\n");
        printf(" 1 - Datei laden\n 2 - Spiel anzeigen\n 3 - Spiel spielen\n 4 - Rückgängig machen\n 5 - Spiel speichern \n 6 - löse Sudoku\n 7 - Beenden\n");

        if (scanf("%d", &e) != 1) // Prüft ob die Eingabe eine Zahl ist oder ein Buchstabe
        {
            printf("Falsche Eingabe\n");
            while (getchar() != '\n'); // Eingabepuffer leeren
            continue; // Gehe zurück zum Menü
        } 

        switch (e)
        {
        case 1:
            printf("Wählen Sie einen Schwierigkeitsgrad:\n");
            printf(" 1 - Easy\n 2 - Medium\n 3 - Hard\n");
            if (scanf("%d", &e) != 1) // Prüft ob die Eingabe eine Zahl ist oder ein Buchstabe
            {
                printf("Falsche Eingabe\n");
                while (getchar() != '\n'); // Eingabepuffer leeren
                continue; // Gehe zurück zum Menü
            }
            switch (e)
            {
                case 1:
                    open_file(&fp, easy);
                    load_file(fp, board);
                    close_file(fp, easy);
                    break;

                case 2:
                    open_file(&fp, medium);
                    load_file(fp, board);
                    close_file(fp, medium);
                    break;

                case 3:
                    open_file(&fp, hard);
                    load_file(fp, board);
                    close_file(fp, hard);
                    break;

                break;
            }

           
            
        case 2:
            printBoard(board);
            break;
        case 3: 
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
        
        case 4:
            undo(board);
            printBoard(board);
            break;

            
        case 5: 
            printf("Bitte geben Sie einen Dateinamen ein: ");
            scanf("%99s", dateiname);
            speichern(board, dateiname);
            break;
            
        case 6:
            solve(board, 0, 0);
            system("cls");
            printBoard(board);
            break; 

        case 7:
            running = 0;
            break;

        default:
            printf("Falsche Eingabe, versuchen Sie es erneut!\n");
            break;


        }
    }
    

}

       


