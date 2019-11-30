/*///////////////////////////////////////////////////////////////////////
|
| Fichier :                TimeSpec.h
| Auteur :                 RIQUETI Gabriel Henrique
| Date :                   26/09/2019
| Commentaires :           ENSTA ParisTech ROB305 TD1
| Historique de Révision :
|
*////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef TimeSpec_h_INCLUDED
#define TimeSpec_h_INCLUDED

#include <time.h>

double timespec_to_ms(const timespec& time_ts);

timespec timespec_from_ms(double time_ms);

timespec timespec_now();

timespec timespec_negate(const timespec& time_ts);

timespec timespec_add(const timespec& time1_ts, const timespec& time2_ts);

timespec timespec_subtract(const timespec& time1_ts, const timespec& time2_ts);

timespec timespec_wait(const timespec& delay_ts);

timespec  operator- (const timespec& time_ts);

timespec  operator+ (const timespec& time1_ts, const timespec& time2_ts);

timespec  operator- (const timespec& time1_ts, const timespec& time2_ts);

timespec& operator+= (timespec& time_ts, const timespec& delay_ts);

timespec& operator-= (timespec& time_ts, const timespec& delay_ts);

bool operator== (const timespec& time1_ts, const timespec& time2_ts);

bool operator!= (const timespec& time1_ts, const timespec& time2_ts);

bool operator< (const timespec& time1_ts, const timespec& time2_ts);

bool operator> (const timespec& time1_ts, const timespec& time2_ts);

#endif // !TimeSpec_h_INCLUDED
