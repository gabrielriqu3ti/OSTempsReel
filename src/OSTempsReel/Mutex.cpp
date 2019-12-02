/*///////////////////////////////////////////////////////////////////////
|
| Fichier :                Mutex.cpp
| Auteur :                 RIQUETI Gabriel Henrique
| Date :                   01/12/2019
| Commentaires :           ENSTA ParisTech ROB305 TD-4b
| Historique de Révision :
|
*///////////////////////////////////////////////////////////////////////

#include "../TimeSpec.h"
#include "Mutex.h"
#include <errno.h>
#include <iostream>

using namespace OSTempsReel;

/*----------------------------------------------------------------------
* Fonction :               Mutex
* Auteur :                 RIQUETI
* Date :                   01/12/2019
*
* But :                    Constructeur de la classe
----------------------------------------------------------------------*/
Mutex::Mutex()
{
    int rVal;
    pthread_mutexattr_t mutexAttribute;

    rVal = pthread_mutexattr_init(&mutexAttribute);
    if(rVal != 0) throw Monitor::TimeoutException(rVal);

    rVal = pthread_mutexattr_settype(&mutexAttribute, PTHREAD_MUTEX_RECURSIVE);
    if(rVal != 0) throw Monitor::TimeoutException(rVal);

    rVal = pthread_mutex_init(&posixId, &mutexAttribute);
    if(rVal != 0) throw Monitor::TimeoutException(rVal);

    rVal = pthread_mutexattr_destroy(&mutexAttribute);
    if(rVal != 0) throw Monitor::TimeoutException(rVal);

    rVal = pthread_cond_init(&posixCondId, nullptr);
    if(rVal != 0) throw Monitor::TimeoutException(rVal);

}

/*----------------------------------------------------------------------
* Auteur :                 RIQUETI
* Date :                   01/12/2019
*
* But :                    Destructeur de la classe
----------------------------------------------------------------------*/
Mutex::~Mutex()
{
    pthread_mutex_destroy(&posixId);
    pthread_cond_destroy(&posixCondId);
}

/*----------------------------------------------------------------------
* Fonction :               lock
* Auteur :                 RIQUETI
* Date :                   01/12/2019
*
* But :                    ?
----------------------------------------------------------------------*/
void Mutex::lock()
{
    int rVal;

    rVal = pthread_mutex_lock(&posixId);
    if(rVal != 0) throw Monitor::TimeoutException(rVal);
}

/*----------------------------------------------------------------------
* Fonction :               lock
* Auteur :                 RIQUETI
* Date :                   01/12/2019
*
* But :                    ?
----------------------------------------------------------------------*/
bool Mutex::lock(double timeout_ms)
{
    int rVal;
    const timespec timeout_ts = timespec_from_ms(timeout_ms);

    rVal = pthread_mutex_timedlock(&posixId, &timeout_ts);
    if(rVal != 0 && rVal != ETIMEDOUT) throw Monitor::TimeoutException(rVal);
    else if (rVal == ETIMEDOUT) return false;

    return true;
}

/*----------------------------------------------------------------------
* Fonction :               trylock
* Auteur :                 RIQUETI
* Date :                   01/12/2019
*
* But :                    ?
----------------------------------------------------------------------*/
bool Mutex::trylock()
{
    int rVal;

    rVal = pthread_mutex_trylock(&posixId);
    if(rVal != 0 && rVal != EBUSY) throw Monitor::TimeoutException(rVal);
    else if (rVal == EBUSY) return false;

    return true;
}

/*----------------------------------------------------------------------
* Fonction :               unlock
* Auteur :                 RIQUETI
* Date :                   01/12/2019
*
* But :                    ?
----------------------------------------------------------------------*/
void Mutex::unlock()
{
    int rVal;

    rVal = pthread_mutex_unlock(&posixId);
    if(rVal != 0) throw Monitor::TimeoutException(rVal);

}

/*----------------------------------------------------------------------
* Fonction                 Monitor
* Auteur :                 RIQUETI
* Date :                   01/12/2019
*
* But :                    Constructeur de la classe Monitor
----------------------------------------------------------------------*/
Mutex::Monitor::Monitor(Mutex& m)
{
    mutex = &m;
}

/*----------------------------------------------------------------------
* Fonction :               wait
* Auteur :                 RIQUETI
* Date :                   01/12/2019
*
* But :                    ?
----------------------------------------------------------------------*/
void Mutex::Monitor::wait()
{
    int rVal;

    rVal = pthread_cond_wait(&mutex->posixCondId, &mutex->posixId);
    if(rVal != 0) throw Monitor::TimeoutException(rVal);

}

/*----------------------------------------------------------------------
* Fonction :               wait
* Auteur :                 RIQUETI
* Date :                   01/12/2019
*
* But :                    ?
----------------------------------------------------------------------*/
bool Mutex::Monitor::wait(double timeout_ms)
{
    int rVal;
    timespec abstime_ts, timeout_ts;

    timeout_ts = timespec_from_ms(timeout_ms);
    clock_gettime(CLOCK_REALTIME, &abstime_ts);
    abstime_ts += timeout_ts;

    rVal = pthread_cond_timedwait(&mutex->posixCondId, &mutex->posixId, &abstime_ts);
    if(rVal != 0 && rVal != ETIMEDOUT) throw Monitor::TimeoutException(rVal);
    else if (rVal == ETIMEDOUT) return false;

    return true;
}

/*----------------------------------------------------------------------
* Fonction :               notify
* Auteur :                 RIQUETI
* Date :                   01/12/2019
*
* But :                    ?
----------------------------------------------------------------------*/
void Mutex::Monitor::notify()
{
    int rVal;

    rVal = pthread_cond_signal(&mutex->posixCondId);
    if(rVal != 0) throw Monitor::TimeoutException(rVal);

}

/*----------------------------------------------------------------------
* Fonction :               notifyAll
* Auteur :                 RIQUETI
* Date :                   01/12/2019
*
* But :                    ?
----------------------------------------------------------------------*/
void Mutex::Monitor::notifyAll()
{
    int rVal;

    rVal = pthread_cond_broadcast(&mutex->posixCondId);
    if(rVal != 0) throw Monitor::TimeoutException(rVal);

}

/*----------------------------------------------------------------------
* Fonction :               TimeroutException::Exception
* Auteur :                 RIQUETI
* Date :                   01/12/2019
*
* But :                    Constructeur de la
----------------------------------------------------------------------*/
Mutex::Monitor::TimeoutException::TimeoutException(int rVal)
{
    retVal = rVal;
}


/*----------------------------------------------------------------------
* Fonction :               TimeoutException::message
* Auteur :                 RIQUETI
* Date :                   01/12/2019
*
* But :                    Montrer une message d'erreur
----------------------------------------------------------------------*/
void Mutex::Monitor::TimeoutException::message()
{
    switch(retVal)
    {
        case(EAGAIN):
        std::cout << "Timeout Mutex Erreur EAGAIN (" << retVal << ") : Ressources unsifisants !" << std::endl;
        break;
        case(ESRCH):
        std::cout << "Timeout Mutex Erreur ESRCH (" << retVal << ") : ID spécifié n'était pas trouvé !" << std::endl;
        break;
        case(EINVAL):
        std::cout << "Timeout Mutex Erreur EINVAL (" << retVal << ") : Paramètres invalides !" << std::endl; // dans attr ou join ou abstime
        break;
        case(EPERM):
        std::cout << "Timeout Mutex Erreur EPERM (" << retVal << ") : Aucune autorisation !" << std::endl;
        break;
        case(ENOMEM):
        std::cout << "Timeout Mutex Erreur ENOMEM (" << retVal << ") : Allocation de mémoire a échoué !" << std::endl;
        break;
        case(EDEADLK):
        std::cout << "Timeout Mutex Erreur EDEADLK (" << retVal << ") : deadlock detécté ou threads appellent les uns les autres !" << std::endl;
        break;
        case(EBUSY):
        std::cout << "Timeout Mutex Erreur EBUSY (" << retVal << ") : thread pas encore terminé au moment de l'appel !" << std::endl;
        break;
        case(ETIMEDOUT):
        std::cout << "Timeout Mutex Erreur ETIMEDOUT (" << retVal << ") : L'appel terminé avant thread !" << std::endl;
        break;
        default:
        std::cout << "Timeout Mutex Erreur " << retVal << " : inconnu !" << std::endl;
        break;
        exit(1);
    }
}

/*----------------------------------------------------------------------
* Fonction :               Lock
* Auteur :                 RIQUETI
* Date :                   01/12/2019
*
* But :                    Constructeur de la classe Lock
----------------------------------------------------------------------*/
Mutex::Lock::Lock(Mutex& m) : Mutex::Monitor::Monitor(m)
{
    int rVal;

    rVal = pthread_mutex_lock(&m.posixId);
    if(rVal != 0) throw Monitor::TimeoutException(rVal);
}

/*----------------------------------------------------------------------
* Fonction :               Lock
* Auteur :                 RIQUETI
* Date :                   01/12/2019
*
* But :                    Constructeur de la classe Lock
----------------------------------------------------------------------*/
Mutex::Lock::Lock(Mutex& m, double timeout_ms) : Mutex::Monitor::Monitor(m)
{
    int rVal;
    const timespec timeout_ts = timespec_from_ms(timeout_ms);

    rVal = pthread_mutex_timedlock(&m.posixId, &timeout_ts);
    if(rVal != 0  && rVal != ETIMEDOUT) throw Monitor::TimeoutException(rVal);

}

/*----------------------------------------------------------------------
* Fonction :               Lock
* Auteur :                 RIQUETI
* Date :                   01/12/2019
*
* But :                    Constructeur de la classe Lock
----------------------------------------------------------------------*/
Mutex::Lock::~Lock()
{
    pthread_mutex_unlock(&mutex->posixId);
}

/*----------------------------------------------------------------------
* Fonction                 TryLock
* Auteur :                 RIQUETI
* Date :                   01/12/2019
*
* But :                    Constructeur de la classe TryLock
----------------------------------------------------------------------*/
Mutex::TryLock::TryLock(Mutex& m) : Mutex::Monitor::Monitor(m)
{
    int rVal;

    rVal = pthread_mutex_trylock(&m.posixId);
    if(rVal != 0 && rVal != EBUSY) throw Monitor::TimeoutException(rVal);

}

/*----------------------------------------------------------------------
* Fonction :               ~TryLock
* Auteur :                 RIQUETI
* Date :                   01/12/2019
*
* But :                    Destructeur de la classe TryLock
----------------------------------------------------------------------*/
Mutex::TryLock::~TryLock()
{
    pthread_mutex_unlock(&mutex->posixId);
}
