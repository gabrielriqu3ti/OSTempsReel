/*///////////////////////////////////////////////////////////////////////
|
| Fichier :                ThreadCounter.cpp
| Auteur :                 RIQUETI Gabriel Henrique
| Date :                   01/12/2019
| Commentaires :           ENSTA ParisTech ROB305 TD-4a
| Historique de Révision :
|
*///////////////////////////////////////////////////////////////////////

#include "../TimeSpec.h"
#include "PosixThread.h"
#include "Thread.h"
#include "Mutex.h"
#include "ThreadCounterSafe.h"

using namespace OSTempsReel;

/*----------------------------------------------------------------------
* Fonction :               ThreadCounterSafe
* Auteur :                 RIQUETI
* Date :                   01/12/2019
*
* But :                    Construteur de la classe
----------------------------------------------------------------------*/
ThreadCounterSafe::ThreadCounterSafe()
{
}

/*----------------------------------------------------------------------
* Fonction :               ThreadCounterSafe
* Auteur :                 RIQUETI
* Date :                   01/12/2019
*
* But :                    Construteur de la classe
----------------------------------------------------------------------*/
ThreadCounterSafe::ThreadCounterSafe(Mutex& mtx) : taskId(nTasks)
{
    mutex = &mtx;
    nTasks += 1;
}

/*----------------------------------------------------------------------
* Fonction :               setLoops
* Auteur :                 RIQUETI
* Date :                   01/12/2019
*
* But :                    Attribuer une valeur à nLoops
----------------------------------------------------------------------*/
void ThreadCounterSafe::setLoops(unsigned int Loops)
{
    nLoops = Loops;
}

/*----------------------------------------------------------------------
* Fonction :               setTimeout
* Auteur :                 RIQUETI
* Date :                   01/12/2019
*
* But :                    Attribuer une valeur aux temps d'attente
----------------------------------------------------------------------*/
void ThreadCounterSafe::setTimeout(double timeout_ms)
{
    timeoutMs = timeout_ms;
}

/*----------------------------------------------------------------------
* Fonction :               getCount
* Auteur :                 RIQUETI
* Date :                   01/12/2019
*
* But :                    Retourner le compteur
----------------------------------------------------------------------*/
unsigned int ThreadCounterSafe::getCount()
{
    return count;
}

/*----------------------------------------------------------------------
* Fonction :               nextThreadActive
* Auteur :                 RIQUETI
* Date :                   01/12/2019
*
* But :                    Déterminer la proichanne thread à exécuter
----------------------------------------------------------------------*/
void ThreadCounterSafe::nextThreadActive()
{
    if(activeTask == nTasks-1)
    {
        activeTask = 0;
    }
    else
    {
        activeTask++;
    }
}

/*----------------------------------------------------------------------
* Fonction :               run
* Auteur :                 RIQUETI
* Date :                   01/12/2019
*
* But :                    ?
----------------------------------------------------------------------*/
void ThreadCounterSafe::run()
{
    chrono.restart();

    try
    {
        {
            Mutex::Lock lock = Mutex::Lock(*mutex);

            while(activeTask!=taskId)
            {
                if(timeoutMs==0) lock.wait();
                else lock.wait(timeoutMs);
            }

            for(unsigned int i=0; i<nLoops; i++) count ++;

            if(timeoutMs==0) lock.notify();
            else lock.notifyAll();

            nextThreadActive();
        }
    }
    catch(Mutex::Monitor::TimeoutException timeExc)
    {
        timeExc.message();
    }



    chrono.stop();
}
