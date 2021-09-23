/**
 * @file listaDoble.cpp
 *
 * Definicion de la clase "ListaDoble"
 * 
 * @author Alejandro Delgado Rivera <AlejandroDR_IV@Outlook.com>
 * @version 1.0
 * @date 21/09/2021
 */

#include"listaDoble.h"

int strToInt(string strNumero, int cantDigitos)
{
    // Para las unidades, decenas, centenas, etc
    int cifra = 1;
    int numero = 0;

    // Bucle que convierte la cadena en un entero
    while(cantDigitos > 0)  {
        // Identifica la cifra
        switch(strNumero[cantDigitos - 1])  {
            case '0':
                numero += 0;
                break;

            case '1':
                numero += 1 * cifra;
                break;

            case '2':
                numero += 2 * cifra;
                break;

            case '3':
                numero += 3 * cifra;
                break;

            case '4':
                numero += 4 * cifra;
                break;

            case '5':
                numero += 5 * cifra;
                break;

            case '6':
                numero += 6 * cifra;
                break;

            case '7':
                numero += 7 * cifra;
                break;

            case '8':
                numero += 8 * cifra;
                break;

            case '9':
                numero += 9 * cifra;
                break;

            case '-':
                numero *= -1;
                break;
        }
        cifra *= 10;  // Para la siguiente cifra
        cantDigitos--;
    }

    return numero;
}

template<typename T>
typename ListaDoble<T>::Nodo* ListaDoble<T>::getCabeza()
{
    return cabeza;
}

template<typename T>
typename ListaDoble<T>::Nodo** ListaDoble<T>:: getCabezaDireccion()
{
    return &cabeza;
}

template<typename T>
void ListaDoble<T>::setCabeza(Nodo *cabeza)
{
    this->cabeza = cabeza;
}

template<typename T>
void ListaDoble<T>::listInsert(const T &dato)
{
    // Crea un nuevo nodo en el heap con el valor almacenado "dato"
    Nodo *nodo = new Nodo(dato);
    // El nuevo nodo apunta al primer elemento de la lista
    nodo->sig = cabeza;

    // Si la cabeza no esta vacia (es decir, la lista tiene elementos)
    if(cabeza != NULL)  {
        // El nodo anterior del antiguo primer nodo ahora sera el nodo nuevo
        cabeza->prev = nodo;
    }

    // Actualiza los demas punteros
    cabeza = nodo;
    nodo->prev = nullptr;
}

template<typename T>
typename ListaDoble<T>::Nodo* ListaDoble<T>::listSearch(const T &datoBuscado)
{
    // Inicializacion de variable temporal auxiliar para recorrer toda la lista
    Nodo *tmpAux = cabeza;

    // Bucle que recorrera toda la lista y se detendra hasta encontrar el dato buscado o hasta que "tmpAux" apunte a "nullptr"
    while(tmpAux && tmpAux->data != datoBuscado)  {
        tmpAux = tmpAux->sig;
    }

    return tmpAux;
}

template<typename T>
void ListaDoble<T>::listDelete(Nodo *node)
{
    // Si el nodo que se quiere eliminar no esta en la cabeza de la lista
    if(node->prev)  {
        node->prev->sig = node->sig;
    }
    // Si el nodo que se quiere eliminar esta en la cabeza de la lista
    else cabeza = node->sig;

    // Si el nodo que se quiere eliminar no esta al final de la lista
    if(node->sig)  {
        node->sig->prev = node->prev;
    }

    // Libera la memoria ocupada por el nodo que se quiere eliminar
    delete node;
}

template<typename T>
void ListaDoble<T>::listDeleteData(const T &datoEliminado)
{
    // Primero idetifica el nodo que contiene almacenado "datoEliminado"
    Nodo *tmpAux = this->listSearch(datoEliminado);

    // Si se identifico el nodo se elimina
    if(tmpAux)  {
        this->listDelete(tmpAux);
    }
}

template<typename T>
void ListaDoble<T>::imprimirLista()
{
    // Inicializacion de variable temporal auxiliar para recorrer toda la lista
    Nodo *tmpAux = cabeza;
    unsigned int cont = 0;

    // Bucle que recorrera e imprimira cada dato de los nodos de la lista
    while(tmpAux)  {
        cout << "Dato " << (cont + 1) << ": " << tmpAux->data << endl;
        tmpAux = tmpAux->sig;
        cont++;
    }
    cout << "\n" << cont << " datos\n" << endl;
}

template<typename T>
void ListaDoble<T>::imprimirAlReves()
{
    // Inicializacion de variable temporal auxiliar para recorrer toda la lista
    Nodo *tmpAux1 = cabeza;
    Nodo *tmpAux2 = nullptr;
    unsigned int cont = 0;

    // Bucle que recorrera la lista hasta encontrar el ultimo nodo
    while(tmpAux1)  {
        if(tmpAux1)  {
            tmpAux2 = tmpAux1;
        }
        tmpAux1 = tmpAux1->sig;
    }

    // Bucle que recorre la lista de cola a cabeza e imprimira cada dato de los nodos de la lista
    while(tmpAux2 && cont < 20)  {
        cout << "Dato " << (cont + 1) << ": " << tmpAux2->data << endl;
        tmpAux2 = tmpAux2->prev;
        cont++;
    }
    cout << "\n" << cont << " datos\n" << endl;
}

template<typename T>
void ListaDoble<T>::escribirArrDocTxt(string nombre)
{
    // Archivo de texto con la salida
    ofstream salida;
    // Crea o reemplaza el archivo con identificador "nombre"
    salida.open(nombre, ios::out);
    // Inicializacion de variable auxiliar para recorrer la lista
    Nodo *tmpAux = this->getCabeza();

    // Comprueba si se abrio correctamente el archivo
    if(!salida.is_open())  {
        cout << "No fue posible abrir el archivo" << endl;
        exit(1);
    }

    // Bucle que recorre la lista la lista
    while(tmpAux)  {
        salida << tmpAux->data << endl;
        tmpAux = tmpAux->sig;
    }

    // Cierra el archivo
    salida.close();
}