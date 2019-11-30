/*///////////////////////////////////////////////////////////////////////
|
| Fichier :                TimeSpec.cpp
| Auteur :                 RIQUETI Gabriel Henrique
| Date :                   26/09/2019
| Commentaires :           ENSTA ParisTech ROB305 TD1
| Historique de Révision :
|
*///////////////////////////////////////////////////////////////////////

#include "TimeSpec.h"
#include <time.h>

/*----------------------------------------------------------------------
* Fonction :               timespec_to_ms
* Auteur :                 RIQUETI
* Date :                   26/09/2019
*
* But :                    Convertir de timespec en millisecondes
----------------------------------------------------------------------*/
double timespec_to_ms(const timespec& time_ts)
{
	double time_ms;
	time_ms = double (time_ts.tv_sec * 1e3l) + double(time_ts.tv_nsec) * 1.e-6;
	return time_ms;
}


/*----------------------------------------------------------------------
* Fonction :               timespec_from_ms
* Auteur :                 RIQUETI
* Date :                   26/09/2019
*
* But :                    Convertir des millisecondes en timespec
----------------------------------------------------------------------*/
timespec timespec_from_ms(double time_ms)
{
	timespec time_ts;
	time_ts.tv_sec = time_ms / 1e3l;
	time_ms -= (double)time_ts.tv_sec * 1e3l;
	if (time_ms >= 0)
	{
		time_ts.tv_nsec = long(time_ms * 1e6l);
	}
	else
	{
		time_ts.tv_sec--;
		time_ms += 1e3;
		time_ts.tv_nsec = long(time_ms * 1e6l);
	}
	return time_ts;
}


/*----------------------------------------------------------------------
* Fonction :               timespec_now
* Auteur :                 RIQUETI
* Date :                   26/09/2019
*
* But :                    Obtenir le temps courant
----------------------------------------------------------------------*/
timespec timespec_now()
{
	timespec abstime;
	clock_gettime(CLOCK_REALTIME, &abstime); // man clock_gettime

	return abstime;
}


/*----------------------------------------------------------------------
* Fonction :               timespec_negate
* Auteur :                 RIQUETI
* Date :                   26/09/2019
*
* But :                    Obtenir l'oppos� d'un temps
----------------------------------------------------------------------*/
timespec timespec_negate(const timespec& time_ts)
{
	timespec time_nts;
	if (time_ts.tv_nsec > 0)
	{
		time_nts.tv_nsec = 1e9 - time_ts.tv_nsec;
		time_nts.tv_sec = -time_ts.tv_sec - 1l;
	}
	else
	{
		time_nts.tv_nsec = 0;
		time_nts.tv_sec = -time_ts.tv_sec;
	}
	return time_nts;
}


/*----------------------------------------------------------------------
* Fonction :               timespec_add
* Auteur :                 RIQUETI
* Date :                   26/09/2019
*
* But :                    Ajouter deux timespec
----------------------------------------------------------------------*/
timespec timespec_add(const timespec& time1_ts, const timespec& time2_ts)
{
	timespec time_ts;
	time_ts.tv_sec = time1_ts.tv_sec + time2_ts.tv_sec;
	time_ts.tv_nsec = time1_ts.tv_nsec + time2_ts.tv_nsec;
	if (time_ts.tv_nsec > 999999999l)
	{
		time_ts.tv_nsec -= 1e9l;
		time_ts.tv_sec++;
	}
	else if (time_ts.tv_nsec < 0)
	{
		time_ts.tv_nsec = 1e9l - time_ts.tv_nsec;
		time_ts.tv_sec--;
	}
	return time_ts;
}


/*----------------------------------------------------------------------
* Fonction :               timespec_substract
* Auteur :                 RIQUETI
* Date :                   26/09/2019
*
* But :                    Soustraire un timespec d'autre
----------------------------------------------------------------------*/
timespec timespec_subtract(const timespec& time1_ts, const timespec& time2_ts)
{
	const timespec time2_nts = timespec_negate(time2_ts);
	return timespec_add(time1_ts, time2_nts);;
}


/*----------------------------------------------------------------------
* Fonction :               timespec_wait
* Auteur :                 RIQUETI
* Date :                   26/09/2019
*
* But :                    Endormir la t�che appelante durant le temps sp�cifi�
----------------------------------------------------------------------*/
timespec timespec_wait(const timespec& delay_ts)
{
	timespec remtime;
	int pause;
	remtime = delay_ts;
	do {
		pause = nanosleep(&remtime, &remtime); // man nanosleep
	} while(pause == -1);
	return remtime;
}

/*----------------------------------------------------------------------
* Operator :               -
* Auteur :                 RIQUETI
* Date :                   26/09/2019
*
* But :                    Obtenir l'oppos� d'un temps
----------------------------------------------------------------------*/
timespec operator- (const timespec& time_ts)
{
	return timespec_negate(time_ts);
}


/*----------------------------------------------------------------------
* Operator :               +
* Auteur :                 RIQUETI
* Date :                   26/09/2019
*
* But :                    Ajouter deux timespec
----------------------------------------------------------------------*/
timespec  operator+ (const timespec& time1_ts, const timespec& time2_ts)
{
	return timespec_add(time1_ts, time2_ts);
}


/*----------------------------------------------------------------------
* Operator :               -
* Auteur :                 RIQUETI
* Date :                   26/09/2019
*
* But :                    Soustraire un timespec d'autre
----------------------------------------------------------------------*/
timespec  operator- (const timespec& time1_ts, const timespec& time2_ts)
{
	return timespec_subtract(time1_ts, time2_ts);
}


/*----------------------------------------------------------------------
* Operator :               +=
* Auteur :                 RIQUETI
* Date :                   26/09/2019
*
* But :                    Affecter un timespec avec la somme de celui
*                          avec d'autre
----------------------------------------------------------------------*/
timespec& operator+= (timespec& time_ts, const timespec& delay_ts)
{
	time_ts = timespec_add(time_ts, delay_ts);
	return time_ts;
}


/*----------------------------------------------------------------------
* Operator :               -=
* Auteur :                 RIQUETI
* Date :                   26/09/2019
*
* But :                    Affecter un timespec avec la soustraction
*                          de celui par autre
----------------------------------------------------------------------*/
timespec& operator-= (timespec& time_ts, const timespec& delay_ts)
{
	time_ts = timespec_subtract(time_ts, delay_ts);
	return time_ts;
}


/*----------------------------------------------------------------------
* Operator :               ==
* Auteur :                 RIQUETI
* Date :                   26/09/2019
*
* But :                    Vérifier si deux timespec sont égals
----------------------------------------------------------------------*/
bool operator== (const timespec& time1_ts, const timespec& time2_ts)
{
	if (time1_ts.tv_nsec == time2_ts.tv_nsec && time1_ts.tv_sec == time2_ts.tv_sec)
	{
		return true;
	}
	else
	{
		return false;
	}
}


/*----------------------------------------------------------------------
* Operator :               !=
* Auteur :                 RIQUETI
* Date :                   26/09/2019
*
* But :                    Vérifier si deux timespec sont différents
----------------------------------------------------------------------*/
bool operator!= (const timespec& time1_ts, const timespec& time2_ts)
{
	if (time1_ts.tv_nsec == time2_ts.tv_nsec && time1_ts.tv_sec == time2_ts.tv_sec)
		return false;
	else
		return true;
}


/*----------------------------------------------------------------------
* Operator :               <
* Auteur :                 RIQUETI
* Date :                   26/09/2019
*
* But :                    Vérifier si un timespec est plus petit qu'autre
----------------------------------------------------------------------*/
bool operator< (const timespec& time1_ts, const timespec& time2_ts)
{
	if (time1_ts.tv_sec < time2_ts.tv_sec)
		return true;
	else
		if(time1_ts.tv_sec == time2_ts.tv_sec && time1_ts.tv_nsec < time2_ts.tv_nsec)
			return true;
	return false;
}


/*----------------------------------------------------------------------
* Operator :               >
* Auteur :                 RIQUETI
* Date :                   26/09/2019
*
* But :                    V�rifier si un timespec est plus grand qu'autre
----------------------------------------------------------------------*/
bool operator> (const timespec& time1_ts, const timespec& time2_ts)
{
	if (time1_ts.tv_sec > time2_ts.tv_sec)
		return true;
	else
		if (time1_ts.tv_sec == time2_ts.tv_sec && time1_ts.tv_nsec > time2_ts.tv_nsec)
			return true;
	return false;
}
