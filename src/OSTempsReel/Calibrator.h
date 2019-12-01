/*///////////////////////////////////////////////////////////////////////
|
| Fichier :                Calibrator.h
|| Auteur :                RIQUETI Gabriel Henrique
| Date :                   27/10/2019
| Commentaires :           ENSTA ParisTech ROB305 TD-3c
 Historique de Révision :
|
*////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef OSTempsReel_Calibrator_h_INCLUDED
#define OSTempsReel_Calibrator_h_INCLUDED

#include "PeriodicTimer.h"
#include "Looper.h"
#include <time.h>
#include <vector>

namespace OSTempsReel
{

/***********************************************************************
* Classe :                 Calibrator
* Auteur :                 RIQUETI
* Date :                   27/11/2019
*
* But :                    ?
***********************************************************************/
    class Calibrator : public PeriodicTimer
    {
        // Données
        private:
            double a, b;
            std::vector<double> samples;
            Looper cLooper;

        // Méthodes
        public:
            Calibrator(double samplingPeriod_ms, unsigned int nSamples);
            double nLoops(double duration_ms);
        protected:
            void callback();
    };

}

#endif // !OSTempsReel_Calibrator_h_INCLUDED
