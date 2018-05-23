#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "DataManager.h"
#include "Validaciones.h"
#include "Vista.h"

int dm_saveAllX(ArrayList* pArrayX)
{
    //int i;
    int retorno=-1;
 /*
    FILE* pArchivoSocios=fopen(ARCHIVO_SOCIOS,"wb");
    void* pSocio=NULL;
    if(pArchivoSocios!=NULL)
    {
        for(i=0;i<al_len(pArraySocios);i++)
        {
            pSocio=al_get(pArraySocios,i);
            fwrite(pSocio,sizeof(Socio),1,pArchivoSocios);
            retorno=0;
        }

    }
    fclose(pArchivoSocios);
*/

/*

 int i;
    int retorno=-1;
    FILE* pFile=fopen("out.csv","w");
    void* pEmployees=NULL;
    if(pFile!=NULL)
    {
		fprintf(pFile,"id,first_name,last_name,age,type\n");
        for(i=0;i<al_len(list);i++)
        {
            pEmployees=al_get(list,i);
            fprintf(pFile, "%d,%s,%s,%d,%d\n", employee_getId(pEmployees),employee_getName(pEmployees), employee_getLastName(pEmployees), employee_getAge(pEmployees), employee_getType(pEmployees));

            retorno=0;
        }

    }
    fclose(pFile);
    return retorno;


*/


    return retorno;
}

int dm_readAllX(ArrayList* pArrayX)
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
/*
    FILE *pFile;
	Employee* auxEmployee;
	int retorno=-1;

    char var1[50],var2[50],var3[50],var4[50],var5[50];

    pFile = fopen("data.csv","r");

	if(pFile!=NULL)
    {
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5);
        do{
            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5) >0)
			{
				if(val_validarInt(var1)!=-1 && val_validarDescripcion(var2)!=-1 && val_validarDescripcion(var3)!=-1 && val_validarInt(var4)!=-1 && val_validarInt(var5)!=-1)
				{
					auxEmployee=employee_new(atoi(var1), var2, var3,atoi(var4), atoi(var5));
					al_add(nominaEmployees, auxEmployee);
					retorno=0;
				}
			}
		}while(!feof(pFile));
        fclose(pFile);
	}
	return retorno;

*/


    return retorno;
}

/*************************************************************/
/*
int dm_saveAllClientes(ArrayList* nominaClientes)
{
    int i;
    int retorno=-1;
    FILE* pFile=fopen("clientes.csv","w");
    Cliente* auxCliente=NULL;
    if(pFile==NULL)
    {
        vista_mostrarError("No se pudo abrir el archivo para escritura\n");
    }
    else
    {
		fprintf(pFile,"ID,NOMBRE,APELLIDO,DNI\n");
        for(i=0;i<al_len(nominaClientes);i++)
        {
            auxCliente=al_get(nominaClientes,i);
            fprintf(pFile, "%d,%s,%s,%s\n", cliente_getId(auxCliente),cliente_getNombre(auxCliente),cliente_getApellido(auxCliente),cliente_getDni(auxCliente));

            retorno=0;
        }
    }
    fclose(pFile);
    return retorno;
}

int dm_readAllClientes(ArrayList* nominaClientes)
{
    FILE *pFile;
	Cliente* auxCliente;
	int retorno=-1;
	int maxId=0;

    char id[10],nombre[50],apellido[50],dni[9];

    pFile = fopen("clientes.csv","r");

	if(pFile==NULL)
    {
        vista_mostrarError("No se pudo abrir el archivo para lectura\n");
    }
    else
    {
        char aux[200];
        fgets(aux,200,pFile); //leer primer fila
		//fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,dni);
        do{
            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,dni) >0)
			{
				if( val_validarUnsignedInt(id)!=-1 &&
                    val_validarString(nombre)!=-1 &&
                    val_validarString(apellido)!=-1 &&
                    validarDni(dni)!=-1)
				{
					auxCliente=cliente_new(atoi(id),nombre,apellido,dni,1);
					al_add(nominaClientes, auxCliente);
					if(auxCliente->id>maxId)
                    {
                        maxId=auxCliente->id;
                    }
                    retorno=maxId;
				}
			}
		}while(!feof(pFile));
        fclose(pFile);
	}
	return retorno;
}
*/
/*************************************************************/
/*

int dm_saveAllVentas(ArrayList* nominaVenta)
{
    int i;
    int retorno=-1;
    FILE* pFile=fopen("ventas.csv","w");
    Venta* auxVenta=NULL;
    if(pFile==NULL)
    {
        vista_mostrarError("No se pudo abrir el archivo para escritura\n");
    }
    else
    {
		fprintf(pFile,"id_venta,id_cliente,codProducto,cantidad,precioUnitario\n");
        for(i=0;i<al_len(nominaVenta);i++)
        {
            auxVenta=al_get(nominaVenta,i);
            fprintf(pFile, "%d,%d,%d,%d,%d\n",venta_getId_venta(auxVenta),venta_getId_cliente(auxVenta),venta_getCodProducto(auxVenta),venta_getCantidad(auxVenta),venta_getPrecioUnitario(auxVenta));

            retorno=0;
        }
    }
    fclose(pFile);
    return retorno;
}
*/
/*
int dm_readAllClientes(ArrayList* nominaClientes)
{
    FILE *pFile;
	Cliente* auxCliente;
	int retorno=-1;
	int maxId=0;

    char id[10],nombre[50],apellido[50],dni[9];

    pFile = fopen("clientes.csv","r");

	if(pFile==NULL)
    {
        vista_mostrarError("No se pudo abrir el archivo para lectura\n");
    }
    else
    {
        char aux[200];
        fgets(aux,200,pFile); //leer primer fila
		//fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,dni);
        do{
            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,dni) >0)
			{
				if( val_validarUnsignedInt(id)!=-1 &&
                    val_validarString(nombre)!=-1 &&
                    val_validarString(apellido)!=-1 &&
                    validarDni(dni)!=-1)
				{
					auxCliente=cliente_new(atoi(id),nombre,apellido,dni,1);
					al_add(nominaClientes, auxCliente);
					if(auxCliente->id>maxId)
                    {
                        maxId=auxCliente->id;
                    }
                    retorno=maxId;
				}
			}
		}while(!feof(pFile));
        fclose(pFile);
	}
	return retorno;
}
*/
/*************************************************************/
