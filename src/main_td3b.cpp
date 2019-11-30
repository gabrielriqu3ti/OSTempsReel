/*////////////////////////////////////////////////////////////////////////////////
|
| Fichier :                td1a_main.cpp
| Auteur :                 RIQUETI Gabriel Henrique
| Date :                   18/10/2019
| Commentaires :           ENSTA ParisTech ROB307 TD1a
| Commande :               g++ td3b_main.cpp TimeSpec.cpp OSTempsReel/Timer.cpp
|                          OSTempsReel/PeriodicTimer.cpp OSTempsReel/CountDown.cpp
|                          -lrt -lpthread -o ../td3b && sudo ../td3b
| Historique de Révision :
|
*/////////////////////////////////////////////////////////////////////////////////

// archive principal
#include "TimeSpec.h"
#include "OSTempsReel/CountDown.h"
#include <time.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{

	if (argc==1)
	{
		cout << "Tapez le numéro à démarrer le compte à rebours !" << endl;
	}
	else if (argc==2)
	{
		int n = atoi(argv[1]);
		double period_ms = 1000.0;
		double delay_ms = n*period_ms;
		timespec begin, end;

		OSTempsReel::CountDown countDown = OSTempsReel::CountDown(n);

		clock_gettime(CLOCK_REALTIME, &begin);

		countDown.start(period_ms);

		timespec_wait(timespec_from_ms(delay_ms));

		clock_gettime(CLOCK_REALTIME, &end);

		cout << "Durée : " << timespec_to_ms(end-begin) << " ms" << endl;

	}

	return 0;
}
