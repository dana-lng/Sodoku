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
    int feld_start_zeile = (zeile / 3) * 3;
    int feld_start_spalte = (spalte / 3) * 3;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(uebergebenesBoard[feld_start_zeile + i][feld_start_spalte + j] == wert)
            {
                printf("Die Zahl %d ist bereits in diesem Feldblock vorhanden.\n", wert);
                return 1;
            }
        }
    }
    return 0;
   
}

int check_double_zeilen_spalten(int uebergebenesBoard[9][9], int zeile, int spalte, int wert)
{
    int i; 

    // Prüfen ob im Array zeilen_elemente die Zahl vorkommt  
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

int check_if_occupied(int uebergebenesBoard[9][9], int zeile, int spalte)
{
     
    if(uebergebenesBoard[zeile - 1][spalte - 1] == 0)
    {
        return 0; 
    }
    else
    {
        printf("Diese Position ist bereits besetzt. Bitte wählen Sie eine andere Position.\n");
        return 1;
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

    if (check_if_occupied(uebergebenesBoard, zeile, spalte) == 1)
    {
        goto Start;
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
  

    if (wahrheitswert == 0)
    {
        uebergebenesBoard[zeile - 1][spalte - 1] = wert; // Setzt die Zahl in das Board
    }

    


}

int solve(int uebergebenesBoard[9][9], int zeile, int spalte) 
{   
   int wert;

   if(zeile == 9)
   {
        return 1;
   }
   else if(spalte == 9)
   {
        return solve(uebergebenesBoard, zeile + 1, 0);
   }
   else if (uebergebenesBoard[zeile][spalte] != 0)
   {
        return solve(uebergebenesBoard, zeile, spalte + 1);
   }
   else
   {
        for(wert = 1; wert < 10; wert++)
        {
            if(check_double_zeilen_spalten(uebergebenesBoard, zeile + 1, spalte + 1, wert) == 0 && check_double_felder(uebergebenesBoard, zeile, spalte, wert) == 0)
            {
                uebergebenesBoard[zeile][spalte] = wert;
                if(solve(uebergebenesBoard, zeile, spalte + 1) == 1)
                {
                    return 1;
                }

                uebergebenesBoard[zeile][spalte] = 0;
            }
        }

        return 0;
   }
   
}
