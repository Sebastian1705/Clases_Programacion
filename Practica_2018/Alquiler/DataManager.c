#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "DataManager.h"
#include "Cliente.h"
#include "Validaciones.h"

int dm_saveAllCliente(ArrayList* nominaCliente)
{
    int i;
    int retorno=-1;

    FILE* pFile=fopen("Clientes.txt","w");
    void* pCliente=NULL;
    if(pFile!=NULL)
    {
		fprintf(pFile,"Id,Nombre,Apellido,Dni\n");
        for(i=0;i<al_len(nominaCliente);i++)
        {
            pCliente=al_get(nominaCliente,i);
            fprintf(pFile, "%d,%s,%s,%s\n",cliente_getId(pCliente),cliente_getNombre(pCliente),cliente_getApellido(pCliente),cliente_getDni(pCliente));
            retorno=0;
        }
    }
    fclose(pFile);
    return retorno;
}

int dm_readAllCliente(ArrayList* nominaCliente)
{
    FILE *pFile;
	Cliente* auxCliente;
	int retorno=-1;
    int maxId = 0 ;
    char id[10], nombre[50], apellido[50], dni[10];
    pFile = fopen("Clientes.txt","r");

	if(pFile!=NULL)
    {
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,]\n",id,nombre,apellido,dni);
        do{
            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,]\n",id,nombre,apellido,dni) >0)
			{
				if(val_validarInt(id)!=-1 && val_validarString(nombre)!=-1 && val_validarString(apellido)!=-1 && val_validarDni(dni)!=-1)
				{
					auxCliente=cliente_new(nombre,apellido,dni,atoi(id),CLIENTE_ALTA);
					al_add(nominaCliente, auxCliente);
					if(cliente_getId(auxCliente) > maxId)
                    {
                        maxId = cliente_getId(auxCliente);
                    }
                    retorno = maxId;
				}
			}
		}while(!feof(pFile));
        fclose(pFile);
	}
	return retorno;
}

