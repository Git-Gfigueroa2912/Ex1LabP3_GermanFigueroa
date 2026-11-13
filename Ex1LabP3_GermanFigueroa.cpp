#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale>

using namespace std;

void ejecutarJuego();
void mapasinLinterna();
void mapaconLinterna();

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
    int opciónAcción;
    do {
        system("cls");
        cout << " We´re really quite surprised we get to see you this night. :D " << endl;
        cout << " Can´t wait to meet yooouuuuu " << endl;
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
            mapa[foxy.getX()][foxy.getY()] = 'W';
            mapa[puppet.getX()][puppet.getY()] = 'P';

            mapasinLinterna(mapa);

            cout << " Caja Musical: " << cajaMusical << endl;
            cout << " ¿ Ahora que hago ? " << endl;
            cout << " 1. Máscara " << endl;
            cout << " 2. Linterna " << endl;
            cout << " 3. Caja Musical " << endl;
            cout << " Ingrese una opción: ";
            cin >> opciónAcción;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                opciónAcción;
            }
            int reduccionCaja = 5 + (rand() % 5);
            cajaMusical -= reduccionCaja;
            if (cajaMusical < 0) cajaMusical = 0;

            if (opciónAcción == 1) {
                if (freddy.getX() >= 5) { pasoFreddy = 0; freddy.setX(rutaFreddyX[0]); freddy.setY(rutaFreddyY[0]); }
                if (chica.getX() >= 5) { pasoChica = 0; chica.setX(rutaChicaX[0]); chica.setY(rutaChicaY[0]); }
                if (bonnie.getX() >= 5) { pasoBonnie = 0; bonnie.setX(rutaBonnieX[0]); bonnie.setY(rutaBonnieY[0]); }

            }else if (opciónAcción == 2){
                pasoFoxy = 0;
                foxy.setX(rutaFoxyX[0]);
                foxy.setY(rutaFoxyY[0]);

                system("cls");
                cout << "NIGHT " << noche << " [USANDO LINTERNA]" << endl;
                mapaConLinterna(mapa);
                cout << "Caja Musical: " << cajaMusical << endl;
                system("pause");

            }else if (opciónAcción == 3) {
                cajaMusical += 10;
                if (cajaMusical > 100) cajaMusical = 100;
            }
            if (cajaMusical <= 0) {
                vivo = false;
                causaMuerte = puppet.getNombre();
                mensajeMuerteAnimatronico = puppet.getMensaje();
                break;
            }
            int rndFreddy = rand() % 21;
            if (rndFreddy < freddy.getIA() && pasoFreddy < 4) {
                pasoFreddy++;
                freddy.setX(rutaFreddyX[pasoFreddy]);
                freddy.setY(rutaFreddyY[pasoFreddy]);
            }
            
            int rndChica = rand() % 21;
            if (rndChica < chica.getIA() && pasoChica < 6) {
                pasoChica++;
                chica.setX(rutaChicaX[pasoChica]);
                chica.setY(rutaChicaY[pasoChica]);
            }
            int rndBonnie = rand() % 21;
            if (rndBonnie < bonnie.getIA() && pasoBonnie < 6) {
                pasoBonnie++;
                bonnie.setX(rutaBonnieX[pasoBonnie]);
                bonnie.setY(rutaBonnieY[pasoBonnie]);
            }
            int rndFoxy = rand() % 21;
            if (rndFoxy < foxy.getIA() && pasoFoxy < 2) {
                pasoFoxy++;
                foxy.setX(rutaFoxyX[pasoFoxy]);
                foxy.setY(rutaFoxyY[pasoFoxy]);
            }
            if (freddy.getX() == 8 && freddy.getY() == 3) {
                vivo = false; causaMuerte = freddy.getNombre(); mensajeMuerteAnimatronico = freddy.getMensaje();
            }
            else if (chica.getX() == 8 && chica.getY() == 3) {
                vivo = false; causaMuerte = chica.getNombre(); mensajeMuerteAnimatronico = chica.getMensaje();
            }
            else if (bonnie.getX() == 8 && bonnie.getY() == 3) {
                vivo = false; causaMuerte = bonnie.getNombre(); mensajeMuerteAnimatronico = bonnie.getMensaje();
            }
            else if (foxy.getX() == 8 && foxy.getY() == 3) {
                vivo = false; causaMuerte = foxy.getNombre(); mensajeMuerteAnimatronico = foxy.getMensaje();
            }
        }

        system("cls");
        if (!vivo) {
            cout << "Te ha matado " << causaMuerte << endl;
            cout << mensajeMuerteAnimatronico << endl;
        }
        else {
            cout << "¡Has sobrevivido a la Noche " << noche << "!" << endl;
        }
        system("pause");


    }while (noche != 0);
 

}
void mapaSinLinterna(char mapa[9][7]) {
    for (size_t i = 0; i < 9; i++)
    {
        for (size_t j = 0; j < 7; j++)
        {
            if ((i == 0 && j == 0) || (i == 0 && j == 1) || (i == 1 && j == 0) || (i == 1 && j == 1) || (i == 1 && j == 6))
            {
                cout << "[" << mapa[i][j] << "]";
            }
            else if ((i == 3 && j == 0) || (i == 5 && j == 0) || (i == 8 && j == 0))
            {
                cout << "[" << mapa[i][j] << "]";
            }
            else if ((i == 3 && j == 6) || (i == 5 && j == 6) || (i == 8 && j == 6))
            {
                cout << "[" << mapa[i][j] << "]";
            }
            else if ((i == 6 && j == 6) || (i == 7 && j == 6) || (i == 8 && j == 6) || (i == 6 && j == 0) || (i == 7 && j == 0))
            {
                cout << "|" << mapa[i][j] << "|";
            }
            else if ((i == 1 && j == 2) || (i == 2 && j == 2) || (i == 3 && j == 2) || (i == 4 && j == 2))
            {
                cout << "[" << mapa[i][j] << " ";
            }
            else if ((i == 2 && j == 4) || (i == 3 && j == 4) || (i == 4 && j == 4))
            {
                cout << " " << mapa[i][j] << "]";
            }
            else if (i == 5 && j == 2)
            {
                if (mapa[i][j] == ' ')
                {
                    cout << "[_ ";
                }
                else {
                    cout << "[" << mapa[i][j] << " ";
                }
            }
            else if (i == 5 && j == 4)
            {
                if (mapa[i][j] == ' ')
                {
                    cout << " _]";
                }
                else {
                    cout << " " << mapa[i][j] << "]";
                }
            }
            else if ((i == 3 && j == 1) || (i == 3 && j == 5))
            {
                cout << "===";
            }
            else if ((i == 5 && j == 1) || (i == 5 && j == 5))
            {
                cout << "===";
            }
            PERIODO 2 / SEMESTRE 2 / AÑO 2026 10
            else if ((i == 8 && j == 1) || (i == 8 && j == 5))
            {
                cout << "===";
            }
            else if (i == 8 && j == 2)
            {
                cout << "[" << mapa[i][j] << " ";
            }
            else if (i == 8 && j == 4)
            {
                cout << " " << mapa[i][j] << "]";
            }
            else if (i == 8 && j == 3)
            {
                cout << " " << mapa[i][j] << " ";
            }
            else if (i == 0 && j <= 5 && j >= 2)
            {
                cout << "___";
            }
            else if (i == 1 && j == 5)
            {
                cout << "__]";
            }
            else {
                cout << " " << mapa[i][j] << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}
void mapaConLinterna(char mapa[9][7]) {
    for (size_t i = 0; i < 9; i++)
    {
        for (size_t j = 0; j < 7; j++)
        {
            if ((i == 0 && j == 0) || (i == 0 && j == 1) || (i == 1 && j == 0) || (i == 1 && j == 1) || (i == 1 && j == 6))
            {
                cout << "[" << mapa[i][j] << "]";
            }
            else if ((i == 3 && j == 0) || (i == 5 && j == 0) || (i == 8 && j == 0))
            {
                cout << "[" << mapa[i][j] << "]";
            }
            else if ((i == 3 && j == 6) || (i == 5 && j == 6) || (i == 8 && j == 6))
            {
                cout << "[" << mapa[i][j] << "]";
            }
            else if ((i == 6 && j == 6) || (i == 7 && j == 6) || (i == 8 && j == 6) || (i == 6 && j == 0) || (i == 7 && j == 0))
            {
                cout << "|" << mapa[i][j] << "|";
            }
            else if ((i == 1 && j == 2) || (i == 2 && j == 2) || (i == 3 && j == 2))
            {
                cout << "[" << mapa[i][j] << " ";
            }
            else if ((i == 2 && j == 4) || (i == 3 && j == 4))
            {
                cout << " " << mapa[i][j] << "]";
            }
            else if (i == 5 && j == 2)
            {
                if (mapa[i][j] == ' ')
                {
                    cout << "[_\\";
                }
                else {
                    cout << "[" << mapa[i][j] << "\\";
                }
            }
            else if (i == 5 && j == 4)
            {
                if (mapa[i][j] == ' ')
                {
                    cout << "/_]";
                }
                else {
                    cout << "/" << mapa[i][j] << "]";
                }
            }
            else if ((i == 3 && j == 1) || (i == 3 && j == 5))
            {
                cout << "===";
            }
            else if ((i == 5 && j == 1) || (i == 5 && j == 5))
            {
                cout << "===";
            }
            else if ((i == 8 && j == 1) || (i == 8 && j == 5))
            {
                cout << "===";
            }
            else if (i == 8 && j == 2)
            {
                cout << "[" << mapa[i][j] << " ";
            }
            else if (i == 8 && j == 4)
            {
                cout << " " << mapa[i][j] << "]";
            }
            else if (i == 8 && j == 3)
            {
                cout << " " << mapa[i][j] << " ";
            }
            else if (i == 0 && j <= 5 && j >= 2)
            {
                cout << "___";
            }
            else if (i == 1 && j == 5)
            {
                cout << "__]";
            }
            else if (i == 7 && j == 3)
            {
               cout << " V ";
            }
            else if (i == 6 && j == 3)
            {
                cout << "\\" << mapa[i][j] << "/";
            }
            else if ((i == 4 && j == 2))
            {
                cout << "[\\ ";
            }
            else if ((i == 4 && j == 4))
            {
                cout << " /]";
            }
            else {
                cout << " " << mapa[i][j] << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}
int main() {
    srand(time(0));
    mostrarMenuPrincipal();
    return 0;
}

