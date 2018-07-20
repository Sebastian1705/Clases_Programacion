
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "deposito.h"
#include "archivos.h"
#include "lib.h"


/** \brief LIMPIAR PANATALLA
 *
 */
void cleanScreen (void)
{
    printf("\n");
    system ("pause");
    system ("cls");
}


/** \brief Pregunta S o N
* *
* \param texto de la pregunta
* \return respuesta
*
*/
int preguntarSiNo ( char texto [])
{
    char respuestachar;
    int respuesta;

    printf("%s S o N:", texto);
    fflush(stdin);
    scanf("%c", &respuestachar);
    tolower(respuestachar);
    while (respuestachar != 's' && respuestachar !='n')
    {
        fflush(stdin);
        printf(" \nRespuesta Incorrecta-%s\t",texto);
        scanf("%c", &respuestachar);
    }
    switch (respuestachar)
    {
       case 's':
            respuesta=1;
            break;
        case 'n':
            respuesta=0;
            break;
    }

return respuesta;
}

/** \brief devolver numero random float //////////arreglar!!!!!!!
 * \param
 * \param
 * \return
 *
 */

float devolverPuntaje()
{
    float random;
    srand(time(NULL));
    random = (rand()%11)+1;
    return random;

}

////////////////////////////////////////


/** \brief INGRESA CUALQUIER TEXTO
 *
 * \param ARRAY DE CHAR
 * \param TAMANIO DEL ARRAY
 * \param PREGUNTA
 * \return
 *
 */
void ingresarTexto (char texto[], int cantTexto, char pregunta[])
{
    char titulo [50];
    char auxtitulo [cantTexto-1];
    int i;

    printf("%s\t", pregunta);
    fflush(stdin);
    gets (titulo);
    for (i=0; i<cantTexto; i++)
    {
        auxtitulo[i]=titulo[i];
    }
    strcpy(texto, auxtitulo);
}
/** \brief INGRESA CUALQUIER NUMERO
 *
 * \param ARRAY DE CHAR
 * \param TAMANIO DEL ARRAY
 * \param PREGUNTA
 * \return
 *
 */
int ingresarInt (char pregunta[], int minimo,int maximo)
{
    int numero;

    printf("%s\t", pregunta);
    fflush(stdin);
    scanf("%d", &numero);

    while(numero>maximo|| numero<minimo|| isalpha(numero))
    {
        fflush(stdin);
        printf("\nReingrese %s\t", pregunta);
        scanf("%d", &numero);
    }
    return numero;
}

/** \brief FUCNION PARA ELEGIR EL GENERO
 *
 * \param ARRAY ESTRUCTURA EMOVIE
 * \param POSICION EN EL ARRAY
 * \return
 *
 *//*
void pedirGenero (EMovie pelicula[], int i)
{
    int auxGenero;
    printf("\n----------------------\n");
    printf("Ingrese El Genero\n");
    printf("----------------------");
    printf("\n 1- Terror\t");
    printf("\n 2- Comedia\t");
    printf("\n 3- Drama\t");
    printf("\n 4- Dibujos Animados\t");
    printf("\n 5- Accion\t");
    printf("\n 6- Ciencia Ficcion\t");
    printf("\n 7- Otro\t");
      do {
    fflush(stdin);
    printf("\n \nSeleccione la opcion deseada\t");
    scanf("%d", &auxGenero);

                switch (auxGenero)
                {
                case 1:
                    strcpy(pelicula[i].genero, "Terror");
                    break;
                case 2:
                    strcpy(pelicula[i].genero, "Comedia");
                    break;
                case 3:
                    strcpy(pelicula[i].genero, "Drama");
                    break;
                case 4:
                    strcpy(pelicula[i].genero, "DA");
                    break;
                case 5:
                    strcpy(pelicula[i].genero, "Accion");
                    break;
                case 6:
                    strcpy(pelicula[i].genero, "CF");
                    break;
                case 7:
                    strcpy(pelicula[i].genero, "Otro");
                    break;
                case 8:
                    strcpy(pelicula[i].genero, "Otro");
                    break;
                default:
                    fflush(stdin);
                    printf("\n-----------------------------\n");
                    printf(" NO INGRESO UNA OPCION VALIDA\t");
                     printf("\n-----------------------------\n");
                    auxGenero=0;
                    break;
                }
    }while (auxGenero==0);

}



/** \brief FUCNION PARA ELEGIR EL GENERO
 *
 * \param ARRAY ESTRUCTURA EMOVIE
 * \param POSICION EN EL ARRAY
 * \param TAMAÑO DEL NOMBRE DEL ARCHIVO
 * \return
 *
 *//*
  void asignarNombrehtml (EMovie pelicula [], int j, int lenLink)
  {
      char buffer [50];
      char aux [lenLink];
      int i;

      strcpy(buffer, pelicula[j].titulo);
      strcat(buffer,"-");
      strcat(buffer,pelicula[j].genero);

      for (i=0; i<lenLink-5; i++)
        {
            aux[i]=buffer[i];
        }

        strcat(aux,".html");


      strcpy(pelicula[j].nombreArchivo, aux);
      RemoveSpaces(pelicula[j].nombreArchivo);

     // printf("\nel nombre del archivo %s\t",pelicula[j].nombreArchivo);

 }

/** \brief VALIDACION DE LA CARGA DE DESCRIPCION
 *
 * \param ARRAY ESTRUCTURA EMOVIE
 * \param TAMANIO DEL ARRAY
 * \param CANTIDAD DE LETRAS QUE TENDRA EL TEXTO
 * \return
 *
 *//*
void pedirDescripcion(EMovie pelicula [], int j, int lenDescrip)
  {
      char buffer [1500];
      char aux [lenDescrip];
      int i;

       printf("Ingrese Descripcion\t");
       fflush(stdin);
       gets(buffer);

      for (i=0; i<lenDescrip; i++)
        {
            aux[i]=buffer[i];
        }

      strcpy(pelicula[j].descripcion, aux);

    //  printf("\nla descripcioon es  %s\t\n",pelicula[j].descripcion);

 }

/** \brief VALIDACION DE LA CARGA DE LINK
 *
 * \param ARRAY ESTRUCTURA EMOVIE
 * \param TAMANIO DEL ARRAY
 * \param CANTIDAD DE LETRAS QUE TENDRA EL LINK
 * \return
 *
 *//*
void pedirLink(EMovie pelicula [], int j, int lenLink)
  {
      char buffer [1500];
      char aux [lenLink];
      int i;

     printf("Ingrese URL\t");
     fflush(stdin);
     gets(buffer);

      for (i=0; i<lenLink; i++)
        {
            aux[i]=buffer[i];
        }

      strcpy(pelicula[j].linkImagen, aux);

 //     printf("\nel link  es  %s\t\n",pelicula[j].linkImagen);

 }


 /** \brief Valida que se cree el ArrayList
  *
  * \param puntero a array
  * \param
  * \return
  *
  */

int validaArrayList (eDeposito*this)
{
    if (this==NULL)
    {
        printf("\n NO hay memoria disponible                \n");
        return 0;
    }
    else
    {
        return 1;
    }

}


