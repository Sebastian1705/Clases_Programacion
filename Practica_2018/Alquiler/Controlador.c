#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "DataManager.h"
#include "Vista.h"
#include "Cliente.h"
#include "Ventas.h"

static ArrayList* nominaCliente;
static int proximoIdCliente=0;
static int getNewIdCliente();
static int setNewIdCliente(int id);

static ArrayList* nominaVenta;
static int proximoIdVenta=0;
static int getNewIdVenta();
static int setNewIdVenta(int id);

void cont_init()
{
    nominaCliente = al_newArrayList();
    setNewIdCliente(dm_readAllCliente(nominaCliente) + 1);
    vista_init(VISTA_IDIOMA_ES);
    vista_mostrarMenu();
}

int cont_altaCliente (char* nombre,char* apellido,char* dni)
{
    Cliente* auxCliente;

    auxCliente = cliente_new(nombre,apellido,dni,getNewIdCliente(),CLIENTE_ALTA);
    al_add(nominaCliente, auxCliente);
    dm_saveAllCliente(nominaCliente);
    return 0;
}

int cont_bajaCliente (int id)
{
    Cliente* auxCliente;
    auxCliente = cliente_findById(nominaCliente,id);

    if(auxCliente != NULL)
    {
        //cliente_delete(auxCliente);
        cliente_setEstado(auxCliente,CLIENTE_BAJA);
        dm_saveAllCliente(nominaCliente);
    }
    return 0;
}


int cont_modificarCliente(int id,char* nombre,char* apellido,char* dni)
{
    Cliente* auxCliente;
    auxCliente = cliente_findById(nominaCliente, id);

    if(auxCliente != NULL)
    {
        cliente_setNombre(auxCliente,nombre);
        cliente_setApellido(auxCliente,apellido);
        cliente_setDni(auxCliente,dni);
        dm_saveAllCliente(nominaCliente);
    }
    return 0;
}

int cont_listarCliente ()
{
    vista_mostrarCliente(nominaCliente);
    return 0;
}

int cont_ordenarCliente ()
{
    al_sort(nominaCliente,cliente_compareByApellido,1);
    return 0;
}

static int getNewIdCliente()
{
    return proximoIdCliente++;
}

static int setNewIdCliente(int id)
{
    proximoIdCliente = id;
    return 0;
}

int cont_existeCliente(int id)
{
    int retorno = -1;
    Cliente* auxCliente = cliente_findById(nominaCliente,id);

    if (auxCliente != NULL && cliente_getEstado(auxCliente) == CLIENTE_ALTA)
    {
        retorno = 0;
    }
    return retorno;
}


static int getNewIdVenta()
{
    return proximoIdVenta++;
}

static int setNewIdVenta(int id)
{
    proximoIdVenta = id;
    return 0;
}

int cont_altaVenta(int idCliente,int producto, int cantidad)
{
    Ventas* auxVenta;
    float precio = 0;
    if(producto == IPHONE7)
    {
        precio = PRECIO_IPHONE7;
    }
    else if(producto == PS4)
    {
        precio = PRECIO_PS4;
    }
    else
    {
        precio = PRECIO_TV_LG_32;
    }
    auxVenta = ventas_new(getNewIdVenta(),idCliente,producto,cantidad,precio,VENTA_ACTIVA);
    al_add(nominaVenta, auxVenta);
    //dm_saveAllVenta(nominaVenta);
    return 0;
}



void imprimir_ventas(void* pVentas) //cambiar nombre entidad
{
    float montoFacturado = ventas_getCantidad(pVentas)*ventas_getPrecioUnitario(pVentas);
    int idCliente;
    Cliente* pCliente;
    idCliente = ventas_getId_clientes(pVentas);
    pCliente = cliente_findById(nominaCliente, idCliente);

    if(pVentas != NULL && pCliente != NULL)
    {
        if(ventas_getEstado(pVentas) == VENTA_ACTIVA && cliente_getEstado(pCliente) == CLIENTE_ALTA)
        {
            printf("Id_venta: %d\tnombre_cliente: %s\tapellido_cliente: %s\tdni_cliente: %s\tcodigo_producto: %d\tmonto_facturado: %f\n",
                    ventas_getId_ventas(pVentas),cliente_getNombre(pCliente),cliente_getApellido(pCliente),
                    cliente_getDni(pCliente),ventas_getCodProducto(pVentas),montoFacturado);
        }
    }
}

