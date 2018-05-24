#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"
#include "string.h"

//REGION CONSTRUCTORES y PROPIEDADES

Cliente* Cliente_new()
{
    return (Cliente*)malloc(sizeof(Cliente));
}

Cliente* Cliente_newP(char* dni, char* nombre, char* apellido, char* cuit, float sueldo, int id)
{
    int ans= -1;
    Cliente* this = Cliente_new();

    if(!Cliente_setDni(this, dni) && !Cliente_setNombre(this, nombre) && !Cliente_setApellido(this, apellido) && !Cliente_setCuit(this, cuit) && !Cliente_setSueldo(this,sueldo))
    {
        ans=1;
        if(id>=0)
        {
            if(!Cliente_setId(this, id))
                ans=0;
        }
        else
        {
            if(!Cliente_setNewId(this))
                ans=0;
        }

    }
    if (!ans)
        return this;
    else
    {
       return NULL;
    }
}

void Cliente_delete(Cliente* this)
{
    free(this);
}

int Cliente_setSueldo(Cliente* this, float sueldo)
{
    int ans= -1;
    if (this != NULL && isValidSueldo(sueldo))
    {
        ans=0;
        this->sueldo = sueldo;
    }
    return ans;
}

int Cliente_getSueldo(Cliente* this, float* sueldo)
{
    int ans= -1;
    if (this != NULL && sueldo != NULL)
    {
        ans=0;
        *sueldo = this->sueldo;
    }
    return ans;
}

int Cliente_setDni(Cliente* this, char* dni)
{
    int ans= -1;
    if (this != NULL && dni!=NULL && isValidDni(dni))
    {
        ans=0;
        strcpy(this->dni , dni);

    }
    return ans;
}

int Cliente_getDni(Cliente* this, char* dni)
{
    int ans= -1;
    if (this != NULL && dni!=NULL)
    {
        ans=0;
        strcpy(dni , this->dni);
    }
    return ans;
}

int Cliente_setApellido(Cliente* this, char* apellido)
{
    int ans= -1;
    if (this != NULL && apellido!=NULL && isValidApellido(apellido))
    {
        ans=0;
        strcpy(this->apellido , apellido);

    }
    return ans;
}

int Cliente_getApellido(Cliente* this, char* apellido)
{
    int ans= -1;
    if (this != NULL && apellido!=NULL)
    {
        ans=0;
        strcpy(apellido , this->apellido);
    }
    return ans;
}

int Cliente_setNombre(Cliente* this, char* nombre)
{
    int ans= -1;
    if (this != NULL && nombre!=NULL && isValidNombre(nombre))
    {
        ans=0;
        strcpy(this->nombre , nombre);

    }
    return ans;
}

int Cliente_getNombre(Cliente* this, char* nombre)
{
    int ans= -1;
    if (this != NULL && nombre!=NULL)
    {
        ans=0;
        strcpy(nombre , this->nombre);
    }
    return ans;
}

int Cliente_setCuit(Cliente* this, char* cuit)
{
    int ans= -1;
    if (this != NULL && cuit!=NULL && isValidCuit(cuit))
    {
        ans=0;
        strcpy(this->cuit , cuit);

    }
    return ans;
}

int Cliente_getCuit(Cliente* this, char* cuit)
{
    int ans= -1;
    if (this != NULL && cuit!=NULL)
    {
        ans=0;
        strcpy(cuit , this->cuit);
    }
    return ans;
}

static int ultimoId = -1;

int Cliente_setNewId(Cliente* this)
{
    int ans= -1;

    if (this != NULL)
    {
        ultimoId++;
        this->id = ultimoId;
        ans=0;
    }
    return ans;
}

int Cliente_setId(Cliente* this, int id)
{
    int ans= -1;


    if (this != NULL)
    {
        if(id > ultimoId)
            ultimoId = id;

        this->id = ultimoId;
        ans=0;
    }
    return ans;
}

/*
int Cliente_getId(Cliente* this, int id)
{
    int ans= -1;
    if (this != NULL && id!=NULL)
    {
        ans=0;
        id = this->id;
    }
    return ans;
}
*/
//ENDREGION

//#REGION VALIDACIONES

int isValidDni(char* dni)
{
    int ans= -1;

    //validacion de parametros

    return ans=1;
}

int isValidNombre(char* nombre)
{
    int ans= -1;

    //validacion de parametros

    return ans=1;
}

int isValidApellido(char* apellido)
{
    int ans= -1;

    //validacion de parametros

    return ans=1;
}

int isValidCuit(char* cuit)
{
    int ans= -1;

    //validacion de parametros

    return ans=1;
}

int isValidSueldo(int sueldo)
{
    int ans= -1;

    //validacion de parametros

    return ans=1;
}

int isValidId (int id)
{
    int ans= -1;

    //validacion de parametros

    return ans=-1;
}


//ENDREGION
