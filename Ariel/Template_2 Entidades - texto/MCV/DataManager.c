#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Cliente.h"
#include "Alquiler.h"
#include "DataManager.h"
#include "Validaciones.h"


int dm_readAllCliente(ArrayList* pArrayCliente)
{
    FILE *pFile;
    Cliente* auxCliente;
    int maxId=0, retorno=-1;

    char id[50],name[50],lastName[50],dni[50],estado[50];

    pFile = fopen(ARCHIVO_CLIENTES,"r");
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
           fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,name,lastName,estado,dni);
           if (val_getUnsignedIntFromFile(id,0,9999) == 0 &&
               val_validarString(name) == 0 &&
               val_validarString(lastName) == 0 &&
               val_esDni(dni) == 0 &&
               val_getUnsignedIntFromFile(estado,0,2) == 0)
               {
                        auxCliente = cliente_new(atoi(id),name,lastName,atoi(estado),dni);
                        al_add(pArrayCliente,auxCliente);
                        if(auxCliente->id>maxId)
                        {
                            maxId=auxCliente->id;
                        }
                        retorno=maxId;
               }
        }
    }
    return retorno;
}

int dm_saveAllCliente(ArrayList* nominaCliente)
{
    int i,retorno = -1;
    FILE *pArchivo;
    pArchivo=fopen(ARCHIVO_CLIENTES, "w");
    if(pArchivo == NULL)
    {
        printf("No se pudo abrir el archivo para escritura\n");
    }
    else
    {
        fprintf(pArchivo,"id;nombre;apellido;estado;dni\n");
        Cliente* auxCliente;
        for(i=0; i<al_len(nominaCliente); i++)
        {
            auxCliente = al_get(nominaCliente,i);
            //if(auxCliente->estado == EMPLEADO_ESTADO_ACTIVO)
            //{
                fprintf(pArchivo,"%d,%s,%s,%d,%s\n", cliente_getId(auxCliente),
                        cliente_getNombre(auxCliente),cliente_getApellido(auxCliente),
                        cliente_getEstado(auxCliente),cliente_getDni(auxCliente));
            //}
        }
        retorno = 0;
    }
    fclose(pArchivo);
    //printf("\nArchivo guardado con exito\n");
    return retorno;
}






/**********************************************///Alquiler


int dm_readAllAlquiler(ArrayList* pArrayAlquiler)
{
    FILE *pFile;
    Alquiler* auxAlquiler;
    int maxId=0, retorno=-1;

    char id[50],idCliente[50],equipo[50],estado[50];

    pFile = fopen(ARCHIVO_ALQUILER,"r");
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
           fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,idCliente,equipo,estado);
           if (val_getUnsignedIntFromFile(id,0,9999) == 0 &&
               val_getUnsignedIntFromFile(idCliente,0,9999) == 0 &&
               val_getUnsignedIntFromFile(equipo,0,9999) == 0 &&
               val_getUnsignedIntFromFile(estado,0,2) == 0)
               {
                        auxAlquiler = alquiler_new(atoi(id),atoi(idCliente),atoi(equipo),atoi(estado));
                        al_add(pArrayAlquiler,auxAlquiler);
                        if(auxAlquiler->id>maxId)
                        {
                            maxId=auxAlquiler->id;
                        }
                        retorno=maxId;
               }
        }
    }
    return retorno;
}

int dm_saveAllAlquiler(ArrayList* nominaAlquiler)
{
    int i,retorno = -1;
    FILE *pArchivo;
    pArchivo=fopen(ARCHIVO_ALQUILER, "w");
    if(pArchivo == NULL)
    {
        printf("No se pudo abrir el archivo para escritura\n");
    }
    else
    {
        fprintf(pArchivo,"id;nombre;apellido;estado;dni\n");
        Alquiler* auxAlquiler;
        for(i=0; i<al_len(nominaAlquiler); i++)
        {
            auxAlquiler = al_get(nominaAlquiler,i);
            //if(auxAlquiler->estado == EMPLEADO_ESTADO_ACTIVO)
            //{
                fprintf(pArchivo,"%d,%d,%d,%d\n", alquiler_getId(auxAlquiler),
                        alquiler_getIdCliente(auxAlquiler),alquiler_getEquipo(auxAlquiler),
                        alquiler_getEstado(auxAlquiler));
            //}
        }
        retorno = 0;
    }
    fclose(pArchivo);
    //printf("\nArchivo guardado con exito\n");
    return retorno;
}

