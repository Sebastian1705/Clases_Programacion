#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"

#define MAX_INPUT_BUFFER 4096

/** \brief fgets con modificacion por \0 y LF
 *
 * \param buffer con dato a ingresar
 * \param limite de caracteres que puede tener el dato
 * \param puntero a archivo
 * \return VOID
 *
 */
void myFgets(char* buffer, int limite ,FILE* archivo)
{
    int i=0;
    fflush(stdin);
    fgets(buffer, limite ,archivo);
    buffer[limite-1] = '\0';
    while(buffer[i] != '\0')
    {
        if(buffer[i] == 10)//10 -> LF
        {
            buffer[i] = '\0';
            break;
        }
        i++;
    }
}

/**
 * \brief Solicita un numero al usuario y valida que sea int
 * \param input puntero al lugar donde se cargará el numero ingresado
 * \param Es el mensaje a ser mostrado para solicitar el dato
 * \param Es el mensaje a ser mostrado en caso de error
 * \param Indica la cantidad de reintentos ante un error
 * \param Limite de caracteres a cargar
 * \return 0 si consiguio el Numero -1 si no
 *
 */
int val_getInt(int* destino, char* mensaje,char* mensajeError,int intentos,int lowLimit, int hiLimit)
{
    int retorno = -1,aux;
    char buffer[MAX_INPUT_BUFFER];

    printf(mensaje);
    for( ; intentos>0; intentos--)
    {
        myFgets(buffer, MAX_INPUT_BUFFER,stdin);

        if(val_validarInt(buffer) == -1)
        {
            printf(mensajeError);
            continue;
        }
        aux = atoi(buffer);
        if(aux < lowLimit || aux > hiLimit)
        {
            printf ("%s",mensajeError);
            continue;
        }
        else
        {
            *destino = aux;
            retorno = 0;
            break;
        }
    }
    return retorno;
}

/**
 * \brief Solicita un numero al usuario y valida que sea unsigned int
 * \param input puntero al lugar donde se cargará el numero ingresado
 * \param Es el mensaje a ser mostrado para solicitar el dato
 * \param Es el mensaje a ser mostrado en caso de error
 * \param Indica la cantidad de reintentos ante un error
 * \param Limite de caracteres a cargar
 * \return 0 si consiguio el Numero -1 si no
 *
 */
int val_getUnsignedInt(int* destino, char* mensaje,char* mensajeError,int intentos,int lowLimit, int hiLimit)
{
    int retorno = -1,aux;
    char buffer[MAX_INPUT_BUFFER];

    printf(mensaje);
    for( ; intentos>0; intentos--)
    {
        myFgets(buffer, MAX_INPUT_BUFFER,stdin);

        if(val_soloNumeros(buffer) == -1)
        {
            printf(mensajeError);
            continue;
        }
        aux = atoi(buffer);
        if(aux < lowLimit || aux > hiLimit)
        {
            printf ("%s",mensajeError);
            continue;
        }
        else
        {
            *destino = aux;
            retorno = 0;
            break;
        }
    }
    return retorno;
}

/**
 * \brief Verifica si el valor recibido contiene solo numeros flotantes
 * \param float* destino puntero con valor a pasar por referencia
 * \param Es el mensaje a ser mostrado para solicitar el dato
 * \param Es el mensaje a ser mostrado en caso de error
 * \param Indica la cantidad de reintentos ante un error
 * \param Limite minimo para numero ingresado
 * \param Limite maximo para numero ingresado
 * \return 0 si es OK y -1 si no lo es
 *
 */
int val_getFloat(float* destino, char* mensaje,char* mensajeError,int intentos,float lowLimit, float hiLimit)
{
    int retorno = -1;
    float aux;
    char buffer[MAX_INPUT_BUFFER];

    printf(mensaje);
    for( ; intentos>0; intentos--)
    {
        myFgets(buffer, MAX_INPUT_BUFFER,stdin);

        if(val_esNumericoFlotante(buffer) == -1)
        {
            printf(mensajeError);
            continue;
        }
        aux = atof(buffer);
        if(aux < lowLimit || aux > hiLimit)
        {
            printf ("%s",mensajeError);
            continue;
        }
        else
        {
            *destino = aux;
            retorno = 0;
            break;
        }
    }
    return retorno;
}

/**
 * \brief Verifica si el valor recibido contiene solo numeros flotantes
 * \param float* destino puntero con valor a pasar por referencia
 * \param Es el mensaje a ser mostrado para solicitar el dato
 * \param Es el mensaje a ser mostrado en caso de error
 * \param Indica la cantidad de reintentos ante un error
 * \param Limite minimo para numero ingresado
 * \param Limite maximo para numero ingresado
 * \return 0 si es OK y -1 si no lo es
 *
 */
int val_getUnsignedFloat(float* destino, char* mensaje,char* mensajeError,int intentos,float lowLimit, float hiLimit)
{
    int retorno = -1;
    float aux;
    char buffer[MAX_INPUT_BUFFER];

    printf(mensaje);
    for( ; intentos>0; intentos--)
    {
        myFgets(buffer, MAX_INPUT_BUFFER,stdin);

        if(val_esUnsignedFloat(buffer) == -1)
        {
            printf(mensajeError);
            continue;
        }
        aux = atof(buffer);
        if(aux < lowLimit || aux > hiLimit)
        {
            printf ("%s",mensajeError);
            continue;
        }
        else
        {
            *destino = aux;
            retorno = 0;
            break;
        }
    }
    return retorno;
}

/** \brief Toma un dato a ingresar de tipo string
 *
 * \param destino a donde se guarda el string
 * \param mensaje a imprimir al usuario
 * \param mensaje de error a imprimir al usuario en caso de que haya un problema
 * \param numero de intentos para que trate de ingresar de nuevo
 * \param limite de caracteres que puede tener el string
 * \return -1 error, 0 OK
 *
 */
int val_getString(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ;intentos>0;intentos--)
        {
            myFgets(buffer, limite ,stdin);

            if(val_validarString(buffer) == -1)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/**
 * \brief Verifica si el valor recibido es solo letras
 * \param input puntero al lugar donde se cargará el numero ingresado
 * \param Es el mensaje a ser mostrado para solicitar el dato
 * \param Es el mensaje a ser mostrado en caso de error
 * \param Indica la cantidad de reintentos ante un error
 * \param Limite
 * \return 0 si es OK y -1 si no lo es
 *
 */
int val_getNombre(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ;intentos>0;intentos--)
        {
            myFgets(buffer, limite ,stdin);

            if(val_esSoloLetras(buffer) == -1)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/**
 * \brief Verifica si el valor recibido es alfanumerico
 * \param input puntero al lugar donde se cargará el numero ingresado
 * \param Es el mensaje a ser mostrado para solicitar el dato
 * \param Es el mensaje a ser mostrado en caso de error
 * \param Indica la cantidad de reintentos ante un error
 * \param Limite
 * \return 0 si es OK y -1 si no lo es
 *
 */
int val_getAlfanumerico(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ;intentos>0;intentos--)
        {
            myFgets(buffer, limite ,stdin);

            if(val_esAlfaNumerico(buffer) == 0)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/**
 * \brief Verifica si el valor recibido es DNI
 * \param input puntero al lugar donde se cargará el numero ingresado
 * \param Es el mensaje a ser mostrado para solicitar el dato
 * \param Es el mensaje a ser mostrado en caso de error
 * \param Indica la cantidad de reintentos ante un error
 * \param Limite
 * \return 0 si es OK y -1 si no lo es
 *
 */
int val_getDni(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ;intentos>0;intentos--)
        {
            myFgets(buffer, limite ,stdin);

            if(val_esDni(buffer) == -1)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Toma un dato a ingresar de tipo string
 *
 * \param destino a donde se guarda el string
 * \param mensaje a imprimir al usuario
 * \param mensaje de error a imprimir al usuario en caso de que haya un problema
 * \param numero de intentos para que trate de ingresar de nuevo
 * \param limite de caracteres que puede tener el string
 * \return -1 error, 0 OK
 *
 */
int val_getDate(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ;intentos>0;intentos--)
        {
            myFgets(buffer, limite ,stdin);

            if(val_validarDate(buffer) == -1)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Toma un dato a ingresar de tipo string
 *
 * \param destino a donde se guarda el string
 * \param mensaje a imprimir al usuario
 * \param mensaje de error a imprimir al usuario en caso de que haya un problema
 * \param numero de intentos para que trate de ingresar de nuevo
 * \param limite de caracteres que puede tener el string
 * \return -1 error, 0 OK
 *
 */
int val_getTime(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ;intentos>0;intentos--)
        {
            myFgets(buffer, limite ,stdin);

            if(val_validarTime(buffer) == -1)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Toma un dato a ingresar de tipo string
 *
 * \param destino a donde se guarda el string
 * \param mensaje a imprimir al usuario
 * \param mensaje de error a imprimir al usuario en caso de que haya un problema
 * \param numero de intentos para que trate de ingresar de nuevo
 * \param limite de caracteres que puede tener el string
 * \return -1 error, 0 OK
 *
 */
int val_getEmail(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ;intentos>0;intentos--)
        {
            myFgets(buffer, limite ,stdin);

            if(val_validarEmail(buffer) == -1)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/*******************************************************************************/

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int val_esSoloLetras(char* buffer)
{
    int i=0;
    int retorno = 0;
    while(buffer[i] != '\0')
    {
        if((buffer[i] < 'a' || buffer[i] > 'z') && (buffer[i] < 'A' || buffer[i] > 'Z'))
        {
            retorno = -1;
            break;
        }
        i++;
    }
    return retorno;
}

/** \brief Revisa que el string ingresado no tenga caracteres invalidos
 *
 * \param buffer conteniendo el string
 * \return -1 error, 0 OK
 *
 */
int val_validarString(char* buffer)
{
    int i=0;
    int retorno = 0;
    while(buffer[i] != '\0')
    {
        if((buffer[i] < 'a' || buffer[i] > 'z') && (buffer[i] < 'A' || buffer[i] > 'Z') && buffer[i] != ' ' && (buffer[i] != '-')) //agregar los caracteres a permitir
        {
            retorno = -1;
            break;
        }
        i++;
    }
    return retorno;
}

/** \brief Revisa que el string ingresado no tenga caracteres invalidos
 *
 * \param buffer conteniendo el string
 * \return -1 error, 0 OK
 *
 */
int val_validarDate(char str[])
{
   int i=0;
   int cantidadBarras=0;
   while(str[i] != '\0')
   {
       if (str[i] == '/' && cantidadBarras < 2)
       {
           cantidadBarras++;
           i++;
           continue;
       }
       if(str[i] < '0' || str[i] > '9')
           return -1;
       i++;
   }
   return 0;
}

/** \brief Revisa que el string ingresado no tenga caracteres invalidos
 *
 * \param buffer conteniendo el string
 * \return -1 error, 0 OK
 *
 */
int val_validarTime(char str[])
{
   int i=0;
   int cantidadDosPuntos=0;
   while(str[i] != '\0')
   {
       if (str[i] == ':' && cantidadDosPuntos == 0)
       {
           cantidadDosPuntos++;
           i++;
           continue;
       }
       if(str[i] < '0' || str[i] > '9')
           return -1;
       i++;
   }
   return 0;
}

/** \brief Revisa que el string ingresado no tenga caracteres invalidos
 *
 * \param buffer conteniendo el string
 * \return -1 error, 0 OK
 *
 */
int val_validarEmail(char* buffer)
{
    int i=0;
    int retorno = 0;
    int cantidadArroba=0;

    while(buffer[i] != '\0')
    {
        if(buffer[i] == ' ' || (buffer[i] == '@' && cantidadArroba < 0))
        {
            retorno = -1;
            break;
        }
        if (buffer[i] == '@' && cantidadArroba == 0)
        {
            cantidadArroba++;
            i++;
            continue;
        }
        i++;
    }
    return retorno;
}

/**
 * \brief Verifica si el valor recibido es DNI
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */
int val_esDni(char* buffer)
{
    int retorno = 0,i=0;

    while(buffer[i] != '\0')
    {
        if(buffer[i] < '0' || buffer[i] > '9' || strlen(buffer) < 7 || strlen(buffer) > 8)
        {
            retorno = -1;
            break;
        }
        i++;
    }
    return retorno;
}

/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */
int val_soloNumeros(char* buffer)
{
    int retorno = 0,i=0;

    while(buffer[i] != '\0')
    {
        if(buffer[i] < '0' || buffer[i] > '9')
        {
            retorno = -1;
            break;
        }
        i++;
    }
    return retorno;
}

/**
 * \brief Verifica si el valor recibido es entero aceptando negativos
 * \param buffer Array con la cadena a ser analizada
 * \return 0 si es númerico y -1 si no lo es
 *
 */
int val_validarInt(char buffer[])
{
   int i=0;

   while(buffer[i] != '\0')
   {
       if (i == 0 && buffer[i] == '-')
       {
           i++;
           continue;
       }
       if(buffer[i] < '0' || buffer[i] > '9')
           return -1;
       i++;
   }
   return 0;
}

/**
 * \brief Verifica si el valor recibido es numérico aceptando flotantes
 * \param str Array con la cadena a ser analizada
 * \return 0 si es númerico y -1 si no lo es
 *
 */
int val_esNumericoFlotante(char str[])
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

/**
 * \brief Verifica si el valor recibido es numérico aceptando flotantes positivos
 * \param str Array con la cadena a ser analizada
 * \return 0 si es númerico y -1 si no lo es
 *
 */
int val_esUnsignedFloat(char str[])
{
   int i=0;
   int cantidadPuntos=0;
   while(str[i] != '\0')
   {
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
/**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 *
 */
int val_esAlfaNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
           return 0;
       i++;
   }
   return 1;
}




/*********************************************///FUNCIONES PARA IMPORTAR


/**
 * \brief Solicita un numero entero al usuario y lo valida
 * \param input puntero al lugar donde se cargará el numero ingresado
 * \param Es el mensaje a ser mostrado para solicitar el dato
 * \param Es el mensaje a ser mostrado en caso de error
 * \param Indica la cantidad de reintentos ante un error
 * \param Limite de caracteres a cargar
 * \return 0 si consiguio el Numero -1 si no
 *
 */
char val_getUnsignedIntFromFile(char* destino, int lowLimit, int hiLimit)
{
    int retorno = 0;

    if(val_soloNumeros(destino) == -1 || atoi(destino) < lowLimit || atoi(destino) > hiLimit)
    {
        retorno = -1;
    }
    return retorno;
}


int val_getFloatFromFile(char* destino, float lowLimit, float hiLimit)
{
    int retorno = 0;

    if(val_esNumericoFlotante(destino) == -1 || atof(destino) < lowLimit || atof(destino) > hiLimit)
    {
        retorno = -1;
    }
    return retorno;
}


