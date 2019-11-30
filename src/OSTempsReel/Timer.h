/*///////////////////////////////////////////////////////////////////////
|
| Fichier :                Timer.h
|| Auteur :                RIQUETI Gabriel Henrique
| Date :                   18/10/2019
| Commentaires :           ENSTA ParisTech ROB305 TD-3b
 Historique de R�vision :
|
*////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef OSTempsReel_Timer_h_INCLUDED
#define OSTempsReel_Timer_h_INCLUDED

#include <time.h>
#include <signal.h>

namespace OSTempsReel
{

/***********************************************************************
* Classe :                 Timer
* Auteur :                 RIQUETI
* Date :                   22/11/2019
*
* But :                    Implémenter les fonctionnalités d'un timer
*                          Posix
***********************************************************************/
    class Timer
    {
        // Données
        protected:
            timer_t tid;

        // Méthodes
        public:
            Timer();
            ~Timer();
            void start(double duration_ms);
            void stop();
        protected:
            virtual void callback()=0;
        private:
            static void call_callback(int sig, siginfo_t* si, void*);
    };

}

#endif // !OSTempsReel_Timer_h_INCLUDED
