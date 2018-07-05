#ifndef GETSVALIDS_H_INCLUDED
#define GETSVALIDS_H_INCLUDED

int get_Int(char* mensaje, int *input);
int get_Float(char* mensaje, float *input);
int get_Long(char* mensaje, long *input);
int get_Char(char* mensaje, char *input);
int get_String(char* mensaje, char *input);
int val_numero(char *str);
int val_flotante(char *str);
int val_letras(char *str);
int val_alfaNumerico(char *str);
int val_email(char *str);
int val_telefono(char *str);
int val_noespacios(char *str);

int get_stringLetras(char *mensaje,char *input);
int get_stringNumeros(char *mensaje,char *input);
int get_stringFlotantes(char *mensaje,char *input);
int get_stringAlfaNumerico(char *mensaje,char *input);
int get_stringNoespacios(char *mensaje,char *input);

int get_validInt(char *requestMessage,char *errorMessage, int* input,int lowLimit, int hiLimit,int attemps);
int get_validLong(char *requestMessage,char *errorMessage, long* input,long lowLimit, long hiLimit,int attemps);
int get_validLetras(char *requestMessage,char *errorMessage, char *errorMessageLenght,char *input, int maxLenght,int attemps);
int get_validStringNumeros(char *requestMessage,char *errorMessage, char *errorMessageLenght,char *input, int maxLenght,int attemps);
int get_validFloat(char *requestMessage,char *errorMessage, float* input,int lowLimit, int hiLimit,int attemps);
int get_validAlfaNumerico(char *requestMessage,char *errorMessage, char *errorMessageLenght,char *input, int maxLenght,int attemps);
int get_validStringSinEspacios(char *requestMessage,char *errorMessage, char *errorMessageLenght,char *input, int maxLenght,int attemps);

#endif // GETSVALIDS_H_INCLUDED
