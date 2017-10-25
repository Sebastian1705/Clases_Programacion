#include "Calculadora.h"

int calculadora(float* resultadoDivision, float* resultadoSuma, float* resultadoResta, float* resultadoMultiplica, float num1, float num2)
{
    int retorno = -1;
    *resultadoSuma=num1+num2;
    *resultadoResta=num1-num2;
    *resultadoMultiplica=num1*num2;

    if(num2 != 0)
    {
        *resultadoDivision = num1/num2;
        retorno = 0;
    }
    return retorno;
}





int calculadora2(float* resultado, float num1, float num2, char operacion)
{
    int retorno = -1;

    switch(operacion)
    {
        case SUMA:
            *resultado=num1+num2;
            retorno = 0;
            break;
        case RESTA:
            *resultado=num1-num2;
            retorno = 0;
            break;
        case MULTIPLICACION:
            *resultado=num1*num2;
            retorno = 0;
            break;
        case DIVISION:
            if(num2 != 0)
            {
                *resultado = num1/num2;
                retorno = 0;
            }
            break;
        default:
            retorno=-2;


    }

    return retorno;
}
