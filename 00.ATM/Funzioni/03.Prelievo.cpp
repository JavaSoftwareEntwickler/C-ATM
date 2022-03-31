#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

typedef struct atm
{
    int prelievo, saldo, versamento, importo;
} atm;

atm movimenti[0];
movimenti.saldo = 1500;


///Funzioni e Procedure per modulo PRELIEVO
//******************************************
void stampaMenuPrelievo();
void controlloRisposta(char []);
void digitaImporto();
void confermaPrelievo(char []);
int prel();
//******************************************


int main(int argc, char *argv[])
{


    int preliev=prel();



    system("PAUSE");


    return 0;
}

int prel()
{

    int scegliImp = 0;
    const int EURO_50 = 1, EURO_100 = 2, EURO_250 = 3, ALTRO = 4, ESCI = 5;

    do
    {
        stampaMenuPrelievo();
        scanf("%d", &scegliImp);
    }
    while (scegliImp <1 || scegliImp >6);
    switch(scegliImp)
    {
    case EURO_50:
    {
        movimenti[0].prelievo=50;
        movimenti[0].importo=50;
        char risposta[5];
        int confronto=0;
        confermaPrelievo(risposta);
        controlloRisposta(risposta);
    }
    break;
    case EURO_100:
    {
        movimenti[0].prelievo=100;
        movimenti[0].importo=100;
        char risposta[5];
        int confronto=0;
        confermaPrelievo(risposta);
        controlloRisposta(risposta);
    }
    break;
    case EURO_250:
    {
        movimenti[0].prelievo=250;
        movimenti[0].importo=250;
        char risposta[5];
        int confronto=0;
        confermaPrelievo(risposta);
        controlloRisposta(risposta);
    }
    break;
    case ALTRO:
    {
        char risposta[5];
        int confronto=0;
        digitaImporto();
        confermaPrelievo(risposta);
        controlloRisposta(risposta);
    }
    break;
    case ESCI:
    {
        system("cls");
        printf("Esci");

    }
    break;
    }// *************fine switch PRELIEVO **************
    return movimenti[0].prelievo;
}

void stampaMenuPrelievo()
{
    system("cls");
    printf("%s-36\n", "Scegli l'importo del prelievo :");
    printf("%35s\n", "-----------------------------------");
    printf("1.Per ---> %8s %16s\n", " 50 Euro", "|");
    printf("2.Per ---> %8s %16s\n", "100 Euro", "|");
    printf("3.Per ---> %8s %16s\n", "250 Euro", "|");
    printf("4.Per digitare un importo diverso %2s\n", "|");
    printf("%36s\n", "|");
    printf("5.ESCI %29s\n", "|");
    printf("%35s\n", "-----------------------------------");
}

void digitaImporto()
{
    system("cls");
    printf("Digita l'importo: ");
    scanf("%d", &movimenti[0].importo);
}

void confermaPrelievo(char risposta[])
{
    system("cls");
    printf("***PRELIEVO %3d EURO***\n",movimenti[0].importo);
    printf("SI.------->Conferma\n");
    printf("NO.------->Tornare Indietro\n");
    scanf("%s",risposta);
}

void controlloRisposta(char risposta[])
{
    if( (strcmp(risposta, "SI")==0 || (strcmp(risposta, "si")==0) ))
    {
        movimenti[0].prelievo = movimenti[0].importo;
        movimenti[0].saldo-=movimenti[0].prelievo;
        system("cls");
        printf("Ritira le banconote.\nIl saldo e: %d\n Grazie ed arrivederci\n", movimenti[0].saldo);
    }
    else
    {
        printf("Ritira la carta bancomat.\nGrazie ed arrivederci\n");
        exit(0);
    }
}







