/*///////////////////////////////////////////////////////////////////////
|
| Fichier :                Calibrator.cpp
| Auteur :                 RIQUETI Gabriel Henrique
| Date :                   27/10/2019
| Commentaires :           ENSTA ParisTech ROB305 TD-3c
| Historique de R�vision :
|
*///////////////////////////////////////////////////////////////////////

#include "Calibrator.h"
#include <vector>
#include <iostream>

using namespace OSTempsReel;

/*----------------------------------------------------------------------
* Fonction :               Calibrator
* Auteur :                 RIQUETI
* Date :                   27/11/2019
*
* But :                    Construteur de la classe
----------------------------------------------------------------------*/
Calibrator::Calibrator(double samplingPeriod_ms, unsigned int nSamples)
{
    a = b = 0;
    Looper looper;

    for(unsigned int iSample = 0; iSample<nSamples; iSample++)
    {
        looper.runLoop(samplingPeriod_ms*(iSample+1));
    }


}

/*----------------------------------------------------------------------
* Fonction :               nLoops
* Auteur :                 RIQUETI
* Date :                   27/11/2019
*
* But :                    Convertir un duration à un nombre de boucles
----------------------------------------------------------------------*/
double Calibrator::nLoops(double duration_ms)
{
    return a*duration_ms + b;
}

/*----------------------------------------------------------------------
* Fonction :               callback
* Auteur :                 RIQUETI
* Date :                   27/11/2019
*
* But :                    callback
----------------------------------------------------------------------*/
void Calibrator::callback()
{
    std::cout << "Calibrator::callback" << std::endl;
    samples.push_back(0.0);

}
