/*///////////////////////////////////////////////////////////////////////
|
| Fichier :                PeriodicTimer.h
| Auteur :                 RIQUETI Gabriel Henrique
| Date :                   22/11/2019
| Commentaires :           ENSTA ParisTech ROB305 TD-3b
| Historique de R�vision :
|
*////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef PERIODIC_TIMER_h_INCLUDED
#define PERIODIC_TIMER_h_INCLUDED

#include "Timer.h"
#include <time.h>

namespace OSTempsReel
{

/***********************************************************************
* Classe :                 PeriodicTimer
* Auteur :                 RIQUETI
* Date :                   22/11/2019
*
* But :                    Implémenter les fonctionnalités d'un timer
*                          periodique Posix
***********************************************************************/
    class PeriodicTimer : public Timer
    {
        public:
            void start(double duration_ms);
    };

}

#endif // !PERIODIC_TIMER_h_INCLUDED
