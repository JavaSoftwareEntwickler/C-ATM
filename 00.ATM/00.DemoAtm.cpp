#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
using namespace std;


const char userId[7] = "ciccio", psw[5] = "1234"; // utili per login()
typedef struct atm
{
    int prelievo, saldo, versamento, importo;
} atm;
atm movimenti[0];


void atmOn();
bool login(const char [], const char []);
void stampaMenuAtm();
void accediAtm();

///Funzioni e Procedure PRELIEVO
//******************************************
void stampaMenuOperazione();      // utile per prelievo e versamento
void controlloRisposta(char []);
int digitaImporto();              // utile per prelievo e versamento
void confermaOperazione(char[], char[]); // utile per prelievo e versamento
void gestionePrelievo(int, char[]);
int prel();

//******************************************
///Funzioni e Procedure per modulo VERSAMENTO
//******************************************
void controlloRispostaV(char []);
void gestioneVersamento(int, char[]);
int versamento();
//******************************************


int main()
{
    atmOn();
    return 0;
}

void atmOn()
{
    while(1)
    {
        system("cls");
        if (!login(psw, userId))
        {
            exit(0);
        }
        movimenti[0].saldo = 1500;
        accediAtm();
    }
}

//************ INIZIO FUNZ E PROC LOGIN ********************
bool login(const char psw[], const char userId[])
{
    char userIdDigitata[20], pswDigitata[20];
    bool accessoAtm = false;
    int tentativi = 4;

    do
    {
        tentativi --;
        printf("UserId..");
        scanf("%s", &userIdDigitata);
        printf("Password..");
        scanf("%s", &pswDigitata);

        int comaparaId =strcmp(userId, userIdDigitata);
        int comaparaPsw=strcmp(psw, pswDigitata);

        if ((comaparaId ==0) && (comaparaPsw==0))
        {
            system("cls");
            tentativi=0;
            accessoAtm = true;// acessoAtm diventa : uno! quindi entrare nel modulo menu dell'ATM
            printf("\n%s\n", "***Connessione in corso.....");
            system("PAUSE");
            system("cls");
            printf("%s\n", "************ATM ATTIVATO************");
            system("PAUSE");
        }
        else if (tentativi>1)
        {
            system("cls");
            printf("Hai ancora %d tentativi\n",tentativi);
        }
        else if (tentativi==1)
        {
            system("cls");
            printf("*******************\n*Ultimo tentativo *\n");
            printf("*******************\nSe sbagli anche questo tentativo\n");
            printf("l'account verra' bloccato.\n**************************\n");
        }
        else
        {
            system("cls");
            printf("%s","**LogOut****Account bloccato****");
            tentativi=0;
            accessoAtm = false; // acessoAtm diventa :zero
        }
    }
    while(tentativi!=0);

    return accessoAtm;
}

//************ FINE FUNZ E PROC ++++LOGIN+++++ ********************


//************ FINE FUNZ E PROC ++++ACCEDI ATM+++++ ***************

void stampaMenuAtm()
{
    system("cls");
    printf("%s\n", "-----------------------------------");
    printf("%s\n", "1.Preleva                          |");
    printf("%s\n", "2.Versa                            |");
    printf("%s\n", "3.Saldo                            |");
    printf("%s\n", "4.Esci                             |");
    printf("%s\n", "                                   |");
    printf("%s\n", "Digita il numero corrispondente    |");
    printf("%s\n", "                                   |");
    printf("%s\n", "-----------------------------------");
}

void accediAtm()
{
    int scegliOp=0;
    const int PRELEVA = 1, VERSA = 2, SALDO = 3, ESCI = 4;
    do
    {
        stampaMenuAtm();
        scanf("%d", &scegliOp);
    }
    while(scegliOp <1 || scegliOp>4);


    switch (scegliOp)
    {
    case PRELEVA :
    {
        system("cls");
        movimenti[0].prelievo=prel();
        system("PAUSE");
    }
    break;
    case VERSA :
    {
        system("cls");
        movimenti[0].versamento=versamento();
        system("PAUSE");
    }
    break;
    case SALDO :
    {
        system("cls");
        printf("\nIl saldo e': %d\n\n Grazie ed arrivederci\n", movimenti[0].saldo);
        system("PAUSE");
    }
    break;
    case ESCI :
    {
        system("cls");
        printf("%s\n", "4.Esci                             |");
    }
    break;

    default :
    {
        system("cls");
        printf("%s\n", "default                            |");
    }
    break;
    }
}
//************ FINE FUNZ E PROC ++++ACCEDI ATM+++++ ***************

/// INIZIO PROCEDURE E FUNZIONI
/// **********PRELIEVO****************
int prel()
{
    int scegliImp = 0;
    const int EURO_50 = 1, EURO_100 = 2, EURO_250 = 3, ALTRO = 4, ESCI = 5;
    char operazione[20]= {"PRELIEVO"};
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
        gestionePrelievo(importo, operazione);
    }
    break;
    case EURO_100:
    {
        int importo =100;
        gestionePrelievo(importo, operazione);
    }
    break;
    case EURO_250:
    {
        int importo =250;
        gestionePrelievo(importo, operazione);
    }
    break;
    case ALTRO:
    {
        gestionePrelievo(digitaImporto(), operazione);
    }
    break;
    case ESCI:
    {
        system("cls");
        printf("Grazie arrivederci\n");
    }
    break;
    }
    return movimenti[0].prelievo;
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

void confermaOperazione(char risposta[], char operazione[])
{
    system("cls");
    printf("***%s %3d EURO***\n", operazione, movimenti[0].importo);
    printf("SI.------->Conferma\n");
    printf("NO.------->Torna indietro'\n");
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
        system("cls");
        system("PAUSE");
        prel();
    }
}

void gestionePrelievo(int importo, char operazione[])
{
    char risposta[5];
    int confronto=0;

    movimenti[0].importo=importo;
    movimenti[0].prelievo=importo;
    confermaOperazione(risposta, operazione);
    controlloRisposta(risposta);
}
///              FINE
///       PROCEDURE E FUNZIONI
/// **********PRELIEVO****************

/// INIZIO PROCEDURE E FUNZIONI
/// **********VERSAMENTO**************
int versamento()
{
    int scegliImp = 0;
    char operazione[20]= {"VERSAMENTO"};
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
        gestioneVersamento(importo, operazione);
    }
    break;
    case EURO_100:
    {
        int importo =100;
        gestioneVersamento(importo, operazione);
    }
    break;
    case EURO_250:
    {
        int importo =250;
        gestioneVersamento(importo, operazione);
    }
    break;
    case ALTRO:
    {
        gestioneVersamento(digitaImporto(), operazione);
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


void controlloRispostaV(char risposta[])
{
    if( (strcmp(risposta, "SI")==0 || (strcmp(risposta, "si")==0) ))
    {
        movimenti[0].versamento = movimenti[0].importo;
        movimenti[0].saldo+=movimenti[0].versamento;
        system("cls");
        printf("Inserisci le banconote....\n");
        system("PAUSE");
        printf("ttrtrtrtrtrtrt......\n");
        system("PAUSE");
        system("cls");
        printf("Il saldo e': %d\n\n Grazie ed arrivederci\n", movimenti[0].saldo);
    }
    else
    {
        system("cls");
        system("PAUSE");
        versamento();
    }
}


void gestioneVersamento(int importo, char operazione[])
{
    char risposta[5];
    int confronto=0;
    movimenti[0].importo=importo;
    movimenti[0].versamento=importo;
    confermaOperazione(risposta, operazione);
    controlloRispostaV(risposta);
}



///              FINE
///       PROCEDURE E FUNZIONI
/// **********VERSAMENTO****************









