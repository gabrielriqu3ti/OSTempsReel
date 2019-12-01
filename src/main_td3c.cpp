/*////////////////////////////////////////////////////////////////////////////////
|
| Fichier :                td3c_main.cpp
| Auteur :                 RIQUETI Gabriel Henrique
| Date :                   27/11/2019
| Commentaires :           ENSTA ParisTech ROB305 TD3c
| Commande :               g++ main_td3c.cpp TimeSpec.cpp OSTempsReel/Timer.cpp
|                          OSTempsReel/PeriodicTimer.cpp OSTempsReel/Looper.cpp
|                          OSTempsReel/Calibrator.cpp OSTempsReel/CpuLoop.cpp
|                          -lrt -lpthread -o ../td3c && sudo ../td3c
| Historique de Révision :
|
*/////////////////////////////////////////////////////////////////////////////////

// archive principal
#include "TimeSpec.h"
#include "OSTempsReel/Looper.h"
#include "OSTempsReel/PeriodicTimer.h"
#include "OSTempsReel/Calibrator.h"
#include "OSTempsReel/CpuLoop.h"
#include <time.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
//	if (argc==1)
//	{
	double samplingPeriod_ms = 500.0;
	unsigned int nSamples = 10;

	cout << "TD-3c" << endl;

	OSTempsReel::Calibrator calibrator = OSTempsReel::Calibrator(samplingPeriod_ms, nSamples);
	vector<OSTempsReel::CpuLoop> vCpuLoop;

//	for (unsigned int i; i<nSamples; i++)
//	{
//		vCpuLoop.push_back(OSTempsReel::CpuLoop(calibrator));
//	}

//		timespec_wait(timespec_from_ms(3000));
//	}
//	else if (argc==2)
//	{
//		OSTempsReel::CountDown coutDown = OSTempsReel::CountDown::CountDown((void*) (argv+1));
//	}
//	OSTempsReel::Looper looper;
//	cout << "Durée : " << looper.runLoop(10000.0) << endl;

	return 0;
}
