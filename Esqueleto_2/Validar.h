#ifndef VALIDAR_H_INCLUDED
#define VALIDAR_H_INCLUDED



#endif // VALIDAR_H_INCLUDED
#define MAX_INPUT_BUFFER 4096

void val_myFgets(char* buffer, int len ,FILE* archivo);

int val_getCadena(char* destino, char* mensaje, char* mensajeError, int intentos,int len);
int val_validarCadena(char* buffer);

int val_getFloat(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_validarFloat(char* buffer);

int val_getInt(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_validarInt(char* buffer);

int val_getDni(char* destino, char* mensaje, char* mensajeError, int intentos, int limite);
int val_validarDni(char* buffer);
