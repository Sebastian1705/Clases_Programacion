#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED


char getNumeroAleatorio(int desde , int hasta, int iniciar);

int esFloat(char* str);
int esEntero(char* str);
int esAlfaNumerico(char* str);
int esSoloLetras(char* str);
char getChar(char* mensaje);
void getString(char* mensaje,char* input);

int getStringAlfanumerico(char* str,int len,char* mensaje,char* mensajeError,int intentos);
int getStringSoloLetras(char* str,int len,char* mensaje,char* mensajeError,int intentos);
int getStringNumeros(char* mensaje,char* input);
int getStringNumerosFlotantes(char* mensaje,char* input);

int getValidInt(char* mensaje,char* mensajeError, int* input,int desde, int hasta,int intentos);
int getValidFloat(char* mensaje,char* mensajeError, float* input,float desde, float hasta,int intentos);

void clearStdin(void);
void pause(void);
void clearScreen(void);



#endif // UTN_H_INCLUDED
