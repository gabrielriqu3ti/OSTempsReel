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

}

/*----------------------------------------------------------------------
* Fonction :               PosixThread
* Auteur :                 RIQUETI
* Date :                   30/11/2019
*
* But :                    Construteur de la classe
----------------------------------------------------------------------*/
PosixThread::PosixThread(pthread_t posixId);
{

}

/*----------------------------------------------------------------------
* Fonction :               ~PosixThread
* Auteur :                 RIQUETI
* Date :                   30/11/2019
*
* But :                    Destruteur de la classe
----------------------------------------------------------------------*/
PosixThread::~PosixThread()
{

}

/*----------------------------------------------------------------------
* Fonction :               start
* Auteur :                 RIQUETI
* Date :                   30/11/2019
*
* But :                    ?
----------------------------------------------------------------------*/
void PosixThread::start(void* (*) (void*) threadFunc, void* threadArg)
{

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
* But :                    ?
----------------------------------------------------------------------*/
bool PosixThread::setScheduling(int schedPolicy, int priority)
{
    return false;
}

/*----------------------------------------------------------------------
* Fonction :               setScheduling
* Auteur :                 RIQUETI
* Date :                   30/11/2019
*
* But :                    ?
----------------------------------------------------------------------*/
bool PosixThread::getScheduling(int* p_schedPolity, int* p_priority)
{
    return false;
}
