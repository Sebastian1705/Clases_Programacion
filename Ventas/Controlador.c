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

    nominaVenta = al_newArrayList();
    setNewIdVenta(dm_readAllVentas(nominaVenta) + 1);

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


int cont_existeVenta(int id)
{
    int retorno = -1;
    Ventas* auxVentas = ventas_findById_ventas(nominaVenta,id);

    if (auxVentas != NULL && ventas_getEstado(auxVentas) == VENTA_ACTIVA)
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
    dm_saveAllVentas(nominaVenta);
    return 0;
}

void cont_imprimir_ventas(void* pVentas) //cambiar nombre entidad
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
            printf("Id_venta: %d\tnombre_cliente: %s\tapellido_cliente: %s\tdni_cliente: %s\tcodigo_producto: %d\tmonto_facturado: %.2f\n",
                    ventas_getId_ventas(pVentas),cliente_getNombre(pCliente),cliente_getApellido(pCliente),
                    cliente_getDni(pCliente),ventas_getCodProducto(pVentas),montoFacturado);
        }
    }
}

int cont_listarVentas()
{
    vista_mostrarVentas(nominaVenta);
    return 0;
}

int cont_bajaVenta(int id)
{
    Ventas* auxVenta;
    auxVenta = ventas_findById_ventas(nominaVenta,id);

    if(auxVenta != NULL)
    {
        //Venta_delete(auxVenta);
        ventas_setEstado(auxVenta,VENTA_BAJA);
        dm_saveAllVentas(nominaVenta);
    }
    return 0;
}

int cont_listarVentasProducto(int codProducto)
{
    Cliente* auxCliente;
    Ventas* auxVentas;
    int i=0, idCliente;
    float montoFacturado;

    for(i=0;i<al_len(nominaVenta);i++)
    {
        auxVentas = al_get(nominaVenta,i);
        idCliente = ventas_getId_clientes(auxVentas);
        auxCliente = cliente_findById(nominaCliente,idCliente);
        montoFacturado = ventas_getCantidad(auxVentas)*ventas_getPrecioUnitario(auxVentas);

        if(auxCliente != NULL && auxVentas != NULL && ventas_getCodProducto(auxVentas) == codProducto)
        {
            if(ventas_getEstado(auxVentas) == VENTA_ACTIVA && cliente_getEstado(auxCliente) == CLIENTE_ALTA)
            {
                printf("Id_venta: %d\tnombre_cliente: %s\tapellido_cliente: %s\tdni_cliente: %s\tcodigo_producto: %d\tmonto_facturado: %.2f\n",
                    ventas_getId_ventas(auxVentas),cliente_getNombre(auxCliente),cliente_getApellido(auxCliente),
                    cliente_getDni(auxCliente),ventas_getCodProducto(auxVentas),montoFacturado);
            }
        }
    }
    return 0;
}

int cont_generarInforme()
{
    dm_generarInforme(nominaCliente,nominaVenta);
    return 0;
}

int cont_informarVentasCliente()
{

    return 0;
}
