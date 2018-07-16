#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "DataManager.h"
#include "Cliente.h"
#include "Validaciones.h"
#include "Ventas.h"

int dm_saveAllCliente(ArrayList* nominaCliente)
{
    int i;
    int retorno=-1;

    FILE* pFile=fopen("Clientes.txt","w");
    void* pCliente=NULL;
    if(pFile!=NULL)
    {
        fprintf(pFile,"Id,Nombre,Apellido,Dni\n");
        for(i=0; i<al_len(nominaCliente); i++)
        {
            pCliente=al_get(nominaCliente,i);
            fprintf(pFile, "%d,%s,%s,%s\n",cliente_getId(pCliente),cliente_getNombre(pCliente),
                    cliente_getApellido(pCliente),cliente_getDni(pCliente));
            retorno=0;
        }
    }
    fclose(pFile);
    return retorno;
}

int dm_readAllCliente(ArrayList* nominaClientes)
{
    int retorno = -1;
    char bId[4096];
    char bNombre[4096];
    char bApellido[4096];
    char bDni[4096];

    FILE* pFile = fopen("Clientes.txt", "r");
    int maxId=0;

    Cliente* auxiliarCliente;

    if(pFile != NULL)
    {
        retorno = 0;
        if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bId,bNombre,bApellido,bDni)==4)
        {
            do
            {
                if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bId,bNombre,bApellido,bDni)==4)
                {
                    if( !val_validarUnsignedInt(bId) && !val_validarString(bNombre)&&
                            !val_validarString(bApellido) && !val_validarDni(bDni))
                    {
                        auxiliarCliente = cliente_new(bNombre,bApellido,bDni,atoi(bId),CLIENTE_ALTA);
                        al_add(nominaClientes,auxiliarCliente);
                        if(cliente_getId(auxiliarCliente)>maxId)
                        {
                            maxId=cliente_getId(auxiliarCliente);
                        }
                        retorno=maxId;
                    }
                }
            }
            while(!feof(pFile));
        }
    }

    return retorno;
}


int dm_saveAllVenta(ArrayList* nominaVenta)
{
    int i;
    int retorno=-1;

    FILE* pFile=fopen("Ventas.txt","w");
    void* pVenta=NULL;
    if(pFile!=NULL)
    {
        fprintf(pFile,"Id_venta,Id_cliente,codProducto,cantidad,precioUnitario\n");
        for(i=0; i<al_len(nominaVenta); i++)
        {
            pVenta=al_get(nominaVenta,i);
            fprintf(pFile, "%d,%d,%d,%d,%f\n", ventas_getId_ventas(pVenta),ventas_getId_clientes(pVenta),
                                    ventas_getCodProducto(pVenta),ventas_getCantidad(pVenta),ventas_getPrecioUnitario(pVenta));
            retorno=0;
        }
    }
    fclose(pFile);
    return retorno;
}
