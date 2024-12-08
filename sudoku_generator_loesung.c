#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void print_board(int uebergebenesBoard[9][9])
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            printf("%d ", uebergebenesBoard[i][j]);
        }
        printf("\n");
    }
} 

void print_positionen(int positionen[9][2])
{
    for (int i = 0; i < 9; i++)
    {   
        if (i % 3 == 0)
        {
            printf("\n");
        }
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", positionen[i][j]);
        }
        printf(" ; ");
    }
}

void print_zahlen(int zahlen[9])
{
    for (int i = 0; i < 9; i++)
    {
        printf("%d ", zahlen[i]);
    }
}

void erstelle_null_board(int uebergebenesBoard[9][9])
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            uebergebenesBoard[i][j] = 0;
        }
    }
}

int check_double_zeilen_spalten(int uebergebenesBoard[9][9], int zeile, int spalte, int wert)
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

int check_double_felder(int uebergebenesBoard[9][9], int zeile, int spalte, int wert)
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

int solve(int uebergebenesBoard[9][9], int zeile, int spalte) 
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
                //saveBoardState(uebergebenesBoard); // Speichert den aktuellen Zustand des Boards (für "Undo"-Funktion
                
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
    // Fisher-Yates-Shuffle (habe ich nur gegooglet) -> mischt einfach die positionen zufällig um
    for (int i = 9 - 1; i > 0; i--) // von i = 8 bis i = 0
    {
        // Zufälligen Index generieren
        int j = rand() % (i + 1);

        // Elemente tauschen
        int temp[2];
        temp[0] = positionen[i][0];
        temp[1] = positionen[i][1];

        positionen[i][0] = positionen[j][0];
        positionen[i][1] = positionen[j][1];

        positionen[j][0] = temp[0];
        positionen[j][1] = temp[1];
    }
}

void vertausche_reihenfolge_zahlen_zufaellig(int zahlen[9])
{
    // Vertausche wieder die Reinfolge der Zahlen für gewährleistete Zufälligkeit
    for (int i = 9 - 1; i > 0; i--) // geht von i = 8 bis i = 0
    {
        // Zufallisgen Index generieren
        int j = rand() % (i + 1);

        // Elemente tauschen
        int temp = zahlen[i];
        zahlen[i] = zahlen[j];
        zahlen[j] = temp;
    }
}

int generate_sudoku(int uebergebenesBoard[9][9])
{
    srand(time(NULL));
    erstelle_null_board(uebergebenesBoard);

    // erstelle die Zeilen und Spalten für die erste Diagonal-Matrix
    int positionen[9][2] = {{0, 0}, {0, 1}, {0, 2}, 
                            {1, 0}, {1, 1}, {1, 2},
                            {2, 0}, {2, 1}, {2, 2}};

    //print_positionen(positionen);
    // die Ausgabe sieht so aus:
    // 0 0  ; 0 1  ; 0 2  ; 
    // 1 0  ; 1 1  ; 1 2  ;
    // 2 0  ; 2 1  ; 2 2  ;
    // die erste Zahl ist die Zeile, die zweite ist die Spalte also (zeile 0, spalte 0) = (0, 0)
    
    // Vertausche die Positionen zufällig
    vertausche_reihenfolge_positionen_zufaellig(positionen);
    // z.B. kann die Ausgabe so aussehenen:
    // 1 0  ; 2 0  ; 0 0  ;             // 0 2  ; 2 0  ; 0 1  ; 
    // 2 1  ; 0 1  ; 0 2  ;     ODER    // 1 0  ; 1 1  ; 0 0  ;     ODER    ...
    // 2 2  ; 1 1  ; 1 2  ;             // 2 2  ; 2 1  ; 1 2  ;


    // jetzt erstelle einfach ein Array mit den 9 Zahlen drin
    int zahlen[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // print_zahlen(zahlen);
    // die Ausgabe sieht so aus:
    // 1 2 3 4 5 6 7 8 9

    // Vertausche die Zahlen zufällig
    vertausche_reihenfolge_zahlen_zufaellig(zahlen);
    // print_zahlen(zahlen);
    // z.B. sieht die Ausgabe so aus:
    // 7 6 2 3 8 9 1 5 4  ODER // 5 4 9 6 3 7 1 8 2 


    // Fülle die erste Diagonal-Matrix also oben links mit random Zahlen
    for (int i = 0; i < 9; i++)
    {
        uebergebenesBoard[positionen[i][0]][positionen[i][1]] = zahlen[i];
    }
    // print_board(uebergebenesBoard);
    // z.B. Ausgabe sieht die ausgabe so aus:
    // 5 6 1 0 0 0 0 0 0                // 2 6 8 0 0 0 0 0 0           
    // 9 7 2 0 0 0 0 0 0                // 4 9 1 0 0 0 0 0 0            
    // 4 3 8 0 0 0 0 0 0                // 3 5 7 0 0 0 0 0 0            
    // 0 0 0 0 0 0 0 0 0                // 0 0 0 0 0 0 0 0 0            
    // 0 0 0 0 0 0 0 0 0      ODER      // 0 0 0 0 0 0 0 0 0   
    // 0 0 0 0 0 0 0 0 0                // 0 0 0 0 0 0 0 0 0        
    // 0 0 0 0 0 0 0 0 0                // 0 0 0 0 0 0 0 0 0
    // 0 0 0 0 0 0 0 0 0                // 0 0 0 0 0 0 0 0 0
    // 0 0 0 0 0 0 0 0 0                // 0 0 0 0 0 0 0 0 0

    // !!! ab hier analog wie die erste Diagonal-Matrix, nur dass jetzt die zweite Diagonal-Matrix gefüllt wird, daher zeile + 3 und spalte + 3
    // Vertausche die Positionen zufällig für die zweite Diagonal-Matrix
    vertausche_reihenfolge_positionen_zufaellig(positionen);
    // Vertausche die Zahlen zufällig für die zweite Diagonal-Matrix
    vertausche_reihenfolge_zahlen_zufaellig(zahlen);
    // Fülle die zweite Diagonal-Matrix also mitte mit random Zahlen
    for (int i = 0; i < 9; i++)
    {
        uebergebenesBoard[positionen[i][0] + 3][positionen[i][1] + 3] = zahlen[i]; // + 3 weil die Diagonal-Matrix bei zeile = 3 un spalte = 3 beginnt
    }

    // !!! ab hier analog wie die erste und die zweite Diagonal-Matrix, nur dass jetzt die dritte Diagonal-Matrix gefüllt wird, daher zeile + 6 und spalte + 6
    // Vertausche die Positionen zufällig für die dritte Diagonal-Matrix
    vertausche_reihenfolge_positionen_zufaellig(positionen);
    // Vertausche die Zahlen zufällig für die dritte Diagonal-Matrix
    vertausche_reihenfolge_zahlen_zufaellig(zahlen);
    // Fülle die dritte Diagonal-Matrix also mitte mit random Zahlen
    for (int i = 0; i < 9; i++)
    {
        uebergebenesBoard[positionen[i][0] + 6][positionen[i][1] + 6] = zahlen[i]; // + 6 weil die Diagonal-Matrix bei zeile = 6 un spalte = 6 beginnt
    }

    // print_board(uebergebenesBoard);
    // z.B. Ausgabe sieht die ausgabe so aus:
    // 3 4 7 0 0 0 0 0 0  
    // 5 1 2 0 0 0 0 0 0  
    // 9 8 6 0 0 0 0 0 0  
    // 0 0 0 9 7 2 0 0 0  
    // 0 0 0 8 1 5 0 0 0  
    // 0 0 0 3 4 6 0 0 0  
    // 0 0 0 0 0 0 5 8 1 
    // 0 0 0 0 0 0 3 2 7  
    // 0 0 0 0 0 0 9 4 6  

    // jetzt löse dieses sudoku mit der Funktion solve (DAS IST JETZT IMMER LÖSBAR!!!!!
    solve(uebergebenesBoard, 0, 0);
    // print_board(uebergebenesBoard);
    // z.B. Ausgabe sieht die ausgabe so aus:
    // 3 4 7 6 2 8 9 5 1  
    // 5 1 2 9 4 3 7 6 8  
    // 9 8 6 5 1 7 4 2 3  
    // 4 9 8 1 5 6 3 7 2  
    // 7 2 5 8 9 4 6 1 3  
    // 6 3 4 7 8 2 1 9 5  
    // 2 7 1 3 6 9 5 8 4 
    // 8 5 9 2 7 1 3 4 6  
    // 1 6 3 4 8 5 2 7 9

    // jetzt entferne ich k-Elemente vom gelösten sudoku Brett
    int k = 30; // Anzahl der Elemente die entfernt werden sollen
    while(k > 0)
    {
        int random_zeile = rand() % 9; // Zufallsgenerator von 0 bis 8
        int random_spalte = rand() % 9; // Zufallsgenerator von 0 bis 8
        if (uebergebenesBoard[random_zeile][random_spalte] != 0) // Wenn die Zelle besetzt ist
        {
            uebergebenesBoard[random_zeile][random_spalte] = 0; // setze die Zelle auf 0
            k--; // Ein Element wurde entfernt (auf 0 gesetzt), daher k-1
        }
    }
    // Ausgabe der random Matrix
    printf("Sudoku-Matrix mit %d zufälligen Zahlen:\n", 81 - k);
    print_board(uebergebenesBoard);
    return 0;
}

// Hauptprogramm nur als Beispiel; du musst das in spiel.c machen!!!
int main()
{
    int random_board[9][9];
    generate_sudoku(random_board);
}