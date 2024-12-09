#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void erstelle_NullBoard(int uebergebenesBoard[9][9])
{
    for (int i = 0; i < 9; i++) // Schleife über alle Zeilen
    {
        for (int j = 0; j < 9; j++) // Schleife über alle Spalten
        {
            uebergebenesBoard[i][j] = 0; // Setze jedes Element des Boards auf 0
        }
    }
}

void print_Board(int uebergebenesBoard[9][9])
{
    for (int i = 0; i < 9; i++) // Schleife über die Zeilen
    {
        // Trennlinie nach jeder dritten Zeile
        if (i % 3 == 0)
        {
            printf("+-------+-------+-------+\n");
        }

        for (int j = 0; j < 9; j++) // Schleife über die Spalten
        {
            if (j % 3 == 0) // Zusätzliche Trennlinie vor jeder dritten Spalte
            {
                printf("| ");
            }

            printf("%d ", uebergebenesBoard[i][j]); // Druckt das aktuelle Board-Element

            // Am Ende der Zeile (bei der 9. Spalte): abschließendes '|'
            if (j == 8)
            {
                printf("|");
            }
        }
        printf("\n"); 
    }

    printf("+-------+-------+-------+\n");
}
void print_position(int position[9][2])
{
    for (int i = 0; i < 9; i++)
    {   
        if (i % 3 == 0)
        {
            printf("\n");
        }
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", position[i][j]);
        }
        printf(" ; ");
    }
}

void print_zahlen(int zahlen[9])
{
    for(int i = 0; i < 9; i++)
    {
        printf("%d", zahlen[i]);
    }
}

int check_double_felder2(int uebergebenesBoard[9][9], int zeile, int spalte, int wert)
{
    // Durch Division der Zeile und Spalte durch 3 und Multiplikation mit 3 wird die obere linke Ecke des Blocks ermittelt.
    int feld_start_zeile = (zeile / 3) * 3; 
    int feld_start_spalte = (spalte / 3) * 3; 

    for (int i = 0; i < 3; i++) // Iteriert über die 3 Zeilen des Blocks
    {
        for (int j = 0; j < 3; j++) // Iteriert über die 3 Spalten des Blocks
        {
           
            if (uebergebenesBoard[feld_start_zeile + i][feld_start_spalte + j] == wert)  // Prüft, ob die Zahl `wert` bereits in einer der Zellen des Blocks vorhanden ist
            {
              
                printf("Die Zahl %d ist bereits in diesem Feldblock vorhanden.\n", wert);
                return 1; 
            }
        }
    }

    // Wenn die Zahl in keinem der Felder gefunden wurde, ist sie zulässig
    return 0; 
}

int check_double_zeilen_spalten2(int uebergebenesBoard[9][9], int zeile, int spalte, int wert)
{
    int i; 

    // Prüft ob im Array zeilen_elemente die Zahl vorkommt  
    // oder ob im Array spalten_elemente die Zahl vorkommt
    for (i = 0; i < 9; i++)
    {   
        
        if (uebergebenesBoard[zeile - 1][i] == wert)
        {
            printf("Die Zahl %d ist bereits in Zeile %d und Spalte %d vorhanden.\n", wert, zeile, i + 1);
            return 1;
        }
        else if (uebergebenesBoard[i][spalte - 1] == wert)
        {
            printf("Die Zahl %d ist bereits in Zeile %d und Spalte %d vorhanden.\n", wert, i + 1, spalte);
            return 1;
        }
    }

    return 0; 
}

int solve2(int uebergebenesBoard[9][9], int zeile, int spalte) 
{
    int wert; 
    
    if (zeile == 9) // Wenn alle Zeilen abgearbeitet sind, ist das Sudoku vollständig gelöst
    {
        return 1; 
    }
    else if (spalte == 9)  // Wenn alle Spalten in der aktuellen Zeile abgearbeitet sind, springt zur nächsten Zeile
    {
        return solve(uebergebenesBoard, zeile + 1, 0); // Wechselt zur nächsten Zeile und starte bei Spalte 0
    }
    else if (uebergebenesBoard[zeile][spalte] != 0)    // Wenn die aktuelle Zelle bereits einen festen Wert hat, wird übersprungen
    {
        return solve(uebergebenesBoard, zeile, spalte + 1); 
    }
    else 
    {
        for (wert = 1; wert < 10; wert++) //geht alle Werte von 1 bis 9 durch
        {
            if (check_double_zeilen_spalten(uebergebenesBoard, zeile + 1, spalte + 1, wert) == 0 &&  // Prüft, ob der Wert in der aktuellen Zeile, Spalte oder dem 3x3-Block gültig ist
                check_double_felder(uebergebenesBoard, zeile, spalte, wert) == 0) 
            {
                
                uebergebenesBoard[zeile][spalte] = wert;  // Setzt den Wert in das Board

                if (solve(uebergebenesBoard, zeile, spalte + 1) == 1) // Prüft, ob das Sudoku mit diesem Wert lösbar ist
                {
                    return 1; // Sudoku erfolgreich gelöst 
                }

                uebergebenesBoard[zeile][spalte] = 0; // Rückgängigmachen der Änderung (Backtracking), wenn der aktuelle Wert nicht zur Lösung führt
            }
        }
        return 0;
    }
}

void vertausche_reihenfolge_positionen_zufaellig(int positionen[9][2])
{
    // Fisher-Yates-Shuffle-Algorithmus-> mischt die positionen zufällig um
    for (int i = 9 - 1; i > 0; i--) // von i = 8 bis i = 0 (der letzte Index wird nichtmehr getauscht!)
    {
        // Zufälligen Index generieren
        int j = rand() % (i + 1);

        // Elemente tauschen
        int temp[2]; //Zwischenspeicher für die Werte von position[i]
        temp[0] = positionen[i][0];
        temp[1] = positionen[i][1];

        positionen[i][0] = positionen[j][0]; //die Werte von position[i] werden durch zufällige Werte von position[j] ersetzt
        positionen[i][1] = positionen[j][1];

        positionen[j][0] = temp[0]; //die Werte von position[j] werden durch die ursprünglichen Werte von position[i] ersetzt
        positionen[j][1] = temp[1];
    }
}

void vertausche_reihenfolge_zahlen_zufaellig(int zahlen[9])
{
    // Vertausche wieder die Reinfolge der Zahlen für gewährleistete Zufälligkeit
    for (int i = 9 - 1; i > 0; i--) // geht von i = 8 bis i = 0
    {
        // Zufälliger Index generieren
        int j = rand() % (i + 1);

        // Elemente tauschen
        int temp = zahlen[i]; //Speicher für ein Wert von zahlen[i]
        zahlen[i] = zahlen[j]; //der Wert von zahlen[i] wird durch den Wert von zahlen[j] ersetzt
        zahlen[j] = temp; //der Wert von zahlen[j] wird durch den ursprünglichen Wert von zahlen ersetzt 
    }
}

int create_random_sudoku(int uebergebenesBoard[9][9])
{
    erstelleNullBoard(uebergebenesBoard);
    srand(time(NULL));
    int zahlen[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int position[9][2] = {{0, 0}, {0, 1}, {0, 2}, 
                          {1, 0}, {1, 1}, {1, 2},
                          {2, 0}, {2, 1}, {2, 2}};


    vertausche_reihenfolge_positionen_zufaellig(position);

    vertausche_reihenfolge_zahlen_zufaellig(zahlen);

    for(int i = 0; i < 9; i++) //setzt in den ersten Block die Zahlen
    {
        uebergebenesBoard[position[i][0]][position[i][1]] = zahlen[i];
    }

    vertausche_reihenfolge_positionen_zufaellig(position);

      for(int i = 0; i < 9; i++) //setzt in den zweiten Block die Zahlen
    {
        uebergebenesBoard[position[i][0] + 3][position[i][1] + 3] = zahlen[i];
    }

    vertausche_reihenfolge_positionen_zufaellig(position);

      for(int i = 0; i < 9; i++) //setzt in den dritten Block die Zahlen
    {
        uebergebenesBoard[position[i][0] + 6][position[i][1] + 6] = zahlen[i];
    }

    solve(uebergebenesBoard, 0, 0);
    system("cls");

    int k = 50;
    

    while(k > 0)
    {
        int random_zeile = rand() % 9;
        int random_spalte = rand () % 9;

        if(uebergebenesBoard[random_zeile][random_spalte] != 0)
        {
            uebergebenesBoard[random_zeile][random_spalte] = 0;
            k--;
        } 
    }
    printf("Ein zufälliges Sudoku Board mit %d freien Feldern\n", 50);
    printBoard(uebergebenesBoard);
    return 0;
}

