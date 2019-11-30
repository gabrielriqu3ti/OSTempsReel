/*///////////////////////////////////////////////////////////////////////
|
| Fichier :                CountDown.h
|| Auteur :                RIQUETI Gabriel Henrique
| Date :                   18/10/2019
| Commentaires :           ENSTA ParisTech ROB305 TD-3b
 Historique de R�vision :
|
*////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef OSTempsReel_CountDown_h_INCLUDED
#define OSTempsReel_CountDown_h_INCLUDED

#include "Timer.h"
#include "PeriodicTimer.h"
#include <time.h>
#include <signal.h>

namespace OSTempsReel
{

/***********************************************************************
* Classe :                 CountDown
* Auteur :                 RIQUETI
* Date :                   22/11/2019
*
* But :                    Implémenter un compte à rebours
***********************************************************************/
    class CountDown : public PeriodicTimer
    {
        // Données
        private:
            int count;
        // Méthodes
        public:
            CountDown(int n);
        protected:
            void callback();
    };

}

#endif // !OSTempsReel_CountDown_h_INCLUDED
