#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Socio.h"
#include "Vista.h"
#include "DataManager.h"
#include "Servicios.h"
#include "Relacion.h"

static ArrayList* nominaServicios;
static ArrayList* nominaSocios;
static ArrayList* nominaRelaciones;

static int proximoIdSocio=0;
static int proximoIdServicio=0;
static int proximoIdRelacion=0;

static int getNewId();
static int getNewIdServicio();
static int getNewIdRelacion();

static int setNewId(int id);
static int setNewIdServicio(int id);
static int setNewIdRelacion(int id);


void cont_init()
{
    nominaSocios = al_newArrayList();
    nominaServicios=al_newArrayList();
    nominaRelaciones = al_newArrayList();

    setNewId(dm_readAll(nominaSocios) + 1);
    setNewIdServicio(dm_readAllServicios(nominaServicios) + 1);
    setNewIdRelacion(dm_readAllRelacion(nominaRelaciones) + 1);

    vista_init(VISTA_IDIOMA_ES);
    vista_mostrarMenu();
}

/**************************************************************************************/

int cont_altaSocio (char* nombre,char* apellido,char* dni)
{
    Socio* auxSocio;
    auxSocio = soc_new(nombre,apellido,dni,getNewId(),SOCIO_ESTADO_ACTIVO);
    al_add(nominaSocios,auxSocio);
    dm_saveAll(nominaSocios);
    return 0;
}

int cont_bajaSocio (int id)
{
    Socio* auxSocio;
    auxSocio=soc_findById(nominaSocios,id);
    if(auxSocio!=NULL)
    {
        soc_setEstado(auxSocio,SOCIO_ESTADO_INACTIVO);
        dm_saveAll(nominaSocios);
    }

    return 0;
}


int cont_modificarSocio (char* nombre,char* apellido,char* dni, int id, int estado)
{
    Socio* auxSocio;

    auxSocio=soc_findById(nominaSocios,id);

    if(auxSocio!=NULL)
    {
        soc_setNombre(auxSocio,nombre);
        soc_setApellido(auxSocio,apellido);
        soc_setDni(auxSocio,dni);
        soc_setEstado(auxSocio,estado);
        dm_saveAll(nominaSocios);
    }

    return 0;
}

int cont_listarSocios ()
{
    vista_mostrarSocios(nominaSocios);
    return 0;
}


static int getNewId()
{
    return proximoIdSocio++;
}

static int setNewId(int id)
{
    proximoIdSocio = id;
    return 0;
}

/**************************************************************************************/

int cont_altaServicio(char* descripcion)
{
    Servicio* auxServicio;
    auxServicio = ser_new(descripcion, getNewIdServicio(),SERVICIO_ESTADO_ACTIVO);
    al_add(nominaServicios,auxServicio);
    dm_saveAllServicios(nominaServicios);
    return 0;
}

int cont_bajaServicio(int id)
{
    Servicio* auxServicio;
    auxServicio = ser_findById(nominaServicios,id);
    if(auxServicio != NULL)
    {
        ser_setEstado(auxServicio,SERVICIO_ESTADO_INACTIVO);
        dm_saveAllServicios(nominaServicios);
    }

    return 0;
}

int cont_modificarServicio(char* descripcion, int id, int estado)
{
    Servicio* auxServicio;

    auxServicio = ser_findById(nominaServicios,id);

    if(auxServicio!=NULL)
    {
        ser_setDescripcion(auxServicio,descripcion);
        ser_setEstado(auxServicio,estado);
        dm_saveAllServicios(nominaServicios);
    }

    return 0;
}

int cont_listarServicios()
{
    vista_mostrarServicios(nominaServicios);
    return 0;
}


static int getNewIdServicio()
{
    return proximoIdServicio++;
}

static int setNewIdServicio(int id)
{
    proximoIdServicio = id;
    return 0;
}

/**************************************************************************************/

static int getNewIdRelacion()
{
    return proximoIdRelacion++;
}

static int setNewIdRelacion(int id)
{
    proximoIdRelacion = id;
    return 0;
}

int cont_altaRelacion(int idServicio, int idSocio)
{
    Relacion* auxRelacion;
    auxRelacion = rel_new(idServicio,idSocio,getNewIdRelacion(),RELACION_ESTADO_ACTIVO);
    al_add(nominaRelaciones,auxRelacion);
    dm_saveAll(nominaRelaciones);
    return 0;
}

int cont_bajaRelacion(int id)
{
    Relacion* auxRelacion;
    auxRelacion = rel_findById(nominaRelaciones,id);
    if(auxRelacion != NULL)
    {
        rel_setEstado(auxRelacion,RELACION_ESTADO_INACTIVO);
        dm_saveAllRelacion(nominaRelaciones);
    }

    return 0;
}

int cont_listarRelacion()
{
    vista_mostrarRelaciones(nominaRelaciones);
    return 0;
}



/*int ctrlr_checkSocio(int id)
{
    int retorno = -1;
    Socio* auxiliar;
    auxiliar = soc_findById (listaSocios, id);

    if(auxiliar != NULL && soc_getEstado(auxiliar) == SOCIO_ESTADO_ACTIVO)
    {
        retorno = 0;
    }
    return retorno;
}
int ctrlr_checkServicio(int id)
{
    int retorno = -1;
    Servicios* auxiliar;
    auxiliar = svcs_findById (listaServicios, id);

    if(auxiliar != NULL && svcs_getEstado(auxiliar) == SERVICIO_ACTIVO)
    {
        retorno = 0;
    }
    return retorno;
}*/
