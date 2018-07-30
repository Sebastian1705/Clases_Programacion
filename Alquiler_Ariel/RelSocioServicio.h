#ifndef RELSOCIOSERVICIO_H_INCLUDED
#define RELSOCIOSERVICIO_H_INCLUDED
typedef struct
{
    int id;
    int idSocio;
    int idServicio;
    int estado;
}RelSocioServicio;
#endif // RELSOCIOSERVICIO_H_INCLUDED

#define REL_SOCIO_SERVICIO_ESTADO_ACTIVO 0
#define REL_SOCIO_SERVICIO_ESTADO_INACTIVO 1

RelSocioServicio* relSyS_new(int id, int idSocio, int idServicio, int estado);
int relSyS_delete(RelSocioServicio* this);
int relSyS_setId(RelSocioServicio* this,int id);
int relSyS_getId(RelSocioServicio* this);
int relSyS_setIdSocio(RelSocioServicio* this,int idSocio);
int relSyS_getIdSocio(RelSocioServicio* this);
int relSyS_setIdServicio(RelSocioServicio* this,int idServicio);
int relSyS_getIdServicio(RelSocioServicio* this);
int relSyS_setEstado(RelSocioServicio* this,int estado);
RelSocioServicio* relSyS_findById(ArrayList* pArrayRelSocioServicio, int id);
RelSocioServicio* relSyS_findByIdSocioAndIdServicio(ArrayList* pArrayRelSocioServicio, int idSocio,int idServicio);
