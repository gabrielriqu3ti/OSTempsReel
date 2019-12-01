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
#include <errno.h>
#include <iostream>
//#include <exception>

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
            class Exception
            {
                public:

                    int retVal;
                    Exception(int rval)
                    {
                        retVal = rval;
                    };
                    void message()
                    {
                        switch(retVal)
                        {
                            case(EAGAIN):
                            std::cout << "Erreur " << retVal << " : Ressources unsifisants pour créer un thread !" << std::endl;
                            break;
                            case(ESRCH):
                            std::cout << "Erreur " << retVal << " : Aucun thread avec l'ID spécifié était trouvé !" << std::endl;
                            break;
                            case(EINVAL):
                            std::cout << "Erreur " << retVal << " : Paramètres invalides dans attr" << std::endl;
                            break;
                            case(EPERM):
                            std::cout << "Erreur " << retVal << " : Aucune autorisation pour établir un scheduling policy";
                            std::cout << " et paramètres spécifiés dans attr" << std::endl;
                            break;
                            case(ENOMEM):
                            std::cout << "Erreur " << retVal << " : pthread_attr_init ou pthread_attr_destroy a échoué" << std::endl;
                            break;
                        }
                    };
            };
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
//            void start(void* (*) (void*) threadFunc, void* threadArg);
            void start(void* threadFunc, void* threadArg);
            void join();
            bool join(double timeout_ms);
            bool setScheduling(int schedPolicy, int priority);
            bool getScheduling(int* p_schedPolity = nullptr, int* p_priority = nullptr);
    };

}

#endif // !OSTempsReel_PosixThread_h_INCLUDED
