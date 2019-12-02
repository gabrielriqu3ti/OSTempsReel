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
#include "ThreadCounter.h"
#include <iostream>

using namespace OSTempsReel;

/*----------------------------------------------------------------------
* Fonction :               setLoops
* Auteur :                 RIQUETI
* Date :                   31/11/2019
*
* But :                    Attribuer une valeur à nLoops
----------------------------------------------------------------------*/
void ThreadCounter::setLoops(unsigned int Loops)
{
    nLoops = Loops;
}

/*----------------------------------------------------------------------
* Fonction :               getCount
* Auteur :                 RIQUETI
* Date :                   31/11/2019
*
* But :                    Retourner le compteur
----------------------------------------------------------------------*/
unsigned int ThreadCounter::getCount()
{
    return count;
}

/*----------------------------------------------------------------------
* Fonction :               run
* Auteur :                 RIQUETI
* Date :                   01/12/2019
*
* But :                    ?
----------------------------------------------------------------------*/
void ThreadCounter::run()
{
    chrono.restart();

    for(unsigned int i=0; i<nLoops; i++) count ++;

    chrono.stop();
}
