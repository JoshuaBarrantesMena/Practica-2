#include <iostream>
#include <vector>

using namespace std;

struct Empleado {
    int idEmpleado;
    int horasTrabajadas;
    Empleado* sig;
    Empleado(int id, int horas) : idEmpleado(id), horasTrabajadas(horas), sig(nullptr) {}
};

Empleado* devolverHoras(Empleado*& lista) { // ej1 main

    if (!lista) {
        return nullptr;
    }

    Empleado* cabezaNuevaLista = new Empleado(lista->idEmpleado, 0);
    Empleado* actual2 = cabezaNuevaLista;
    Empleado* otro = nullptr;
    Empleado* actual = lista;

    while (actual != nullptr) {
        bool idEncontrado = false;
        while (actual2 != nullptr) {
            if (actual->idEmpleado == actual2->idEmpleado) {
                actual2->horasTrabajadas += actual->horasTrabajadas;
                idEncontrado = true;
                break;
            }
            otro = actual2;
            actual2 = actual2->sig;
        }
        if (!idEncontrado) {
            otro->sig = new Empleado(actual->idEmpleado, actual->horasTrabajadas);
        }
        actual = actual->sig;
        actual2 = cabezaNuevaLista;
    }
    return cabezaNuevaLista;
}

void insertarEmpleado(Empleado*& lista, int id, int horas) {

    Empleado* nuevo = new Empleado(id, horas);

    if (lista==nullptr) {
        lista = nuevo;
        return;
    }

    Empleado* actual = lista;

    while (actual->sig != nullptr) {

        actual = actual->sig;
    }

    actual->sig = nuevo;
}

void print(Empleado* a) {
    while (a != nullptr) {
        cout << "ID: " << a->idEmpleado << "\nHoras: " << a->horasTrabajadas << endl;
        a = a->sig;
    }
    cout << "\n\n";
}



// ejercicio 2 y 3
struct Numero {
    int numero;
    Numero* sig;
    Numero(int num) : numero(num), sig(nullptr) {}
};

void limpiarNumeros(Numero*& lista) { // ej 2 main
    Numero* actual = lista;
    Numero* aux;
    Numero* sig;

    while (actual != nullptr) {
        aux = actual;
        sig = actual->sig;
        while (sig != nullptr) {
            if (actual->numero == sig->numero) {
                aux->sig = sig->sig;
                sig = nullptr;
                sig = aux->sig;
            }
            else {
                sig = sig->sig;
                aux = aux->sig;
            }
        }
        actual = actual->sig;
    }
}

void insertarNumeroEnPosicion(Numero*& lista, int num, int pos) { // ej 3 main

    Numero* nuevo = new Numero(num);
    int posicion = 0;

    if (pos <= 0) {
        nuevo->sig = lista;
        lista = nuevo;
        return;
    }

    Numero* actual = lista;
    Numero* prev = nullptr;
    while (actual != nullptr && posicion != pos) {

        posicion++;
        prev = actual;
        actual = actual->sig;
    }

    if (prev != nullptr) {
        nuevo->sig = actual;
        prev->sig = nuevo;
    }
}

void intercalarNumeros(Numero*& lista1, Numero*& lista2) { // ej 4 main

    if (!lista2) {
        return;
    }
    
    Numero* actual1 = lista1;
    Numero* prev1 = nullptr;
    Numero* actual2 = lista2;
    Numero* auxL2 = lista2;

    while (actual1 != nullptr && actual2 != nullptr) {
        auxL2 = auxL2->sig;
        actual2->sig = actual1->sig;
        actual1->sig = actual2;
        actual2 = auxL2;
        prev1 = actual1->sig;
        actual1 = actual1->sig->sig;
    }
    if (actual1 == nullptr) {
        if (prev1 != nullptr) {
            prev1->sig = actual2;
        }
    }
}

void eliminarNumeroMenor(Numero*& lista) { // ej 5 main

    if (!lista) {
        return;
    }

    Numero* actual = lista;
    Numero* peque = actual;
    Numero* prev = nullptr;
    Numero* prevPeque = nullptr;

    while (actual != nullptr) {
        if (actual->numero < peque->numero) {
            prevPeque = prev;
            peque = actual;
        }
        prev = actual;
        actual = actual->sig;
    }
    if (peque == lista) {
        Numero* guardar = lista->sig;
        lista = nullptr;
        lista = guardar;
    }
    if (prevPeque != nullptr) {
        prevPeque->sig = peque->sig;
        peque = nullptr;
    }
}

int total(Numero*& lista) { // ej 6 main

    Numero* actual = lista;
    int total = 0;

    while (actual != nullptr) {
        total++;
        actual = actual->sig;
    }
    return total;
}

bool esAscendente(Numero*& lista) { // ej 7 main

    Numero* actual = lista;

    while (actual->sig != nullptr) {
        if (actual->numero > actual->sig->numero) {
            return false;
        }
        actual = actual->sig;
    }

    return true;
}

void insertarNumero(Numero*& lista, int num) {

    Numero* nuevo = new Numero(num);

    if (!lista) {
        lista = nuevo;
        return;
    }

    Numero* actual = lista;

    while (actual->sig != nullptr) {
        actual = actual->sig;
    }
    actual->sig = nuevo;
}

void printN(Numero* a) {
    while (a != nullptr) {
        cout << "#: " << a->numero << endl;
        a = a->sig;
    }
    cout << "\n";
}
// fin ejercicio 2 y 3


int main(){

    // ejercicio 1
    //=========================================================================================================================
    Empleado* listaEmpleados = new Empleado(1, 3);

    insertarEmpleado(listaEmpleados, 1, 7);
    insertarEmpleado(listaEmpleados, 1, 8);
    insertarEmpleado(listaEmpleados, 2, 12);
    insertarEmpleado(listaEmpleados, 1, 13);
    insertarEmpleado(listaEmpleados, 3, 5);
    insertarEmpleado(listaEmpleados, 4, 1);

    cout << "[Lista de empleados completa]\n";
    print(listaEmpleados);

    Empleado* horas = devolverHoras(listaEmpleados);

    cout << "[Lista de empleados con horas acumuladas]\n";
    print(horas);
    // fin ejercicio 1
    //=========================================================================================================================

    //=========================================================================================================================
    // ejercicio 2
    Numero* numeros1 = new Numero(3);

    insertarNumero(numeros1, 1);
    insertarNumero(numeros1, 1);
    insertarNumero(numeros1, 2);
    insertarNumero(numeros1, 2);
    insertarNumero(numeros1, 2);
    insertarNumero(numeros1, 1);
    insertarNumero(numeros1, 3);
    insertarNumero(numeros1, 1);

    cout << "[Numeros1 sin modificar]\n";
    printN(numeros1);

    limpiarNumeros(numeros1);

    cout << "[Numeros1 modificado]\n";
    printN(numeros1);
    // fin ejercicio 2
    //=========================================================================================================================

    //=========================================================================================================================
    // ejercicio 3
    Numero* numeros2 = new Numero(3);

    insertarNumero(numeros2, 1);
    insertarNumero(numeros2, 1);
    insertarNumero(numeros2, 2);
    insertarNumero(numeros2, 1);

    cout << "[Numeros2 sin modificar]\n";
    printN(numeros2);

    insertarNumeroEnPosicion(numeros2, 6, 2);
    insertarNumeroEnPosicion(numeros2, 7, 3);
    insertarNumeroEnPosicion(numeros2, 10, 30);
    insertarNumeroEnPosicion(numeros2, 12, 0);

    cout << "[Numeros2 modificado]\n";
    printN(numeros2);
    // fin ejercicio 3
    //=========================================================================================================================

    //=========================================================================================================================
    // ejercicio 4

    cout << "[Numeros1 y Numeros2 intercalados]\n";
    intercalarNumeros(numeros1, numeros2);

    printN(numeros1);
    // fin ejercicio 4
    //=========================================================================================================================

    //=========================================================================================================================
    // ejercicio 5
    Numero* numeros3 = new Numero(1);

    insertarNumero(numeros3, 2);
    insertarNumero(numeros3, 3);
    insertarNumero(numeros3, 4);
    insertarNumero(numeros3, 5);
    insertarNumero(numeros3, 6);

    cout << "[Numeros3 sin modificar]\n";
    printN(numeros3);

    eliminarNumeroMenor(numeros3);

    cout << "[Numeros3 modificado]\n";
    printN(numeros3);
    // fin ejercicio 5
    //=========================================================================================================================

    //=========================================================================================================================
    // ejercicio 6;

    cout << "[El total de numeros en la lista Numeros3 es de: " << total(numeros3) << "]\n\n";

    // fin ejercicio 6
    //=========================================================================================================================

    //=========================================================================================================================
    // ejercicio 7
    if (esAscendente(numeros3)) {
        cout << "[Numeros3 es ascendente]\n";
    }
    else {
        cout << "[Numeros3 no es ascendente]\n";
    }
    // fin ejercicio 7
    //=========================================================================================================================
    return 0;
}