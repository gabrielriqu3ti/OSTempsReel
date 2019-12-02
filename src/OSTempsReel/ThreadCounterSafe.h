/*///////////////////////////////////////////////////////////////////////
|
| Fichier :                ThreadCounterSafe.h
| Auteur :                RIQUETI Gabriel Henrique
| Date :                   01/12/2019
| Commentaires :           ENSTA ParisTech ROB305 TD-4a
| Historique de Révision :
|
*////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef OSTempsReel_ThreadCounterMutex_h_INCLUDED
#define OSTempsReel_ThreadCounterMutex_h_INCLUDED

#include <pthread.h>
#include "Thread.h"
#include "Mutex.h"

namespace OSTempsReel
{

/***********************************************************************
* Classe :                 ThreadCounterSafe
* Auteur :                 RIQUETI
* Date :                   01/12/2019
*
* But :                    Implémenter les fonctionnalités d'un thread
*                          comptant avec mutex
***********************************************************************/
class ThreadCounterSafe : public Thread
    {
        // Données
        private:
            static unsigned int count;      // déclaration de variable statique
            static unsigned int nLoops;     // déclaration de variable statique
            static unsigned int nTasks;     // déclaration de variable statique
            static unsigned int activeTask; // déclaration de variable statique
            static double timeoutMs;       // déclaration de variable statique
            unsigned int taskId;
            Mutex* mutex;
        // Méthodes
        public:
            ThreadCounterSafe();
            ThreadCounterSafe(Mutex& mtx);
            static void setLoops(unsigned int Loops);
            static void setTimeout(double timeout_ms);
            static unsigned int getCount();
        protected:
            static void nextThreadActive();
            void run();
    };

}

#endif // !OSTempsReel_ThreadCounterMutex_h_INCLUDED
