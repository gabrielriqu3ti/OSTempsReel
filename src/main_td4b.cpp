/*////////////////////////////////////////////////////////////////////////////////
|
| Fichier :                td4b_main.cpp
| Auteur :                 RIQUETI Gabriel Henrique
| Date :                   31/11/2019
| Commentaires :           ENSTA ParisTech ROB305 TD4a
| Commande :               g++ td4b_main.cpp TimeSpec.cpp OSTempsReel/PosixThread.cpp
|                          OSTempsReel/Thread.cpp OSTempsReel/Chrono.cpp
|                          OSTempsReel/ThreadCounterSafe.cpp OSTempsReel/Mutex.cpp
|                          -lrt -lpthread -o ../td4b && sudo ../td4b
| Historique de Révision :
|
*/////////////////////////////////////////////////////////////////////////////////

// archive principal
#include "TimeSpec.h"
#include "OSTempsReel/PosixThread.h"
#include "OSTempsReel/Thread.h"
#include "OSTempsReel/ThreadCounterSafe.h"
#include "OSTempsReel/Mutex.h"
#include <pthread.h>
#include <time.h>
#include <string.h>
#include <iostream>

// unsigned définiton de variables statiques
unsigned int OSTempsReel::ThreadCounterSafe::count = 0;
unsigned int OSTempsReel::ThreadCounterSafe::nLoops = 0;
unsigned int OSTempsReel::ThreadCounterSafe::nTasks = 0;
unsigned int OSTempsReel::ThreadCounterSafe::activeTask = 0;
double OSTempsReel::ThreadCounterSafe::timeoutMs = 0.0;

using namespace std;

int main(int argc, char *argv[])
{
	if (argc==1 || argc==2 || argc==3)
    {
		cout << "Tapez le taile de la boucle et le nombre des tâches et l'ordonnance de tâches (SCHED_RR, SCHED_FIFO ou SCHED_OTHER)" << endl;
		cout << "Observation : vous pouvez déterminer le temps d'attente des tâches en écrivant un quatrième argument" << endl;
    }
    else if (argc==4 || argc == 5)
    {
		unsigned int nLoops = atoi(argv[1]);
		unsigned int nTasks = atoi(argv[2]);
		int schedPolicy;
		double delay_ms = 500.0;

		if(argc==5)
		{
				delay_ms = atoi(argv[4]);
		}

		if (string(argv[3]) == "SCHED_RR" || atoi(argv[3]) == SCHED_RR)
		{
			schedPolicy = SCHED_RR;
		}
		else if(string(argv[3]) == "SCHED_FIFO" || atoi(argv[3]) == SCHED_FIFO)
		{
			schedPolicy = SCHED_FIFO;
		}
		else if(string(argv[3]) == "SCHED_OTHER" || atoi(argv[3]) == SCHED_OTHER)
		{
			schedPolicy = SCHED_OTHER;
		}
		else
		{
			cout << "Le troisième paramètre doit être SCHED_RR, SCHED_FIFO ou SCHED_OTHER" << endl;
			return 0;
		}

		cout << "Taille de boucles : " << nLoops << endl;
        cout << "Nombre de tâches  : " << nTasks << endl;
		cout << "Ordonnance : ";
        if(schedPolicy==SCHED_RR)
        {
            cout << "SCHED_RR" << endl;
        }
        else if(schedPolicy==SCHED_FIFO)
        {
            cout << "SCHED_FIFO" << endl;
        }
        else if(schedPolicy==SCHED_OTHER)
        {
            cout << "SCHED_OTHER" << endl;
        }


		OSTempsReel::Mutex mutex = OSTempsReel::Mutex();
		OSTempsReel::ThreadCounterSafe thread[nTasks];
		for(unsigned int i=0; i<nTasks; i++)
		{
			try
			{
				thread[i] = OSTempsReel::ThreadCounterSafe(mutex);
			}
			catch(OSTempsReel::PosixThread::Exception exc)
			{
				std::cout << "OSTempsReel::ThreadCounterSafe" << std::endl;
				exc.message();
			}

			try
			{
				if(schedPolicy == SCHED_OTHER) thread[i].setScheduling(schedPolicy, 0);
				else thread[i].setScheduling(schedPolicy, i);
			}
			catch(OSTempsReel::PosixThread::Exception exc)
			{
				std::cout << "OSTempsReel::Thread::setSheduling" << std::endl;
				exc.message();
			}
		}

		OSTempsReel::ThreadCounterSafe::setLoops(nLoops);
		OSTempsReel::ThreadCounterSafe::setTimeout(delay_ms);

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

		for(unsigned int i=0; i<nTasks; i++)
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
			cout << "Compteur : " << OSTempsReel::ThreadCounterSafe::getCount() << endl;
		}
		catch(OSTempsReel::PosixThread::Exception exc)
		{
			std::cout << "OSTempsReel::Thread::getCount" << std::endl;
			exc.message();
		}

	}
	return 0;
}
