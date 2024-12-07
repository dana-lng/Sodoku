#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sudoku.c" // Enthält die Prüffunktionen und die printBoard-Funktion


int check_double_zeilen_spalten1(int array[9][9], int zeile, int spalte, int zahl) {
    // Prüfe Zeile
    for (int i = 0; i < 9; i++) {
        if (array[zeile][i] == zahl) {
            return 0; // Zahl existiert in der Zeile
        }
    }

    // Prüfe Spalte
    for (int i = 0; i < 9; i++) {
        if (array[i][spalte] == zahl) {
            return 0; // Zahl existiert in der Spalte
        }
    }

    return 1; // Zahl ist gültig
}

int check_double_felder1(int array[9][9], int zeile, int spalte, int zahl) {
    // Bestimme den Startpunkt des 3×3-Blocks
    int startZeile = (zeile / 3) * 3;
    int startSpalte = (spalte / 3) * 3;

    // Prüfe den 3×3-Block
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (array[startZeile + i][startSpalte + j] == zahl) {
                return 0; // Zahl existiert im Block
            }
        }
    }

    return 1; // Zahl ist gültig
}

// Hauptprogramm
int main() {
    int uebergebenesBoard[9][9];
    srand(time(NULL));
    int f = 0;             // Anzahl der gefüllten Zellen
    int random_zeile;
    int random_spalte;
    int random_zahl;
    memset(uebergebenesBoard, 0, sizeof(uebergebenesBoard[0]) * 9);


    while (f < 30) 
    { // Fülle 30 Zellen
        random_zeile = rand() % 9; // Zufällige Zeile (0-8)
        random_spalte = rand() % 9; // Zufällige Spalte (0-8)
        random_zahl = rand() % 9 + 1; // Zufällige Zahl (1-9)

        // Überprüfe die Regeln: Zelle muss leer sein und Zahl muss gültig sein
        if (uebergebenesBoard[random_zeile][random_spalte] == 0 && 
            check_double_zeilen_spalten(uebergebenesBoard, random_zeile, random_spalte, random_zahl) && 
            check_double_felder(uebergebenesBoard, random_zeile, random_spalte, random_zahl)) 
        {
            uebergebenesBoard[random_zeile][random_spalte] = random_zahl; // Setze die Zahl
            f++; // Erhöhe den Zähler der gefüllten Zellen
        }
    }

    // Ausgabe der gefüllten Matrix
    printf("Sudoku-Matrix mit 30 zufälligen Zahlen:\n");
    printBoard(uebergebenesBoard);

    return 0;
}
    
    
    /*
    srand(time(NULL));

    int array[9][9] = {0}; // Initialisiere die Matrix mit Nullen
    int f = 0;             // Anzahl der gefüllten Zellen
    int random_zeile;
    int random_spalte;
    int random_zahl;

    while (f < 30) 
    { // Fülle 30 Zellen
        random_zeile = rand() % 9; // Zufällige Zeile (0-8)
        random_spalte = rand() % 9; // Zufällige Spalte (0-8)
        random_zahl = rand() % 9 + 1; // Zufällige Zahl (1-9)

        // Überprüfe die Regeln: Zelle muss leer sein und Zahl muss gültig sein
        if (array[random_zeile][random_spalte] == 0 && 
            check_double_zeilen_spalten1(array, random_zeile, random_spalte, random_zahl) && 
            check_double_felder1(array, random_zeile, random_spalte, random_zahl)) 
        {
            array[random_zeile][random_spalte] = random_zahl; // Setze die Zahl
            f++; // Erhöhe den Zähler der gefüllten Zellen
        }
    }

    // Ausgabe der gefüllten Matrix
    printf("Sudoku-Matrix mit 30 zufälligen Zahlen:\n");
    printBoard(array);

    return 0;
*/


