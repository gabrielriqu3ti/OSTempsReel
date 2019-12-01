/*///////////////////////////////////////////////////////////////////////
|
| Fichier :                CpuLoop.cpp
| Auteur :                 RIQUETI Gabriel Henrique
| Date :                   27/10/2019
| Commentaires :           ENSTA ParisTech ROB305 TD-3c
| Historique de Révision :
|
*///////////////////////////////////////////////////////////////////////

#include "Calibrator.h"
#include "CpuLoop.h"

using namespace OSTempsReel;

/*----------------------------------------------------------------------
* Fonction :               CpuLoop
* Auteur :                 RIQUETI
* Date :                   27/11/2019
*
* But :                    Construteur de la classe
----------------------------------------------------------------------*/
CpuLoop::CpuLoop(Calibrator& calibrator)
{
    paCalibrator = &calibrator;
//    paCalibrator->nLoops(10.0);
}

/*----------------------------------------------------------------------
* Fonction :               runTime
* Auteur :                 RIQUETI
* Date :                   27/11/2019
*
* But :                    ?
----------------------------------------------------------------------*/
void CpuLoop::runTime(double duration_ms)
{
    runLoop();
}
