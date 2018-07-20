
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "deposito.h"
#include "archivos.h"
#include "lib.h"

int  formato_ABM_Archivo(ArrayList * depo1, ArrayList * depo0)
{
    int i;
    int opcion;
    int opcion2;
    int opcion3;
    int auxflag=0;
    int flagArchivo=0;
    int auxArchivo;
    char nombreArchivo [20];
    eDeposito aux;
    eDeposito* aux2;
    int auxiliaNumero;
    int*auxNum;
    eDeposito*pAux;
    int aux15;
    int aux_Baja;
    ArrayList*ordenada;


    do
    {
        flagArchivo=0;
        printf("\r\n\r\n********************************************************************\r\n");
        printf("******    MENU ABM GENERICO CON 2 ARRAY LIST - ARCHIVO CSV ************\r\n");
        printf("********************************************************************\r");
        printf("\n\t 1- Leer de Archivo\n\t 2- Alta\n\t 3- Dar de Baja un Producto cualquier deposito \n\t 4- Reducir Stock \n\t 5- Aumentar Stock \n\t 6- Listar\n\t "
               "7- Mover entre Depositos \n\t 0- Salir\tSeleccione la opcion: \t");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 2:///////////////////ALTA
            printf("\nEn que deposito desea agregar? \n1- Deposito 0 \n2- Deposito 1 \n");
            scanf( "%d", &opcion3 );
            switch (opcion3)
            {
            case 1:
                formato_altaProducto(depo0);
                formato_respuestaFlagArchivo(archivos_guardarTexto(depo0,"dep0.csv"));
                break;
            case 2:
                formato_altaProducto(depo1);
                formato_respuestaFlagArchivo(archivos_guardarTexto(depo1,"dep1.csv"));
                break;
            }
            cleanScreen();
            break;
        case 3: //////////// FORMATO BAJA
            formato_baja(depo0, depo1);
            cleanScreen();
            break;
        case 4: ////////////////// MENOS STOCK
            formato_bajaStock(depo0, depo1);
            cleanScreen();
            break;
        case 5: ////////////////// MAS STOCK
            formato_sumaStock(depo0, depo1);
            cleanScreen();
            break;
        case 6: /////////LISTAR
            printf("\n Que listado desea ver? \n1- Deposito 0 \n2- Deposito 1 \n");
            scanf( "%d", &opcion3 );
            switch (opcion3)
            {
            case 1:
                formato_listadoDeposito(depo0);
                break;
            case 2:
                formato_listadoDeposito(depo1);
                break;

            default:
                fflush(stdin);
                printf("\nNO INGRESO UNA OPCION VALIDA\n");
                cleanScreen();
                break;
            }
            cleanScreen();
            break;
        case 1: ////////////// LEER CSV
            flagArchivo=parserCSV(depo0, "dep0.csv");
            flagArchivo+=parserCSV(depo1, "dep1.csv"); // ver como funciona este codigo
            formato_respuestaFlagArchivo(flagArchivo);
            cleanScreen();
            break;
        case 7: /////////////// mover de un deposito al otro
            printf("\n Que movimiento desea realizar \n1- Mover de Dep0 a Dep1 \n2- Mover de Dep1 a Dep0  \n");
            scanf( "%d", &opcion3 );
            switch (opcion3)
            {
            case 1:
                formato_movimientoEntreDepositos(depo0, depo1);
                formato_respuestaFlagArchivo(archivos_guardarTexto(depo0,"dep0.csv"));
                formato_respuestaFlagArchivo(archivos_guardarTexto(depo1,"dep1.csv"));
                break;
            case 2:
                formato_movimientoEntreDepositos(depo1, depo0);
                formato_respuestaFlagArchivo(archivos_guardarTexto(depo0,"dep0.csv"));
                formato_respuestaFlagArchivo(archivos_guardarTexto(depo1,"dep1.csv"));
                break;
            default:
                fflush(stdin);
                printf("\nNO INGRESO UNA OPCION VALIDA\n");
                cleanScreen();
                break;
            }
            cleanScreen();
            break;
        case 0:
            printf("\r\n\r\n*********************************************\r\n");
            printf("******        CHAU       ************\r\n");
            printf("************************************************\r");
            cleanScreen();
            break;

        default:
            fflush(stdin);
            printf("\nNO INGRESO UNA OPCION VALIDA\n");
            cleanScreen();
            break;
        }

        /*

            flagArchivo=0;
            formato_respuestaFlagArchivo(archivos_guardarTexto(depo1,"dep1.csv"));*/
    }
    while (opcion !=0);
}

/** \brief FORMATO de respuesta al guardar un archivo
 *
 * \param flag de respuesta del guardado del archivo
 * \return void
 *
 */

void formato_respuestaFlagArchivo(int flagArchivo)
{
    if (flagArchivo>=1)
    {
        printf("\n-------------------------------\n");
        printf("\nDatos Guardados en Archivo\n");
        printf("\n-------------------------------\n");
    }
    else
    {
        printf("\n-------------------------------\n");
        printf("\nNO SE PUDO COPIAR EL ARCHIVO\n");
        printf("\n-------------------------------\n");
    }

}


void formato_listadoDeposito (ArrayList *this)
{
    int i;
    eDeposito*pAux;

    if(!(this->isEmpty(this)))
    {
        printf("\r\n\r\n********************************************************************\r\n");
        printf("***********    Productos: %d   ************\r\n",al_len(this));
        printf("********************************************************************\r\n");
        printf("**|  Producto  |          Descripcion                  ||     Cantidad    |**\r\n");

        for (i=0; i<al_len(this); i++ )
        {
            //casteo a una estructura  COPIO LA DIRECCION DE MEMORIA DE LA INFO QUE QUIERO
            pAux=(eDeposito*)al_get(this,i);
            printf("**|     %3d    |          %8s                     ||       %d        |**\r\n", deposito_getProducto(pAux),deposito_getDescripcion(pAux), deposito_getCantidad(pAux));

            if (i%100==0 &&i!=0)// CONVERTIR ESTO EN FUNCION
            {
                printf("\n\n");
                system("pause");
            }
        }
    }
    else
    {
        printf("\r\n\r\n********************************************************************\r\n");
        printf("***********    NO HAY ELEMENTOS CARGADOS - Elementos: %d   ************\r\n",al_len(this));
        printf("********************************************************************\r\n");
    }

}


void formato_OrdenarNombre(ArrayList *this)
{
    if(this->len(this)>1)
    {
        printf("\n-------------------------------------\n");
        //    al_sort(this, persona_compareName, (ingresarInt("Que orden prefiere?\n 1- A-Z\n 0- Z-A       :", 0, 1)));
        printf("\r\n\r\n********************************************************************\r\n");
        printf("***********    ORDEN REALIZADO - Elementos: %d   ************\r\n",al_len(this));
        printf("********************************************************************\r\n");
    }
    else
    {
        printf("\r\n\r\n********************************************************************\r\n");
        printf("***********    NO HAY ELEMENTOS SUFICIENTES - Elementos: %d   ************\r\n",al_len(this));
        printf("********************************************************************\r\n");
    }
}


void formato_baja (ArrayList*this, ArrayList*this2)
{
    int aux_Baja;
    int flag=0;
    int i;
    eDeposito* aux;

    if(this->len(this)>0 && this2->len(this2)>0)
    {
        printf("\n-------------------------------------\n");
        aux_Baja=ingresarInt("Que numero de productos desea dar de baja?", 0, 100);
        //////////////////////FUNCION QUE BUSCA EL INDEX DEL NRO DE PRODUCXTO INGRESADO/////////
        for (i=0; i<this->len(this); i++)
        {
            aux= al_get(this, i);
            if (aux->producto == aux_Baja)
            {
                flag=1;
                break;
            }
        }

        if (flag ==0)
        {
            for (i=0; i<this2->len(this2); i++)
            {
                aux= al_get(this2, i);
                if (aux->producto == aux_Baja)
                {
                    flag=2;
                    break;
                }
            }
        }
        else
        {
            al_remove(this,i);
        }

        if (flag== 2)
        {
            al_remove(this2, i);
        }

        formato_respuestaFlagArchivo(archivos_guardarTexto(this,"dep0.csv"));
        formato_respuestaFlagArchivo(archivos_guardarTexto(this2,"dep1.csv"));


    }
    else
    {
        printf("\r\n\r\n********************************************************************\r\n");
        printf("***********    NO HAY ELEMENTOS CARGADOS - Elementos: %d   ************\r\n",al_len(this));
        printf("********************************************************************\r\n");
    }
}




void formato_bajaStock (ArrayList*this, ArrayList*this2)
{
    int aux_Baja;
    int flag=0;
    int i;
    eDeposito* aux;
    int stock;

    if(this->len(this)>0 && this2->len(this2)>0)
    {
        printf("\n-------------------------------------\n");
        aux_Baja=ingresarInt("Que Producto desea descontar stock?", 0, 100);
        //////////////////////FUNCION QUE BUSCA EL INDEX DEL NRO DE PRODUCXTO INGRESADO/////////
        for (i=0; i<this->len(this); i++) // busca en el deposito 1
        {
            aux= al_get(this, i);
            if (aux->producto == aux_Baja)
            {
                flag=1;
                break;
            }
        }

        if (flag ==0) // si no esta en el 1
        {
            for (i=0; i<this2->len(this2); i++) // busca en el deposito 2
            {
                aux= al_get(this2, i);
                if (aux->producto == aux_Baja)
                {
                    flag=2;
                    break;
                }
            }
        }

        if (flag>0)
        {
            printf("\n\nEL STOCK DEL PRODUCO %d - %s es -> %d", aux->producto,  aux->descripcion,aux->cantidad);
            if(preguntarSiNo("\nDesea Modificarlo?"))
            {
                printf("\nIngrese la cantidad a descontar:");
                scanf("%d", &stock);

                if( stock <= aux->cantidad && stock >0)
                {
                    aux->cantidad-=stock;
                }
                else
                {
                    printf("\nEl descuento ingresado no es valido\n");
                }
                if (stock == aux->cantidad)
                {
                    printf("\nPara borrar - opcion 2\n");
                }


            }
        }


    }
    else
    {
        printf("\r\n\r\n********************************************************************\r\n");
        printf("***********    NO HAY ELEMENTOS CARGADOS - Elementos: %d   ************\r\n",al_len(this));
        printf("********************************************************************\r\n");
    }
}


void formato_sumaStock (ArrayList*this, ArrayList*this2)
{
    int aux_Baja;
    int flag=0;
    int i;
    eDeposito* aux;
    int stock;

    if(this->len(this)>0 && this2->len(this2)>0)
    {
        printf("\n-------------------------------------\n");
        aux_Baja=ingresarInt("Que Producto desea Agregar stock?", 0, 100);
        //////////////////////FUNCION QUE BUSCA EL INDEX DEL NRO DE PRODUCXTO INGRESADO/////////
        for (i=0; i<this->len(this); i++) // busca en el deposito 1
        {
            aux= al_get(this, i);
            if (aux->producto == aux_Baja)
            {
                flag=1;
                break;
            }
        }

        if (flag ==0) // si no esta en el 1
        {
            for (i=0; i<this2->len(this2); i++) // busca en el deposito 2
            {
                aux= al_get(this2, i);
                if (aux->producto == aux_Baja)
                {
                    flag=2;
                    break;
                }
            }
        }

        if (flag>0)
        {
            printf("\n\nEL STOCK DEL PRODUCO %d - %s es -> %d", aux->producto,  aux->descripcion,aux->cantidad);
            if(preguntarSiNo("\nDesea Modificarlo?"))
            {
                printf("\nIngrese la cantidad a Agregar:");
                scanf("%d", &stock);

                if( stock >0)
                {
                    aux->cantidad+=stock;
                }
                else
                {
                    printf("\nEl descuento ingresado no es valido\n");
                }
                if (stock <= 0)
                {
                    printf("\nNo ingreso un numero valido\n");
                }


            }
        }


    }
    else
    {
        printf("\r\n\r\n********************************************************************\r\n");
        printf("***********    NO HAY ELEMENTOS CARGADOS - Elementos: %d   ************\r\n",al_len(this));
        printf("********************************************************************\r\n");
    }
}


/*
void formato_leerArchivo(ArrayList*this)
{
    int aux15;
    int flagArchivo=0;

        printf("\n\t 1- CSV\n\t 2- BInario \n\t\tSeleccione la opcion: \t");
        scanf("%d", &aux15);
        switch (aux15)
        {
        case 1:
            flagArchivo=parserCSV(this, "data.csv");
            formato_respuestaFlagArchivo(flagArchivo);
            cleanScreen();
            break;
        case 2:
            flagArchivo=archivos_leer(this);
            formato_respuestaFlagArchivo(flagArchivo);
            cleanScreen();
            break;
        default:
            printf("\nNO INGRESO UNA OPCION VALIDA\n");
            fflush(stdin);
            cleanScreen();
            break;

        }
}
*/
/** \brief FORMATO - alta de producto
 *
 * \param puntero arraylist
 * \param
 * \return
 *
 */

void formato_altaProducto ( ArrayList* this)
{
    eDeposito aux;
    eDeposito*pAux;
    do
    {
        printf("\n--------------Ingreso de nuevo-----------------------\n");
        aux.producto=ingresarInt("Nro Producto", 0, 100);
        ingresarTexto(aux.descripcion, 20, "Descripcion:");
        aux.cantidad=ingresarInt("Cantidad:", 1, 200);
        printf("\n-------------------------------------\n");
        pAux= deposito_newProductoParam(aux.producto,aux.descripcion,aux.cantidad);
        if (pAux!=NULL)
        {
            al_add(this, pAux);
            deposito_printProducto(pAux);
        }
    }
    while(preguntarSiNo("\nDesea cargar otra producto en el mismo deposito?\n"));
}


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void formato_movimientoEntreDepositos ( ArrayList* this1, ArrayList *this2)
{
    int aux_Baja;
    int i;
    eDeposito* aux2;

    formato_listadoDeposito(this1);
    printf("\n-------------------------------------\n");
    aux_Baja=ingresarInt("Que numero de productos desea mover?", 0, 100);

    for (i=0; i<this1->len(this1); i++)
    {
        aux2= al_get(this1, i);
        if (aux2->producto == aux_Baja)
        {
            al_add(this2, aux2);
            al_remove(this1,i);
            printf(" \n Movimiento Confirmado \n");
            break;
        }
    }
}

