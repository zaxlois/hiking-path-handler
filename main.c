#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "funcs.h"
#define N 500
int main()
{
    int n;
    char k,c;
    struct route A[N];
    do
    {
        scanf("%c",&k);
        while ((c = getchar() ) != EOF && c != '\n' && c!='\r');
        switch (k)
        {
            case 'i': n=readFromInput(A);
                break;
            case 'p':   printData(A,n);
                break;
            case 'l':   findShort(A,n);
                break;
            case 's':   findLocation(A,n);
                break;
            case 'u':   findUpHill(A,n);
                break;
            case 'd':   findDownHill(A,n);
                break;
            case 'h':   findAltitude(A,n);
                break;
            case 't':   findTimely(A,n);
                break;
            case 'f': n=readFromFile(A);
                break;
            case 'o':   saveData(A,n);
                break;
        }
        scanf (" ");
    }
    while (k!='q');
    return 0;
}
