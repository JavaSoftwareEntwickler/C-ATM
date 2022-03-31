#include <stdio.h>
#include <stdlib.h>

using namespace std;

void stampaMenu(void);


int main(int argc, char *argv[])


{

    char c;
    printf("Digita un tasto:");
    c = getchar ();
    printf("Il carattere inserito e':");
    putchar(c);
    puts("");

    system("PAUSE");
    return 0;
}







