#ifndef VALIDAR_H_INCLUDED
#define VALIDAR_H_INCLUDED
#define MAX_INPUT_BUFFER 4096


#endif // VALIDAR_H_INCLUDED

int val_validarNombre(char* buffer);
int val_getNombre(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
void myFgets(char* buffer, int limite ,FILE* archivo);
int val_getUnsignedInt(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_validarUnsignedInt(char* buffer);
int validarDni(char* buffer);
int getDni(char* destino, char* mensaje, char* mensajeError, int intentos, int limite);
