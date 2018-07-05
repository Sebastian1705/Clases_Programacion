#ifndef GENERADOR_H_INCLUDED
#define GENERADOR_H_INCLUDED
typedef struct
{
    char nombreCampo[40];
    int esString;
    int cantidadChars;
    char tipoVariable[20];
    int id;
}EGenerar;
#include "ArrayList.h"

EGenerar* campo_new();
int campoNuevo(ArrayList* listaCampos);
int mostrarCampos(ArrayList* listaCampos);
int borrarCampo(ArrayList* listaCampos);

int parserHeader(ArrayList* lista,char* nombreStruct,char archivo[50]);
int generarArchivos(char* nombreStruct,char* prefijo,ArrayList* listaCampos,char* nombreArchivo);

int campo_setNombreCampo(EGenerar* this,char* nombre);
int campo_getNombreCampo(EGenerar* this,char* nombre);

int campo_setTipoVariable(EGenerar* this,char* tipoVariable);
int campo_getTipoVariable(EGenerar* this,char* tipoVariable);

int campo_setEsString(EGenerar* this,int esString);
int campo_getEsString(EGenerar* this,int* esString);

int campo_setCantidadChars(EGenerar* this,int cantidadChars);
int campo_getCantidadChars(EGenerar* this,int* cantidadChars);

int campo_setId(EGenerar* this,int id);
int campo_getId(EGenerar* this,int* id);

#endif // GENERADOR_H_INCLUDED
