/*///////////////////////////////////////////////////////////////////////
|
| Fichier :                ThreadCounter.h
|| Auteur :                RIQUETI Gabriel Henrique
| Date :                   01/12/2019
| Commentaires :           ENSTA ParisTech ROB305 TD-4a
 Historique de Révision :
|
*////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef OSTempsReel_ThreadCounter_h_INCLUDED
#define OSTempsReel_ThreadCounter_h_INCLUDED

#include <pthread.h>
#include "Thread.h"

namespace OSTempsReel
{

/***********************************************************************
* Classe :                 ThreadCounter
* Auteur :                 RIQUETI
* Date :                   01/12/2019
*
* But :                    Implémenter les fonctionnalités d'un thread
*                          comptant
***********************************************************************/
    class ThreadCounter : public Thread
    {
        // Données
        private:
            static unsigned int count;  // déclaration de variable statique
            static unsigned int nLoops; // déclaration de variable statique
        // Méthodes
        public:
            static void setLoops(unsigned int Loops);
            static unsigned int getCount();
        protected:
            void run();
    };

}

#endif // !OSTempsReel_ThreadCounter_h_INCLUDED
