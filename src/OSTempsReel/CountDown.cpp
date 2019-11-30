/*///////////////////////////////////////////////////////////////////////
|
| Fichier :                CountDown.cpp
| Auteur :                 RIQUETI Gabriel Henrique
| Date :                   26/11/2019
| Commentaires :           ENSTA ParisTech ROB305 TD-3b
| Historique de R�vision :
|
*///////////////////////////////////////////////////////////////////////

#include "Timer.h"
#include "PeriodicTimer.h"
#include "CountDown.h"
#include <time.h>
#include <signal.h>
#include <iostream>

using namespace OSTempsReel;

/*----------------------------------------------------------------------
* Fonction :               CountDown
* Auteur :                 RIQUETI
* Date :                   26/11/2019
*
* But :                    Constructeur de la classe
----------------------------------------------------------------------*/
CountDown::CountDown(int n)
{
    count = n;
    std::cout << "Compte à rebours" << std::endl;
    std::cout << count << std::endl;
}

/*----------------------------------------------------------------------
* Fonction :               callback
* Auteur :                 RIQUETI
* Date :                   26/11/2019
*
* But :                    callback
----------------------------------------------------------------------*/
void CountDown::callback()
{
    if (count > 0)
        count--;
    else
        stop();
    std::cout << count << std::endl;
}
