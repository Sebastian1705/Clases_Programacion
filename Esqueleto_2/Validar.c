#include <stdio.h>
#include <stdlib.h>
#include "Validar.h"
#include <string.h>

/**
 * \brief Guarda el dato ingresado por el usuario
 * \param buffer Corresponde a la posicion de memoria del array
 * \param len Es la cantidad de elementos que contiene el array
 * \param FILE permite recibir entradas por teclado
 * \return void
 *
 */
void val_myFgets(char* buffer, int len ,FILE* archivo)
{
    int i=0;
    fgets(buffer, len ,archivo);
    buffer[len-1] = '\0';
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
 * \brief Solicita un texto al usuario
 * \param destino Espacio de memoria asignado para guardar lo que se ingresa
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje a ser mostrado en caso de error
 * \param intentos Es la cantidad de veces que se puede cometer un error
 * \param len es la cantidad maxima de caracteres a guardar
 * \return 0 si se ingreso correctamente
 * dentro de la funcion se valida que no se ingresen caracteres incorrectos
 * en ese caso se imprime el mensaje de error
 */
int val_getCadena(char* destino, char* mensaje, char* mensajeError, int intentos,int len)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && len > 0 && len < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ;intentos>0;intentos--)
        {
            val_myFgets(buffer, len ,stdin);

            if(val_validarCadena(buffer) == -1)
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
 * \return 0 si contiene solo letras -1 en caso contario
 *
 */
int val_validarCadena(char* buffer)
{
    int i=0;
    int retorno = 0;
    while(buffer[i] != '\0')
    {
        if((buffer[i] < 'a' || buffer[i] > 'z') && (buffer[i] < 'A' || buffer[i] > 'Z' ))
        {
            retorno = -1;
            break;
        }
        i++;
    }
    return retorno;
}

/**
 * \brief Solicita un texto al usuario
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
int val_getCadenaConEspacio(char* destino, char* mensaje, char* mensajeError, int intentos,int len)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && len > 0 && len < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ;intentos>0;intentos--)
        {
            val_myFgets(buffer, len ,stdin);

            if(val_validarCadena(buffer) == -1)
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
int val_validarCadenaConEspacio(char* buffer)
{
    int i=0;
    int retorno = 0;
    while(buffer[i] != '\0')
    {
        if((buffer[i] < 'a' || buffer[i] > 'z') && (buffer[i] < 'A' || buffer[i] > 'Z' ) && buffer[i] != 32)
        {
            retorno = -1;
            break;
        }
        i++;
    }
    return retorno;
}

/**
 * \brief Verifica si el dato recibido es del tipo flotante
 * \param buffer es la cadena a ser analizada
 * \return 0 si contiene caracteres que conforman un flotante -1 en caso contario
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

/**
 * \brief Solicita al usuario que ingrese un numero flotante
 * \param destino Es la posicion donde se almacenara el valor recibido
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje a ser mostrado en caso de error
 * \param intentos Es la cantidad de veces que se puede cometer un error
 * \param len es la cantidad maxima de caracteres a guardar
 * \return 0 si el usuario ingresa un flotante -1 en caso contario
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

            val_myFgets(buffer, limite ,stdin);

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


/**
 * \brief Solicita al usuario que ingrese un numero entero
 * \param destino Es la posicion donde se almacenara el valor recibido
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje a ser mostrado en caso de error
 * \param intentos Es la cantidad de veces que se puede cometer un error
 * \param len es la cantidad maxima de caracteres a guardar
 * \return 0 si el usuario ingresa un entero -1 en caso contario
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

            val_myFgets(buffer, limite ,stdin);

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


/**
 * \brief Verifica si el dato recibido es del tipo entero
 * \param buffer es la cadena a ser analizada
 * \return 0 si contiene caracteres que conforman un entero -1 en caso de error
 *
 */
int val_validarInt(char* buffer)
{
    int i=0;
    int retorno = 0;

    while(buffer[i] != '\0')
    {
        if(buffer[i] < '0' || buffer[i] > '9' )
        {
            retorno = -1;
            break;
        }
      i++;
    }
    return retorno;
}

/**
 * \brief Solicita al usuario que ingrese un dni y lo guarda
 * \param destino Es la posicion donde se almacenara el valor recibido
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje a ser mostrado en caso de error
 * \param intentos Es la cantidad de veces que se puede cometer un error
 * \param len es la cantidad maxima de caracteres a guardar
 * \return 0 si el usuario ingresa un entero -1 en caso contario
 *
 */
int val_getDni(char* destino, char* mensaje, char* mensajeError, int intentos, int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);

        for( ;intentos>0;intentos--)
        {
            val_myFgets(buffer, limite ,stdin);

            if(val_validarDni(buffer) == -1)
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
 * \brief Valida que el tipo y cantidad de caracteres correspondientes
 * \param buffer es la cadena de caracteres a analizar
 * \return 0 si correcto -1 en caso de error
 *
 */
int val_validarDni(char* buffer)
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

