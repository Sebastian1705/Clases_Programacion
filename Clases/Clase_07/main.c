#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char auxiliar[50];

    //strcpy(auxiliar,"-Hello World!\n");
    strncpy(auxiliar,"-Hello World!\n",51);
    auxiliar[50] = '\0';
    printf("\n---->  %s - LARGO: %d\n",auxiliar,strlen(auxiliar));

    strncpy(auxiliar,"123\n",51);
    printf("\n---->  %s - LARGO: %d\n",auxiliar,strlen(auxiliar));

    printf("\n%d",strcmp("A","B"));
    printf("\n%d",strcmp("B","A"));
    printf("\n%d\n",strcmpi("A","a"));


    char buffer[4];

    printf("\nIngrese un dato: ");
    //scanf("%s",buffer);           //sobrescribe memoria
    fgets(buffer,4,stdin);

    printf("\n%s",buffer);

    //atoi();   //funcion para pasar string a entero
    //atof();   //funcion para pasar string a flotante

    return 0;
}
