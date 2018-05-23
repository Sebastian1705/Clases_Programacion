#ifndef VALIDAR_H_INCLUDED
#define VALIDAR_H_INCLUDED

#endif // VALIDAR_H_INCLUDED


void myFgets(char* buffer, int limite ,FILE* archivo);

int val_getInt(int* destino, char* mensaje,char* mensajeError,int intentos,int lowLimit, int hiLimit);
int val_validarInt(char* buffer);

int val_getUnsignedInt(int* destino, char* mensaje,char* mensajeError,int intentos,int lowLimit, int hiLimit);
int val_soloNumeros(char* buffer);

int val_getFloat(float* destino, char* mensaje,char* mensajeError,int intentos,float lowLimit, float hiLimit);
int val_esNumericoFlotante(char str[]);

int val_getUnsignedFloat(float* destino, char* mensaje,char* mensajeError,int intentos,float lowLimit, float hiLimit);
int val_esUnsignedFloat(char str[]);

int val_getString(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_validarString(char* buffer);

int val_getNombre(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_esSoloLetras(char* buffer);

int val_getAlfanumerico(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_esAlfaNumerico(char str[]);

int val_getDni(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_esDni(char* buffer);

int val_getEmail(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_validarEmail(char* buffer);

int val_getDate(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_validarDate(char str[]);

int val_getTime(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_validarTime(char str[]);



char val_getUnsignedIntFromFile(char* destino, int lowLimit, int hiLimit);
int val_getFloatFromFile(char* destino, float lowLimit, float hiLimit);

