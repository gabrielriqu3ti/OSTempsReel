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
#ifndef OSTempsReel_PosixThread_h_INCLUDED
#define OSTempsReel_PosixThread_h_INCLUDED

#include <pthread.h>

namespace OSTempsReel
{

/***********************************************************************
* Classe :                 PosixThread
* Auteur :                 RIQUETI
* Date :                   30/11/2019
*
* But :                    Implémenter les fonctionnalités d'un thread
*                          Posix
***********************************************************************/
    class PosixThread
    {
        // Données
        public:
            Exception e;
        private:
            pthread_t posixId;
            pthread_attr_t posixAttr;
        protected:
            bool isActive;

        // Méthodes
        public:
            PosixThread();
            PosixThread(pthread_t posixId);
            ~PosixThread();
            void start(void* (*) (void*) threadFunc, void* threadArg);
            void join();
            bool join(double timeout_ms);
            bool setScheduling(int schedPolicy, int priority);
            bool getScheduling(int* p_schedPolity = nullptr, int* p_priority = nullptr);
    };

}

#endif // !OSTempsReel_PosixThread_h_INCLUDED
