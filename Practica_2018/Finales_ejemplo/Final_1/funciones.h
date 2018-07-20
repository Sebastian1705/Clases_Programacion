#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "deposito.h"
#include "ArrayList.h"

/**
 *  Solicita datos al usuario para crear un producto
 * \return EProducto* Devuelve el producto creado
 *
 */
EProducto* crearProducto();

/**
 *  Agrega un producto y la guarda en el archivo csv
 *  @param producto la estructura a ser agregada
 *  @return int [0] OK , [-1]Error
 */
int agregarProducto(ArrayList* pArrayDeposito, EProducto* producto);

/**
 *  Borra una pelicula y guarda la eliminacion en el archivo csv
 *  @param pArrayProducto ArrayList*
 *  @return int [0] OK , [-1]Error
 */
int borrarProducto(ArrayList* pArrayPeliculas);

/**
 *  Modifica pelicula pidiendo el nombre a modificar al usuario, y guarda en el archivo csv
 * \param pArrayProductos ArrayList*
 * \return int [0] OK , [-1]Error
 */
int modificarProducto(ArrayList* pArrayPeliculas);


#endif // FUNCIONES_H_INCLUDED
