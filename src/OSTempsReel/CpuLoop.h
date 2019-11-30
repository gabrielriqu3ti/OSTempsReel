/*///////////////////////////////////////////////////////////////////////
|
| Fichier :                CpuLoop.h
|| Auteur :                RIQUETI Gabriel Henrique
| Date :                   27/10/2019
| Commentaires :           ENSTA ParisTech ROB305 TD-3c
 Historique de Révision :
|
*////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef OSTempsReel_CpuLoop_h_INCLUDED
#define OSTempsReel_CpuLoop_h_INCLUDED

#include <time.h>
#include "Looper.h"
#include "Calibrator.h"

namespace OSTempsReel
{

/***********************************************************************
* Classe :                 CpuLoop
* Auteur :                 RIQUETI
* Date :                   27/11/2019
*
* But :                    ?
***********************************************************************/
    class CpuLoop : public Looper
    {
        // Méthodes
        public:
            CpuLoop(Calibrator& calibrator);
            void runTime(double duration_ms);
    };

}

#endif // !OSTempsReel_CpuLoop_h_INCLUDED
