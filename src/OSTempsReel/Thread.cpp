/*///////////////////////////////////////////////////////////////////////
|
| Fichier :                Thread.cpp
| Auteur :                 RIQUETI Gabriel Henrique
| Date :                   30/11/2019
| Commentaires :           ENSTA ParisTech ROB305 TD-4a
| Historique de Révision :
|
*///////////////////////////////////////////////////////////////////////

#include "../TimeSpec.h"
#include "PosixThread.h"
#include "Thread.h"
#include "Chrono.h"
#include <iostream>

using namespace OSTempsReel;

/*----------------------------------------------------------------------
* Fonction :               Thread
* Auteur :                 RIQUETI
* Date :                   30/11/2019
*
* But :                    Construteur de la classe
----------------------------------------------------------------------*/
Thread::Thread() : started(false)
{
    PosixThread(pThreadId);

    chrono = Chrono();
}

/*----------------------------------------------------------------------
* Fonction :               ~Thread
* Auteur :                 RIQUETI
* Date :                   30/11/2019
*
* But :                    Destruteur de la classe
----------------------------------------------------------------------*/
Thread::~Thread()
{
}

/*----------------------------------------------------------------------
* Fonction :               startTime_ms
* Auteur :                 RIQUETI
* Date :                   30/11/2019
*
* But :                    Retourner le temps absolu de fin
----------------------------------------------------------------------*/
bool Thread::start()
{
    if(!started)
    {
        PosixThread::start(call_run, (void*) this);
        started = true;
    }
    return started;
}

/*----------------------------------------------------------------------
* Fonction :               sleep_ms
* Auteur :                 RIQUETI
* Date :                   30/11/2019
*
* But :                    ?
----------------------------------------------------------------------*/
double Thread::sleep_ms(double delay_ms)
{
    timespec_wait(timespec_from_ms(delay_ms));
    return delay_ms;
}

/*----------------------------------------------------------------------
* Fonction :               startTime_ms
* Auteur :                 RIQUETI
* Date :                   30/11/2019
*
* But :                    Retourner le temps absolu du début
----------------------------------------------------------------------*/
double Thread::startTime_ms()
{
    return chrono.startTime();
}

/*----------------------------------------------------------------------
* Fonction :               stopTime_ms
* Auteur :                 RIQUETI
* Date :                   30/11/2019
*
* But :                    Retourner le temps absolu du fin
----------------------------------------------------------------------*/
double Thread::stopTime_ms()
{
    return chrono.stopTime();
}

/*----------------------------------------------------------------------
* Fonction :               execTime_ms
* Auteur :                 RIQUETI
* Date :                   30/11/2019
*
* But :                    Retourner le temps d'exécution
----------------------------------------------------------------------*/
double Thread::execTime_ms()
{
    return (chrono.stopTime() - chrono.startTime());
}

/*----------------------------------------------------------------------
* Fonction :               call_run
* Auteur :                 RIQUETI
* Date :                   30/11/2019
*
* But :                    Appeler run
----------------------------------------------------------------------*/
void* Thread::call_run(void* v_thread)
{
    Thread* pThread = (Thread*) v_thread;
    pThread->run();

    return v_thread;
}
