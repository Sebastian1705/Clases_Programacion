#include "ArrayList.h"

int p_guardar(ArrayList* lista, char* archivo);
int p_leer(ArrayList* lista, char* archivo);

int p_leerMensajes(ArrayList* lista, char* archivo);
int p_leerUsuarios(ArrayList* lista, char* archivo);

int p_guardarFeeds(ArrayList* lista_mensajes, ArrayList* lista_usuarios, char* archivo);
