/**
 * @file leerArchivo.cpp
 *
 * Definicion de la clase "Archivo"
 * 
 * @author Alejandro Delgado Rivera <AlejandroDR_IV@Outlook.com>
 * @version 2.0
 * @date 22/09/2021
 */

#include"leerArchivo.h"

Archivo::Archivo(string nombreArch)
{
    // Abre el archivo
    archivo.open(nombreArch, ios::in);

    // Comprueba si se abrio correctamente el archivo
    if(!archivo.is_open())  {
        cout << "No fue posible abrir el archivo" << endl;
        exit(1);
    }
    
    // Inicializa las demas variables de clase
    cantNum = 0;
    cadenaNumeros = "";
}

int Archivo::getCantNum()
{
    return cantNum;
}

string Archivo::getCadenaNumeros()
{
    return cadenaNumeros;
}

void Archivo::contarNumerosYCrearCadenaNumeros()
{
    string tmp;
    // Recorre el archivo, cuenta la cantidad de lineas que hay en el archivo y extrae los numeros en formato "str"
    while(!archivo.eof())  {
        while(getline(archivo, tmp))  {
            // Ira concantenando los numeros y los separara con una "x"
            cadenaNumeros += tmp + 'x';
            cantNum++;
        }
    }

    // Se posiciona al inicio del archivo
    archivo.clear();
    archivo.seekg(0, archivo.beg);

    // Cierra el archivo
    archivo.close();
}