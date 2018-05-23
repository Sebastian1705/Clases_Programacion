#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Cliente.h"
#include "Alquiler.h"
#include "Vista.h"
#include "DataManager.h"

static ArrayList* nominaCliente;
static ArrayList* nominaAlquiler;

static int proximoIdCliente=0;
static int getNewIdCliente();
static int setNewIdCliente(int id);

static int proximoIdAlquiler=0;
static int getNewIdAlquiler();
static int setNewIdAlquiler(int id);

static int cont_calcularCantidadAlquileres(int id);
static int cont_calcularCantidadEquipos(int idEquipo);
static float cont_calcularTiempoRealEquipos(int idEquipo);

void cont_init()
{
    nominaCliente = al_newArrayList();
    nominaAlquiler = al_newArrayList();
    setNewIdCliente(dm_readAll(nominaCliente) + 1);
    setNewIdAlquiler(dm_readAllAlquiler(nominaAlquiler) + 1);
    vista_init(VISTA_IDIOMA_ES);
    vista_mostrarMenu();
}

int cont_altaCliente (char* nombre,char* apellido,char* dni)
{
    Cliente* auxCliente;
    auxCliente = cliente_new(getNewIdCliente(),nombre,apellido,CLIENTE_ESTADO_ACTIVO,dni);
    al_add(nominaCliente,auxCliente);
    dm_saveAll(nominaCliente);
    return 0;
}

int cont_bajaCliente (int id)
{
    Cliente* auxCliente;
    auxCliente=cliente_findById(nominaCliente,id);
    if(auxCliente!=NULL)
    {
        cliente_setEstado(auxCliente,CLIENTE_ESTADO_INACTIVO);
        dm_saveAll(nominaCliente);
    }

    return 0;
}

int cont_modificarCliente (char* nombre,char* apellido,char* dni, int id, int estado)
{
    Cliente* auxCliente;
    auxCliente=cliente_findById(nominaCliente,id);

    if(auxCliente!=NULL && cliente_getEstado(auxCliente)==CLIENTE_ESTADO_ACTIVO)
    {
        cliente_setNombre(auxCliente,nombre);
        cliente_setApellido(auxCliente,apellido);
        cliente_setDni(auxCliente,dni);
        cliente_setEstado(auxCliente,estado);
        dm_saveAll(nominaCliente);
    }

    return 0;
}

int cont_listarCliente ()
{
    vista_mostrarCliente(nominaCliente);
    return 0;
}

int cont_existeCliente (int id)
{
    int retorno = -1;
    Cliente* auxCliente = cliente_findById(nominaCliente,id);

    if (auxCliente != NULL && cliente_getEstado(auxCliente) == CLIENTE_ESTADO_ACTIVO)
    {
        retorno = 0;
    }
    return retorno;
}

static int getNewIdCliente()
{
    return proximoIdCliente++;
}

static int setNewIdCliente(int id)
{
    proximoIdCliente = id;
    return 0;
}

int cont_ordenarCliente()
{
    al_sort(nominaCliente,cliente_compareByApellido,1);
    return 0;
}


//***************************Alquiler*************

int cont_altaAlquiler (int idCliente,int equipo,int tiempoEstimado)
{
    Alquiler* auxAlquiler;
    auxAlquiler = alquiler_new(getNewIdAlquiler(),idCliente, equipo,ESTADO_ALQUILADO,tiempoEstimado,0);
    al_add(nominaAlquiler,auxAlquiler);
    dm_saveAllAlquiler(nominaAlquiler);
    return 0;
}

int cont_bajaAlquiler (int id, int tiempoReal)
{
    Alquiler* auxAlquiler;
    auxAlquiler=alquiler_findById(nominaAlquiler,id);
    if(auxAlquiler!=NULL)
    {
        alquiler_setTiempoReal(auxAlquiler,tiempoReal);
        alquiler_setEstado(auxAlquiler,ESTADO_FINALIZADO);
        dm_saveAllAlquiler(nominaAlquiler);
    }

    return 0;
}


int cont_modificarAlquiler (char* descripcion, int id, int estado)
{
    /*Alquiler* auxAlquiler;

    auxAlquiler=alquiler_findById(nominaAlquiler,id);

    if(auxAlquiler!=NULL)
    {
        alquiler_setDescripcion(auxAlquiler,descripcion);
        alquiler_setEstado(auxAlquiler,estado);
        dm_saveAllAlquiler(nominaAlquiler);
    }
*/
    return 0;
}


int cont_listarAlquiler ()
{
    vista_mostrarAlquiler(nominaAlquiler);
    return 0;
}

int cont_existeAlquiler (int id)
{
    int retorno = -1;
    Alquiler* auxAlquiler = alquiler_findById(nominaAlquiler,id);

    if (auxAlquiler != NULL && alquiler_getEstado(auxAlquiler) == ESTADO_ALQUILADO)
    {
        retorno = 0;
    }
    return retorno;
}

static int getNewIdAlquiler()
{
    return proximoIdAlquiler++;
}

static int setNewIdAlquiler(int id)
{
    proximoIdAlquiler = id;
    return 0;
}

/****************************************/

void cont_informe1()
{
    Cliente* auxCliente;
    Cliente* destino;
    int i, idCliente, aux, maxSocio = 0;
    for(i=0; i<al_len(nominaCliente); i++)
    {
        auxCliente=al_get(nominaCliente,i);
        if(auxCliente->estado==CLIENTE_ESTADO_ACTIVO)
        {
            idCliente = cliente_getId(auxCliente);
            aux = cont_calcularCantidadAlquileres(idCliente);
            if (aux>maxSocio)
            {
                maxSocio = aux;
                destino = auxCliente;
            }
        }
    }
    vista_mostrarInformes(destino);
}

static int cont_calcularCantidadAlquileres(int id)
{
    Alquiler* auxAlquiler;
    int i, contador = 0;
    for(i=0; i<al_len(nominaAlquiler); i++)
    {
        auxAlquiler=al_get(nominaAlquiler,i);
        if(auxAlquiler->estado==ESTADO_ALQUILADO)
        {
            if(alquiler_getIdCliente(auxAlquiler) == id)
            {
                contador++;
            }
        }
    }
    return contador;
}


void cont_informe2()
{
    int i, aux[3], maxEquipo = 0;

    for(i=0;i<2;i++)
    {
        aux[i] = cont_calcularCantidadEquipos(i);
        if (aux[i]>maxEquipo)
        {
            maxEquipo = aux[i];
        }
    }
    printf("El/los equipos con mas alguileres son:\n");
    for(i=0;i<2;i++)
    {
        if(aux[i]==maxEquipo)
        {
            if(i==0)
                printf("Amoladora ");
            else if(i==1)
                printf("Mezcladora ");
            else
                printf("Taladro. ");
        }
    }
    printf("La cantidad es: %d\n\n",maxEquipo);
}


static int cont_calcularCantidadEquipos(int idEquipo)
{
    Alquiler* auxAlquiler;
    int i, contador = 0;
    for(i=0; i<al_len(nominaAlquiler); i++)
    {
        auxAlquiler=al_get(nominaAlquiler,i);
        if(auxAlquiler->estado==ESTADO_ALQUILADO)
        {
            if(alquiler_getEquipo(auxAlquiler) == idEquipo)
            {
                contador++;
            }
        }
    }
    return contador;
}


void cont_informe3()
{
    int i;
    float aux[3];

    for(i=0;i<2;i++)
    {
        aux[i] = cont_calcularTiempoRealEquipos(i);
        if(i==0)
        {
            if(aux[i]!=0)
                printf("El tiempo promedio de Amoladora es: %.2f\n",aux[i]);
        }
        else if(i==1)
        {
            if(aux[i]!=0)
                printf("El tiempo promedio de Mezcladora es: %.2f\n",aux[i]);
        }
        else
        {
            if(aux[i]!=0)
                printf("El tiempo promedio de Taladro es: %.2f\n",aux[i]);
        }
    }
}

static float cont_calcularTiempoRealEquipos(int idEquipo)
{
    Alquiler* auxAlquiler;
    int i, contador = 0, tiempoReal = 0;
    for(i=0; i<al_len(nominaAlquiler); i++)
    {
        auxAlquiler=al_get(nominaAlquiler,i);
        if(auxAlquiler->estado==ESTADO_FINALIZADO)
        {
            if(alquiler_getEquipo(auxAlquiler) == idEquipo)
            {
                tiempoReal = tiempoReal + alquiler_getTiempoReal(auxAlquiler);
                contador++;
            }
        }
    }
    //printf("%d",tiempoReal);
    //printf("%d",contador);
    //system("pause");

    if (contador == 0)
        return 0;

    return (float)tiempoReal / (float)contador;
}




























/*void cont_informe2()

{
    Alquiler* auxAlquiler;
    int i, contador,contadorAmoladora, contadorMezcladora,contadorTaladro,resultado=0;
    for(i=0; i<al_len(nominaAlquiler); i++)
    {
        auxAlquiler=al_get(nominaAlquiler,i);

        if(alquiler_getEquipo(auxAlquiler) == 0)
            contadorAmoladora++;
        else if(alquiler_getEquipo(auxAlquiler) == 1)
            contadorMezcladora++;
        else
            contadorTaladro++;
    }
    contador = contadorAmoladora;
    if(contadorMezcladora>contador)
    {
        contador=contadorMezcladora;
        resultado=1;
    }
    if(contadorTaladro>contador)
    {
        contador=contadorTaladro;
        resultado=2;
    }
    if(resultado == 0)
    {
        if(contador == contadorMezcladora && contador == contadorTaladro)
            printf("Los maximos son: Amoladora, Mezcladora y Taladro, la cantidad es %d",contador);
        else if(contador == contadorMezcladora)
            printf("Los maximos son: Amoladora y Mezcladora, la cantidad es %d",contador);
        else if(contador == contadorTaladro)
            printf("Los maximos son: Amoladora y Taladro, la cantidad es %d",contador);
        else
            printf("El maximo es: Amoladora, la cantidad es %d",contador);
    }




}*/






