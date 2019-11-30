/*////////////////////////////////////////////////////////////////////////////////
|
| Fichier :                td2a_main.cpp
| Auteur :                 RIQUETI Gabriel Henrique
| Date :                   04/11/2019
| Commentaires :           ENSTA ParisTech ROB305 TD-2a
| Commande :               g++ td2a_main.cpp TimeSpec.cpp -lrt -lpthread -o ../td2a
|                          sudo ../td2a
| Historique de Révision :
|
*/////////////////////////////////////////////////////////////////////////////////

// archive principal
#include "TimeSpec.h"
#include <time.h>
#include <iostream>
#include <pthread.h>

using namespace std;

struct Data
{
    unsigned int nLoops;
    volatile double counter;
};
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

/*----------------------------------------------------------------------------
* Fonction :               call_incr
* Auteur :                 RIQUETI
* Date :                   07/11/2019
*
* But :                    Appeler de la fonction incr lorsque elle est appelée
*                          par la tâche
----------------------------------------------------------------------------*/
void* call_incr(void* vData)
{
    Data* pData = (Data*) vData;
    incr(pData->nLoops, (double*) &pData->counter);
    return (void*) pData;
}

/************************************MAIN**************************************/
int main(int argc, char *argv[])
{
    if (argc==1 || argc==2)
    {
        cout << "Tapez le taile de la boucle et le nombre des tâches" << endl;
    }
    else if (argc==3)
    {
        timespec begin, end;
        unsigned int nTasks = atoi(argv[2]);
        Data data;
        data.nLoops = atoi(argv[1]);
        data.counter = 0;
        pthread_t incrementThread[nTasks];

        cout << "Boucle de taille " << data.nLoops << endl;
        cout << "Nombre de tâches : " << nTasks << endl;

        clock_gettime(CLOCK_REALTIME, &begin);
        for(int i=0; i<nTasks; ++i)
        {
            pthread_create(&incrementThread[i], nullptr, call_incr, &data);
        }
        for(int i=0; i<nTasks; ++i)
        {
            pthread_join(incrementThread[i], nullptr);
        }
        cout << "Compteur : " << data.counter << endl;
        clock_gettime(CLOCK_REALTIME, &end);

        cout << "Temps d'exécution : " << timespec_to_ms(end-begin) << " ms" << endl;
    }

    return 0;
}
