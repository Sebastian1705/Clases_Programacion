#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Cliente.h"
#include "Servicio.h"
#include "DataManager.h"
#include "Validaciones.h"
#include "Controlador.h"

int dm_saveAllClientes(ArrayList* pArrayClientes)
{
    int i;
    int retorno=-1;
    FILE* pArchivoSocios=fopen(ARCHIVO_CLIENTES,"wb");
    void* pSocio=NULL;
    if(pArchivoSocios!=NULL)
    {
        for(i=0; i<al_len(pArrayClientes); i++)
        {
            pSocio=al_get(pArrayClientes,i);
            fwrite(pSocio,sizeof(Cliente),1,pArchivoSocios);
            retorno=0;
        }

    }
    fclose(pArchivoSocios);
    return retorno;
}

int dm_readAllClientes(ArrayList* pArrayClientes)
{
    int retorno=-1;
    Cliente auxSocio;
    int maxId=0;
    Cliente* pSocio=NULL;
    FILE* pArchivoSocios=fopen(ARCHIVO_CLIENTES,"rb");

    if(pArchivoSocios!=NULL)
    {
        do
        {
            if(fread(&auxSocio,sizeof(Cliente),1,pArchivoSocios)==1)
            {
                pSocio=cliente_new(auxSocio.nombre,auxSocio.apellido,auxSocio.dni,auxSocio.id,auxSocio.estado);
                al_add(pArrayClientes,pSocio);
                if(auxSocio.id>maxId)
                {
                    maxId=auxSocio.id;
                }
                retorno=maxId;
            }
        }
        while(!feof(pArchivoSocios));
        fclose(pArchivoSocios);
    }
    return retorno;
}


int dm_saveAllServicios(ArrayList* pArrayServicios)
{
    int i;
    int retorno=-1;
    FILE* pArchivoSocios=fopen(ARCHIVO_SERVICIOS,"wb");
    void* pSocio=NULL;
    if(pArchivoSocios!=NULL)
    {
        for(i=0; i<al_len(pArrayServicios); i++)
        {
            pSocio=al_get(pArrayServicios,i);
            fwrite(pSocio,sizeof(Servicio),1,pArchivoSocios);
            retorno=0;
        }
    }
    fclose(pArchivoSocios);
    return retorno;
}

/*
int dm_readAllServicios(ArrayList* pArrayServicios)
{

    int retorno=-1;
    Servicio auxServicio;
    int maxId=0;
    Servicio* pServ=NULL;
    FILE* pF=fopen(ARCHIVO_SERVICIOS,"rb");

    if(pF!=NULL)
    {
        do{
            if(fread(&auxServicio,sizeof(Servicio),1,pF)==1)
            {
                pServ=serv_new(auxServicio.id);

                al_add(pArrayServicios,pServ);
                if(auxServicio.id>maxId)
                {
                    maxId=auxServicio.id;
                }
                retorno=maxId;
            }
        }while(!feof(pF));
        fclose(pF);
    }
    return retorno;
}
*/





int dm_readAllClientesTxt()
{
    FILE *pFile;

    int retorno=-1;

    char nombre[50],apellido[50],dni[50];

    pFile = fopen("clientes.csv","r");
    if(pFile == NULL)
    {
        printf("No se pudo abrir el archivo para lectura\n");
    }
    else
    {
        char aux[200];
        fgets(aux,200,pFile); //leer primer fila
        //fscanf(pFile,"%[^\n]\n",aux,aux,aux,aux,aux);

        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^\n]\n",nombre,apellido,dni);
            //if(val_validarString(nombre) == 0 && val_validarString(apellido) == 0 && validarDni(dni) == 0 &&)

            {
                cont_altaCliente(nombre, apellido, dni);
                retorno = 0;
            }
        }
    }
    return retorno;

}

