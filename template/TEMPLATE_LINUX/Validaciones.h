#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED



#endif // VALIDACIONES_H_INCLUDED

#define MAX_INPUT_BUFFER 4096


void myFgets(char* buffer, int limite,FILE* archivo);

int val_getString(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_validarString(char* buffer);

int val_getUnsignedInt(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_validarUnsignedInt(char* buffer);

int val_getInt(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_validarInt(char* buffer);

int val_getFloat(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_validarFloat(char* buffer);

int val_getEmail(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_validarEmail(char* buffer);

int getDni(char* destino, char* mensaje, char* mensajeError, int intentos, int limite);
int validarDni(char* buffer);

int val_getAlfanumerico(char* destino, char* mensaje, char* mensajeError, int intentos,int len);
int val_validarAlfanumerico(char* buffer);
