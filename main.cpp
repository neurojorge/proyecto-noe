// app.cpp  (nuevo main: mantiene "Hello world!" y añade menú)
#include <iostream>
#include <vector>
#include <string>
#include <limits>

#include "Oso.h"
#include "Antilope.h"
#include "Venado.h"

void limpiarEntrada() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int pedirEntero(const std::string &prompt, int min=0, int max=1000) {
    int v;
    while (true) {
        std::cout << prompt;
        if (std::cin >> v) {
            if (v >= min && v <= max) return v;
            std::cout << "Valor fuera de rango.\n";
        } else {
            std::cout << "Entrada invalida.\n";
        }
        limpiarEntrada();
    }
}

float pedirFloat(const std::string &prompt, float min=0.0f, float max=10000.0f) {
    float v;
    while (true) {
        std::cout << prompt;
        if (std::cin >> v) {
            if (v >= min && v <= max) return v;
            std::cout << "Valor fuera de rango.\n";
        } else {
            std::cout << "Entrada invalida.\n";
        }
        limpiarEntrada();
    }
}

std::string pedirString(const std::string &prompt) {
    std::string s;
    std::cout << prompt;
    limpiarEntrada();
    std::getline(std::cin, s);
    return s;
}

// Busca por nombre (usa dynamic_cast, accede a nombre si es public)
int buscarPorNombre(const std::vector<Especie*> &vec, const std::string &nombre) {
    for (size_t i = 0; i < vec.size(); ++i) {
        if (Oso* o = dynamic_cast<Oso*>(vec[i])) {
            if (o->nombre == nombre) return static_cast<int>(i);
        } else if (Antilope* a = dynamic_cast<Antilope*>(vec[i])) {
            if (a->nombre == nombre) return static_cast<int>(i);
        } else if (Venado* v = dynamic_cast<Venado*>(vec[i])) {
            if (v->nombre == nombre) return static_cast<int>(i);
        }
    }
    return -1;
}

void mostrar(const std::vector<Especie*> &vec) {
    if (vec.empty()) { std::cout << "No hay registros.\n"; return; }
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << i << ") ";
        vec[i]->imprimir(std::cout);
    }
}

void alta(std::vector<Especie*> &vec) {
    std::cout << "Tipo: 1) Oso 2) Antilope 3) Venado\n";
    int op = pedirEntero("Opcion: ", 1, 3);
    std::string nombre = pedirString("Nombre: ");
    int edad = pedirEntero("Edad (1-20): ", 1, 20);
    float tam = pedirFloat("Tamano (cm): ", 1.0f, 1000.0f);
    std::string alim = pedirString("Alimentacion: ");
    std::string gen = pedirString("Genero: ");
    float peso = pedirFloat("Peso (kg): ", 0.1f, 2000.0f);

    Especie* p = nullptr;
    if (op == 1) p = new Oso(nombre, edad, tam, alim, gen, peso);
    else if (op == 2) p = new Antilope(nombre, edad, tam, alim, gen, peso);
    else p = new Venado(nombre, edad, tam, alim, gen, peso);

    vec.push_back(p);
    std::cout << "Alta realizada.\n";
}

void baja(std::vector<Especie*> &vec) {
    std::string nombre = pedirString("Nombre a dar de baja: ");
    int idx = buscarPorNombre(vec, nombre);
    if (idx == -1) { std::cout << "No encontrado.\n"; return; }
    std::cout << "Registro encontrado:\n";
    vec[idx]->imprimir(std::cout);
    std::string conf = pedirString("Confirmar baja (si/no): ");
    if (conf == "si" || conf == "SI" || conf == "Si") {
        delete vec[idx];
        vec.erase(vec.begin() + idx);
        std::cout << "Eliminado.\n";
    } else {
        std::cout << "Operacion cancelada.\n";
    }
}

void demostrarPunteroAPuntero(const std::vector<Especie*> &vec) {
    if (vec.empty()) { std::cout << "Vector vacio.\n"; return; }
    size_t n = vec.size();
    Especie **arr = new Especie*[n];
    for (size_t i = 0; i < n; ++i) arr[i] = vec[i];

    std::cout << "Mostrando mediante Especie**:\n";
    for (size_t i = 0; i < n; ++i) {
        std::cout << i << ") ";
        arr[i]->imprimir(std::cout);
    }

    delete[] arr;
    std::cout << "Arreglo liberado.\n";
}

int main() {
    // conservamos el Hello world() que ya tenias
    std::cout << "Hello world!" << std::endl;

    std::vector<Especie*> zoo;
    bool salir = false;
    while (!salir) {
        std::cout << "\n--- MENU ---\n1) Alta\n2) Buscar por nombre\n3) Baja\n4) Listar todo\n5) Demostrar puntero a puntero\n6) Salir\n";
        int opt = pedirEntero("Opcion: ", 1, 6);
        switch (opt) {
            case 1: alta(zoo); break;
            case 2: {
                std::string nombre = pedirString("Nombre a buscar: ");
                int idx = buscarPorNombre(zoo, nombre);
                if (idx == -1) std::cout << "No encontrado.\n";
                else zoo[idx]->imprimir(std::cout);
                break;
            }
            case 3: baja(zoo); break;
            case 4: mostrar(zoo); break;
            case 5: demostrarPunteroAPuntero(zoo); break;
            case 6: salir = true; break;
            default: break;
        }
    }

    for (Especie* p : zoo) delete p;
    zoo.clear();

    std::cout << "Saliendo...\n";
    return 0;
}
