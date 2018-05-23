#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"


/** \brief fgets con modificacion por \0 y LF
 *
 * \param buffer con dato a ingresar
 * \param limite de caracteres que puede tener el dato
 * \param puntero a archivo
 * \return VOID
 *
 */
void myFgets(char* buffer, int limite,FILE* archivo)
{
    int i=0;
    fgets(buffer, limite,archivo);
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
        for( ; intentos>0; intentos--)
        {
            myFgets(buffer, limite,stdin);

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
        if((buffer[i] < 'a' || buffer[i] > 'z') && buffer[i] != 32 && (buffer[i] < 'A' || buffer[i] > 'Z'))
        {
            retorno = -1;
            break;
        }
        i++;
    }
    return retorno;
}

/** \brief Toma un dato a ingresar como char de tipo UnsignedInt
 *
 * \param destino a donde se guarda el string
 * \param mensaje a imprimir al usuario
 * \param mensaje de error a imprimir al usuario en caso de que haya un problema
 * \param numero de intentos para que trate de ingresar de nuevo
 * \param limite de caracteres que puede tener el string
 * \return -1 error, 0 OK
 *
 */

int val_getUnsignedInt(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ;intentos>0;intentos--)
        {

            myFgets(buffer, limite ,stdin);

            if(val_validarUnsignedInt(buffer) == -1)
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

/** \brief Revisa que el string sean solo numeros con o sin signos
 *
 * \param buffer conteniendo el int como string
 * \return -1 error, 0 OK
 *
 */

int val_validarUnsignedInt(char* buffer)
{
    int i=0;
    int retorno = 0;
    int flagPunto = 0;
    while(buffer[i] != '\0')
    {
        if(buffer[i] < '0' || buffer[i] > '9' )
        {
            retorno = -1;
            break;
        }
        else
        {
            if(buffer[i] == '-' && i != 0)
            {
                retorno = -1;
                break;
            }
            else if(buffer[i] == '.')
            {
                flagPunto++;
                if(flagPunto > 1)
                {
                    retorno = -1;
                    break;
                }
            }
        }
        i++;
    }
    return retorno;
}

/** \brief Toma un dato a ingresar como char de tipo int
 *
 * \param destino a donde se guarda el string
 * \param mensaje a imprimir al usuario
 * \param mensaje de error a imprimir al usuario en caso de que haya un problema
 * \param numero de intentos para que trate de ingresar de nuevo
 * \param limite de caracteres que puede tener el string
 * \return -1 error, 0 OK
 *
 */

int val_getInt(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ;intentos>0;intentos--)
        {
            myFgets(buffer, limite ,stdin);

            if(val_validarInt(buffer) == -1)
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

/** \brief Revisa que el string sean solo numeros
 *
 * \param buffer conteniendo el int como string
 * \return -1 error, 0 OK
 *
 */

int val_validarInt(char* buffer)
{
    int i=0;
    int retorno = 0;

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

/** \brief Toma un dato a ingresar como char de tipo float
 *
 * \param destino a donde se guarda el string
 * \param mensaje a imprimir al usuario
 * \param mensaje de error a imprimir al usuario en caso de que haya un problema
 * \param numero de intentos para que trate de ingresar de nuevo
 * \param limite de caracteres que puede tener el string
 * \return -1 error, 0 OK
 *
 */

int val_getFloat(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ;intentos>0;intentos--)
        {

            myFgets(buffer, limite ,stdin);

            if(val_validarFloat(buffer) == -1)
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

/** \brief Revisa que el string sean numeros  y 1 punto
 *
 * \param buffer conteniendo el int como string
 * \return -1 error, 0 OK
 *
 */
int val_validarFloat(char* buffer)
{
    int i=0;
    int retorno = 0;
    int flagPunto = 0;
    while(buffer[i] != '\0')
    {
        if((buffer[i] < '0' || buffer[i] > '9') && buffer[i] != '.' && buffer[i] != '-' )
        {
            retorno = -1;
            break;
        }
        else
        {
            if(buffer[i] == '-' && i != 0)
            {
                retorno = -1;
                break;
            }
            else if(buffer[i] == '.')
            {
                flagPunto++;
                if(flagPunto > 1)
                {
                    retorno = -1;
                    break;
                }
            }
        }
        i++;
    }
    return retorno;
}

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

int val_validarEmail(char* buffer)
{
    int i=0;
    int retorno = 0;
    while(buffer[i] != '\0')
    {
        if((buffer[i] < 'a' || buffer[i] > 'z' ) && buffer[i] != 32 && buffer[i] != 64 && buffer[i] != 45 && buffer[i] != 22 &&(buffer[i] < 'A' || buffer[i] > 'Z' ))
        {
            retorno = -1;
            break;
        }
        i++;
    }
    return retorno;
}

int getDni(char* destino, char* mensaje, char* mensajeError, int intentos, int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);

        for( ;intentos>0;intentos--)
        {
            myFgets(buffer, limite ,stdin);

            if(validarDni(buffer) == -1)
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

int validarDni(char* buffer)
{
    int i=0;
    int retorno = 0;

    while(buffer[i] != '\0')
    {
        if(buffer[i] < '0' || buffer[i] > '9' || strlen(buffer)>8 || strlen(buffer)<7)
        {
            retorno = -1;
            break;
        }
        i++;
    }
    return retorno;
}

/**
 * \brief Solicita un texto al usuario verifica que tenga solo letras y numeros y lo almacena
 * \param destino Espacio de memoria asignado para guardar lo que se ingresa
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje a ser mostrado en caso de error
 * \param intentos Es la cantidad de veces que se puede cometer un error
 * \param len es la cantidad maxima de caracteres a guardar
 * \return 0 si se ingreso correctamente
 * dentro de la funcion se valida que no se ingresen caracteres incorrectos
 * en ese caso se imprime el mensaje de error
 *
 */
int val_getAlfanumerico(char* destino, char* mensaje, char* mensajeError, int intentos,int len)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && len > 0 && len < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ;intentos>0;intentos--)
        {
            myFgets(buffer, len ,stdin);

            if(val_validarAlfanumerico(buffer) == -1)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,len);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param buffer Array con la cadena a ser analizada
 * \return 0 si contiene solo letras y espacios -1 en caso contario
 *  los espacios sirven para el caso de descripciones o datos que lo necesiten
 *  como los apellidos compuestos
 *
 */

int val_validarAlfanumerico(char* buffer)
{
    int i=0;
    int retorno = 0;
    while(buffer[i] != '\0')
    {
        if((buffer[i] < 'a' || buffer[i] > 'z') && (buffer[i] < 'A' || buffer[i] > 'Z' ) && buffer[i] != 32 && (buffer[i] < '0' || buffer[i] > '9'))
        {
            retorno = -1;
            break;
        }
        i++;
    }
    return retorno;
}
