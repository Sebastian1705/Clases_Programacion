//
//#include <stdio.h>
//#include <stdlib.h>
//#include "ArrayList.h"
//#include "Cliente.h"
//#include "DataManager.h"
//
//int dm_saveAll(ArrayList* pArrayClientes)
//{
//    int i;
//    int retorno=-1;
//    FILE* pArchivoClientes=fopen(ARCHIVO_ClienteS,"wb");
//    void* pCliente=NULL;
//    if(pArchivoClientes!=NULL)
//    {
//        for(i=0;i<al_len(pArrayClientes);i++)
//        {
//            pCliente=al_get(pArrayClientes,i);
//            fwrite(pCliente,sizeof(Cliente),1,pArchivoClientes);
//            retorno=0;
//        }
//
//    }
//    fclose(pArchivoClientes);
//    return retorno;
//}
//
//int dm_readAll(ArrayList* pArrayClientes)
//{
//    int retorno=-1;
//    Cliente auxCliente;
//    int maxId=0;
//    Cliente* pCliente=NULL;
//    FILE* pArchivoClientes=fopen(ARCHIVO_ClienteS,"rb");
//
//    if(pArchivoClientes!=NULL)
//    {
//        do{
//            if(fread(&auxCliente,sizeof(Cliente),1,pArchivoClientes)==1)
//            {
//                pCliente=soc_new(auxCliente.nombre,auxCliente.apellido,auxCliente.dni,auxCliente.id,auxCliente.estado);
//                al_add(pArrayClientes,pCliente);
//                if(auxCliente.id>maxId)
//                {
//                    maxId=auxCliente.id;
//                }
//                retorno=maxId;
//            }
//        }while(!feof(pArchivoClientes));
//        fclose(pArchivoClientes);
//    }
//    return retorno;
//}
