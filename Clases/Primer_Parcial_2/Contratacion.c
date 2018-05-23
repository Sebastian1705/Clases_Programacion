#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Contratacion.h"
#include "Validar.h"


/** \brief inicializa el array poniendo estado en LIBRE
 * \param array posicion de memoria del inicio array
 * \param longitud Es la cantidad de elementos del array
 * \return 0 OK  o -1 error
 *
 */
int cont_init(sContratacion* array, int longitud)
{
    int retorno = -1;
    int i;
    if(array != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            (array+i)->flagEstado = CONTRATACION_LIBRE;
        }
    }
    return retorno;
}

/*****************************************************/

/** \brief genera un id autoincrementable
 * \param void
 * \return retorna idAutoincrementable
 *
 */

static int idContratacion = -1;

int cont_generarProximoId(void)
{
    idContratacion++;
    return idContratacion;
}

/*****************************************************/

/**
 * \brief Busca un índice libre en el array de Contrataciones
 * \param array Es el array a analizar
 * \param longitud cantidad de elementos del array
 * \return retorna el indice, o -1 en caso de error
 */
int cont_buscarIndiceLibre(sContratacion* array, int longitud)
{
    int retorno = -1;
    int i;
    if(array != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if((array+i)->flagEstado == CONTRATACION_LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

/*****************************************************/

/** \brief realiza la toma de datos validando y almacenando cada uno
 * \param arrayContrataciones es la posicion de memoria del inicio del array de Contrataciones
 * \param arrayPantallas es la posicion de memoria del inicio del array de Pantallas
 * \param lenContrataciones cantidad de elementos del array de contrataciones
 * \param lenPantallas cantidad de elementos del array de pantallas
 * \return 0 si se realizo la carga correctamente o -1 en case de error
 *
 */
int cont_alta(sContratacion* arrayContrataciones, sPantalla* arrayPantallas, int lenContrataciones, int lenPantallas)
{
    int retorno = -1;
    char bufferCuit[20];
    char bufferDias[20];
    char bufferNombreVideo[50];
    char bufferIdPantalla[10];

    if(arrayPantallas != NULL && lenPantallas > 0 && arrayContrataciones != NULL && lenContrataciones > 0 )
    {
        int indexVacio = cont_buscarIndiceLibre(arrayContrataciones, lenContrataciones);
        if (indexVacio >= 0)
        {
            if(val_getUnsignedInt(bufferIdPantalla,"\nId de pantalla a contratar: \n","\nIngrese un numero valido\n",INTENTOS,10)==0)
            {
                if (pant_buscarIndicePorId(arrayPantallas, lenPantallas, atoi(bufferIdPantalla)) != -1)
                {
                    if (val_getCuit(bufferCuit,"Ingrese su CUIT:\n","\nIngrese un CUIT valido:\n",INTENTOS,20)!= -1)
                    {
                        if (val_getUnsignedInt(bufferDias,"Ingrese la cantidad de dias que desea contratar la pantalla:\n","\Error:\n",INTENTOS,20) != -1)
                        {
                            if (val_getNombreVideo(bufferNombreVideo,"Ingrese el nombre del archivo de video:\n","\nIngrese un nombre valido:\n",INTENTOS,50) != -1)
                            {
                                (arrayContrataciones+indexVacio)->flagEstado = CONTRATACION_EN_CURSO;
                                (arrayContrataciones+indexVacio)->idContratacion = cont_generarProximoId();
                                (arrayContrataciones+indexVacio)->dias = atoi(bufferDias);
                                (arrayContrataciones+indexVacio)->idPantalla = atoi(bufferIdPantalla);
                                strncpy( (arrayContrataciones+indexVacio)->cuit, bufferCuit, 20);
                                strncpy((arrayContrataciones+indexVacio)->nombreVideo, bufferNombreVideo, 50);

                                printf("Carga exitosa.");
                                retorno = 0;
                            }
                        }
                    }
                }
            }
            else
            {
                printf("\nEl ID ingresado no corresponde a ninguna pantalla.\n");
            }
        }
        else
        {
            printf("\nNo hay posiciones libres.");
        }
    }
    return retorno;
}

/*****************************************************/

int cont_modificarDias(sContratacion* arrayContrataciones, sPantalla* arrayPantallas, int lenContrataciones, int lenPantallas)
{
    int retorno = -1;

    if(arrayPantallas != NULL && lenPantallas > 0 && arrayContrataciones != NULL && lenContrataciones > 0 )
    {
        char bufferCuit[20];
        char bufferDias[50];
        char bufferId[10];

        if(val_getCuit(bufferCuit,"\nIngrese su CUIT: \n","\nIngrese un numero valido\n",INTENTOS,20)==0)
        {
            if (inf_listarPantallasContratadas(arrayPantallas,arrayContrataciones,lenPantallas,lenContrataciones,bufferCuit) != -1)
            {
                if (val_getUnsignedInt(bufferId,"\nIngrese ID de la pantalla a modificar:\n","\nIngese un ID valido\n",INTENTOS,10) != -1)
                {
                    int index = cont_buscarIndicePorIdPantalla(arrayContrataciones,lenContrataciones,atoi(bufferId));
                    if(index >= 0)
                    {
                        if (val_getUnsignedInt(bufferDias,"Ingrese la cantidad de dias a contratar pantalla:\n","\nIngrese un numero valido:\n",INTENTOS,10)!= -1)
                        {
                            arrayContrataciones[index].dias = atoi(bufferDias);
                            printf("Modificacion correcta.");
                            retorno = 0;
                        }
                    }
                    else
                    {
                        printf("\nEl ID ingresado no corresponde a ninguna pantalla.");
                    }
                }
            }
        }
    }
    return retorno;
}

/*****************************************************/
