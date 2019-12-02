/*///////////////////////////////////////////////////////////////////////
|
| Fichier :                Thread.h
| Auteur :                 RIQUETI Gabriel Henrique
| Date :                   30/11/2019
| Commentaires :           ENSTA ParisTech ROB305 TD-4a
| Historique de Révision :
|
*////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef OSTempsReel_Thread_h_INCLUDED
#define OSTempsReel_Thread_h_INCLUDED

#include <pthread.h>
#include "PosixThread.h"
#include "Chrono.h"

namespace OSTempsReel
{

/***********************************************************************
* Classe :                 Thread
* Auteur :                 RIQUETI
* Date :                   30/11/2019
*
* But :                    Implémenter les fonctionnalités d'un thread
***********************************************************************/
    class Thread : public PosixThread
    {
        // Données
        protected:
            Chrono chrono;
        private:
            bool started;
        // Méthodes
        public:
            Thread();
            ~Thread();
//            void start();
            bool start();
            static double sleep_ms(double delay_ms);
            double startTime_ms();
            double stopTime_ms();
            double execTime_ms();
        protected:
            virtual void run()=0;
        private:
            static void* call_run(void* v_thread);
    };

}

#endif // !OSTempsReel_Thread_h_INCLUDED
