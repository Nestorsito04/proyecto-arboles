#include "view.h"
#include "../controller/controller.h"
#include <iostream>
#include <string>

using namespace std;

void displayMenu() {
    cout << "\n=== SISTEMA DE GESTION REAL ===\n";
    cout << "1. Mostrar arbol genealogico\n";
    cout << "2. Mostrar rey actual\n";
    cout << "3. Asignar nuevo rey\n";
    cout << "4. Buscar persona por ID\n";
    cout << "5. Salir\n";
    cout << "Seleccione una opcion: ";
}

void displayPersonInfo(int id, const char* name, const char* last_name, char gender, 
                      int age, int id_father, int is_dead, int was_king, int is_king) {
    cout << "\n=== INFORMACION DE PERSONA ===\n";
    cout << "ID: " << id << '\n';
    cout << "Nombre: " << name << ' ' << last_name << '\n';
    cout << "Genero: " << gender << '\n';
    cout << "Edad: " << age << '\n';
    cout << "ID Padre: " << id_father << '\n';
    cout << "Estado: " << (is_dead ? "Difunto" : "Vivo") << '\n';
    cout << "Fue Rey: " << (was_king ? "Si" : "No") << '\n';
    cout << "Es Rey: " << (is_king ? "Si" : "No") << '\n';
}

void displayMessage(const char* message) {
    cout << message << '\n';
}

void displayTreeLevel(const char* text, int level) {
    for (int i = 0; i < level; i++) {
        cout << "  ";
    }
    cout << text << '\n';
}

void runApplication() {
    cout << "=== SISTEMA DE GESTION DEL REINO ===\n";
    
    // Inicializar el sistema a través del controlador
    initializeSystem();
    
    int option;
    int running = 1;
    
    while (running) {
        displayMenu();
        string input;
        if (!getline(cin, input)) {
            displayMessage("Error al leer la entrada. Finalizando aplicacion.");
            break;
        }
        try {
            option = stoi(input);
        } catch (...) {
            displayMessage("Entrada no valida. Intente nuevamente ingresando un numero.");
            continue;
        }
        
        switch (option) {
            case 1:
                displayFamilyTree();
                break;
            case 2:
                displayCurrentKing();
                break;
            case 3:
                assignNewKing();
                displayMessage("Nuevo rey asignado automaticamente segun las reglas de sucesion.");
                displayCurrentKing();
                break;
            case 4:
                searchPersonById();
                break;
            case 5:
                displayMessage("Saliendo del sistema...");
                running = 0;
                break;
            default:
                displayMessage("Opcion no valida. Intente nuevamente.");
                break;
        }
    }
    
    // Limpiar recursos a través del controlador
    cleanupSystem();
}