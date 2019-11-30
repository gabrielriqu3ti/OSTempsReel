/*///////////////////////////////////////////////////////////////////////
|
| Fichier :                PosixThread.h
|| Auteur :                RIQUETI Gabriel Henrique
| Date :                   30/11/2019
| Commentaires :           ENSTA ParisTech ROB305 TD-4a
 Historique de Révision :
|
*////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef OSTempsReel_Thread_h_INCLUDED
#define OSTempsReel_Thread_h_INCLUDED

#include <pthread.h>
#include "PosixThread.h"

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
        // Méthodes
        public:
            Thread();
            ~Thread();
            double sleep_ms(double delay_ms);
            double startTime_ms();
            double stopTime_ms();
            double execTime_ms();
        protected:
            run();
        private:
            static void* call_run(void* v_thread);
    };

}

#endif // !OSTempsReel_Thread_h_INCLUDED
