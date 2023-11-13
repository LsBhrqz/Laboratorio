#ifndef ROUTER_H
#define ROUTER_H
#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <queue>
#include <climits>
#include <list>
#include <time.h>


class Router {
public:
    Router(char id);
    char idRouter;
    std::string camino;
    std::vector<std::pair<Router*, int>> vecinos; // Un vector de pares, guarda los vecinos y los costos al vecino
    int distancia;
    bool visitado;
    void nuevoVecino(Router* vecino, int costo);
    void confDistancia(int distancia);
    void reinicio();
    bool operator==(const Router& otro) const {
        return idRouter == otro.idRouter;
    }
};

void dijkstra(Router* fuente, Router* destino, std::list <Router>& topologia);

bool verificarVecino(Router* a, Router b);

void verVecinos(Router& a);

void generar_routers_Aleatorios(std::list <Router>& topologia);

bool verificarExistenciaRouter(std::list<Router>& topologia, char& nombre, Router*& puntero);

void Buscando_camino(std::list <Router>& topologia);

void recibirConexiones(int& conexiones, int tamaño);

void crearRouters(std::list <Router>& topologia);

void eliminarRouter(std::list <Router>& topologia);

#endif // ROUTER_H

/*

*/
