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
    isActive = false;
    rVal = pthread_attr_init(&posixAttr);

    if (rVal != 0) throw Exception(rVal);

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
    int rVal;
    isActive = false;
    posixId = pThreadId;

    rVal = pthread_attr_init(&posixAttr);

    if (rVal != 0) throw Exception(rVal);

}

/*----------------------------------------------------------------------
* Auteur :                 RIQUETI
* Date :                   30/11/2019
*
* But :                    Destruteur de la classe
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
* But :                    Créer et démarrer la thread Posix
----------------------------------------------------------------------*/
void PosixThread::start(void* threadFunc(void*), void* threadArg)
{
    isActive = true;
    pthread_create(&posixId, &posixAttr, threadFunc, threadArg);

}

/*----------------------------------------------------------------------
* Fonction :               join
* Auteur :                 RIQUETI
* Date :                   30/11/2019
*
* But :                    Attendre jusqu'à la fin d'exécution de la thread
----------------------------------------------------------------------*/
void PosixThread::join()
{
    if (isActive) {
        pthread_join(posixId, nullptr);
        isActive = false;
    }
}

/*----------------------------------------------------------------------
* Fonction :               join
* Auteur :                 RIQUETI
* Date :                   30/11/2019
*
* But :                    Attendre jusqu'à un temps spécifié la fin
*                          d'exécution de la thread
----------------------------------------------------------------------*/
bool PosixThread::join(double timeout_ms)
{
    int rVal;

    const timespec abstime = (const timespec) timespec_from_ms(timeout_ms);

    if (isActive) {
        rVal = pthread_timedjoin_np(posixId, nullptr, &abstime);
        if(rVal != 0) throw Exception(rVal);

        isActive = false;
    }
}

/*----------------------------------------------------------------------
* Fonction :               setScheduling
* Auteur :                 RIQUETI
* Date :                   30/11/2019
*
* But :                    Appliquer l’ordonnancement et la priorité
*                          spécifiée à la tâche
----------------------------------------------------------------------*/
bool PosixThread::setScheduling(int schedPolicy, int priority)
{
    if(isActive)
    {
        int rVal;
        sched_param schedParam;

        rVal = pthread_attr_setinheritsched(&posixAttr, PTHREAD_EXPLICIT_SCHED);
        if (rVal != 0) throw Exception(rVal);

        rVal = pthread_attr_setschedpolicy(&posixAttr, schedPolicy);
        if (rVal != 0) throw Exception(rVal);

        schedParam.sched_priority = priority;

        rVal = pthread_attr_setschedparam(&posixAttr, &schedParam);
        if (rVal != 0) throw Exception(rVal);

        rVal = pthread_setschedparam(posixId, schedPolicy, &schedParam);
        if (rVal != 0) throw Exception(rVal);
    }

    return isActive;
}

/*----------------------------------------------------------------------
* Fonction :               setScheduling
* Auteur :                 RIQUETI
* Date :                   30/11/2019
*
* But :                    Obtenir l’ordonnancement et la priorité
*                          spécifiée à la tâche
----------------------------------------------------------------------*/
bool PosixThread::getScheduling(int* p_schedPolicy, int* p_priority)
{
    if(isActive)
    {
        int rVal;
        struct sched_param* p_schedParam;

        rVal = pthread_getschedparam(posixId, p_schedPolicy, p_schedParam);
        if (rVal != 0) throw Exception(rVal);

        p_priority = &p_schedParam->sched_priority;
    }

    return isActive;
}

/*----------------------------------------------------------------------
* Fonction :               Exception::Exception()
* Auteur :                 RIQUETI
* Date :                   31/11/2019
*
* But :                    Montrer une message d'erreur
----------------------------------------------------------------------*/
PosixThread::Exception::Exception(int rVal)
{
    retVal = rVal;
}


/*----------------------------------------------------------------------
* Fonction :               Exception::message
* Auteur :                 RIQUETI
* Date :                   31/11/2019
*
* But :                    Montrer une message d'erreur
----------------------------------------------------------------------*/
void PosixThread::Exception::message()
{
    switch(retVal)
    {
        case(EAGAIN):
        std::cout << "Erreur EAGAIN (" << retVal << ") : Ressources unsifisants pour créer un thread !" << std::endl;
        break;
        case(ESRCH):
        std::cout << "Erreur ESRCH (" << retVal << ") : Aucun thread avec l'ID spécifié était trouvé !" << std::endl;
        break;
        case(EINVAL):
        std::cout << "Erreur EINVAL (" << retVal << ") : Paramètres invalides !" << std::endl; // dans attr ou join ou abstime
        break;
        case(EPERM):
        std::cout << "Erreur EPERM (" << retVal << ") : Aucune autorisation pour établir un scheduling policy";
        std::cout << " et paramètres spécifiés dans attr !" << std::endl;
        break;
        case(ENOMEM):
        std::cout << "Erreur ENOMEM (" << retVal << ") : pthread_attr_init ou pthread_attr_destroy a échoué !" << std::endl;
        break;
        case(EDEADLK):
        std::cout << "Erreur EDEADLK (" << retVal << ") : deadlock detécté ou threads appellent les uns les autres !" << std::endl;
        break;
        case(EBUSY):
        std::cout << "Erreur EBUSY (" << retVal << ") : thread pas encore terminé au moment de l'appel !" << std::endl;
        break;
        case(ETIMEDOUT):
        std::cout << "Erreur ETIMEDOUT (" << retVal << ") : L'appel terminé avant thread !" << std::endl;
        break;
        default:
        std::cout << "Erreur " << retVal << " : inconnu !" << std::endl;
        break;
        exit(1);
    }
}
