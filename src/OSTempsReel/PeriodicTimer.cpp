/*///////////////////////////////////////////////////////////////////////
|
| Fichier :                PeriodicTimer.cpp
| Auteur :                 RIQUETI Gabriel Henrique
| Date :                   22/11/2019
| Commentaires :           ENSTA ParisTech ROB305 TD-3b
| Historique de R�vision :
|
*///////////////////////////////////////////////////////////////////////

#include "Timer.h"
#include "PeriodicTimer.h"
#include "../TimeSpec.h"
#include <time.h>
#include <iostream>

using namespace OSTempsReel;

/*----------------------------------------------------------------------
* Fonction :               start
* Auteur :                 RIQUETI
* Date :                   22/11/2019
*
* But :                    Démarrer les timer periodique
----------------------------------------------------------------------*/
void PeriodicTimer::start(double duration_ms)
{
    itimerspec its;

    its.it_value    = timespec_from_ms(duration_ms);
    its.it_interval = timespec_from_ms(duration_ms);

    timer_settime(tid, 0, &its, nullptr);
}
