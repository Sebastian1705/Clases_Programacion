#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED
#include "ArrayList.h"


/**
 *  Inicializa el array con los productos guardados en el archivo .csv
 * \param pArrayProductos ArrayList*
 * \return int
 *
 */
int cargarDepositos(ArrayList* pArrayDepositos, char* archivoDep);


/**
 *  Guarda en el archivo .csv los productos cargados
 * \param pArrayProductos ArrayList*
 * \return int
 *
 */
int guardarDepositos(ArrayList* pArrayDepositos, char* archivoDep);

#endif // PARSER_H_INCLUDED
