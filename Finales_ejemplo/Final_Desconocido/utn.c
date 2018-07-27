#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utn.h"

/**
 * \brief Genera un número aleatorio
 * \param desde Número aleatorio mínimo
 * \param hasta Número aleatorio máximo
 * \param iniciar Indica si se trata del primer número solicitado 1 indica que si
 * \return retorna el número aleatorio generado
 *
 */
char getNumeroAleatorio(int desde , int hasta, int iniciar)
{
    if(iniciar)
        srand (time(NULL));
    return desde + (rand() % (hasta + 1 - desde)) ;
}


/** \brief
 *
 * \param mensaje char*
 * \return retorna char
 *
 */
char getChar(char* mensaje)
{
    char auxiliar;
    printf("%s",mensaje);
    clearStdin();
    scanf("%c",&auxiliar);
    return auxiliar;
}

/** \brief
 *
 * \param str char*
 * \return 0 si es float, -1 si no es float
 *
 */
int esFloat(char* str)
{
    int i=0;
    int retorno=0;
    int cantPuntos=0;
    int len=strlen(str)-1;

    while(i<len && cantPuntos<=1)
    {
        if(str[i]<'0' || str[i]>'9')
        {
            if(i==0 && (str[i]=='-' ||str[i]=='+'))
            {
                i++;
                continue;
            }
            if(str[i]=='.')
            {
                cantPuntos++;
                i++;
                continue;
            }
            retorno=-1;
            break;
        }
        i++;
    }
    return retorno;
}

/** \brief
 *
 * \param str char*
 * \return retorna 0 si es entero,-1 si no es entero
 *
 */
int esEntero(char* str)
{
    int i=0;
    int retorno=0;
    int len=strlen(str)-1;

    while(i<len)
    {
        if(str[i]<'0' || str[i]>'9')
        {
            if((str[i]=='-' || str[i]=='+' )&& i==0)
            {
                retorno=0;
            }
            else
            {
                retorno=-1;
                break;
            }
        }
        i++;
    }
    return retorno;
}

/** \brief
 *
 * \param str char*
 * \return 0 si es alfanumerico, -1 si no es alfanumerico
 *
 */
int esAlfaNumerico(char* str)
{
   int i=0;
   int retorno=0;
   int len=strlen(str)-1;

   while(i<len)
   {
       if(str[i] != ' ' && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
       {
           retorno=-1;
           break;
       }
       i++;
   }
   return retorno;
}

/** \brief
 *
 * \param str[] char
 * \return retorna 0 si solo contiene letras y espacios, -1 si no
 *
 */
int esLetras(char str[])
{
   int i=0;
   int retorno=0;
   int len=strlen(str)-1;

   while(i<len)
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
       {
           retorno=-1;
           break;
       }
       i++;
   }
   return retorno;
}

/** \brief
 *
 * \param str char*: array donde se guarda el string
 * \param len: longitud del array
 * \param mensaje: mensaje de pedido
 * \param mensajeError: mensaje de error
 * \param intentos: cantidad de intentos
 * \return retorna 0 si se consiguio el array, -1 si no
 *
 */
int getStringAlfanumerico(char* str,int len,char* mensaje,char* mensajeError,int intentos)
{
    int retorno=0;
    char aux[100];
    printf("%s",mensaje);

    while(intentos>0)
    {

        fflush(stdin);
        fgets(aux,len,stdin);

        if(!esAlfaNumerico(aux) && strlen(aux)>2)
        {
            strcpy(str,aux);
            strtok(str,"\n");
            break;
        }
        else
        {
            retorno=-1;
            printf("\n%s",mensajeError);
        }
        intentos--;
    }

    return retorno;
}

/** \brief
 *
 * \param str:array donde se guarda el string
 * \param len: longitud del array
 * \param mensaje: mensaje de pedido
 * \param mensajeError: mensaje de error
 * \param intentos:cantidad de intentos
 * \return retorna 0 si se consiguio el string, -1 si no
 *
 */
int getStringSoloLetras(char* str,int len,char* mensaje,char* mensajeError,int intentos)
{
    int retorno=0;
    char aux[100];

    while(intentos>0)
    {

        printf("%s",mensaje);
        fflush(stdin);
        fgets(aux,len,stdin);

        if(!esLetras(aux)&&strlen(aux)>2)
        {
            strcpy(str,aux);
            strtok(str,"\n");
            retorno=0;
            break;
        }
        else
        {
            retorno=-1;
            printf("\n%s",mensajeError);
        }
        intentos--;
    }

    return retorno;
}

/** \brief
 *
 * \param mensaje: mensaje de pedido
 * \param input: array donde se guarda el string
 * \return void
 *
 */
void getString(char* mensaje,char* input)
{
    char aux[256];

    printf("%s",mensaje);
    fflush(stdin);
    fgets(aux,256,stdin);
    strcpy(input,aux);
    strtok(input,"\n");
}

/** \brief
 *
 * \param mensaje[]: mensaje de pedido
 * \param input[]: array donde se guarda el numero en chars
 * \return int
 *
 */
int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    int retorno=-1;

    getString(mensaje,aux);
    if(!esEntero(aux)&& strcmp(aux,"\n\0"))
    {

        strcpy(input,aux);
        strtok(input,"\n");
        retorno=0;
    }
    return retorno;
}

/** \brief
 *
 * \param mensaje[]: mensaje de pedido
 * \param input[]: array donde se guarda el numero en chars
 * \return int
 *
 */
int getStringNumerosFlotantes(char mensaje[],char input[])
{
    int retorno=-1;
    char aux[256];
    getString(mensaje,aux);
    if(!esFloat(aux))
    {
        strcpy(input,aux);
        strtok(input,"\n");
        retorno=0;
    }
    return retorno;
}

/** \brief
 *
 * \param mensaje: mensaje pedido
 * \param mensajeError: mensaje de error
 * \param input: int donde se guarda el entero validado
 * \param desde: limite inferior
 * \param hasta int: limite superior
 * \param intentos: cantidad intentos
 * \return retorna 0 si se consigue el numero validado, -1 si se terminan los intentos
 *
 */
int getValidInt(char* mensaje,char* mensajeError, int* input,int desde, int hasta,int intentos)
{
    char auxStr[256];
    int auxInt;
    int i;
    int retorno=-1;

    for(i=0;i<intentos;i++)
    {
        if (getStringNumeros(mensaje,auxStr))
        {
            printf ("%s",mensajeError);
            continue;
        }
        auxInt = atoi(auxStr);

        if(auxInt < desde || auxInt > hasta)
        {
            printf ("%s",mensajeError);
            continue;
        }
        *input = auxInt;
        retorno = 0;
        break;

    }
    return retorno;

}

/** \brief
 *
 * \param mensaje: mensaje pedido
 * \param mensajeError: mensaje error
 * \param input: float donde se guarda el numero validado
 * \param desde: limite inferior
 * \param hasta: limite superior
 * \param intentos: cantidad intentos
 * \return retorna 0 si se consigue el numero validado, -1 si se terminan los intentos
 *
 */
int getValidFloat(char* mensaje,char* mensajeError, float* input,float desde, float hasta,int intentos)
{
    char auxStr[256];
    int i;
    int retorno=-1;
    float auxInt;

    for(i=0;i<intentos;i++)
    {
        if (getStringNumerosFlotantes(mensaje,auxStr))
        {
            printf ("%s",mensajeError);
            continue;

        }
        auxInt = atof(auxStr);
        if(auxInt < desde || auxInt > hasta)
        {
            printf ("%s",mensajeError);
            continue;

        }
        *input = auxInt;
        retorno = 0;
        break;
    }
    return retorno;

}

void clearStdin(void)
{
    setbuf(stdin,NULL);
}

void pause(void)
{
    getChar("");
}






/**
 * \brief Hace un clear, similar al system("clear")
 * \param -
 * \return -
 *
 */
void clearScreen(void)
{
    system("cls"); //system("cls");
}

