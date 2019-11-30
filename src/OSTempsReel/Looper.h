/*///////////////////////////////////////////////////////////////////////
|
| Fichier :                Looper.h
|| Auteur :                RIQUETI Gabriel Henrique
| Date :                   27/10/2019
| Commentaires :           ENSTA ParisTech ROB305 TD-3c
 Historique de Révision :
|
*////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef OSTempsReel_Looper_h_INCLUDED
#define OSTempsReel_Looper_h_INCLUDED

#include <cfloat>

namespace OSTempsReel
{

/***********************************************************************
* Classe :                 Looper
* Auteur :                 RIQUETI
* Date :                   27/11/2019
*
* But :                    Implémenter les fonctionnalités d'un timer
*                          Posix
***********************************************************************/
    class Looper
    {
        // Données
        private:
            bool doStop;
            double iLoop;

        // Méthodes
        public:
            double runLoop(double nLoops = DBL_MAX);
            double getSample();
            double stopLoop();
    };

}

#endif // !OSTempsReel_Looper_h_INCLUDED
