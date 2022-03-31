#include <iostream>
#include<string.h>
#include<stdbool.h>

using namespace std;

void stampaMenuAtm();
void accendiAtm();


int main()

{

    accendiAtm();

    return 0;
}

void accendiAtm()
{

    int scegliOp=0;
    const int PRELEVA = 1, VERSA = 2, SALDO = 3, ESCI = 4;

    do
    {
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
            printf("%s\n", "1.Prelev                            |");
        }
        break;
        case VERSA :
        {
            system("cls");
            printf("%s\n", "2.Versa                            |");
        }
        break;
        case SALDO :
        {
            system("cls");
            printf("%s\n", "3.Saldo                            |");
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
    while(scegliOp != 4);

}

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






