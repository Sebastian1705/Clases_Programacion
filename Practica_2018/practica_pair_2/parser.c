#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Cliente.h"
#include "Validaciones.h"


int parserEmployee(char* path, ArrayList* pArrayListCliente)
{
    int retorno = -1;

    char bNombre[4096];
	char bApellido[4096];
	char bEmail[4096];
	char bGenero[4096];
	char bProfesion[4096];
	char bNacionalidad[4096];
	char bId[4096];
	char bUsuario[4096];

    Cliente* auxiliarCliente;
    FILE* pFile = fopen(path, "r");

    if(pFile != NULL)
    {
        retorno = 0;
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",bId,bNombre,bApellido,bEmail,
                                                                                bGenero,bProfesion,bUsuario,bNacionalidad);
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",bId,bNombre,bApellido,bEmail,
                                                                                bGenero,bProfesion,bUsuario,bNacionalidad);

            if( !val_validarUnsignedInt(bId) && !val_validarString(bNombre)&&
                !val_validarString(bApellido)&& !val_validarEmail(bEmail)&&
                !val_validarString(bGenero)&&   !val_validarString(bProfesion)&&
                !val_validarAlfanumerico(bUsuario)&& !val_validarString(bNacionalidad))
            {
                auxiliarCliente = cliente_new(bNombre,bApellido,bEmail,bGenero,bProfesion,bNacionalidad,atoi(bId),bUsuario);
                al_add(pArrayListCliente,auxiliarCliente);
                retorno =0;
            }

        }
    }

    return retorno;
}
