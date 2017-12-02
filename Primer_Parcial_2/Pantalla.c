#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pantalla.h"
#include "Validar.h"


 /** \brief inicializa el array
 * \param array pocicion de memoria del iniciio del array
 * \param longitud cantidad de elemntos del array
 * \return 0 OK  o -1 error
 *
 */
int pant_init(sPantalla* array, int longitud)
{
    int retorno = -1;
    int i;
    if(array != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            (array+i)->flagEstado = PANTALLA_LIBRE;
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

static int idAutoincrementable = -1;

int pant_generarProximoId(void)
{
    idAutoincrementable++;
    return idAutoincrementable;
}

/*****************************************************/

/**
* \brief Busca un indice libre
* \param array Corresponde a la posicion de memoria del array
* \param longitud Es la cantidad de elementos que contiene el array
* \return Retorna el indice libre o -1 en caso de error
*
*/
int pant_buscarPosicionLibre(sPantalla* array, int longitud)
{
    int retorno = -1;
    int i;
    if(array != NULL && longitud > 0)
    {
        for(i=0; i < longitud ; i++)
        {
            if((array+i)->flagEstado == PANTALLA_LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

/*****************************************************/

/** \brief recorre array busca el indice del elemento que contiene el id pasado como parametro
 * \param array pocicion de memoria del inicio del array
 * \param longitud Es la cantidad de elementos del array
 * \param id parametro para buscar indice
 * \param mensaje mensaje a ser mostrado
 * \return el indice si se encuentra  o -1 en caso de error
 *
 */
int pant_buscarIndicePorId(sPantalla* array, int longitud, int id)
{
    int i;
    int retorno = -1;
    if(array != NULL && longitud > 0 && id >=0)
    {
        for(i=0; i<longitud ; i++)
        {
            if((array+i)->flagEstado == PANTALLA_OCUPADA)
            {
                if((array+i)->id == id);
                {
                    retorno = i;
                    break;
                }
            }
        }

        if(retorno == -1)
        {
            printf("No se encontro el ID");
        }
    }
    return retorno;
}

/*****************************************************/

/** \brief Imprime un menu de opciones
 * \param void
 * \return void
 *
 */
void pant_printMenu(void)
{
    printf("\tMENU DE OPCIONES\n\n"
            "\n1. Alta de Pantallas"
            "\n2. Modificar datos de Pantallas"
            "\n3. Baja de Pantallas"
            "\n4. Contratar publicidad"
            "\n5. Modificar condiciones de publicacion"
            "\n6. Cancelar contratacion"
            "\n7. Consultar facturacion"
            "\n8. Listar contrataciones"
            "\n9. Listar Pantallas"
            "\n10. Informar\n"
            "\n0. Salir\n");
}

/*****************************************************/

/** \brief realiza la toma de datos validando y almacenando cada uno
 * \param array es la posicion de memoria del inicio del array
 * \param longitud cantidad de elementos del array
 * \return 0 si se realizo la carga correctamente o -1 en case de error
 *
 */
int pant_alta(sPantalla* array, int longitud)
{
    int retorno = -1;
    int indice = pant_buscarPosicionLibre(array, longitud);
    char bNombre[50];
    char bDireccion[100];
    char bPrecio[20];
    char auxTipo[5];

    if(array != NULL && longitud >= 0 && indice >=0)
    {
        if(val_getString(bNombre,"\nNombre: \n","\nError!\n",INTENTOS,50)==0)
        {
            if(val_getAlfanumerico(bDireccion, "\nDireccion: \n","\nError!\n",INTENTOS,100)== 0)
            {
                if(val_getFloat(bPrecio,"\nPrecio por dia: \n","\nError\n",INTENTOS,50)==0)
                {
                    printf("1 - LED\n2 - LCD \n");
                    if(val_getUnsignedInt(auxTipo,"\nTipo: \n","\nError\n",INTENTOS,50)==0)
                    {
                        if(atoi(auxTipo)>2 || atoi(auxTipo)<1)
                        {
                            printf("Elija 1 o 2 \n");
                        }
                        else
                        {
                            strncpy((array+indice)->nombre, bNombre, 50);
                            strncpy((array+indice)->direccion, bDireccion,100);
                            (array+indice)->precio = atof(bPrecio);
                            (array+indice)->tipo = atoi(auxTipo);
                            (array+indice)->id = pant_generarProximoId();
                            (array+indice)->flagEstado = PANTALLA_OCUPADA;
                            retorno = 0;
                        }
                    }
                }
            }
        }
    }
    return retorno;
}

/*****************************************************/

/** \brief solicicita ID localiza el detro del array el indice correspondiente y permite la modificacion de sus campos
 * \param array es la posicion de memoria del inicio del array
 * \param longitud cantidad de elementos del array
 * \return 0 si se realizo la mificacion correctamente o -1 en case de error
 *
 */
int pant_modificar(sPantalla* array, int longitud)
{
    int retorno = -1;
    int indice;
    int idAux;
    char buffer[5];
    char bNombre[51];
    char bDireccion[100];
    char bPrecio[10];
    char auxTipo[10];

    val_getUnsignedInt(buffer,"Ingrese el ID de la pantalla a modificar", "El ID no se encontro",INTENTOS,5);
    idAux = atoi(buffer);
    indice = pant_buscarIndicePorId(array, longitud, idAux);

    if(indice != -1)
    {
        if(val_getString(bNombre,"\nNombre: \n","\nError!\n",INTENTOS,50)==0)
        {
            if(val_getAlfanumerico(bDireccion, "\nDireccion: \n","\nError\n",INTENTOS,100)== 0)
            {
                if(val_getFloat(bPrecio,"\nPrecio: \n","\nError\n",INTENTOS,50)==0)
                {

                    printf("1 - LED\n2 - LCD \n");
                    if(val_getUnsignedInt(auxTipo,"\nTipo: \n","\nError\n",INTENTOS,50)==0)
                    {
                        if(atoi(auxTipo)>2 || atoi(auxTipo)<1)
                        {
                            printf("Elija 1 o 2 \n");
                        }
                        else
                        {
                            strncpy((array+indice)->nombre, bNombre, 50);
                            strncpy((array+indice)->direccion, bDireccion,100);
                            (array+indice)->precio = atof(bPrecio);
                            (array+indice)->tipo = atoi(auxTipo);
                            retorno = 0;
                        }
                    }
                }
            }
        }
    }
    return retorno;
}

/*****************************************************/

/** \brief hace el borrado logico poniendo el estado en LIBRE
 * \param
 * \param limite la cantidad de elementos para el array
 * \return 0 si se hace el borrado correctamente o -1 en caso de error
 *
 */
int pant_baja(sPantalla* array, int longitud)
{
    int retorno = -1;
    int idAux;
    int indice;
    char buffer[5];

    val_getUnsignedInt(buffer,"Ingrese el ID de la pantalla a borrar", "El ID no se encontro",INTENTOS,5);
    idAux = atoi(buffer);
    indice = pant_buscarIndicePorId(array, longitud, idAux);

    if(array != NULL && longitud > 0 )
    {
        if(indice != -1 && (array+indice)->flagEstado == PANTALLA_OCUPADA)
        {
             (array+indice)->flagEstado = PANTALLA_LIBRE;
        }
    }
    return retorno;
}

/*****************************************************/

/**
 * \brief Imprime datos de la Pantalla
 * \param array Es el array donde se obtienen los datos a imprimir
 * \param longitud Cantidad de elementos del array
 * \return 0 si se imprime correctamente o -1 en caso de error
 */
int pant_print(sPantalla* array, int longitud)
{
    int retorno = -1;
    int i;
    char tipo[10];
    printf("\tPANTALLAS\n\n");
    if(array != NULL && longitud > 0)
    {
        for(i = 0; i < longitud; i++)
        {
            if(array[i].flagEstado == PANTALLA_OCUPADA)
            {
                if(array[i].tipo == LCD)
                {
                    strncpy(tipo, "LCD", 20);
                }
                if(array[i].tipo == LED)
                {
                    strncpy(tipo, "LED", 20);
                }
                printf("\nId: %d\nNombre: %s\nDireccion: %s\nPrecio: %f\nTipo: %s", array[i].id, array[i].nombre, array[i].direccion, array[i].precio, tipo);
                retorno = 0;
            }
        }
    }
    return retorno;
}

/*****************************************************/

