#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale>



using namespace std;

void mostrarMenuPrincipal() {
    setlocale(LC_ALL, "spanish");
    int opción;
    do {
        system("cls");
        cout << " --- MENÚ PRINCIAPL --- " << endl;
        cout << " Hello?... Hello Hello!!! " << endl;
        cout << " *-*-*-*-*-*-*-*-*-* FNAF *-*-*-*-*-*-*-*-*-*" << endl;
        cout << " 1. Five Night´s at Freddy´s 2 " << endl;
        cout << " 2. Salir " << endl;
        cout << " Ingrese una opción: ";
        cin >> opción;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            opción;

        }
        switch (opción) {
        case 1:
            cout << " Aquí se ejecutara el juego de FNAF 2... " << endl;
            system("pause");
            break;

        case 2:
            cout << " Saliendo del programa " << endl;
            break;

        default:
            cout << " Opción invalida " << endl;
            system("pause");
            break;

        }

    } while (opción != 2);
}
void ejecutarJuego() {
    int noche = 0;
    do {
        system("cls");
        cout << " We´re really quite surprised we get to see you this night. :D " << endl;
        cout << " Can´t wait to meet youuuuu " << endl;
        cout << " 0. Salir " << endl;
        cout << " Noche 1 " << endl;
        cout << " Noche 2 " << endl;
        cout << " Noche 3 " << endl;
        cout << " Noche 4 " << endl;
        cout << " Noche 5 " << endl;
        cout << " Seleccione una noche (0-5): ";
        cin >> noche;

        if (noche == 0) return;
        if (noche < 1 || noche > 5) {
            cout << " La noche es invalida " << endl;
            system("pause");
            continue;
        }


    } while (noche != 0);

}
int main() {
    srand(time(0));
    mostrarMenuPrincipal();
    return 0;
}

