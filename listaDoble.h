/**
 * @file listaDoble.h
 *
 * Declaracion de la clase "ListaDoble" que tendra la implementacion de los algoritmos para el ordenamiento y creacion de una lista doblemente ligada
 * Dentro de la clase tambien se define la clase "Nodo" que se usaran en la clase "ListaDoble"
 * 
 * @author Alejandro Delgado Rivera <AlejandroDR_IV@Outlook.com>
 * @version 1.0
 * @date 21/09/2021
 */

#pragma once

#include<iostream>
#include<cstring>
#include<fstream>

using namespace std;

/**
 * @brief Funcion que convierte una cadena de caracteres a un entero
 * @param strNumero Numero en formato "str"
 * @param cantDigitos Cantidad de digitos
 * @return Numero convertido
 */
int strToInt(string strNumero, int cantDigitos);

template<typename T>
class ListaDoble
{
    private:
        class Nodo  // Definicion de la clase "Nodo"
        {
            public:
                const T &data;  // Dato almacenado en el nodo
                Nodo *sig;  // Puntero al nodo siguiente
                Nodo *prev;  // Puntero al nodo anterior

                /**
                * @brief Constructor de la clase "Nodo" que inicializara los valores de los punteros a "nullptr"
                * @param data Dato que se desea almacenar
                */
                Nodo(const T &data) : data(data), sig(nullptr), prev(nullptr)  {  }
        };

        Nodo *cabeza;  // Puntero que apunta al primer nodo de la lista

    public:
        /**
         * @brief Constructor de la clase "ListaDoble" que inicializara el valor del puntero "cabeza" a "nullptr"
         */
        ListaDoble() : cabeza(nullptr)  {  }

        /**
         * @brief Constructor de la clase "ListaDoble" que inicializara el valor del puntero "cabeza"
         * @param cabeza Puntero cabeza de la lista
         */
        ListaDoble(Nodo *cabeza) : cabeza(cabeza)  {  }

        /**
         * @brief Metodo que regresara el puntero "cabeza"
         * @return Puntero cabeza de la lista doblemente ligada
         */
        Nodo* getCabeza();

        /**
         * @brief Metodo que regresara un puntero a "cabeza"
         * @return Puntero a cabeza de la lista doblemente ligada
         */
        Nodo** getCabezaDireccion();

        /**
         * @brief Metodo que asignara un valor a "cabeza"
         * @param cabeza Nuevo puntero cabeza de la lista doblemente ligada
         */
        void setCabeza(Nodo *cabeza);

        /**
         * @brief Metodo que insertara un nodo al principio de la lista doblemente ligada
         * @param dato Dato que se desea agregar a la lista
         */
        void listInsert(const T &dato);

        /**
         * @brief Metodo que buscara el dato "datoBuscado" en la lista doblemente ligada y se regresara un puntero a ese nodo
         * @param datoBuscado Dato que se desea buscar
         * @return Puntero a nodo
         */
        Nodo* listSearch(const T &datoBuscado);

        /**
         * @brief Metodo que eliminara el nodo al que apunta el parametro
         * @param node Nodo que se desea eliminar
         */
        void listDelete(Nodo *node);

        /**
         * @brief Metodo que busca el nodo con el dato "datoEliminado" para eliminar el nodo que lo contiene
         * @param datoEliminado Dato que se eliminara de la lista
         */
        void listDeleteData(const T &datoEliminado);

        /**
         * @brief Metodo que imprimira los datos de la lista doblemente ligada
         */
        void imprimirLista();

        /**
         * @brief Metodo que imprimira los datos de la lista doblemente ligada al reves
         */
        void imprimirAlReves();

        /**
         * @brief Metodo que escribe el contenido de la lista doblemente ligada en un archivo de texto
         * @param nombre Nombre del archivo de salida
         */
        void escribirArrDocTxt(string nombre);

    /**
     * @brief Funcion que aplica el algoritmo de Merge Sort en una lista doblemente ligada
     * @param cabezaLista Puntero a cabeza de la lista a la que se le aplicara el algorimo de ordenacion
     */
    friend void mergeSort(Nodo **cabezaLista)
    {
        // Inicializacion de puntero auxiliar
        Nodo *ptrAux = *cabezaLista;
        
        // Si la lista tiene un elemento o no tiene elementos detiene la recurrencia
        if(ptrAux == nullptr || ptrAux->sig == nullptr) return;

        pair<Nodo *, Nodo *> particion = divideList(*cabezaLista);
        mergeSort(&particion.first);
        mergeSort(&particion.second);
        *cabezaLista = mergeLists(particion.first, particion.second);
    }

    /**
     * @brief Funcion que divide la lista a la mitad
     * @param cabezaListaDividida Cabeza de la lista doblemente ligada que se desea dividir
     * @return Un par de cabezas de dos listas
     */
    friend pair<Nodo *, Nodo *> divideList(Nodo *cabezaListaDividida)
    {
        /* Inicializa los punteros que se usaran para dividir la lista:
           el primer puntero apunta al primer nodo de la lista y el segundo apunta al segundo nodo de la lista */
        Nodo *tmpAuxSlow = cabezaListaDividida;
        Nodo *tmpAuxFast = tmpAuxSlow->sig;

        // Bucle que se repetira mientras "tmpAuxFast" pueda avanzar
        while(tmpAuxFast->sig)  {
            tmpAuxFast = tmpAuxFast->sig;
            // Si puede "tmpAuxFast" puede avanzar de nuevo
            if(tmpAuxFast->sig)  {
                // Si el primer puntero se pudo mover dos nodos, entonces el segundo puntero sse mueve uno
                tmpAuxFast = tmpAuxFast->sig;
                tmpAuxSlow = tmpAuxSlow->sig;
            }
        }
        // El siguiente de "tmpAuxSlow" sera la cabeza de la siguiente lista
        tmpAuxSlow = tmpAuxSlow->sig;
        // Desconecta las listas
        tmpAuxSlow->prev->sig = nullptr;
        tmpAuxSlow->prev = nullptr;

        // Regresa el par de cabezas de la lista dividida
        return make_pair(cabezaListaDividida, tmpAuxSlow);
    }

    /**
     * @brief Funcion que mezcla dos listas
     * @param L Cabeza de la primera lista
     * @param R Cabeza de la segunda lista
     * @return Un puntero cabeza de la lista ordenada
     */
    friend Nodo* mergeLists(Nodo *L, Nodo *R)
    {
        // Declaracion de variable que contendra la mezcla de las dos listas anteriores en orden
        ListaDoble mergedLists;
        // Inicializacion de variable auxiliar para agregar nodos a la lista "mergedLists"
        Nodo *tmpAux = nullptr;

        // Primero debe inicializar la cabeza de "mergedLists"
        // Si "L" apunta a un nodo con dato que es mayor o igual al que apunta "R"
        if(L->data >= R->data)  {
            mergedLists.setCabeza(R);
            tmpAux = mergedLists.getCabeza();
            R = R->sig;
        }
        // Si "R" apunta a un nodo con dato que es mayor al que apunta "L"
        else if(R->data > L->data)  {
            mergedLists.setCabeza(L);
            tmpAux = mergedLists.getCabeza();
            L = L->sig;
        }

        // Bucle que se repetira hasta que se acabe de recorrer una de las listas
        while(L || R)  {
            // Si ya se ha recorrido "listaL" en su totalidad y todavia hay elementos en "listaR"
            if(L == nullptr && R)  {
                tmpAux->sig = R;
                R->prev = tmpAux;
                R = nullptr;
            }
            
            // Si ya se ha recorrido "listaR" en su totalidad y todavia hay elementos en "listaL"
            if(R == nullptr && L)  {
                tmpAux->sig = L;
                L->prev = tmpAux;
                L = nullptr;
            }

            // Si "L" apunta a un nodo con dato que es mayor o igual al que apunta "R"
            if(L && R && L->data >= R->data)  {
                tmpAux->sig = R;
                R->prev = tmpAux;
                tmpAux = tmpAux->sig;
                R = R->sig;
            }
            // Si "R" apunta a un nodo con dato que es mayor al que apunta "L"
            else if(L && R && R->data > L->data)  {
                tmpAux->sig = L;
                L->prev = tmpAux;
                tmpAux = tmpAux->sig;
                L = L->sig;
            }
        }

        return mergedLists.getCabeza();
    }
};

#include"listaDoble.hpp"