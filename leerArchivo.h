/**
 * @file leerArchivo.h
 *
 * Declaracion de la clase "Archivo" que es para abrir un archivo, extraer los numeros que estan escritos
 * dentro del documento (uno por linea) y los almacena en una cadena con un separador
 * 
 * @author Alejandro Delgado Rivera <AlejandroDR_IV@Outlook.com>
 * @version 2.0
 * @date 22/09/2021
 */

#pragma once

#include"listaDoble.h"
#include<stdlib.h> 

using namespace std;

class Archivo
{
    private:
        ifstream archivo;  // Archivo
        int cantNum;  // Cantidad de numeros que hay en el archivo
        string cadenaNumeros;  // Cadena que contendra todo los numeros

    public:
        /**
         * @brief Constructor de la clase "Archivo" que abrira el archivo con el nombre "nombreAch"
         * @param nombreArch Nombre del archivo
         */
        Archivo(string nombreArch);

        /**
         * @brief Metodo que regresa el numero "cantNum"
         * @return Cantidad de numeros que se encontraron en el archivo
         */
        int getCantNum();

        /**
         * @brief Metodo que regresara la cadena "cadenaNumeros"
         * @return Cadena de numeros separados por 'x'
         */
        string getCadenaNumeros();

        /**
         * @brief Metodo que recorrera el archivo y creara la cadena que contendra los numeros con una separacion
         */
        void contarNumerosYCrearCadenaNumeros();
};

#include"leerArchivo.hpp"