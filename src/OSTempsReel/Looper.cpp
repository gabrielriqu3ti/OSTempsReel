/*///////////////////////////////////////////////////////////////////////
|
| Fichier :                Looper.cpp
| Auteur :                 RIQUETI Gabriel Henrique
| Date :                   27/10/2019
| Commentaires :           ENSTA ParisTech ROB305 TD-3c
| Historique de R�vision :
|
*///////////////////////////////////////////////////////////////////////

#include "Looper.h"
#include "../TimeSpec.h"
#include <time.h>
#include <cfloat>

using namespace OSTempsReel;

/*----------------------------------------------------------------------
* Fonction :               runLoop
* Auteur :                 RIQUETI
* Date :                   27/11/2019
*
* But :                    Mésurer le nombre de boucles efféctuées
*                          pendant un temps spécifié
----------------------------------------------------------------------*/
double Looper::runLoop(double nLoops)
{
    doStop = false;
    iLoop = nLoops;
    timespec begin, end;

    clock_gettime(CLOCK_REALTIME, &begin);

    for (iLoop = nLoops; iLoop > 0.0 && ~doStop; iLoop--)
    {}

    clock_gettime(CLOCK_REALTIME, &end);

    return timespec_to_ms(end-begin);
}

/*----------------------------------------------------------------------
* Fonction :               getSample
* Auteur :                 RIQUETI
* Date :                   27/11/2019
*
* But :                    Acquérir les nombre de boucles efféctuées
----------------------------------------------------------------------*/
double Looper::getSample()
{
    return iLoop;
}

/*----------------------------------------------------------------------
* Fonction :               stopLoop
* Auteur :                 RIQUETI
* Date :                   27/11/2019
*
* But :                    Arrêter un boucle
----------------------------------------------------------------------*/
double Looper::stopLoop()
{
    doStop = true;
    return iLoop;
}
