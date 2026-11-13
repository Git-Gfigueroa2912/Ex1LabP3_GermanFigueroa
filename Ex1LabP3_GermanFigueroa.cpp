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
        int iaFreddy = noche * 2;
        int iaChica = noche * 2;
        int iaBonnie = noche * 2;
        int iaFoxy = noche * 2 + 1;
        int iaPuppet = 18;

        Animatronic freddy("Freddy", iaFreddy, 0, 0, " HUR HUR HUR HUR HUR HUR HUR HUR HUR HUR ");
        Animatronic chica("Chica", iaChica, 1, 0, " ¡Te ha atrapado Chica! ");
        Animatronic bonnie("Bonnie", iaBonnie, 0, 1, " ¡Te ha atrapado Bonnie! ");
        Animatronic foxy("Foxy", iaFoxy, 1, 1, " ¡Te ha atrapado Foxy! ");
        Animatronic puppet("Puppet", iaPuppet, 1, 6, " ¡La caja musical llego a 0, Puppet te ha atacado! ");

        int rutaFoxyX[] = { 1, 4, 8 };
        int rutaFoxyY[] = { 1, 3, 3 };
        int pasoFoxy = 0;

        int rutaFreddyX[] = { 0, 1, 3, 5, 8 };
        int rutaFreddyY[] = { 0, 3, 3, 3, 3 };
        int pasoFreddy = 0;

        int rutaChicaX[] = { 1, 1, 3, 5, 5, 8 };
        int rutaChicaY[] = { 0, 4, 4, 4, 6, 6, 3 };
        int pasoChica = 0;

        int rutaBonnieX[] = { 0, 1, 3, 5, 5, 8, 8 };
        int rutaBonnieY[] = { 1, 2, 2, 2, 0, 0, 3 };
        int pasoBonnie = 0;

        int cajaMusical = 100;
        bool vivo = true;
        string causaMuerte = "";
        string mensajeMuerteAnimatronico = "";

        while (vivo && cajaMusical > 0) {
            system(" cls ");
            cout << " NIGHT " << noche << endl;

            char mapa[9][7];
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 7; j++) {
                    mapa[i][j] = ' ';
                }
            }
            mapa[freddy.getX()][freddy.getY()] = 'F';
            mapa[chica.getX()][chica.getY()] = 'C';
            mapa[bonnie.getX()][bonnie.getY()] = 'B';
            mapa[foxy.getX()][foxy.getY()] = 'A';
            mapa[puppet.getX()][puppet.getY()] = 'P';
        }

    } while (noche != 0);

}
int main() {
    srand(time(0));
    mostrarMenuPrincipal();
    return 0;
}

