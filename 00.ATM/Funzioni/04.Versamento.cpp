#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

typedef struct atm
{
    int prelievo, saldo, versamento, importo;
} atm;

atm movimenti[0];



///Funzioni e Procedure per modulo VERSAMENTO
//******************************************
void stampaMenuOperazione();

void controlloRisposta(char []);

int digitaImporto();
void confermaOperazione(char []);

void gestioneVersamento(int importo);
int versamento();
//******************************************


int main(int argc, char *argv[])
{

    movimenti[0].saldo = 1500;
    int v=versamento();

    system("PAUSE");


    return 0;
}



int versamento()
{

    int scegliImp = 0;
    const int EURO_50 = 1, EURO_100 = 2, EURO_250 = 3, ALTRO = 4, ESCI = 5;

    do
    {
        stampaMenuOperazione();
        scanf("%d", &scegliImp);
    }
    while (scegliImp<1 || scegliImp>6);

    switch(scegliImp)
    {
    case EURO_50:
    {
        int importo =50;
        gestioneVersamento(importo);

    }
    break;
    case EURO_100:
    {
        int importo =100;
        gestioneVersamento(importo);
    }
    break;
    case EURO_250:
    {
        int importo =250;
        gestioneVersamento(importo);

    }
    break;
    case ALTRO:
    {
        gestioneVersamento(digitaImporto());

    }
    break;
    case ESCI:
    {
        system("cls");
        printf("Grazie arrivederci\n");

    }
    break;
    }
    return movimenti[0].versamento;
}

void stampaMenuOperazione()
{
    system("cls");
    printf("%s-36\n", "Scegli l'importo dell'operazione :");
    printf("%35s\n", "-----------------------------------");
    printf("1.Per ---> %8s %16s\n", " 50 Euro", "|");
    printf("2.Per ---> %8s %16s\n", "100 Euro", "|");
    printf("3.Per ---> %8s %16s\n", "250 Euro", "|");
    printf("4.Per digitare un importo diverso %2s\n", "|");
    printf("%36s\n", "|");
    printf("5.ESCI %29s\n", "|");
    printf("%35s\n", "-----------------------------------");
}

int digitaImporto()
{
    system("cls");
    printf("Digita l'importo: ");
    scanf("%d", &movimenti[0].importo);
    return movimenti[0].importo;
}

void confermaOperazione(char risposta[])
{
    system("cls");
    printf("***PRELIEVO %3d EURO***\n",movimenti[0].importo);
    printf("SI.------->Conferma\n");
    printf("NO.------->Torna indietro\n");
    scanf("%s",risposta);
}

void controlloRisposta(char risposta[])
{
    if( (strcmp(risposta, "SI")==0 || (strcmp(risposta, "si")==0) ))
    {
        movimenti[0].versamento = movimenti[0].importo;
        movimenti[0].saldo+=movimenti[0].versamento;
        system("cls");
        printf("Inserisci le banconote....\nIl saldo e': %d\n\n Grazie ed arrivederci\n", movimenti[0].saldo);
    }
    else
    {
        system("cls");
        system("PAUSE");
        versamento();
    }
}


void gestioneVersamento(int importo)
{
    char risposta[5];
    int confronto=0;

    movimenti[0].importo=importo;
    movimenti[0].versamento=importo;
    confermaOperazione(risposta);
    controlloRisposta(risposta);
}




