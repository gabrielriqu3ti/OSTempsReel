/*////////////////////////////////////////////////////////////////////////////////
|
| Fichier :                td3c_main.cpp
| Auteur :                 RIQUETI Gabriel Henrique
| Date :                   27/10/2019
| Commentaires :           ENSTA ParisTech ROB307 TD1a
| Commande :               g++ td3c_main.cpp TimeSpec.cpp OSTempsReel/Timer.cpp
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
		cout << "TD-3c" << endl;

		OSTempsReel::Calibrator calibrator = OSTempsReel::Calibrator(200.0,10);
		calibrator.start(1000.0);

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
