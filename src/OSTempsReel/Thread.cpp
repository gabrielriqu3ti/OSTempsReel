/*///////////////////////////////////////////////////////////////////////
|
| Fichier :                PosixThread.cpp
| Auteur :                 RIQUETI Gabriel Henrique
| Date :                   30/11/2019
| Commentaires :           ENSTA ParisTech ROB305 TD-4a
| Historique de Révision :
|
*///////////////////////////////////////////////////////////////////////

#include "../TimeSpec.h"
#include "PosixThread.h"
#include "Thread.h"
#include <iostream>

using namespace OSTempsReel;

/*----------------------------------------------------------------------
* Fonction :               Thread
* Auteur :                 RIQUETI
* Date :                   30/11/2019
*
* But :                    Construteur de la classe
----------------------------------------------------------------------*/
Thread::Thread()
{

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
* Fonction :               sleep_ms
* Auteur :                 RIQUETI
* Date :                   30/11/2019
*
* But :                    ?
----------------------------------------------------------------------*/
double Thread::sleep_ms(double delay_ms)
{
    return 0.0;
}

/*----------------------------------------------------------------------
* Fonction :               startTime_ms
* Auteur :                 RIQUETI
* Date :                   30/11/2019
*
* But :                    ?
----------------------------------------------------------------------*/
double Thread::startTime_ms()
{
    timespec begin, end;

    clock_gettime(CLOCK_REALTIME, &begin);



    clock_gettime(CLOCK_REALTIME, &end);

    return timespec_to_ms(end-begin);
}

/*----------------------------------------------------------------------
* Fonction :               stopTime_ms
* Auteur :                 RIQUETI
* Date :                   30/11/2019
*
* But :                    ?
----------------------------------------------------------------------*/
double Thread::stopTime_ms()
{
    timespec begin, end;

    clock_gettime(CLOCK_REALTIME, &begin);



    clock_gettime(CLOCK_REALTIME, &end);

    return timespec_to_ms(end-begin);
}

/*----------------------------------------------------------------------
* Fonction :               execTime_ms
* Auteur :                 RIQUETI
* Date :                   30/11/2019
*
* But :                    ?
----------------------------------------------------------------------*/
double Thread::execTime_ms()
{
    timespec begin, end;

    clock_gettime(CLOCK_REALTIME, &begin);



    clock_gettime(CLOCK_REALTIME, &end);

    return timespec_to_ms(end-begin);
}

/*----------------------------------------------------------------------
* Fonction :               run
* Auteur :                 RIQUETI
* Date :                   30/11/2019
*
* But :                    ?
----------------------------------------------------------------------*/
void Thread::run()
{

}

/*----------------------------------------------------------------------
* Fonction :               call_run
* Auteur :                 RIQUETI
* Date :                   30/11/2019
*
* But :                    ?
----------------------------------------------------------------------*/
void* Thread::call_run(void* v_thread)
{
    void* pData;
    return pData;
}
