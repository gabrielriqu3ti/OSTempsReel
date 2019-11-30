/*////////////////////////////////////////////////////////////////////////////////
|
| Fichier :                td3a_main.cpp
| Auteur :                 RIQUETI Gabriel Henrique
| Date :                   08/11/2019
| Commentaires :           ENSTA ParisTech ROB305 TD3a
| Commande :               g++ td3a_main.cpp TimeSpec.cpp OSTempsReel/Chrono.cpp
|                          -lrt -o ../td3a && sudo ../td3a
| Historique de Révision :
|
*/////////////////////////////////////////////////////////////////////////////////

// archive principal
#include "TimeSpec.h"
#include <time.h>
#include "OSTempsReel/Chrono.h"
#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char *argv[])
{
    cout << "Teste de la classe Chrono" << endl;
    OSTempsReel::Chrono chrono;
    cout << "Démarrage" << endl;
    chrono = OSTempsReel::Chrono();

    for(char cmd = 'i'; cmd != 'q'; cin >> cmd){
        cout << endl;
        if(cmd == 's')
        {
            cout << "Arrêt" << endl;
            chrono.stop();
        }
        else if(cmd=='r')
        {
            cout << "Redémarrage" << endl;
            chrono.restart();
        }
        else if(cmd=='i')
        {
            if(chrono.isActive())
            {
                cout << "Chronomètre activé !"<< endl;
            }
            else
            {
                cout << "Chronomètre desactivé !"<< endl;
            }
            cout << "StartTime : " << chrono.startTime() << " ms" << endl;
            cout << "StopTime  : " << chrono.stopTime() << " ms" << endl;
            cout << "Durée     : " << chrono.lap() << " ms" << endl;
        }
        else // Aide
        {
            cout << "Tapez :" << endl;
            cout << "      - h pour demander aide" << endl;
            cout << "      - i pour recevoir des informations sur le chronomètre" << endl;
            cout << "      - r pour redémarrer le chronomètre," << endl;
            cout << "      - s pour arrêter le chronomètre" << endl;
            cout << "      - q pour sortir," << endl;
        }
        cout << "Tapez h, i, r, s ou q : ";
    }

    return 0;


    /*
    callback doit être définit comme virtuel pure
    chaque classe
    carré jaune : virtual protected
    carré rouge : private static
    circle vert :
    */
}
