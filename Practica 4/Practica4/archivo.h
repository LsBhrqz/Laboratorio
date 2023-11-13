#ifndef ARCHIVO_H
#define ARCHIVO_H

#include "router.h"

using namespace std;

bool comprobarLectura( string nombredelarchivo);

bool leer_red_archivo(list <Router>& topologia);

void menus(list <Router>& topologia);

#endif // ARCHIVO_H
