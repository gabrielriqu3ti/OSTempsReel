# ROB305 Travaux Dirigés de 1 à 5

ENSTA Paris

ROB305 - Programmation multitâches et OS temps réel

Auteur : Gabriel Henrique RIQUETI

Orientateur : Anvar SHEBLI

Le 2 décembre de 2019

Ce projet est l'ensemble des archives sources en C++ pour exécuter les TDs de ROB305 - Programmation multitâches et OS temps réel. Pour lire la propose de chaque code source, accéder le site suivant [Programmation multitâches & OS temps réel](http://irfu.cea.fr/Pisp/shebli.anvar/prog-mt-rtos/index.html)

## Conténu

Dédans le dossier [src]() de ce projet, on peut trouver les codes sources développés.

Les fichiers de classes crées sont dans le dossier [OSTempsReel]().

## [TD 1] - Mesure de temps et échantillonnage en temps

### a) Gestion simplifiée du temps Posix

#### Compilation

```bash
g++ main_td1a.cpp TimeSpec.cpp -lrt -o ../td1a
```

#### Exécution

```bash
../td1a [OPTIONS]
```

### b) Timers avec callback

#### Compilation

```bash
g++ main_td1b.cpp TimeSpec.cpp -lrt -o ../td1b
```

#### Exécution

```bash
../td1b
```

### c) Fonction simple consommant du CPU

#### Compilation

```bash
g++ main_td1c.cpp TimeSpec.cpp -lrt -o ../td1c
```

#### Exécution

```bash
../td1c [TAILLE_DE_LA_BOUCLE]
```

### d) Mesure du temps d'exécution d'une fonction

#### Compilation

```bash
g++ main_td1d.cpp TimeSpec.cpp -lrt -o ../td1d
```

#### Exécution

```bash
../td1d
```

### e) Amélioration des mesures

#### Compilation

```bash
g++ main_td1e.cpp TimeSpec.cpp -lrt -lpthread -o ../td1e
```

#### Exécution

```bash
sudo ../td1e
```

## [TD-2] - Familiarisation avec l'API multitâches pthread

### a) Exécution sur plusieurs tâches sans mutex

#### Compilation

```bash
g++ main_td2a.cpp TimeSpec.cpp -lrt -lpthread -o ../td2a
```

#### Exécution

```bash
sudo ../td2a [TAILLE_DE_LA_BOUCLE] [NOMBRE_DE_TACHES]
```

TAILLE_DE_LA_BOUCLE : entier.

NOMBRE_DE_TACHES : entier.

### b) Mesure de temps d'exécution

#### Compilation

```bash
g++ main_td2b.cpp TimeSpec.cpp -lrt -lpthread -o ../td2b
```

#### Exécution

```bash
sudo ../td2b [TAILLE_DE_LA_BOUCLE] [NOMBRE_DE_TACHES] [ORDENANCE]
```
TAILLE_DE_LA_BOUCLE : entier.

NOMBRE_DE_TACHES : entier.

ORDENANCE :
- SCHED_RR
- SCHED_FIFO
- SCHED_OTHER


### c) Exécution sur plusieurs tâches avec mutex

#### Compilation

```bash
g++ main_td2c.cpp TimeSpec.cpp -lrt -lpthread -o ../td2c
```

#### Exécution

```bash
sudo ../td2c [TAILLE_DE_LA_BOUCLE] [NOMBRE_DE_TACHES] [ORDENANCE] [MUTEX]
```

TAILLE_DE_LA_BOUCLE : entier.

NOMBRE_DE_TACHES : entier.

ORDENANCE :
- SCHED_RR
- SCHED_FIFO
- SCHED_OTHER

MUTEX (optionel) :
- PTHREAD_MUTEX_DEFAULT
- PTHREAD_MUTEX_NORMAL
- PTHREAD_MUTEX_ERRORCHECK
- PTHREAD_MUTEX_RECURSIVE

## [TD-3] - Classes pour la gestion du temps

### a) Classe Chrono

#### Compilation

```bash
g++ main_td3a.cpp TimeSpec.cpp OSTempsReel/Chrono.cpp -lrt -o ../td3a
```

#### Exécution

```bash
../td3a
```

### b) Classe Timer

#### Compilation

```bash
g++ main_td3b.cpp TimeSpec.cpp OSTempsReel/Timer.cpp OSTempsReel/PeriodicTimer.cpp OSTempsReel/CountDown.cpp -lrt -lpthread -o ../td3b
```

#### Exécution

```bash
sudo ../td3b
```

### c) Calibration en temps d'une boucle

#### Compilation

```bash
g++ main_td3c.cpp TimeSpec.cpp OSTempsReel/Timer.cpp OSTempsReel/PeriodicTimer.cpp OSTempsReel/Looper.cpp OSTempsReel/Calibrator.cpp OSTempsReel/CpuLoop.cpp -lrt -lpthread -o ../td3c
```

#### Exécution

```bash
sudo ../td3c
```

## [TD-4] - Classes de base pour la programmation multitâches

### a) Classe Thread ?

#### Compilation

```bash
g++ main_td3a.cpp TimeSpec.cpp OSTempsReel/Chrono.cpp -lrt -o ../td3a
```

#### Exécution

```bash
../td3a
```

### b) Classe Mutex et Mutex::Lock ?

#### Compilation

```bash
g++ main_td3b.cpp TimeSpec.cpp OSTempsReel/Timer.cpp OSTempsReel/PeriodicTimer.cpp OSTempsReel/CountDown.cpp -lrt -lpthread -o ../td3b
```

#### Exécution

```bash
sudo ../td3b
```

### c) Classe Semaphore ?

#### Compilation

```bash
g++ main_td3c.cpp TimeSpec.cpp OSTempsReel/Timer.cpp OSTempsReel/PeriodicTimer.cpp OSTempsReel/Looper.cpp OSTempsReel/Calibrator.cpp OSTempsReel/CpuLoop.cpp -lrt -lpthread -o ../td3c
```

#### Exécution

```bash
sudo ../td3c
```

### d) Classe Fifo multitâches ?

#### Compilation

```bash
g++ main_td3c.cpp TimeSpec.cpp OSTempsReel/Timer.cpp OSTempsReel/PeriodicTimer.cpp OSTempsReel/Looper.cpp OSTempsReel/Calibrator.cpp OSTempsReel/CpuLoop.cpp -lrt -lpthread -o ../td3c
```

#### Exécution

```bash
sudo ../td3c
```

## [TD-5] - Inversion de priorité ?

#### Compilation

```bash
g++ main_td3a.cpp TimeSpec.cpp OSTempsReel/Chrono.cpp -lrt -o ../td3a
```

#### Exécution

```bash
../td3a
```
