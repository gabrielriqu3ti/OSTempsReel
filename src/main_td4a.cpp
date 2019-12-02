/*////////////////////////////////////////////////////////////////////////////////
|
| Fichier :                td4a_main.cpp
| Auteur :                 RIQUETI Gabriel Henrique
| Date :                   27/11/2019
| Commentaires :           ENSTA ParisTech ROB305 TD4a
| Commande :               g++ td4a_main.cpp TimeSpec.cpp OSTempsReel/PosixThread.cpp
|                          OSTempsReel/Thread.cpp OSTempsReel/Chrono.cpp
|                          OSTempsReel/ThreadCounter.cpp -lrt -lpthread -o ../td4a
|                          && sudo ../td4a
| Historique de Révision :
|
*/////////////////////////////////////////////////////////////////////////////////

// archive principal
#include "TimeSpec.h"
#include "OSTempsReel/PosixThread.h"
#include "OSTempsReel/Thread.h"
#include "OSTempsReel/ThreadCounter.h"
#include <pthread.h>
#include <time.h>
#include <iostream>

// unsigned définiton de variables statiques
unsigned int OSTempsReel::ThreadCounter::count = 0;
unsigned int OSTempsReel::ThreadCounter::nLoops = 0;

using namespace std;

int main(int argc, char *argv[])
{
	if (argc==1 || argc==2)
    {
        cout << "Tapez le taile de la boucle et le nombre des tâches" << endl;
    }
    else if (argc==3)
    {
		unsigned int nLoops = atoi(argv[1]);
		unsigned int nTasks = atoi(argv[2]);
		double delay_ms = 500.0;

		cout << "Taille de boucles : " << nLoops << endl;
        cout << "Nombre de tâches  : " << nTasks << endl;

		OSTempsReel::ThreadCounter thread[nTasks];
		OSTempsReel::ThreadCounter::setLoops(nLoops);

		for(unsigned int i=0; i<nTasks; i++)
		{
			try
			{
				thread[i].start();
			}
			catch(OSTempsReel::PosixThread::Exception exc)
			{
				std::cout << "OSTempsReel::Thread::start" << std::endl;
				exc.message();
			}
		}

		try
		{
			OSTempsReel::Thread::sleep_ms(delay_ms/5);
		}
		catch(OSTempsReel::PosixThread::Exception exc)
		{
			std::cout << "OSTempsReel::Thread::sleep_ms" << std::endl;
			exc.message();
		}

		for(unsigned int i=0; i<nTasks/2; i++)
		{
			try
			{
				thread[i].join();
			}
			catch(OSTempsReel::PosixThread::Exception exc)
			{
				std::cout << "OSTempsReel::Thread::join" << std::endl;
				exc.message();
			}
		}

		for(unsigned int i=nTasks/2; i<nTasks; i++)
		{
			try
			{
				thread[i].join(delay_ms);
			}
			catch(OSTempsReel::PosixThread::Exception exc)
			{
				std::cout << "OSTempsReel::Thread::join" << std::endl;
				exc.message();
			}
		}

		for(unsigned int i=0; i<nTasks; i++)
		{
			try
			{
//				cout << "Début [" << i << "]: " << thread[i].startTime_ms() << " ms" << endl;
//				cout << "Fin   [" << i << "]: " << thread[i].stopTime_ms() << " ms" << endl;
				cout << "Durée [" << i << "]: " << thread[i].execTime_ms() << " ms" << endl;
			}
			catch(OSTempsReel::PosixThread::Exception exc)
			{
				std::cout << "OSTempsReel::Thread::startTime_ms, stopTime_ms et execTime_ms" << std::endl;
				exc.message();
			}
		}


		try
		{
			cout << "Compteur : " << OSTempsReel::ThreadCounter::getCount() << endl;
		}
		catch(OSTempsReel::PosixThread::Exception exc)
		{
			std::cout << "OSTempsReel::Thread::getCount" << std::endl;
			exc.message();
		}

	}
	return 0;
}
