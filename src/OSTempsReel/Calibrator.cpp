/*///////////////////////////////////////////////////////////////////////
|
| Fichier :                Calibrator.cpp
| Auteur :                 RIQUETI Gabriel Henrique
| Date :                   27/10/2019
| Commentaires :           ENSTA ParisTech ROB305 TD-3c
| Historique de Révision :
|
*///////////////////////////////////////////////////////////////////////

#include "Calibrator.h"
#include <vector>
#include <iostream>
#include <cmath>

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
    double error = 0;
    double sumDurCount, sumDur2, avgCount, avgDur;
    double sumDurcount = sumDur2 = avgCount = avgDur = 0;
    a = b = 0;

    for(int i=0;i<nSamples;++i)
    {
        samples.push_back(samplingPeriod_ms*(i+1));
    }

    start(samplingPeriod_ms);

/*
    for(int i=0;i<nSamples;++i)
    {
        avgCount += i+1;
        avgDur += samples[i];
        sumDurCount += (i+1)*samples[i];
        sumDur2 += samples[i]*samples[i];
    }

    avgCount = avgCount/nSamples;
    avgDur = avgDur/nSamples;

    a = (sumDurCount - nSamples*avgDur*avgCount)/(sumDur2 - nSamples*avgDur*avgDur);
    b = avgCount - a*avgDur;

    for(int i=0;i<nSamples;++i)
    {
        error += (samples[i]*a + b - (i+1))*(samples[i]*a + b - (i+1));
    }
    error = sqrt(error/nSamples);
*/

    std::cout << "a = " << a << " counters/ms" << std::endl;
    std::cout << "b = " << b << " counters" << std::endl;
    std::cout << "Erreur = " << error << " counters" << std::endl;


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
* But :                    Callback
----------------------------------------------------------------------*/
void Calibrator::callback()
{
    std::cout << "Calibrator::callback" << std::endl;
    cLooper.stopLoop();
    cLooper.getSample();
}
