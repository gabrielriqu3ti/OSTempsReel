/*////////////////////////////////////////////////////////////////////////////////
|
| Fichier :                td2b_main.cpp
| Auteur :                 RIQUETI Gabriel Henrique
| Date :                   07/11/2019
| Commentaires :           ENSTA ParisTech ROB305 TD-2b
| Commande :               g++ td2b_main.cpp TimeSpec.cpp -lrt -lpthread -o ../td2b
|                          && sudo ../td2b
| Historique de Révision :
|
*/////////////////////////////////////////////////////////////////////////////////

// archive principal
#include "TimeSpec.h"
#include <time.h>
#include <iostream>
#include <pthread.h>
#include <string.h>

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
    if (argc==1 || argc==2 || argc==3)
    {
        cout << "Tapez le taile de la boucle et le nombre des tâches et l'ordenance de tâches (SCHED_RR, SCHED_FIFO ou SCHED_OTHER) " << endl;
    }
    else if (argc==4)
    {
        timespec begin, end;
        unsigned int nTasks = atoi(argv[2]);
        Data data;
        data.nLoops = atoi(argv[1]);
        data.counter = 0;
        int schedPolicy;

        if (string(argv[3]) == "SCHED_RR" || atoi(argv[3]) == SCHED_RR)
        {
            schedPolicy = SCHED_RR;
        }
        else if(string(argv[3]) == "SCHED_FIFO" || atoi(argv[3]) == SCHED_FIFO)
        {
            schedPolicy = SCHED_FIFO;
        }
        else if(string(argv[3]) == "SCHED_OTHER" || atoi(argv[3]) == SCHED_OTHER)
        {
            schedPolicy = SCHED_OTHER;
        }
        else
        {
            cout << "Le troisième paramètre doit être SCHED_RR, SCHED_FIFO ou SCHED_OTHER" << endl;
            return 0;
        }

        pthread_attr_t attr;
        pthread_attr_init(&attr);
        pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
        pthread_attr_setschedpolicy(&attr, schedPolicy);
        sched_param schedParam;
        schedParam.sched_priority = sched_get_priority_max(schedPolicy);
        pthread_attr_setschedparam(&attr, &schedParam);
        pthread_setschedparam(pthread_self(), schedPolicy, &schedParam);
        pthread_t incrementThread[nTasks];

        cout << "Boucle de taille " << data.nLoops << endl;
        cout << "Nombre de tâches : " << nTasks << endl;
        cout << "Ordenance : ";
        if(schedPolicy==SCHED_RR)
        {
            cout << "SCHED_RR" << endl;
        }
        else if(schedPolicy==SCHED_FIFO)
        {
            cout << "SCHED_FIFO" << endl;
        }
        else if(schedPolicy==SCHED_OTHER)
        {
            cout << "SCHED_OTHER" << endl;
        }

        clock_gettime(CLOCK_REALTIME, &begin);
        for(int i=0; i<nTasks; i++)
        {
            if(schedPolicy==SCHED_OTHER)
            {
                schedParam.sched_priority = 0;
            }
            else
            {
                schedParam.sched_priority = sched_get_priority_min(schedPolicy);
            }
            pthread_attr_setschedparam(&attr, &schedParam);
            pthread_create(&incrementThread[i], &attr, call_incr, &data);
        }

        pthread_attr_destroy(&attr);

        for(int i=0; i<nTasks; i++)
        {
            pthread_join(incrementThread[i], nullptr);
        }

        cout << "Compteur : " << data.counter << endl;
        clock_gettime(CLOCK_REALTIME, &end);
        cout << "Temps d'exécution : " << timespec_to_ms(end-begin) << " ms" << endl;
    }

    return 0;
}
