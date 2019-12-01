/*////////////////////////////////////////////////////////////////////////////////
|
| Fichier :                td1e_main.cpp
| Auteur :                 RIQUETI Gabriel Henrique
| Date :                   04/11/2019
| Commentaires :           ENSTA ParisTech ROB305 TD-1e
| Commande :               g++ main_td1e.cpp TimeSpec.cpp -lrt -lpthread -o ../td1e
|                          sudo ../td1e
| Historique de Révision :
|
*/////////////////////////////////////////////////////////////////////////////////

// archive principal
#include "TimeSpec.h"
#include <time.h>
#include <signal.h>
#include <pthread.h>
#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

#define N_TIMERS 1000

struct myDataHandler
{
    int counter;
    bool stop;
};

/*----------------------------------------------------------------------------
* Fonction :               incr
* Auteur :                 RIQUETI
* Date :                   22/10/2019
*
* But :                    Incrementer un compteur jusqu'à l'arrêt est demandé
----------------------------------------------------------------------------*/
int incr(unsigned int nLoops, double* pCounter, bool* pStop)
{
    int iLoop;
    for (iLoop=0; iLoop<nLoops && !*pStop; ++iLoop)
    {
        *pCounter += 1.0;
    }
    return iLoop;
}

/*----------------------------------------------------------------------------
* Fonction :               myHandler
* Auteur :                 RIQUETI
* Date :                   22/10/2019
*
* But :                    Demande l'arrêt de la boucle lorsque elle est
*                          appelée par le timeur
----------------------------------------------------------------------------*/
void myHandler(int sig, siginfo_t* si, void*)
{
	volatile struct myDataHandler* myData = (volatile struct myDataHandler*) si->si_value.sival_ptr;
	myData->stop = true;
	return;
}

/*----------------------------------------------------------------------------
* Fonction :               calib
* Auteur :                 RIQUETI
* Date :                   04/11/2019
*
* But :                    Trouve les valeur a et b qui mieux approximent la
*                          fonction l(t) = ax+b  par la méthode des moindres
*                          carrés
----------------------------------------------------------------------------*/
void calib()
{

    unsigned int nLoops = UINT_MAX;
    timespec begin[N_TIMERS], end[N_TIMERS];
    double counter[N_TIMERS], duration[N_TIMERS];
    timer_t tid;
	struct sigaction sa;
	itimerspec its;
	struct sigevent sev;
    struct myDataHandler myData;
    double timeStep, aN, a0, x0, xN1, durTotal;

    myData.counter = 0;
    myData.stop = false;

    sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &myHandler;

	sigemptyset(&sa.sa_mask);
	sigaction(SIGRTMIN, &sa, NULL);

	sev.sigev_notify = SIGEV_SIGNAL;
	sev.sigev_signo = SIGRTMIN;
	sev.sigev_value.sival_ptr = (void*) &myData;

    timer_create(CLOCK_REALTIME, &sev, &tid);

    its.it_value.tv_sec = 0;
    its.it_value.tv_nsec = 1e4;
    its.it_interval.tv_sec = 0;
    its.it_interval.tv_nsec = 0;

    durTotal = 0;

    cout << "Méthode des moindres carrés avec " << N_TIMERS << " timers" << endl;
    x0 = 0.01;
    xN1 = 500;
    a0 = x0;
    aN = ((xN1 - a0)/(N_TIMERS-1))/((N_TIMERS-1)*(N_TIMERS-1));
    cout << "durée[i] = " << aN << "*i^3 + " << a0 << endl;

    for(int i=0;i<N_TIMERS;i++)
    {

        timer_settime(tid, 0, &its, NULL);

        clock_gettime(CLOCK_REALTIME, &begin[i]);
        incr(nLoops, &counter[i], &myData.stop);
        clock_gettime(CLOCK_REALTIME, &end[i]);

        timespec_wait(its.it_value);

        duration[i] = timespec_to_ms(end[i]-begin[i]);

        if(i==0 || i==9 || (i+1)%100==0)
        {
            cout << "Timeur : "  << i+1 << endl;
            cout << "Compteur : " << counter[i] << endl;
            cout << "Temps d'exécution : " << duration[i] << " ms" << endl;
        }

        myData.stop = false;

        timeStep = aN*i*i*i + a0;

        its.it_value = timespec_from_ms(timeStep);

        durTotal += duration[i];

    }

	timer_delete(tid);

    /* Etalonage */

    double a, b, error = 0;
    double sumDurCount, sumDur2, avgCount, avgDur;
    double sumDurcount = sumDur2 = avgCount = avgDur = 0;

    for(int i=0;i<N_TIMERS;++i)
    {
        avgCount += counter[i];
        avgDur += duration[i];
        sumDurCount += counter[i]*duration[i];
        sumDur2 += duration[i]*duration[i];
    }

    avgCount = avgCount/N_TIMERS;
    avgDur = avgDur/N_TIMERS;

    a = (sumDurCount - N_TIMERS*avgDur*avgCount)/(sumDur2 - N_TIMERS*avgDur*avgDur);
    b = avgCount - a*avgDur;

    for(int i=0;i<N_TIMERS;++i)
    {
        error += (duration[i]*a + b - counter[i])*(duration[i]*a + b - counter[i]);
    }
    error = sqrt(error/N_TIMERS);

    cout << "Etalonnage" << endl;
    cout << "a = " << a << " compteurs/ms"<< endl;
    cout << "b = " << b << " compteurs"<< endl;
    cout << "Erreur = " << error << " compteurs"<< endl;

    cout << "Temps total d'exécution approximé : " << durTotal << " ms" << endl;

    return;
}

/*----------------------------------------------------------------------------
* Fonction :               call_calib
* Auteur :                 RIQUETI
* Date :                   07/11/2019
*
* But :                    Appeler de la fonction calib lorsque elle est appelée
*                          par la tâche
----------------------------------------------------------------------------*/
void* call_calib(void*)
{
    bool bu = true;
    calib();
    return (void*) bu;
}

/************************************MAIN**************************************/
int main(int argc, char *argv[])
{
    int schedPolicy = SCHED_RR;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
    pthread_attr_setschedpolicy(&attr, schedPolicy);

    sched_param schedParam;
    schedParam.sched_priority = sched_get_priority_max(schedPolicy)-1;
    pthread_setschedparam(pthread_self(), schedPolicy, &schedParam);

    schedParam.sched_priority = sched_get_priority_max(schedPolicy);
    pthread_attr_setschedparam(&attr, &schedParam);

    pthread_t calibThread;

    pthread_create(&calibThread, &attr, call_calib, nullptr);

    pthread_attr_destroy(&attr);
    pthread_join(calibThread, nullptr);

    return 0;
}
