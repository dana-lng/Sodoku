#include <stdio.h>

void erstelleNullBoard(int uebergebenesBoard[9][9])
{
    for (int i = 0; i < 9; i++) // Schleife über alle Zeilen
    {
        for (int j = 0; j < 9; j++) // Schleife über alle Spalten
        {
            uebergebenesBoard[i][j] = 0; // Setze jedes Element des Boards auf 0
        }
    }
}

void printBoard(int uebergebenesBoard[9][9])
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

            printf("%d ", uebergebenesBoard[i][j]); // Drucke das aktuelle Board-Element

            // Am Ende der Zeile (bei der 9. Spalte): abschließendes '|'
            if (j == 8)
            {
                printf("|");
            }
        }
        printf("\n"); // Zeilenumbruch am Ende jeder Zeile
    }

    // Abschließende Trennlinie nach dem letzten Block
    printf("+-------+-------+-------+\n");
}

int check_double_felder(int uebergebenesBoard[9][9], int zeile, int spalte, int wert)
{
    int feld_1[3][3], feld_2[3][3], feld_3[3][3];
    int feld_4[3][3], feld_5[3][3], feld_6[3][3];
    int feld_7[3][3], feld_8[3][3], feld_9[3][3];
    int i, j;

     // Hinzufügen der Zahlen in die 3x3-Felder
    for (i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {   
            feld_1[i][j] = uebergebenesBoard[i][j];
            feld_2[i][j] = uebergebenesBoard[i][j+3];
            feld_3[i][j] = uebergebenesBoard[i][j+6];
            feld_4[i][j] = uebergebenesBoard[i+3][j];
            feld_5[i][j] = uebergebenesBoard[i+3][j+3];
            feld_6[i][j] = uebergebenesBoard[i+3][j+6];
            feld_7[i][j] = uebergebenesBoard[i+6][j];
            feld_8[i][j] = uebergebenesBoard[i+6][j+3];
            feld_9[i][j] = uebergebenesBoard[i+6][j+6];
        }
    }

    
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
             // Prüfung Feld 1, wenn in Feld 1
            if (zeile >= 1 && zeile <= 3 && spalte >= 1 && spalte <= 3) // Wir befinden uns im Feld 1
            {  
                if(feld_1[i][j] == wert)
                {
                    printf("Die Zahl %d ist bereits in Zeile %d und Spalte %d vorhanden.\n", wert, i + 1, j + 1);
                    return 0;
                } 
            }

            
            // Prüfung Feld 2, wenn in Feld 2
            if (zeile >= 1 && zeile <= 3 && spalte >= 4 && spalte <= 6) // Wir befinden uns im Feld 1
            {  
                if(feld_2[i][j] == wert)
                {
                    printf("Die Zahl %d ist bereits in Zeile %d und Spalte %d vorhanden.\n", wert, i + 1, j + 1 + 3);
                    return 0;
                } 
            }

            // Prüfung Feld 3, wenn in Feld 3
            if (zeile >= 1 && zeile <= 3 && spalte >= 7 && spalte <= 9) // Wir befinden uns im Feld 1
            {  
                if(feld_3[i][j] == wert)
                {
                    printf("Die Zahl %d ist bereits in Zeile %d und Spalte %d vorhanden.\n", wert, i + 1, j + 1 + 6);
                    return 0;
                } 
            }

            // Prüfung Feld 4, wenn in Feld 4
            if (zeile >= 4 && zeile <= 6 && spalte >= 1 && spalte <= 3) // Wir befinden uns im Feld 1
            {  
                printf("%d ", feld_4[i]);
                if(feld_4[i][j] == wert)
                {
                    printf("Die Zahl %d ist bereits in Zeile %d und Spalte %d vorhanden.\n", wert, i + 1 + 3, j + 1);
                    return 0;
                } 
            }

            // Prüfung Feld 5, wenn in Feld 5
            if (zeile >= 4 && zeile <= 6 && spalte >= 4 && spalte <= 6) // Wir befinden uns im Feld 1
            {  ;
                if(feld_5[i][j] == wert)
                {
                    printf("Die Zahl %d ist bereits in Zeile %d und Spalte %d vorhanden.\n", wert, i + 1 + 3, j + 1 + 3);
                    return 0;
                } 
            }

            // Prüfung Feld 6, wenn in Feld 6
            if (zeile >= 4 && zeile <= 6 && spalte >= 7 && spalte <= 9) // Wir befinden uns im Feld 1
            {  
                if(feld_6[i][j] == wert)
                {
                    printf("Die Zahl %d ist bereits in Zeile %d und Spalte %d vorhanden.\n", wert, i + 1 + 3, j + 1 + 6);
                    return 0;
                } 
            }

            // Prüfung Feld 7, wenn in Feld 7
            if (zeile >= 7 && zeile <= 9 && spalte >= 1 && spalte <= 3) // Wir befinden uns im Feld 1
            {  
                if(feld_7[i][j] == wert)
                {
                    printf("Die Zahl %d ist bereits in Zeile %d und Spalte %d vorhanden.\n", wert, i + 1 + 6, j + 1);
                    return 0;
                } 
            }

            // Prüfung Feld 8, wenn in Feld 8
            if (zeile >= 7 && zeile <= 9 && spalte >= 4 && spalte <= 6) // Wir befinden uns im Feld 1
            {  
                if(feld_8[i][j] == wert)
                {
                    printf("Die Zahl %d ist bereits in Zeile %d und Spalte %d vorhanden.\n", wert, i + 1 + 6, j + 1 + 3);
                    return 0;
                } 
            }

            // Prüfung Feld 9, wenn in Feld 9
            if (zeile >= 7 && zeile <= 9 && spalte >= 7 && spalte <= 9) // Wir befinden uns im Feld 1
            {  
                if(feld_9[i][j] == wert)
                { 
                    printf("Die Zahl %d ist bereits in Zeile %d und Spalte %d vorhanden.\n", wert, i + 1 + 6, j + 1 + 6);
                    return 0;
                } 
            }

            if (i == 2 && j == 2)
            {
                return 1;
            }
            
        }
    }
   
}

int check_double_zeilen_spalten(int uebergebenesBoard[9][9], int zeile, int spalte, int wert)
{
    // Überprüft, ob die Zahl bereits in der Zeile vorkommt
    int zeilen_elemente[9] = {};
    int spalten_elemente[9] = {};
    int i; 

    // Hinzufügen der Zahlen in der Zeile
    for (i = 0; i < 9; i++)
    {
        zeilen_elemente[i] = uebergebenesBoard[zeile - 1][i];
        //printf("%d", zeilen_elemente[i]);
    }
    // Hinzufügen der Zahlen in der Spalte 
    for (i = 0; i < 9; i++)
    {
        spalten_elemente[i] = uebergebenesBoard[i][spalte - 1];
        //printf("%d", spalten_elemente[i]);
    }
    
    // Prüfen ob im Array zeilen_elemente die Zahl vorkommt  
    // oder ob im Array spalten_elemente die Zahl vorkommt
    for (i = 0; i < 9; i++)
    {   
        
        if (zeilen_elemente[i] == wert)
        {
            printf("Die Zahl %d ist bereits in Zeile %d und Spalte %d vorhanden.\n", wert, zeile, i + 1);
            return 0;
        }
        if (spalten_elemente[i] == wert)
        {
            printf("Die Zahl %d ist bereits in Zeile %d und Spalte %d vorhanden.\n", wert, i + 1, spalte);
            return 0;
        }
        if (i == 8) // Erst wenn alle Zahlen in Spalten und Zeile geprüft wurden
        {
            return 1;
        }
    }
}



void set_board_element(int uebergebenesBoard[9][9])
{   
    int zeile, spalte, wert; // Variablen deklariert
    char ende;

    Start:
    // Eingabe Zeile
    while(1)
    {
        printf("In welcher Zeile wollen Sie die Zahl setzen (1 bis 9)? ");
         
        if (scanf("%d%c", &zeile, &ende) == 2 && // Prüft ob Buchstabe oder nicht,
           (ende == '\n' || ende == ' ') && // &ende prüft ob ganze Zahl oder nicht
           (zeile >= 1 && zeile <= 9)) // Prüfe, ob die Zeile zwischen 1 und 9 liegt
        {

            break;
        }
        else 
        {
            printf("Falsche Eingabe. Bitte geben Sie eine Zahl zwischen 1 und 9 ein.\n");
            while (getchar() != '\n'); // Entfernt restliche Zeichen aus dem Puffer
        }

    }

    // Eingabe Spalte
    while(1)
    {
        printf("In welcher Spalte wollen Sie die Zahl setzen (1 bis 9)? ");
        
        if (scanf("%d%c", &spalte, &ende) == 2 && // Prüft ob Buchstabe oder nicht
           (ende == '\n' || ende == ' ')  && // &ende prüft ob ganze Zahl oder nicht
           (spalte >= 1 && spalte <= 9)) // Prüfe, ob die Eingabe eine ganze Zahl ist
        {
            break;
        }
        else 
        {
            printf("Falsche Eingabe. Bitte geben Sie eine Zahl zwischen 1 und 9 ein.\n");
            while (getchar() != '\n'); // Entfernt restliche Zeichen aus dem Puffer
        }
    }

    while(1)
    {
        if(uebergebenesBoard[zeile - 1][spalte - 1] == 0)
        {
           break; 
        }
        else
        {
            printf("Diese Position ist bereits besetzt. Bitte wählen Sie eine andere Position.");
            while (getchar() != '\n');
            goto Start; //springt wieder zum Anfang der Funktion
        }
    }


    // Eingabe Zahl
    while(1)
    {
        printf("Welche Zahl moechten Sie einsetzen? (1 bis 9)? ");
        //&ende prüft ob ganze Zahl oder nicht
        if (scanf("%d%c", &wert, &ende) == 2 && // Prüft ob Buchstabe oder nicht
            (ende == '\n' || ende == ' ') && // &ende prüft ob ganze Zahl oder nicht
            (wert >= 1 && wert <= 9)) // Prüfe, ob die Eingabe eine ganze Zahl ist
        {
            break;
        }
        else 
        {
            printf("Falsche Eingabe. Bitte geben Sie eine Zahl zwischen 1 und 9 ein.\n");
            while (getchar() != '\n'); // Entfernt restliche Zeichen aus dem Puffer
        }
    }

 
    int wahrheitswert = check_double_zeilen_spalten(uebergebenesBoard, zeile, spalte, wert) + check_double_felder(uebergebenesBoard, zeile, spalte, wert);

    if (wahrheitswert == 2)
    {
        uebergebenesBoard[zeile - 1][spalte - 1] = wert; // Setzt die Zahl in das Board
    }

    


}

