/*////////////////////////////////////////////////////////////////////////////////
|
| Fichier :                td1b_main.cpp
| Auteur :                 RIQUETI Gabriel Henrique
| Date :                   27/09/2019
| Commentaires :           ENSTA ParisTech ROB305 TD-1b
| Commande :               g++ td1b_main.cpp TimeSpec.cpp -lrt -o ../td1b && ../td1b
| Historique de Révision :
|
*/////////////////////////////////////////////////////////////////////////////////

// archive principal
#include "TimeSpec.h"
#include <time.h>
#include <signal.h>
#include <iostream>

using namespace std;

/*----------------------------------------------------------------------------
* Fonction :               myHandler
* Auteur :                 RIQUETI
* Date :                   08/10/2019
*
* But :                    Incremente un compteur lorsque elle est appelée
*                          par le timeur
----------------------------------------------------------------------------*/
void myHandler(int sig, siginfo_t* si, void*)
{
	volatile int* pData = (volatile int*) si->si_value.sival_ptr;
	*pData += 1;
	cout << "Compteur : " << *pData << endl;
	return;
}

/************************************MAIN**************************************/
int main()
{
	timer_t tid;
	struct sigaction sa;
	volatile int myData = 0;
	itimerspec its;
	struct sigevent sev;
	timespec init, end;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = myHandler;

	sigemptyset(&sa.sa_mask);
	sigaction(SIGRTMIN, &sa, nullptr);

	sev.sigev_notify = SIGEV_SIGNAL;
	sev.sigev_signo = SIGRTMIN;
	sev.sigev_value.sival_ptr = (void*) &myData;

	timer_create(CLOCK_REALTIME, &sev, &tid);

	its.it_value.tv_sec = 0;
	its.it_value.tv_nsec = 5e8;
	its.it_interval.tv_sec = its.it_value.tv_sec;
	its.it_interval.tv_nsec = its.it_value.tv_nsec;

	init = timespec_now();

	timer_settime(tid, 0, &its, nullptr);

	while(myData < 15){}

	end = timespec_now();

	timer_delete(tid);

	cout << "Durée : " << timespec_to_ms(end-init) << " ms" << endl;

	return 0;
}
