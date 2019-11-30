/*////////////////////////////////////////////////////////////////////////////////
|
| Fichier :                td1d_main.cpp
| Auteur :                 RIQUETI Gabriel Henrique
| Date :                   22/10/2019
| Commentaires :           ENSTA ParisTech ROB305 TD-1d
| Commande :               g++ td1d_main.cpp TimeSpec.cpp -lrt -o ../td1d && ../td1d
| Historique de Révision :
|
*/////////////////////////////////////////////////////////////////////////////////

// archive principal
#include "TimeSpec.h"
#include <time.h>
#include <signal.h>
#include <iostream>
#include <climits>

using namespace std;

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
    unsigned int iLoop;
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
* Date :                   22/10/2019
*
* But :                    Trouve les valeur a et b qui mieux approximent la
*                          fonction l(t) = ax+b
----------------------------------------------------------------------------*/
void calib()
{
    timespec begin4, end4, begin6, end6;
    unsigned int nLoops = UINT_MAX;
    double counter4, counter6, duration4, duration6;
    counter4 = counter6 = 0.0;
    timer_t tid;
	struct sigaction sa;
	itimerspec its;
	struct sigevent sev;
    struct myDataHandler myData;

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

    myData.stop = false;

	its.it_value.tv_sec = 4;
    its.it_value.tv_nsec = 0;
	its.it_interval.tv_sec = 0;
	its.it_interval.tv_nsec = 0;

    timer_settime(tid, 0, &its, NULL);

    clock_gettime(CLOCK_REALTIME, &begin4);
    incr(nLoops, &counter4, &myData.stop);
    clock_gettime(CLOCK_REALTIME, &end4);

    duration4 = timespec_to_ms(end4-begin4);

    cout << "Compteur : " << counter4 << endl;
    cout << "Temps d'exécution : " << duration4 << " ms" << endl;

    myData.stop = false;

	its.it_value.tv_sec = 6;

    timer_settime(tid, 0, &its, NULL);

    clock_gettime(CLOCK_REALTIME, &begin6);
    incr(nLoops, &counter6, &myData.stop);
    clock_gettime(CLOCK_REALTIME, &end6);

    timespec_wait(its.it_value);

	timer_delete(tid);

    duration6 = timespec_to_ms(end6-begin6);

    cout << "Compteur : " << counter6 << endl;
    cout << "Temps d'exécution : " << duration6 << " ms" << endl;

    double a, b;

    a = (counter6 - counter4)/(duration6 - duration4);
    b = counter4*duration6 - counter6*duration4;

    cout << "Etalonnage" << endl;
    cout << "a = " << a << " compteurs/ms"<< endl;
    cout << "b = " << b << " compteurs"<< endl;

    return;
}

/************************************MAIN**************************************/
int main(int argc, char *argv[])
{
    timespec begin, end;
    unsigned int nLoops = UINT_MAX;
    double counter = 0.0;
    timer_t tid;
	struct sigaction sa;
	itimerspec its;
	struct sigevent sev;
    struct myDataHandler myData;

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

	its.it_value.tv_sec = 1;
	its.it_value.tv_nsec = 0;
	its.it_interval.tv_sec = 0;
	its.it_interval.tv_nsec = 0;

    timer_settime(tid, 0, &its, NULL);

    clock_gettime(CLOCK_REALTIME, &begin);
    incr(nLoops, &counter, &myData.stop);
    clock_gettime(CLOCK_REALTIME, &end);

    timespec_wait(its.it_value);

    cout << "Compteur : " << counter << endl;
    cout << "Temps d'exécution : " << timespec_to_ms(end-begin) << " ms" << endl;

    calib();

    return 0;
}
