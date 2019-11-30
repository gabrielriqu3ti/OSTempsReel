/*////////////////////////////////////////////////////////////////////////////////
|
| Fichier :                td1c_main.cpp
| Auteur :                 RIQUETI Gabriel Henrique
| Date :                   15/10/2019
| Commentaires :           ENSTA ParisTech ROB305 TD-1c
| Commande :               g++ td1c_main.cpp TimeSpec.cpp -lrt -o ../td1c && ../td1c
| Historique de Révision :
|
*/////////////////////////////////////////////////////////////////////////////////

// archive principal
#include "TimeSpec.h"
#include <time.h>
#include <iostream>


using namespace std;

/*----------------------------------------------------------------------------
* Fonction :               incr
* Auteur :                 RIQUETI
* Date :                   15/10/2019
*
* But :                    Incrementer un compteur pour un nombre des fois
*                          spécifié
----------------------------------------------------------------------------*/
void incr(unsigned int nLoops, double* pCounter)
{
    for (int i=0; i<nLoops; ++i)
    {
        *pCounter += 1.0;
    }
    return;
}

/************************************MAIN**************************************/
int main(int argc, char *argv[])
{
    if (argc==1)
    {
        cout << "Tapez le taile de la boucle" << endl;
    }
    else if (argc==2)
    {
        timespec begin, end;
        unsigned int nLoops = atoi(argv[1]);
        double counter = 0.0;
        cout << "Boucle de taille " << nLoops << endl;
        clock_gettime(CLOCK_REALTIME, &begin);
        incr(nLoops, &counter);
        clock_gettime(CLOCK_REALTIME, &end);
        cout << "Compteur : " << counter << endl;
        cout << "Temps d'exécution : " << timespec_to_ms(end-begin) << " ms" << endl;
    }

    return 0;
}
