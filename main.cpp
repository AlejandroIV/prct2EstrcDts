/**
 * @file main.cpp
 * 
 * Codigo para extraer numeros enteros de un documento, aplicar el algoritmo "MergeSort" en una lista doblemente enlazada
 * y para escribir en un archivo de texto el contenido de la lista
 * 
 * @author Alejandro Delgado Rivera <AlejandroDR_IV@Outlook.com>
 * @version 1.0
 * @date 23/09/2021
 */ 

#include"leerArchivo.h"

int main()
{
    string nombre;
    cout << "Escribe el nombre del archivo con los datos de entrada (con extension): ";
    cin >> nombre;
    cin.clear();
    cin.ignore(1000, '\n');

    // Abre el archivo
    Archivo arch(nombre);
    // Crea la cadena con los numeros del documento
    arch.contarNumerosYCrearCadenaNumeros();

    // Declara la lista doblemente ligada que contendra los elementos extraidos del documento de texto
    ListaDoble<int> lista;

    // Declaracion de indices que reccoreran la cadena y de dos contadores
    int l, r, cont, digitos;
    l = r = cont = digitos = 0;
    // Cadena que contendra cada numero en formato "str" para convertirlo a "int"
    string numero = "";
    string cadenaDeNumeros = arch.getCadenaNumeros();
    // Arreglo que contendra todos los numeros extraidos del documento
    int arregloNumeros[arch.getCantNum()];

    // Bucle que se repetira hasta que el indice "r" llegue al indice final de la cadena
    while(r < cadenaDeNumeros.length())  {
        // Si no se ha llegado al final del numero
        if(cadenaDeNumeros[r] != 'x')  {
            r++;
        }
        // Si ya se llego al final del numero
        else  {
            // Bucle que copia el numero en formato "str"
            while(l < r)  {
                numero += cadenaDeNumeros[l];
                l++;
                digitos++;
            }
            // Agrega el elemento al arreglo
            arregloNumeros[cont] = strToInt(numero, digitos);
            // Pasa al indice donde comienza un nuevo numero
            r++;
            l++;
            // Borra los valores de "numero" y "digitos" para un nuevo numero
            numero = "";
            digitos = 0;
            cont++;
        }
    }

    // Agrega los nodos con los valores almacenados en el arreglo "arregloNumeros" a la lista "lista"
    int cont2 = 0;
    while(cont > cont2)  {
        lista.listInsert(arregloNumeros[cont2]);
        cont2++;
    }

    cont = 0;
    unsigned short int opcion = 0;
    cout << "\nElija una de las siguientes opciones\n" << endl;

    do  {
        if(cont == 0)  {
            cout << "1 - Aplicar MergeSort a la lista" << endl;
        }
        cout << "2 - Mostrar el contenido de la lista (si la lista es muy grande es posible que no se vean todos los elementos)" << endl;
        cout << "3 - Escribir el contenido de la lista en un documento de texto" << endl;
        cout << "0 - Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        cin.clear();
        cin.ignore(1000, '\n');
        cout << endl;

        switch(opcion)  {
            case 1:
                if(cont == 0)  {
                    mergeSort(lista.getCabezaDireccion());
                    cont++;
                    opcion++;
                }
                system("clear");
                cout << endl;
                cout << "Lista ordenada" << endl;
                cout << endl;
                break;

            case 2:
                lista.imprimirLista();
                break;

            case 3:
                cout << "Escribe el nombre del archivo con los datos de salida (sin extension): ";
                cin >> nombre;
                cin.clear();
                cin.ignore(1000, '\n');
                lista.escribirArrDocTxt(nombre + ".txt");
                system("clear");
                cout << endl;
                cout << "Archivo creado" << endl;
                cout << endl;
                break;

            default:
                continue;
                break;
        }
    }  while(opcion > cont && opcion < 4);

    system("clear");
    system("pause");
    return 0;
}