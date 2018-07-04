#include "generador.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "ArrayList.h"
#include <ctype.h>

int esString(char* texto);
void borrarEspacios(char* texto);
char* finStruct(char* texto);

EGenerar* campo_new()
{
    EGenerar* this;
    this=malloc(sizeof(EGenerar));
    return this;
}

void campo_delete(EGenerar* this)
{
    free(this);
}

int parserHeader(ArrayList* lista,char* nombreStruct,char archivo[50])
{
    FILE* fileH;
    int retorno=-1;

    EGenerar* this;


    char h[]=".h";
    char archivoH[42];
    char* token;

    char lineaVariable[70];
    char tipoVariable[25];
    char nombreVariable[45];
    int cantidadChars;

    char* auxiliarEstructura;
    char header[100];

    if(lista!=NULL)
    {
        getString("Ingresar nombre de archivo sin extension: ",archivo);
        strcpy(archivoH,archivo);
        strcat(archivoH,h);
        fileH=fopen(archivoH,"r");

        if(fileH!=NULL)
        {
            fscanf(fileH,"%[^\{]",header);
            fgets(lineaVariable,100,fileH);
            do
            {
                fgets(lineaVariable,100,fileH);
                borrarEspacios(lineaVariable);
                auxiliarEstructura=finStruct(lineaVariable);
                if(auxiliarEstructura!=NULL)
                {
                    strcpy(nombreStruct,auxiliarEstructura);
                    break;
                }
                if(esString(lineaVariable))
                {
                    this=campo_new();

                    token=strtok(lineaVariable," ");

                    token=strtok(NULL,"[");
                    strcpy(nombreVariable,token);
                    campo_setNombreCampo(this,nombreVariable);

                    token=strtok(NULL,"[");
                    token=strtok(token,"]");
                    cantidadChars=atoi(token);
                    campo_setCantidadChars(this,cantidadChars);
                    campo_setEsString(this,1);
                    al_add(lista,this);
                    printf("%s %s[%d]\n",tipoVariable,nombreVariable,cantidadChars);
                }
                else
                {
                    this=campo_new();
                    token=strtok(lineaVariable," ");
                    strcpy(tipoVariable,token);

                    token=strtok(NULL," ");
                    strcpy(nombreVariable,token);

                    campo_setEsString(this,0);
                    campo_setNombreCampo(this,nombreVariable);
                    campo_setTipoVariable(this,tipoVariable);
                    al_add(lista,this);
                    printf("%s %s\n",tipoVariable,nombreVariable);
                }
            }while(1);
            retorno=0;
        }

    }
    fclose(fileH);
    return retorno;
}

/** \brief Saca los espacios al principio de la linea y el punto y coma al final
 *
 * \param texto char*
 * \return void
 *
 */
void borrarEspacios(char* texto)
{
    int i;
    int len=strlen(texto);
    int j;

    for(i=0;i<len;i++)
    {
        if(texto[i]!=' ')
        {
            for(j=0;j<len-i;j++)
                texto[j]=texto[j+i];
            break;
        }
    }
    texto=strtok(texto,";");
}

char* finStruct(char* texto)
{
    int len;
    int i;
    char* retorno;
    char* token;
    retorno=NULL;

    len=strlen(texto);

    for(i=0;i<len;i++)
    {
        if(texto[i]=='}')
        {
            token=strtok(texto,"}");
            retorno=token;
            break;
        }
    }
    return retorno;
}

int esString(char* texto)
{
    int i=0;
    int retorno=0;
    if(texto!=NULL)
    {
        while(texto[i]!=';')
        {
            if(texto[i]=='[')
            {
                retorno=-1;
                break;
            }
            i++;
        }
    }
    return retorno;
}

int campoNuevo(ArrayList* listaCampos)
{
    char nombreCampo[40];
    int esString;
    int cantidadChars=0;
    EGenerar* this;
    char tipoVariable[15];
    int retorno=-1;

    if(listaCampos!=NULL)
    {
        this=campo_new();
        getStringSoloLetras(nombreCampo,40,"Ingresar nombre campo: ","Error\n",1);
        if(!campo_setNombreCampo(this,nombreCampo))
        {
            getValidInt("Ingresar si es string (1 es string, 0 no es string): ","Error",&esString,0,1,1);
            if(!campo_setEsString(this,esString))
            {
                if(esString)
                {
                    getValidInt("Ingresar cantidad de caracteres del string: ","Error\n",&cantidadChars,0,200,1);
                }
                else
                getStringSoloLetras(tipoVariable,40,"Ingresar tipo de variable(float, int, char): ","Error\n",1);
                if(!campo_setTipoVariable(this,tipoVariable))
                {
                    if(!campo_setCantidadChars(this,cantidadChars))
                    {
                        campo_setId(this,-1);
                        if(!al_add(listaCampos,this))
                        {
                            retorno=0;
                        }
                    }
                }
            }
        }
    }

    if(retorno==-1)
        free(this);

    return retorno;
}

int mostrarCampos(ArrayList* listaCampos)
{
    char nombreCampo[40];
    int esString;
    int cantidadChars;
    int id;
    int i;
    int retorno=-1;
    EGenerar* this;
    char tipoVariable[15];

    int len=al_len(listaCampos);

    if(listaCampos!=NULL&&len>0)
    {
        for(i=0;i<len;i++)
        {   this=al_get(listaCampos,i);
            campo_getId(this,&id);
            campo_getNombreCampo(this,nombreCampo);
            campo_getEsString(this,&esString);
            if(esString)
                campo_getCantidadChars(this,&cantidadChars);
            else
                campo_getTipoVariable(this,tipoVariable);
            if(esString)
                printf("char %s[%d];\n\n",nombreCampo,cantidadChars);
            else
                printf("%s %s;\n\n",tipoVariable,nombreCampo);
            retorno=0;
        }
    }
    return retorno;
}

int borrarCampo(ArrayList* listaCampos)
{
    int retorno=-1;
    int i;
    int len=al_len(listaCampos);
    EGenerar* this;
    char nombreCampo[50];
    int indexABorrar;

    if(listaCampos!=NULL)
    {
        for(i=0;i<len;i++)
        {
            this=al_get(listaCampos,i);
            campo_getNombreCampo(this,nombreCampo);
            printf("%d: %s\n",i,nombreCampo);
        }
        getValidInt("\nNumero a borrar?: ","Error\n",&indexABorrar,0,len,1);
        if(!al_remove(listaCampos,indexABorrar))
            retorno=0;
    }
    return retorno;
}

int campo_setNombreCampo(EGenerar* this,char* nombre)
{
    int retorno=-1;

    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombreCampo,nombre);
        retorno=0;
    }

    return retorno;
}

int campo_getNombreCampo(EGenerar* this,char* nombre)
{
    int retorno=-1;

    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombreCampo);
        retorno=0;
    }

    return retorno;
}

int campo_setTipoVariable(EGenerar* this,char* tipoVariable)
{
    int retorno=-1;

    if(this!=NULL && tipoVariable!=NULL)
    {
        strcpy(this->tipoVariable,tipoVariable);
        retorno=0;
    }

    return retorno;
}

int campo_getTipoVariable(EGenerar* this,char* tipoVariable)
{
    int retorno=-1;

    if(this!=NULL && tipoVariable!=NULL)
    {
        strcpy(tipoVariable,this->tipoVariable);
        retorno=0;
    }

    return retorno;
}

int campo_setEsString(EGenerar* this,int esString)
{
    int retorno=-1;
    if(this!=NULL && (esString==1 || esString==0))
    {
        this->esString=esString;
        retorno=0;
    }
    return retorno;
}

int campo_getEsString(EGenerar* this,int* esString)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *esString=this->esString;
    }
    return retorno;
}


int campo_setCantidadChars(EGenerar* this,int cantidadChars)
{
    int retorno=-1;
    if(this!=NULL )
    {
        this->cantidadChars=cantidadChars;
        retorno=0;
    }
    return retorno;
}

int campo_getCantidadChars(EGenerar* this,int* cantidadChars)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *cantidadChars=this->cantidadChars;
    }
    return retorno;
}

int campo_setId(EGenerar* this,int id)
{
    static int ultimoId=-1;
    int retorno=-1;

    if(this!=NULL && id==-1)
    {
        ultimoId++;
        retorno=0;
        this->id=ultimoId;
    }
    else if(this!=NULL)
    {
        ultimoId=id;
        retorno=0;
        this->id=ultimoId;
    }

    return retorno;
}

int campo_getId(EGenerar* this,int* id)
{
    int retorno=-1;
    if(this!=NULL && id!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int generarArchivos(char* nombreStruct,char* prefijo,ArrayList* listaCampos,char* nombreArchivo)
{
    int i;
    int retorno=-1;
    FILE* archivo;
    char nombreCampo[40];
    int esString=0;
    char tipoVariable[15];
    int cantidadChars;
    char nombreCampoFuncion[40];
    int len=al_len(listaCampos);

    char c[]=".c";
    char h[]=".h";


    char nombreArchivoHeaders[50];
    char archivoC[100];
    char archivoH[100];

    EGenerar* this;

    if(listaCampos!=NULL && len>0)
    {
        this=campo_new();
        retorno=0;
        if(nombreArchivo!=NULL)
        {
            strcpy(nombreArchivoHeaders,nombreArchivo);
            while(nombreArchivoHeaders[i]!='\0')
            {
                nombreArchivoHeaders[i]=toupper(nombreArchivo[i]);
                i++;
            }
            strcpy(archivoC,nombreArchivo);
            strcpy(archivoH,nombreArchivo);

            strcat(archivoC,c);
            strcat(archivoH,h);

            archivo=fopen(archivoH,"w");
            fprintf(archivo,"#ifndef %s_H_INCLUDED\n#define %s_H_INCLUDED\ntypedef struct\n{\n",nombreArchivoHeaders,nombreArchivoHeaders);
            for(i=0;i<len;i++)
            {
                this=al_get(listaCampos,i);
                campo_getNombreCampo(this,nombreCampo);
                campo_getEsString(this,&esString);

                if(esString)
                {
                    campo_getCantidadChars(this,&cantidadChars);
                    fprintf(archivo,"    char %s[%d];\n",nombreCampo,cantidadChars);
                }
                else
                {
                    campo_getTipoVariable(this,tipoVariable);
                    fprintf(archivo,"    %s %s;\n",tipoVariable,nombreCampo);
                }
            }
            fprintf(archivo,"}%s;\n\n",nombreStruct);
            fprintf(archivo,"%s* %s_new();\n",nombreStruct,prefijo);
            fprintf(archivo,"void %s_delete();\n\n",prefijo);
            for(i=0;i<len;i++)
            {
                this=al_get(listaCampos,i);
                campo_getNombreCampo(this,nombreCampo);
                campo_getEsString(this,&esString);

                strcpy(nombreCampoFuncion,nombreCampo);
                nombreCampoFuncion[0]=toupper(nombreCampo[0]);

                if(esString)
                {
                    fprintf(archivo,"int %s_set%s(%s* this,char* %s);\n",prefijo,nombreCampoFuncion,nombreStruct,nombreCampo);
                    fprintf(archivo,"int %s_get%s(%s* this,char* %s);\n\n",prefijo,nombreCampoFuncion,nombreStruct,nombreCampo);

                }
                else
                {
                    campo_getTipoVariable(this,tipoVariable);
                    fprintf(archivo,"int %s_set%s(%s* this,%s %s);\n",prefijo,nombreCampoFuncion,nombreStruct,tipoVariable,nombreCampo);
                    fprintf(archivo,"int %s_get%s(%s* this,%s* %s);\n\n",prefijo,nombreCampoFuncion,nombreStruct,tipoVariable,nombreCampo);
                }
            }
            fprintf(archivo,"#endif // %s_H_INCLUDED\n",nombreArchivoHeaders);
            fclose(archivo);


            archivo=fopen(archivoC,"w");
            fprintf(archivo,"#include \"%s\"\n#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\n\n",archivoH);
            fprintf(archivo,"%s* %s_new()\n{\n    %s* this;\n    this=malloc(sizeof(%s));\n    return this;\n}\n\n",nombreStruct,prefijo,nombreStruct,nombreStruct);
            fprintf(archivo,"void %s_delete(%s* this)\n{\n    free(this);\n}\n\n",prefijo,nombreStruct);
            for(i=0;i<len;i++)
            {
                this=al_get(listaCampos,i);
                campo_getNombreCampo(this,nombreCampo);
                campo_getEsString(this,&esString);
                strcpy(nombreCampoFuncion,nombreCampo);
                nombreCampoFuncion[0]=toupper(nombreCampo[0]);
                if(esString)
                {
                    campo_getCantidadChars(this,&cantidadChars);
                    fprintf(archivo,"int %s_set%s(%s* this,char* %s)\n",prefijo,nombreCampoFuncion,nombreStruct,nombreCampo);
                    fprintf(archivo,"{\n    int retorno=-1;\n    if(this!=NULL && %s!=NULL)\n    {\n        strcpy(this->%s,%s);\n        retorno=0;\n    }\n    return retorno;\n}\n\n",nombreCampo,nombreCampo,nombreCampo);
                    fprintf(archivo,"int %s_get%s(%s* this,char* %s)\n",prefijo,nombreCampoFuncion,nombreStruct,nombreCampo);
                    fprintf(archivo,"{\n    int retorno=-1;\n    if(this!=NULL && %s!=NULL)\n    {\n        strcpy(%s,this->%s);\n        retorno=0;\n    }\n    return retorno;\n}\n\n",nombreCampo,nombreCampo,nombreCampo);
                }
                else
                {
                    campo_getTipoVariable(this,tipoVariable);
                    fprintf(archivo,"int %s_set%s(%s* this,%s %s)\n",prefijo,nombreCampoFuncion,nombreStruct,tipoVariable,nombreCampo);
                    fprintf(archivo,"{\n    int retorno=-1;\n    if(this!=NULL)\n    {\n        this->%s=%s;\n        retorno=0;\n    }\n    return retorno;\n}\n\n",nombreCampo,nombreCampo);
                    fprintf(archivo,"int %s_get%s(%s* this,%s* %s)\n",prefijo,nombreCampoFuncion,nombreStruct,tipoVariable,nombreCampo);
                    fprintf(archivo,"{\n    int retorno=-1;\n    if(this!=NULL)\n    {\n        *%s=this->%s;\n        retorno=0;\n    }\n    return retorno;\n}\n\n",nombreCampo,nombreCampo);
                }
                retorno=0;
            }


            fclose(archivo);
            }
    }

    if(!retorno)
        printf("Archivos generados\n%s\n%s\n",archivoC,archivoH);
    return retorno;
}


