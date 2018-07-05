#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getsValids.h"

int get_Int(char* mensaje, int *input)
{

    printf("%s",mensaje);
    scanf("%d", input);
    return 0;
}
int get_Float(char* mensaje, float *input)
{

    printf("%s",mensaje);
    scanf("%f", input);
    return 0;
}
int get_Long(char* mensaje, long *input)
{

    printf("%s",mensaje);
    scanf("%ld", input);
    return 0;
}
int get_Char(char* mensaje, char *input)
{

    printf("%s",mensaje);
    *input=getchar();
    return 0;
}

int get_String(char* mensaje, char *input)
{

    printf("%s",mensaje);
    gets(input);
    return 0;
}

int val_numero(char *str)
{

   int i=0;
   while(str[i] != '\0')
   {
       if (i == 0 && str[i] == '-')
       {
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
           return -1;

       i++;
   }
   return 0;
}

int val_letras(char *str)
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return -1;
       i++;
   }
   return 0;
}



int val_alfaNumerico(char *str)
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
           return -1;
       i++;
   }
   return 0;
}

int val_noespacios(char *str)
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] == ' '))
           return -1;
        i++;
    }
    return 0;

}


int val_flotante(char *str)
{
   int i=0;
   int cantidadPuntos=0;
   while(str[i] != '\0')
   {
       if (i == 0 && str[i] == '-')
       {
           i++;
           continue;

       }
       if (str[i] == '.' && cantidadPuntos == 0)
       {
           cantidadPuntos++;
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
           return -1;
       i++;
   }
   return 0;
}


int val_email(char *str){

int i=0;
while(str[i] != '\0')
{
    if(str[i]=='@')
        return 0;
        i++;
}
return -1;
}

int val_telefono(char *str)
{
   int i=0;
   int contadorGuiones=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
           return -1;
       if(str[i] == '-')
            contadorGuiones++;
       i++;
   }
   if(contadorGuiones==1) // debe tener un guion
        return 0;

    return -1;
}

int get_stringLetras(char *mensaje,char *input)
{
    char aux[500];
    get_String(mensaje,aux);
    if(!val_letras(aux))
    {
        strcpy(input,aux);
        return 0;
    }
    return -1;
}

int get_stringNumeros(char *mensaje,char *input)
{
    char aux[500];
    get_String(mensaje,aux);
    if(!val_numero(aux))
    {
        strcpy(input,aux);
        return 0;
    }
    return -1;
}

int get_stringFlotantes(char *mensaje,char *input)
{
    char aux[256];
    get_String(mensaje,aux);
    if(!val_flotante(aux))
    {
        strcpy(input,aux);
        return 0;
    }
    return -1;

}

int get_stringAlfaNumerico(char *mensaje,char *input)
{
    char aux[500];
    get_String(mensaje,aux);
    if(!val_alfaNumerico(aux))
    {
        strcpy(input,aux);
        return 0;
    }
    return -1;
}

int get_stringNoespacios(char *mensaje,char *input)
{

    char aux[500];
    get_String(mensaje,aux);
    {
        if(!val_noespacios(aux))
        {
            strcpy(input,aux);
            return 0;
        }
    }
    return -1;
}

int get_validInt(char *requestMessage,char *errorMessage, int* input,int lowLimit, int hiLimit,int attemps)
{
    char auxStr[256];
    int auxInt, i, retorno = -1;

    for(i=0;i<attemps;i++)
    {
        if (get_stringNumeros(requestMessage,auxStr))
        {
            printf ("%s",errorMessage);
            break;
            continue;

        }
        auxInt = atoi(auxStr);
        if(auxInt < lowLimit || auxInt > hiLimit)
        {
            printf ("%s",errorMessage);
            continue;

        }
        *input = auxInt;
        retorno = 0;
        break;

    }
    return retorno;

}

int get_validStringNumeros(char *requestMessage,char *errorMessage, char *errorMessageLenght,char *input, int maxLenght,int attemps)
{
   int i;
    int retorno=-1;
    char buffer[1024];

    for(i=0;i<attemps;i++)
    {
        if (get_stringNumeros(requestMessage,buffer))
        {
            printf ("%s",errorMessage);
            continue;
        }
        if(strlen(buffer) >= maxLenght)
        {
            printf ("%s",errorMessageLenght);
            continue;

        }
        retorno=0;
        strcpy(input,buffer);
        break;
    }
    return retorno;

}


int get_validStringSinEspacios(char *requestMessage,char *errorMessage, char *errorMessageLenght,char *input, int maxLenght,int attemps)
{
   int i;
    int retorno=-1;
    char buffer[1024];

    for(i=0;i<attemps;i++)
    {
        if (get_stringNoespacios(requestMessage,buffer))
        {
            printf ("%s",errorMessage);
            continue;
        }
        if(strlen(buffer) >= maxLenght)
        {
            printf ("%s",errorMessageLenght);
            continue;

        }
        retorno=0;
        strcpy(input,buffer);
        break;
    }
    return retorno;

}

int get_validLetras(char *requestMessage,char *errorMessage, char *errorMessageLenght,char *input, int maxLenght,int attemps)
{
    int i;
    int retorno=-1;
    char buffer[1024];

    for(i=0;i<attemps;i++)
    {
        if (get_stringLetras(requestMessage,buffer))
        {
            printf ("%s",errorMessage);
            continue;
        }
        if(strlen(buffer) >= maxLenght)
        {
            printf ("%s",errorMessageLenght);
            continue;

        }
        retorno=0;
        strcpy(input,buffer);
        break;
    }
    return retorno;
}


int get_validFloat(char *requestMessage,char *errorMessage, float* input,int lowLimit, int hiLimit,int attemps)
{
    char auxStr[256];
    int i, retorno = -1;
    float auxFloat;

    for(i=0;i<attemps;i++)
    {
        if (get_stringFlotantes(requestMessage,auxStr))
        {
            printf ("%s",errorMessage);
            break;
            continue;

        }
        auxFloat = atof(auxStr);
        if(auxFloat < lowLimit || auxFloat > hiLimit)
        {
            printf ("%s",errorMessage);
            continue;

        }
        *input = auxFloat;
        retorno = 0;
        break;

    }
    return retorno;

}

int get_validAlfaNumerico(char *requestMessage,char *errorMessage, char *errorMessageLenght,char *input, int maxLenght,int attemps)
{
    int i;
    int retorno=-1;
    char buffer[1024];

    for(i=0;i<attemps;i++)
    {
        if (get_stringAlfaNumerico(requestMessage,buffer))
        {
            printf ("%s",errorMessage);
            continue;
        }
        if(strlen(buffer) >= maxLenght)
        {
            printf ("%s",errorMessageLenght);
            continue;

        }
        retorno=0;
        strcpy(input,buffer);
        break;
    }
    return retorno;
}

