#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

using namespace std;

bool login(char [], char []);

int main()


{
    char userId[7] = "ciccio", psw[5] = "1234";
    bool accesso=login(psw, userId);
}

bool login(char psw[], char userId[])
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
            printf("\n%s", "***Connessione in corso.....");
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






