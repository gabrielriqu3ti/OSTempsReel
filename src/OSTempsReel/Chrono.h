/*///////////////////////////////////////////////////////////////////////
|
| Fichier :                Chrono.h
| Auteur :                 RIQUETI Gabriel Henrique
| Date :                   08/11/2019
| Commentaires :           ENSTA ParisTech ROB305 TD-3a
| Historique de Révision :
|
*///////////////////////////////////////////////////////////////////////

#pragma once
#ifndef OSTempsReel_Chrono_h_INCLUDED
#define OSTempsReel_Chrono_h_INCLUDED

#include <time.h>

namespace OSTempsReel
{

/***********************************************************************
* Classe :                 Chrono
* Auteur :                 RIQUETI
* Date :                   08/11/2019
*
* But :                    Implémenter les fonctionnalités de mesures de
*                          temps d'un chronomètre
***********************************************************************/
    class Chrono
    {
        // Données
        private:
            timespec startTime_;
            timespec stopTime_;

        // Méthodes
        public:
            Chrono();
            void stop();
            void restart();
            bool isActive();
            double startTime();
            double stopTime();
            double lap();
    };

}

#endif // !OSTempsReel_Chrono_h_INCLUDED
