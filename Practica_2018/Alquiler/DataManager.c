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

int dm_readAllCliente(ArrayList* nominaClientes)
{
    int retorno=-1;
 /*
    Socio auxSocio;
    int maxId=0;
    Socio* pSocio=NULL;
    FILE* pArchivoSocios=fopen(ARCHIVO_SOCIOS,"rb");
    if(pArchivoSocios!=NULL)
    {
        do{
            if(fread(&auxSocio,sizeof(Socio),1,pArchivoSocios)==1)
            {
                pSocio=socio_new(auxSocio.id,auxSocio.nombre,auxSocio.apellido,auxSocio.dni,auxSocio.estado);
                al_add(pArraySocios,pSocio);
                if(auxSocio.id>maxId)
                {
                    maxId=auxSocio.id;
                }
                retorno=maxId;
            }
        }while(!feof(pArchivoSocios));
        fclose(pArchivoSocios);
    }
*/

    FILE *pFile;
	Cliente* auxCliente;

    char var1[50],var2[50],var3[50],var4[50];
    pFile = fopen("data.csv","r");
	if(pFile!=NULL)
    {
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
        do{
            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4) >0)
			{
				//if(val_validarInt(var1)!=-1 && val_validarDescripcion(var2)!=-1 && val_validarDescripcion(var3)!=-1 && val_validarInt(var4)!=-1 && val_validarInt(var5)!=-1)

					auxCliente=cliente_new(var1,var2,var3,atoi(var4),CLIENTE_ALTA);
					al_add(nominaClientes, auxCliente);
					retorno=0;

			}
		}while(!feof(pFile));
        fclose(pFile);
	}

    return retorno;
}
