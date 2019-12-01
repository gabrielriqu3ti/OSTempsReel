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
#include <iostream>

using namespace OSTempsReel;

/*----------------------------------------------------------------------
* Fonction :               PosixThread
* Auteur :                 RIQUETI
* Date :                   30/11/2019
*
* But :                    Construteur de la classe
----------------------------------------------------------------------*/
PosixThread::PosixThread()
{
    int rVal;
    rVal = pthread_attr_init(&posixAttr);

    if (rVal != 0)
        throw Exception(rVal);



}

/*----------------------------------------------------------------------
* Fonction :               PosixThread
* Auteur :                 RIQUETI
* Date :                   30/11/2019
*
* But :                    Construteur de la classe
----------------------------------------------------------------------*/
PosixThread::PosixThread(pthread_t pThreadId)
{
    posixId = pThreadId;
    int rVal;

    rVal = pthread_attr_init(&posixAttr);

    if (rVal != 0)
        throw Exception(rVal);



}

/*----------------------------------------------------------------------
* Auteur :                 RIQUETI
* Date :                   30/11/2019
*
* But :                    Destruteur de la classe
* Fonction :               ~PosixThread
----------------------------------------------------------------------*/
PosixThread::~PosixThread()
{
    pthread_attr_destroy(&posixAttr);

}

/*----------------------------------------------------------------------
* Fonction :               start
* Auteur :                 RIQUETI
* Date :                   30/11/2019
*
* But :                    ?
----------------------------------------------------------------------*/
//void PosixThread::start(void* (*)(void*) threadFunc, void* threadArg)
void PosixThread::start(void* threadFunc, void* threadArg)
{
//    pthread_create(&posixId, &posixAttr, threadFunc, &threadArg);

}

/*----------------------------------------------------------------------
* Fonction :               join
* Auteur :                 RIQUETI
* Date :                   30/11/2019
*
* But :                    ?
----------------------------------------------------------------------*/
void PosixThread::join()
{

}

/*----------------------------------------------------------------------
* Fonction :               join
* Auteur :                 RIQUETI
* Date :                   30/11/2019
*
* But :                    ?
----------------------------------------------------------------------*/
bool PosixThread::join(double timeout_ms)
{
    return false;
}

/*----------------------------------------------------------------------
* Fonction :               setScheduling
* Auteur :                 RIQUETI
* Date :                   30/11/2019
*
* But :                    Applique l’ordonnancement et la priorité
*                          spécifiée à la tâche
----------------------------------------------------------------------*/
bool PosixThread::setScheduling(int schedPolicy, int priority)
{
    int rVal;
    sched_param schedParam;

    rVal = pthread_attr_setinheritsched(&posixAttr, PTHREAD_EXPLICIT_SCHED);
    if (rVal != 0)
        throw Exception(rVal);

    rVal = pthread_attr_setschedpolicy(&posixAttr, schedPolicy);
    if (rVal != 0)
        throw Exception(rVal);

    schedParam.sched_priority = priority;

    rVal = pthread_attr_setschedparam(&posixAttr, &schedParam);
    if (rVal != 0)
        throw Exception(rVal);

    rVal = pthread_setschedparam(posixId, schedPolicy, &schedParam);
    if (rVal != 0)
        throw Exception(rVal);

    return true;
}

/*----------------------------------------------------------------------
* Fonction :               setScheduling
* Auteur :                 RIQUETI
* Date :                   30/11/2019
*
* But :                    ?
----------------------------------------------------------------------*/
bool PosixThread::getScheduling(int* p_schedPolicy, int* p_priority)
{
    int rVal;
    struct sched_param* p_schedParam;

    rVal = pthread_getschedparam(posixId, p_schedPolicy, p_schedParam);
    if (rVal != 0)
        throw Exception(rVal);
    
    p_priority = &p_schedParam->sched_priority;

    return true;
}
