#include <stdio.h>
#include <ctype.h>

void open_file(FILE **datei, char *dateiname) 
{
    if((*datei = fopen(dateiname, "rt")) == NULL)
    {
        printf("Datei %s konnte nicht geoeffnet werden\n", dateiname);

    }
    else
    {
        printf("Datei %s konnte geoeffnet werden\n", dateiname);
    }
}

void load_file(FILE *datei, int uebergebenesBoard[9][9])
{
    int k = 0;
    int i;
    int j;
    int c;
    int eingelesenes_sudokufeld_1d_array[81] = {};

    while((c = fgetc(datei)) != EOF)
    {
        
        if(isdigit(c))
        {
            eingelesenes_sudokufeld_1d_array[k] = c - '0'; //c wird in ascii code gelesen und - '0' wandelt in die jeweilige Zahl um
            k++;
        }
    }
    printf("\n");

    for(i = 0; i < 9; i++) 
    {
        for(j = 0; j < 9; j++)
        {
            uebergebenesBoard[i][j] = eingelesenes_sudokufeld_1d_array[i * 9 + j]; //umwandlung von 1d array in 2d array (matrix)
        } 
    }   

}

void close_file(FILE *datei, char *dateiname)
{
    if(fclose(datei) == 0)
    {
        printf("Datei %s geschlossen\n", dateiname);
    }
    else
    {
        printf("Datei %s konnte nicht geschlossen werden\n", dateiname);
    }
    
}

