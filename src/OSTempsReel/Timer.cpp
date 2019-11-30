/*///////////////////////////////////////////////////////////////////////
|
| Fichier :                Timer.cpp
| Auteur :                 RIQUETI Gabriel Henrique
| Date :                   18/10/2019
| Commentaires :           ENSTA ParisTech ROB305 TD-3b
| Historique de R�vision :
|
*///////////////////////////////////////////////////////////////////////

#include "Timer.h"
#include "../TimeSpec.h"
#include <time.h>
#include <signal.h>
#include <iostream>

using namespace OSTempsReel;

/*----------------------------------------------------------------------
* Fonction :               Timer
* Auteur :                 RIQUETI
* Date :                   18/10/2019
*
* But :                    Construteur de la classe
----------------------------------------------------------------------*/
Timer::Timer()
{
    struct sigaction sa;
    struct sigevent sev;

    sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = call_callback;

	sigemptyset(&sa.sa_mask);
	sigaction(SIGRTMIN, &sa, nullptr);

    sev.sigev_notify = SIGEV_SIGNAL;
	sev.sigev_signo = SIGRTMIN;
    sev.sigev_value.sival_ptr = (void*) this;

    timer_create(CLOCK_REALTIME, &sev, &tid);
}

/*----------------------------------------------------------------------
* Fonction :               ~Timer
* Auteur :                 RIQUETI
* Date :                   18/10/2019
*
* But :                    Destructeur de la classe
----------------------------------------------------------------------*/
Timer::~Timer()
{
    timer_delete(tid);
}

/*----------------------------------------------------------------------
* Fonction :               start
* Auteur :                 RIQUETI
* Date :                   22/11/2019
*
* But :                    Démarrer le timer
----------------------------------------------------------------------*/
void Timer::start(double duration_ms)
{
    itimerspec its;

    its.it_value    = timespec_from_ms(duration_ms);
    its.it_interval = timespec_from_ms(0);

    timer_settime(tid, 0, &its, nullptr);
}

/*----------------------------------------------------------------------
* Fonction :               stop
* Auteur :                 RIQUETI
* Date :                   22/11/2019
*
* But :                    Arrêter le timer
----------------------------------------------------------------------*/
void Timer::stop()
{
    itimerspec its;

    its.it_value    = timespec_from_ms(0);
    its.it_interval = timespec_from_ms(0);

    timer_settime(tid, 0, &its, nullptr);
}

/*----------------------------------------------------------------------
* Fonction :               call_callback
* Auteur :                 RIQUETI
* Date :                   22/11/2019
*
* But :                    Appeler fonction callback
----------------------------------------------------------------------*/
void Timer::call_callback(int sig, siginfo_t* si, void*)
{
    Timer* pTimer = (Timer*) si->si_value.sival_ptr;
    pTimer->callback();
}
