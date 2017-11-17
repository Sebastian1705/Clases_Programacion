#ifndef RELACION_H_INCLUDED
#define RELACION_H_INCLUDED

typedef struct
{
    int id;
    int idSocio;
    int idServicio;
    int estado;

}Relacion;

#endif // RELACION_H_INCLUDED
#define RELACION_ESTADO_ACTIVO 0
#define RELACION_ESTADO_INACTIVO 1


int rel_delete(Relacion* this);
Relacion* rel_new(int idServicio, int idSocio, int id, int estado);
Relacion* rel_findById(ArrayList* pArrayRelaciones, int id);

int rel_setId(Relacion* this,int id);
int rel_getId(Relacion* this);

int rel_getIdSocio(Relacion* this);
int rel_setIdSocio(Relacion* this,int id);

int rel_getIdServicio(Relacion* this);
int rel_setIdServicio(Relacion* this,int id);

int rel_setEstado(Relacion* this,int estado);
int rel_getEstado(Relacion* this);
