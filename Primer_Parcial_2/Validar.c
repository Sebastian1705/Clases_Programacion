#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validar.h"

/** \brief Recibe un buffer y en la ultima posicion coloca un \0
 * \param buffer posicion de memoria del dato a guardar
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
 * \param limite cantidad maxima de caracteres del string
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
 * \param limite cantidad maxima de caracteres del string
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

/** \brief Valida que solo se ingresen numeros, un punto, y - solo en la primera posicion
 * \param buffer cadena de caracteres a ser analizada
 * \return 0 OK -1 en caso de error
 * \return
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

/*****************************************************/

/** \brief Valida que el string ingresado corresponga un flotante
 * \param destino donde se guarda el string
 * \param mensaje, mensaje para el usuario
 * \param mensajeError mensaje a mostrar en caso de error
 * \param intentos, cantidad de veces antes de mostrar error
 * \param limite, tamaño del string
 * \return 0 OK -1 en caso de error
 *
 */
int val_getFloat(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ; intentos>0; intentos--)
        {

            val_myFgets(buffer, limite,stdin);

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

/*****************************************************/

/** \brief solicita un dato, valida que tenga formato de cuit y lo almacena
 * \param destino espacio asignado para guardar el dato ingresado despues de validarlo
 * \param mensaje, mensaje a ser mostrado
 * \param mensajeError mensaje a mostrar en caso de error
 * \param intentos cantidad de veces que se puede cometer un error
 * \param limite cantidad maxima de caracteres
 * \return 0 OK -1 en caso de error
 *
 */
int val_getCuit(char* destino, char* mensaje,char* mensajeError, int intentos, int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ; intentos>0; intentos--)
        {
            val_myFgets(buffer, limite,stdin);

            if(val_validarCuit(buffer) == -1)
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

/** \brief Valida que solo se ingresen numeros y guiones
 * \param buffer cadena de caracteres a analizar
 * \return 0 OK -1 en caso de error
 *
 */
int val_validarCuit(char* buffer)
{
    int i=0;
    int retorno = 0;
    int flagGuion = 0;
    while(buffer[i] != '\0')
    {
        if((buffer[i] < '0' || buffer[i] > '9') && buffer[i] != '-')
        {
            retorno = -1;
            break;
        }
        else
        {
            if((buffer[i] == '-' && i == 2) || (buffer[i] == '-' && i == 11))
            {
                flagGuion++;
            }
        }
        i++;
    }
    if(flagGuion != 2)
    {
        retorno = -1;
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

/** \brief Obtiene lo valida y lo almacena
 * \param array de caracteres del destino
 * \param mensaje Mensaje para el usuario
 * \param mensajeError mensaje a mostrar en caso de error
 * \param intentos cantidad veces que se tiene para ingresar los datos correctamente
 * \param longitud cantidad de elemntos del array destino
 * \return -1 en caso de error  0 ok
 */
int val_getNombreVideo(char* destino, char* mensaje,char* mensajeError, int intentos, int limite)
{
    int retorno = -1;
    char buffer[20];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);

        for( ; intentos>0; intentos--)
        {
            val_myFgets(buffer, limite,stdin);

            if(val_validarNombreVideo(buffer) == 0)
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

/**
 * \brief Verifica si el valor recibido contiene los caracteres aceptados en el nombre de un archivo de video, letras, numeros y un punto
 * \param char buffer con la cadena a ser analizada
 * \return 0 si la validacion es correcta y -1 error
 *
 */
int val_validarNombreVideo(char str[])
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
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
            return 0;
        i++;
    }
    return 1;
}

/*****************************************************/
