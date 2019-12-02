/*///////////////////////////////////////////////////////////////////////
|
| Fichier :                Mutex.h
| Auteur :               RIQUETI Gabriel Henrique
| Date :                   01/12/2019
| Commentaires :           ENSTA ParisTech ROB305 TD-4b
| Historique de Révision :
|
*////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef OSTempsReel_Mutex_h_INCLUDED
#define OSTempsReel_Mutex_h_INCLUDED

#include <pthread.h>
#include <errno.h>

namespace OSTempsReel
{

/***********************************************************************
* Classe :                 Mutex
* Auteur :                 RIQUETI
* Date :                   01/12/2019
*
* But :                    Implémenter les fonctionnalités d'un mutex
*                          Posix
***********************************************************************/
    class Mutex
    {
        // Données
        public:
            class Monitor
            {
                //Données
                public:
                    class TimeoutException
                    {
                        public:
                            // Données
                            int retVal;
                            // Métodes
                            TimeoutException(int rval);
                            void message();
                    };
                protected:
                    Mutex* mutex;
                // Métodes
                protected:
                    Monitor(Mutex& m);
                public:
                    void wait();
                    bool wait(double timeout_ms);
                    void notify();
                    void notifyAll();
            };
            class Lock : public Monitor
            {
                // Métodes
                public:
                    Lock(Mutex& m);
                    Lock(Mutex& m, double timeout_ms);
                    ~Lock();
            };
            class TryLock : public Monitor
            {
                public:
                    // Métodes
                    TryLock(Mutex& m);
                    ~TryLock();
            };
        private:
            pthread_mutex_t posixId;
            pthread_cond_t posixCondId;

        // Méthodes
        public:
            Mutex();
            ~Mutex();
        private:
            void lock();
            bool lock(double timeout_ms);
            bool trylock();
            void unlock();
    };

}

#endif // !OSTempsReel_Mutex_h_INCLUDED
