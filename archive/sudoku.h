// Sudoku Bibliothek mit allen Funktionen 
#include <stdio.h>
#include <stdlib.h>

// Die Funktion erstelleSpielfeld() erstellt ein dynamisches Sudoku-Spielbrett
// und gibt einen Zeiger auf das 2D-Array zurück.
void **erstelleSpielfeld() 
{
    int i, j; // Variablen für Schleifen
    int **puzzle; // Zeiger auf Zeiger, der später das 2D-Array repräsentiert

    // Statische 9x9 Sudoku-Matrix mit vorgegebenen Werten
    // 0 bedeutet ein leeres Feld
    int board[9][9] = 
    {
        4, 9, 0, 1, 6, 0, 3, 7, 0,
        0, 0, 7, 0, 0, 0, 1, 8, 6,
        0, 8, 0, 2, 0, 0, 0, 5, 0,
        3, 0, 0, 7, 9, 0, 0, 0, 5,
        0, 0, 0, 3, 0, 0, 7, 2, 1,
        8, 7, 0, 4, 2, 5, 6, 0, 0,
        0, 0, 3, 0, 0, 2, 4, 0, 7,
        6, 0, 4, 0, 7, 3, 2, 0, 0,
        0, 2, 0, 0, 1, 0, 0, 9, 0,
    };

    // Speicher für 9 Zeilen des Sudoku-Bretts allokieren.
    // Jede Zeile wird ein Zeiger (int*) sein.
    puzzle = (int **)malloc(9 * sizeof(int *));

    // Iteriere über jede Zeile des Sudoku-Bretts
    for (i = 0; i < 9; i++)
    {
        // Speicher für 9 Spalten in jeder Zeile allokieren.
        puzzle[i] = (int *)malloc(9 * sizeof(int));

        // Kopiere die Werte aus dem statischen Sudoku-Brett (board)
        // in das dynamisch allokierte Brett (puzzle).
        for (j = 0; j < 9; j++)
        {
            puzzle[i][j] = board[i][j]; // Kopiere den Wert aus board[i][j]
        }
    }

    // Gib den Zeiger auf das dynamische 2D-Array zurück.
    return (void **)puzzle;
}

void printpuzzle(int **puzzle)
{
    int i, j;

    for (i = 0; i < 9; i++)
    {
        // Trennlinie nach jeder dritten Zeile
        if (i % 3 == 0)
        {
            printf("+-------+-------+-------+\n");
        }

        for (j = 0; j < 9; j++)
        {
            // Trennlinie nach jeder dritten Spalte
            if (j % 3 == 0)
            {
                printf("| ");
            }

            // Wert des Sudoku-Felds drucken
            printf("%d ", puzzle[i][j]);

            // Ende der Zeile: zusätzliche Trennlinie
            if (j == 8)
            {
                printf("|");
            }
        }

        // Neue Zeile nach jeder Zeile
        printf("\n");
    }

    // Abschluss-Trennlinie für das gesamte Puzzle
    printf("+-------+-------+-------+\n");
}

void menue()
{

}


