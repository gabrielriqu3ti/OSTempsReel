/*///////////////////////////////////////////////////////////////////////
|
| Fichier :                Chrono.cpp
| Auteur :                 RIQUETI Gabriel Henrique
| Date :                   08/11/2019
| Commentaires :           ENSTA ParisTech ROB305 TD-3a
| Historique de Révision :
|
*///////////////////////////////////////////////////////////////////////

#include "Chrono.h"
#include "../TimeSpec.h"
#include <time.h>

using namespace OSTempsReel;

/*----------------------------------------------------------------------
* Fonction :               Chrono
* Auteur :                 RIQUETI
* Date :                   08/11/2019
*
* But :                    Constructeur de la classe Chrono
----------------------------------------------------------------------*/
Chrono::Chrono()
{
	clock_gettime(CLOCK_REALTIME, &startTime_);
    stopTime_ = timespec_from_ms(0.0);
}

/*----------------------------------------------------------------------
* Fonction :               stop
* Auteur :                 RIQUETI
* Date :                   08/11/2019
*
* But :                    Fixer la valeur de stopTime au temps courant
----------------------------------------------------------------------*/
void Chrono::stop()
{
	clock_gettime(CLOCK_REALTIME, &stopTime_);
}

/*----------------------------------------------------------------------
* Fonction :               restart
* Auteur :                 RIQUETI
* Date :                   08/11/2019
*
* But :                    Reinitializer la valeur de startTime au temps
*                          courant
----------------------------------------------------------------------*/
void Chrono::restart()
{
	clock_gettime(CLOCK_REALTIME, &startTime_);
    stopTime_ = timespec_from_ms(0.0);
}

/*----------------------------------------------------------------------
* Fonction :               isActive
* Auteur :                 RIQUETI
* Date :                   08/11/2019
*
* But :                    false
----------------------------------------------------------------------*/
bool Chrono::isActive()
{
    if(stopTime_==timespec_from_ms(0.0))
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*----------------------------------------------------------------------
* Fonction :               startTime
* Auteur :                 RIQUETI
* Date :                   08/11/2019
*
* But :                    Retourner la valeur de startTime en ms
----------------------------------------------------------------------*/
double Chrono::startTime()
{
	return timespec_to_ms(startTime_);
}

/*----------------------------------------------------------------------
* Fonction :               stopTime
* Auteur :                 RIQUETI
* Date :                   08/11/2019
*
* But :                    Retourner la valeur de stopTime en ms
----------------------------------------------------------------------*/
double Chrono::stopTime()
{
	return timespec_to_ms(stopTime_);
}

/*----------------------------------------------------------------------
* Fonction :               lap
* Auteur :                 RIQUETI
* Date :                   08/11/2019
*
* But :                    stopTime - startTime en ms
----------------------------------------------------------------------*/
double Chrono::lap()
{
    if(Chrono::isActive())
    {
        timespec abstime;
        clock_gettime(CLOCK_REALTIME, &abstime);
        return timespec_to_ms(abstime-startTime_);
    }
    else
    {
        return timespec_to_ms(stopTime_-startTime_);
    }
}
