#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include  <cstdio.h>
#include "ArrayList.h"
#include "deposito.h"
#include "formatos.h"
#include "lib.h"


int parserCSV(ArrayList* this, char nombre[])
{
    eDeposito *auxProducto;

    FILE* pFile;

    char auxproducto[50];
    char auxDescripcion[50];
    char auxCantidad[50];
    int cantidad=0;


    pFile=fopen(nombre,"r");
    if(pFile== NULL || this==NULL || strlen(nombre)==0)
    {
        return -1;
    }
    else
    {

        fscanf(pFile,"%[^,], %[^,], %[^\n]\n", auxproducto, auxDescripcion, auxCantidad);
        while(!(feof(pFile)))
        {
            auxProducto=deposito_newProducto();
            if(auxProducto!=NULL)
            {
                // leo del csv a auxiliares sueltos
                fscanf(pFile,"%[^,], %[^,], %[^\n]\n", auxproducto, auxDescripcion, auxCantidad);
                //copio del auxiliar suelto al e estructura
                deposito_setProducto(auxProducto,atoi(auxproducto));
                deposito_setCantidad(auxProducto, atoi(auxCantidad));
                deposito_setDescripcion(auxProducto, auxDescripcion);
                //agrego al array list AL FINAL
                al_add(this,auxProducto);
                cantidad++; // AGREGO

            }

        }

    }

    fclose(pFile);

    return cantidad;
}



/** \brief Guardar en Archivo en Array que se esta Trabajando
 *
 * \param PUNTERO A Array LIst
 * \param PUNTERO A FILE
 * \return  respuesta si es 1 no se genero el arhcivo correctamentem, si es cero todo OK
 */
int  archivos_guardarTexto(ArrayList *this, char nombre[])
{
    FILE *archivo;
    int cantidad=-1;
    int i=0;
    eDeposito*aux;
    ///////////////////////////
    archivo=fopen(nombre,"w");
    if(archivo==NULL)
    {
        return 1;
    }
    else
    {
        cantidad=this->len(this);
        fprintf(archivo,"Producto,Descripcion,Cantidad\n");
        while(i!=cantidad)
        {
            aux=(eDeposito*) this->get(this,i);
            fprintf(archivo,"%d,%s,%d\n",deposito_getProducto(aux),deposito_getDescripcion(aux),deposito_getCantidad(aux));
            i++;
        }
    }
    fclose(archivo);
    return i;
}


/** \brief
 *
 * \param
 * \param
 * \return
 *
 *//*
int archivos_guardarBinario(ArrayList* pArray, char nombreArchivo[])
{
   int i;
   int retorno=-1;
   FILE* fArchivo=fopen("datos22.bin","wb");
   void* pSocio=NULL;

   if(fArchivo!=NULL && pArray!=NULL)
   {

       for(i=0;i<al_len(pArray);i++)
       {
           pSocio=al_get(pArray,i);
           fwrite(pSocio,sizeof(eDeposito),1,fArchivo);
           retorno++;

       }

   }
   fclose(fArchivo);
   return (retorno+1);
}
*/
/** \brief
*
* \param
* \param
* \return
*
*//*
int archivos_leer(ArrayList* pArray)
{
   int retorno=-1;
   eDeposito *auxSocio;
   int maxId=0;
   int i=0;
   FILE* Socios=fopen("datos22.bin","rb");

   if(Socios!=NULL && pArray!=NULL )
   {
       retorno=0;
       do{
           auxSocio=persona_newUnaPersona();
           if(fread(auxSocio,sizeof(eDeposito),1,Socios))
           {

               al_add(pArray,auxSocio);
               retorno++;
               pArray->maxId=auxSocio->id;

           }
       }while(!feof(Socios));
       fclose(Socios);
   }
   return retorno;
}
*/
/** \brief
*
* \param
* \param
* \return
*
*//*
int archivos_leerMaxIdDOC(ArrayList* this)
{
   int retorno=-1;
   int maximo;
   int maxId=0;
   int i=0;
   char maximoId[10];
   FILE* Socios=fopen("maxId.doc","r");

   if(Socios==NULL &&this!=NULL)
   {
      Socios =fopen("maxId.doc","w");
      maxId=this->len(this);
      fprintf(Socios,"%d\n",maxId);
   }


   if(Socios!=NULL && this!=NULL )
   {
       retorno=0;
       do{
           fscanf(Socios,"%[^,]\n",maximoId);
           this->maxId =atoi(maximoId);

       }while(!feof(Socios));
       fclose(Socios);
   }
   return retorno;
}

/** \brief
*
* \param
* \param
* \return
*
*//*
int archivos_guardarMaxIdDOC(ArrayList* pArray)
{
   int retorno=-1;
   int maximo;
   int maxId=0;
   int i=0;
   char maximoId[10];
   FILE* Socios;

   if(Socios!=NULL && pArray!=NULL )
   {
      Socios =fopen("maxId.doc","w");
      do{
           fprintf(Socios,"%[^,]\n",pArray->maxId);
        }while(!feof(Socios));
   }

       fclose(Socios);

   return retorno;
}
*/




