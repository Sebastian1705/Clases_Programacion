#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "DataManager.h"
#include "Vista.h"

static ArrayList* nominaLog;
static int proximoIdLog=0;
static int getNewIdLog();
static int setNewIdLog(int id);

static ArrayList* nominaService;
static int proximoIdService=0;
static int getNewIdService();
static int setNewIdService(int id);

void cont_init()
{
    nominaLog = al_newArrayList();
    dm_readAllLog(nominaLog);
    //setNewIdLog(dm_readAllLog(nominaLog) + 1);

    nominaService = al_newArrayList();
    setNewIdService(dm_readAllService(nominaService) + 1);

    vista_init(VISTA_IDIOMA_ES);
    vista_mostrarMenu();
}

int cont_altaLog (char* a,char* b,int c)
{
    /*
    Log* auxLog;    //aux de entidad
    auxLog = log_new(getNewIdLog(),nombre,apellido,Log_ESTADO_ACTIVO,dni);      aca va el new de la entidad
    al_add(nominaLog,auxLog);
    dm_saveAllLog(nominaLog);
    */
    return 0;
}

int cont_bajaLog (int id)
{
    /*
    Log* auxLog;
    auxLog=log_findById(nominaLog,id);
    if(auxLog!=NULL)
    {
        log_setEstado(auxLog,Log_ESTADO_INACTIVO);
        dm_saveAllLog(nominaLog);
    }
*/
    return 0;
}


int cont_modificarLog (int id, char* a,char* b,int c)
{
    /*
    Log* auxLog;
    auxLog=log_findById(nominaLog,id);

    if(auxLog!=NULL)
    {
        log_setNombre(auxLog,nombre);
        log_setApellido(auxLog,apellido);
        log_setDni(auxLog,dni);
        log_setEstado(auxLog,estado);
        dm_saveAllLog(nominaLog);
    }
*/
    return 0;
}

int cont_existeLogActivoEnLista (int idLog)
{

    int retorno = -1;
    /*
    Log* auxLogModificar;
    auxLogModificar = log_findById(nominaLogs,idLog);
    if (auxLogModificar != NULL && log_getEstado(auxLogModificar) == Log_ESTADO_ACTIVO)
    {
        retorno = 0;
    }
    */
    return retorno;
}

int cont_listarLog ()
{
    vista_mostrarLog(nominaLog);
    return 0;
}

int cont_ordenarLog ()
{

    return 0;
}

static int getNewIdLog()
{
    return proximoIdLog++;
}

static int setNewIdLog(int id)
{
    proximoIdLog = id;
    return 0;
}

//////////////////////////////////////////////////////////////ENTIDAD 2

int cont_altaService (char* a,char* b,int c)
{

    return 0;
}

int cont_bajaService (int id)
{


    return 0;
}


int cont_modificarService (int id, char* a,char* b,int c)
{

    return 0;
}

int cont_listarService ()
{
    vista_mostrarService(nominaService);
    return 0;
}

int cont_ordenarService ()
{

    return 0;
}

static int getNewIdService()
{
    return proximoIdService++;
}

static int setNewIdService(int id)
{
    proximoIdService = id;
    return 0;
}
