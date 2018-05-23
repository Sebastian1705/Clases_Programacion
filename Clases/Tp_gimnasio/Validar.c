#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validar.h"


/** \brief Recibe un buffer y en la ultima posicion coloca un \0
 * \param buffer posicion de memoria del dato a guarda
 * \param limite cantidad maxima de cacteres
 * \param FILE permite recir datos
 *
 */
void val_myFgets(char* buffer, int limite, FILE* archivo)
{
    int i=0;
    fflush(archivo);
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

/*****************************************************/

/** \brief solicita un dato al usuario lo valida y luego lo almacena
 * \param destino espacio de memoria para guardar el dato ingresado
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError mensaje a mostrar en caso de error
 * \param intentos cantidad de veces que se puede cometer un error
 * \param limite cantidad de caracteres del string
 * \return 0 OK -1 en caso de error
 *
 */
int val_getUnsignedInt(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ; intentos>0; intentos--)
        {

            val_myFgets(buffer, limite,stdin);

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

/*****************************************************/

/** \brief Valida que solo se ingresen numeros
 * \param buffer cadena a ser analizada
 * \return 0 OK -1 en caso de error
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

/*****************************************************/

/** \brief Solicita un dato al usuario, valida que contenga solo letras y lo almacena
 * \param destino espacio de memoria asignado para almacenar el dato
 * \param mensaje Es mensaje para el usuario
 * \param mensajeError mensaje a ser mostrado en caso de error
 * \param intentos cantidad de veces que se puede cometer un error
 * \param limite cantidad de caracteres del string
 * \return 0 OK -1 en caso de error
 *
 */
int val_getString(char* destino, char* mensaje, char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ; intentos>0; intentos--)
        {
            val_myFgets(buffer, limite,stdin);

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

/*****************************************************/

/** \brief Valida que la cadena contenga solo letras
 * \param buffer cadena a ser analizada
 * \return 0 OK -1 en caso de error
 *
 */
int val_validarString(char* buffer)
{
    int i=0;
    int retorno = 0;
    while(buffer[i] != '\0')
    {
        if((buffer[i] < 'a' || buffer[i] > 'z') && (buffer[i] < 'A' || buffer[i] > 'Z') && buffer[i] != ' ')
        {
            retorno = -1;
            break;
        }
        i++;
    }
    return retorno;
}

/*****************************************************/

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
            val_myFgets(buffer, len ,stdin);

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

/*****************************************************/

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

/*****************************************************/

/**
 * \brief Borra la pantalla
 * \param void
 * \return Void
 *
 */
void val_cleanScreen()
{
    system("cls");
}

/*****************************************************/

int val_validarLink(char* buffer)
{
    int i=0;
    int retorno = 0;
    while(buffer[i] != '\0')
    {
        if((buffer[i] < 'a' || buffer[i] > 'z') && (buffer[i] < 'A' || buffer[i] > 'Z' ) && buffer[i] != 32 && buffer[i] != '.')
        {
            retorno = -1;
            break;
        }
        i++;
    }
    return retorno;
}

/*****************************************************/

int val_getLink(char* destino, char* mensaje, char* mensajeError, int intentos,int len)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && len > 0 && len < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ;intentos>0;intentos--)
        {
            val_myFgets(buffer, len ,stdin);

            if(val_validarLink(buffer) == -1)
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
