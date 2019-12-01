/*////////////////////////////////////////////////////////////////////////////////
|
| Fichier :                td1a_main.cpp
| Auteur :                 RIQUETI Gabriel Henrique
| Date :                   26/09/2019
| Commentaires :           ENSTA ParisTech ROB305 TD-1a
| Commande :               g++ main_td1a.cpp TimeSpec.cpp -lrt -o ../td1a && ../td1a
| Historique de Révision :
|
*/////////////////////////////////////////////////////////////////////////////////

// archive principal
#include "TimeSpec.h"
#include <time.h>
#include <iostream>
#include <string.h>


using namespace std;

/************************************MAIN**************************************/
int main(int argc, char *argv[])
{

	if (argc < 2)
	{
		cout << "Tapez ../td1a h" << endl;
	}
	else if (argc==2)
	{
		if(string(argv[1]) == "h")
		{
			cout << "Aide de TD1a" << endl;
			cout << "Options :" << endl;
			cout << "	  h        Montrer l'aide" << endl;
			cout << "	  ts2ms    Tester la fonction timespec_to_ms" << endl;
			cout << "	  ms2ts    Tester la fonction timespec_from_ms" << endl;
			cout << "	  now      Tester la fonction timespec_now" << endl;
			cout << "	  neg      Tester la fonction timespec_negate" << endl;
			cout << "	  add      Tester la fonction timespec_add" << endl;
			cout << "	  sub      Tester la fonction timespec_substract" << endl;
			cout << "	  wait     Tester la fonction timespec_wait" << endl;
			cout << "	  opn      Tester l'opérateur - not" << endl;
			cout << "	  op+      Tester l'opérateur +" << endl;
			cout << "	  op-      Tester l'opérateur -" << endl;
			cout << "	  op+=     Tester l'opérateur +=" << endl;
			cout << "	  op-=     Tester l'opérateur -=" << endl;
			cout << "	  op==     Tester l'opérateur ==" << endl;
			cout << "	  op!=     Tester l'opérateur !=" << endl;
			cout << "	  op>      Tester l'opérateur >" << endl;
			cout << "	  op<      Tester l'opérateur <" << endl;
		}
		else if(string(argv[1])=="now")
		{
			timespec time_ts;
			time_ts = timespec_now();
			cout << "Teste de la fonction timespec_now"<< endl;
			cout << "Seconds : " << time_ts.tv_sec << endl;
			cout << "Nanoseconds : " << time_ts.tv_nsec << endl;
		}
		else if(string(argv[1])=="ts2ms" || string(argv[1])=="ms2ts" ||
		string(argv[1])=="neg" || string(argv[1])=="add" || string(argv[1])=="sub"
		|| string(argv[1])=="wait" || string(argv[1])=="opn" || string(argv[1])=="op+"
		|| string(argv[1])=="op-" || string(argv[1])=="op+=" || string(argv[1])=="op-="
		|| string(argv[1])=="op==" || string(argv[1])=="op!=" || string(argv[1])=="op>"
		|| string(argv[1])=="op<")
		{
			cout << "Paramètres insufisants !" << endl;
			cout << "Tapez ../td1a h " << argv[1] << endl;
		}
		else
		{
			cout << "Option pas accepté !" << endl;
		}
	}
	else if (argc==3)
	{
		if(string(argv[1]) == "h")
		{
			if (string(argv[2]) == "h")
			{
				cout << "	  h        Montrer l'aide" << endl;
				cout << "	  s'il a un deuxième paramètre, explique cette fonction" << endl;
			}
			else if (string(argv[2]) == "ts2ms")
			{
				cout << "ts2ms    Tester la fonction timespec_to_ms" << endl;
				cout << "Paramètre 1 : temps en s" << endl;
				cout << "Paramètre 2 : temps en ns" << endl;
			}
			else if (string(argv[2]) == "ms2ts")
			{
				cout << "ms2ts    Tester la fonction timespec_from_ms" << endl;
				cout << "Paramètre 1 : temps en ms" << endl;
			}
			else if (string(argv[2]) == "now")
			{
				cout << "now      Tester la fonction timespec_now" << endl;
			}
			else if (string(argv[2]) == "neg")
			{
				cout << "neg      Tester la fonction timespec_negate" << endl;
				cout << "Paramètre 1 : temps en s" << endl;
				cout << "Paramètre 2 : temps en ns" << endl;
			}
			else if (string(argv[2]) == "add")
			{
				cout << "add      Tester la fonction timespec_add" << endl;
				cout << "Paramètre 1 : temps 1 en s" << endl;
				cout << "Paramètre 2 : temps 1 en ns" << endl;
				cout << "Paramètre 3 : temps 2 en s" << endl;
				cout << "Paramètre 4 : temps 2 en ns" << endl;
			}
			else if (string(argv[2]) == "sub")
			{
				cout << "sub      Tester la fonction timespec_substract" << endl;
				cout << "Paramètre 1 : temps 1 en s" << endl;
				cout << "Paramètre 2 : temps 1 en ns" << endl;
				cout << "Paramètre 3 : temps 2 en s" << endl;
				cout << "Paramètre 4 : temps 2 en ns" << endl;
			}
			else if (string(argv[2]) == "wait")
			{
				cout << "wait     Tester la fonction timespec_wait" << endl;
				cout << "Paramètre 1 : temps en s" << endl;
				cout << "Paramètre 2 : temps en ns" << endl;
			}
			else if (string(argv[2]) == "opn")
			{
				cout << "opn      Tester l'opérateur - not" << endl;
				cout << "Paramètre 1 : temps en s" << endl;
				cout << "Paramètre 2 : temps en ns" << endl;
			}
			else if (string(argv[2]) == "op+")
			{
				cout << "op+      Tester l'opérateur +" << endl;
				cout << "Paramètre 1 : temps 1 en s" << endl;
				cout << "Paramètre 2 : temps 1 en ns" << endl;
				cout << "Paramètre 3 : temps 2 en s" << endl;
				cout << "Paramètre 4 : temps 2 en ns" << endl;
			}
			else if (string(argv[2]) == "op-")
			{
				cout << "op-      Tester l'opérateur -" << endl;
				cout << "Paramètre 1 : temps 1 en s" << endl;
				cout << "Paramètre 2 : temps 1 en ns" << endl;
				cout << "Paramètre 3 : temps 2 en s" << endl;
				cout << "Paramètre 4 : temps 2 en ns" << endl;
			}
			else if (string(argv[2]) == "op+=")
			{
				cout << "op+=     Tester l'opérateur +=" << endl;
				cout << "Paramètre 1 : temps 1 en s" << endl;
				cout << "Paramètre 2 : temps 1 en ns" << endl;
				cout << "Paramètre 3 : temps 2 en s" << endl;
				cout << "Paramètre 4 : temps 2 en ns" << endl;
			}
			else if (string(argv[2]) == "op-=")
			{
				cout << "op-=     Tester l'opérateur -=" << endl;
				cout << "Paramètre 1 : temps 1 en s" << endl;
				cout << "Paramètre 2 : temps 1 en ns" << endl;
				cout << "Paramètre 3 : temps 2 en s" << endl;
				cout << "Paramètre 4 : temps 2 en ns" << endl;
			}
			else if (string(argv[2]) == "op==")
			{
				cout << "op==     Tester l'opérateur ==" << endl;
				cout << "Paramètre 1 : temps 1 en s" << endl;
				cout << "Paramètre 2 : temps 1 en ns" << endl;
				cout << "Paramètre 3 : temps 2 en s" << endl;
				cout << "Paramètre 4 : temps 2 en ns" << endl;
			}
			else if (string(argv[2]) == "op!=")
			{
				cout << "op!=     Tester l'opérateur !=" << endl;
				cout << "Paramètre 1 : temps 1 en s" << endl;
				cout << "Paramètre 2 : temps 1 en ns" << endl;
				cout << "Paramètre 3 : temps 2 en s" << endl;
				cout << "Paramètre 4 : temps 2 en ns" << endl;
			}
			else if (string(argv[2]) == "op>")
			{
				cout << "op>      Tester l'opérateur >" << endl;
				cout << "Paramètre 1 : temps 1 en s" << endl;
				cout << "Paramètre 2 : temps 1 en ns" << endl;
				cout << "Paramètre 3 : temps 2 en s" << endl;
				cout << "Paramètre 4 : temps 2 en ns" << endl;
			}
			else if (string(argv[2]) == "op<")
			{
				cout << "op<      Tester l'opérateur <" << endl;
				cout << "Paramètre 1 : temps 1 en s" << endl;
				cout << "Paramètre 2 : temps 1 en ns" << endl;
				cout << "Paramètre 3 : temps 2 en s" << endl;
				cout << "Paramètre 4 : temps 2 en ns" << endl;
			}
			else
			{
				cout << "Option pas accepté !" << endl;
				cout << "Tapez ../td1a h" << endl;
			}
		}
		else if (string(argv[1]) == "ms2ts")
		{
			cout << "Teste de la fonction timespec_from_ms" << endl;
			timespec time_ts;
			double time_ms;
			time_ms = stod(argv[2]);
			time_ts = timespec_from_ms(time_ms);
			cout << "Seconds : " << time_ts.tv_sec << endl;
			cout << "Nanosseconds : " << time_ts.tv_nsec << endl;
		}
		else if (string(argv[1]) == "now")
		{
			cout << "Trop de paramètres !" << endl;
			cout << "Tapez ../td1a h " << argv[1] << endl;
		}
		else if ((string(argv[1])=="ts2ms" || string(argv[1])=="neg" ||
		string(argv[1])=="add" || string(argv[1])=="sub" || string(argv[1])=="opn"
		|| string(argv[1])=="op+" || string(argv[1])=="op-"
		|| string(argv[1])=="op+=" || string(argv[1])=="op-="
		|| string(argv[1])=="op==" || string(argv[1])=="op!="
		|| string(argv[1])=="op>" || string(argv[1])=="op<"))
		{
			cout << "Paramètres insufisants !" << endl;
			cout << "Tapez ../td1a h" << endl;
		}
		else
		{
			cout << "Option pas accepté !" << endl;
			cout << "Tapez ../td1a h" << endl;
		}
	}
	else if (argc == 4)
	{
		if (string(argv[1])=="ts2ms")
		{
			cout << "Teste de la fonction timespec_to_ms" << endl;
			timespec time_ts;
			time_ts.tv_sec = atoi(argv[2]);
			time_ts.tv_nsec = atoi(argv[3]);
			cout << "Milisseconds : " << timespec_to_ms(time_ts) << endl;
		}
		else if(string(argv[1])=="neg")
		{
			cout << "Teste de la fonction timespec_negate" << endl;
			timespec time_ts;
			time_ts.tv_sec = atoi(argv[2]);
			time_ts.tv_nsec = atoi(argv[3]);
			time_ts = timespec_negate(time_ts);
			cout << "Seconds : " << time_ts.tv_sec << endl;
			cout << "Nanosseconds : " << time_ts.tv_nsec << endl;
		}
		else if(string(argv[1])=="wait")
		{
			cout << "Teste de la fonction timespec_wait" << endl;
			timespec begin_ts, delay_ts, end_ts;
			delay_ts.tv_sec = atoi(argv[2]);
			delay_ts.tv_nsec = atoi(argv[3]);
			cout << "En attendant " << delay_ts.tv_sec << " seconds et ";
			cout << delay_ts.tv_nsec << " nanosseconds..." << endl;
			begin_ts = timespec_now();
			timespec_wait(delay_ts);
			end_ts = timespec_now();
			cout << "Durée du teste de timespec_wait"<< endl;
			cout << "Seconds : " << (end_ts - begin_ts).tv_sec << endl;
			cout << "Nanoseconds : " << (end_ts - begin_ts).tv_nsec << endl;
		}
		else if(string(argv[1])=="opn")
		{
			cout << "Teste de l'operateur -" << endl;
			timespec time_ts;
			time_ts.tv_sec = atoi(argv[2]);
			time_ts.tv_nsec = atoi(argv[3]);
			time_ts = -time_ts;
			cout << "Seconds : " << time_ts.tv_sec << endl;
			cout << "Nanosseconds : " << time_ts.tv_nsec << endl;
		}
		else if(string(argv[1])=="h" || string(argv[1])=="ms2ts" || string(argv[1])=="now")
		{
			cout << "Trop de paramètres !" << endl;
			cout << "Tapez ../td1a h " << argv[1] << endl;
		}
		else if (string(argv[1])=="add" || string(argv[1])=="sub"
		|| string(argv[1])=="op+" || string(argv[1])=="op-"
		|| string(argv[1])=="op+=" || string(argv[1])=="op-="
		|| string(argv[1])=="op==" || string(argv[1])=="op!="
		|| string(argv[1])=="op>" || string(argv[1])=="op<")
		{
			cout << "Paramètres insufisants !" << endl;
			cout << "Tapez ../td1a h" << endl;
		}
		else
		{
			cout << "Option pas accepté !" << endl;
			cout << "Tapez ../td1a h" << endl;
		}
	}
	else if (argc == 6)
	{
		if (string(argv[1])=="add")
		{
			cout << "Teste de la fonction timespec_add" << endl;
			timespec time1_ts, time2_ts;
			time1_ts.tv_sec = atoi(argv[2]);
			time1_ts.tv_nsec = atoi(argv[3]);
			time2_ts.tv_sec = atoi(argv[4]);
			time2_ts.tv_nsec = atoi(argv[5]);
			time1_ts = timespec_add(time1_ts, time2_ts);
			cout << "Seconds : " << time1_ts.tv_sec << endl;
			cout << "Nanosseconds : " << time1_ts.tv_nsec << endl;
		}
		else if (string(argv[1])=="sub")
		{
			cout << "Teste de la fonction timespec_subtract" << endl;
			timespec time1_ts, time2_ts;
			time1_ts.tv_sec = atoi(argv[2]);
			time1_ts.tv_nsec = atoi(argv[3]);
			time2_ts.tv_sec = atoi(argv[4]);
			time2_ts.tv_nsec = atoi(argv[5]);
			time1_ts = timespec_subtract(time1_ts, time2_ts);
			cout << "Seconds : " << time1_ts.tv_sec << endl;
			cout << "Nanosseconds : " << time1_ts.tv_nsec << endl;
		}
		else if (string(argv[1])=="op+")
		{
			cout << "Teste de l'opérateur +" << endl;
			timespec time1_ts, time2_ts;
			time1_ts.tv_sec = atoi(argv[2]);
			time1_ts.tv_nsec = atoi(argv[3]);
			time2_ts.tv_sec = atoi(argv[4]);
			time2_ts.tv_nsec = atoi(argv[5]);
			time1_ts = time1_ts + time2_ts;
			cout << "Seconds : " << time1_ts.tv_sec << endl;
			cout << "Nanosseconds : " << time1_ts.tv_nsec << endl;
		}
		else if (string(argv[1])=="op-")
		{
			cout << "Teste de l'opérateur -" << endl;
			timespec time1_ts, time2_ts;
			time1_ts.tv_sec = atoi(argv[2]);
			time1_ts.tv_nsec = atoi(argv[3]);
			time2_ts.tv_sec = atoi(argv[4]);
			time2_ts.tv_nsec = atoi(argv[5]);
			time1_ts = time1_ts - time2_ts;
			cout << "Seconds : " << time1_ts.tv_sec << endl;
			cout << "Nanosseconds : " << time1_ts.tv_nsec << endl;
		}
		else if (string(argv[1])=="op+=")
		{
			cout << "Teste de l'opérateur +=" << endl;
			timespec time1_ts, time2_ts;
			time1_ts.tv_sec = atoi(argv[2]);
			time1_ts.tv_nsec = atoi(argv[3]);
			time2_ts.tv_sec = atoi(argv[4]);
			time2_ts.tv_nsec = atoi(argv[5]);
			time1_ts += time2_ts;
			cout << "Seconds : " << time1_ts.tv_sec << endl;
			cout << "Nanosseconds : " << time1_ts.tv_nsec << endl;
		}
		else if (string(argv[1])=="op-=")
		{
			cout << "Teste de l'opérateur -=" << endl;
			timespec time1_ts, time2_ts;
			time1_ts.tv_sec = atoi(argv[2]);
			time1_ts.tv_nsec = atoi(argv[3]);
			time2_ts.tv_sec = atoi(argv[4]);
			time2_ts.tv_nsec = atoi(argv[5]);
			time1_ts -= time2_ts;
			cout << "Seconds : " << time1_ts.tv_sec << endl;
			cout << "Nanosseconds : " << time1_ts.tv_nsec << endl;
		}
		else if (string(argv[1])=="op==")
		{
			cout << "Teste de l'opérateur ==" << endl;
			cout << "Égals ?" << endl;
			timespec time1_ts, time2_ts;
			time1_ts.tv_sec = atoi(argv[2]);
			time1_ts.tv_nsec = atoi(argv[3]);
			time2_ts.tv_sec = atoi(argv[4]);
			time2_ts.tv_nsec = atoi(argv[5]);
			if (time1_ts==time2_ts)
				cout << "Vrai" << endl;
			else
				cout << "Faux" << endl;
		}
		else if (string(argv[1])=="op!=")
		{
			cout << "Teste de l'opérateur !=" << endl;
			cout << "Différents ?" << endl;
			timespec time1_ts, time2_ts;
			time1_ts.tv_sec = atoi(argv[2]);
			time1_ts.tv_nsec = atoi(argv[3]);
			time2_ts.tv_sec = atoi(argv[4]);
			time2_ts.tv_nsec = atoi(argv[5]);
			if (time1_ts!=time2_ts)
				cout << "Vrai" << endl;
			else
				cout << "Faux" << endl;
		}
		else if (string(argv[1])=="op>")
		{
			cout << "Teste de l'opérateur >" << endl;
			cout << "Plus grand ?" << endl;
			timespec time1_ts, time2_ts;
			time1_ts.tv_sec = atoi(argv[2]);
			time1_ts.tv_nsec = atoi(argv[3]);
			time2_ts.tv_sec = atoi(argv[4]);
			time2_ts.tv_nsec = atoi(argv[5]);
			if (time1_ts>time2_ts)
				cout << "Vrai" << endl;
			else
				cout << "Faux" << endl;
		}
		else if (string(argv[1])=="op<")
		{
			cout << "Teste de l'opérateur <" << endl;
			cout << "Plus petit ?" << endl;
			timespec time1_ts, time2_ts;
			time1_ts.tv_sec = atoi(argv[2]);
			time1_ts.tv_nsec = atoi(argv[3]);
			time2_ts.tv_sec = atoi(argv[4]);
			time2_ts.tv_nsec = atoi(argv[5]);
			if (time1_ts<time2_ts)
				cout << "Vrai" << endl;
			else
				cout << "Faux" << endl;
		}
		else if(string(argv[1])=="h" || string(argv[1])=="ts2ms" || string(argv[1])=="ms2ts"
		|| string(argv[1])=="wait" || string(argv[1])=="opn" || string(argv[1])=="neg"
		|| string(argv[1])=="now")
		{
			cout << "Trop de paramètres !" << endl;
			cout << "Tapez ../td1a h " << argv[1] << endl;
		}
		else
		{
			cout << "Option pas accepté !" << endl;
			cout << "Tapez ../td1a h" << endl;
		}
	}
	else
	{
		cout << "Option pas accepté !" << endl;
		cout << "Tapez ../td1a h" << endl;
	}

	return 0;
}
