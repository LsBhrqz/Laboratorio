#include "router.h"
#include <algorithm>
Router::Router(char id) : idRouter(id), distancia(INT_MAX), visitado(false) {} //

void Router::nuevoVecino(Router* vecino, int costo) {
    vecinos.emplace_back(vecino, costo); // en vez de push_back, porque construyo el elemento que es un par
}

void Router::confDistancia(int dist) {
    distancia = dist;
}

void Router::reinicio() {
    distancia = INT_MAX;
    visitado = false;
    camino="";
}

void dijkstra(Router* fuente, Router* destino, std::list <Router>& topologia) {

    fuente->confDistancia(0);

    //REINICAR EL STRING CAMINO Y COLOCARLO EN EL DESTINO
    fuente->camino = fuente->idRouter;

    std::priority_queue<std::pair<int, Router*>> pq;
    pq.push({0, fuente});


    while (!pq.empty()) {
        Router* actual = pq.top().second;
        pq.pop();

       /* if (actual == destino) {
            // Hemos alcanzado el nodo de destino, no es necesario seguir con el algoritmo
            break;
        }*/

        if (actual->visitado) continue;

        actual->visitado = true;

        for (auto& vec : actual->vecinos) {
            Router* sigRouter = vec.first;
            int costoBorde = vec.second;
            int nuevaDistancia = actual->distancia + costoBorde;

            if (nuevaDistancia < sigRouter->distancia) {
                sigRouter->confDistancia(nuevaDistancia);
                sigRouter->camino = actual->camino + " -> " + sigRouter->idRouter;
                pq.push({-nuevaDistancia, sigRouter});
            }
        }
    }

    // Imprimir el camino solo para el nodo de destino
    std::cout << "Camino mas corto a " << destino->idRouter <<" desde "<<fuente->idRouter<< " es " << destino->camino << std::endl;
    std::cout << "El menor costo a " << destino->idRouter <<" desde "<<fuente->idRouter<< ": " << destino->distancia << std::endl;

    for(auto& c_router: topologia){
        c_router.reinicio();
    }
}

//Método para verificarvecinos:
bool verificarVecino(Router* a, Router b){
    for(auto& iter : b.vecinos){
        if(iter.first == a){
            return true;
        }
    }
    return false;
}

void verVecinos(Router& a){
    for(auto& iter : a.vecinos){
        std::cout << iter.first->idRouter << iter.second << std::endl;
    }
}

void generar_routers_Aleatorios(std::list <Router>& topologia){

    topologia.clear();

    srand(time(NULL));

    int routers = 0;
    std::cout << "Ingrese la cantidad de routers a generar: " << std::endl;
    std::cin >> routers;


    int i = 0;
    char ident = i + 65;

    while(true){

        if(i >= routers) break;
        Router A(ident);
        topologia.push_back(A);
        i++;
        ident++;
        /*

        if(i >= routers) break;
        Router B(ident);
        topologia.push_back(B);
        i++;
        ident++;

        if(i >= routers) break;
        Router C(ident);
        topologia.push_back(C);
        i++;
        ident++;

        if(i >= routers) break;
        Router D(ident);
        topologia.push_back(D);
        i++;
        ident++;

        if(i >= routers) break;
        Router E(ident);
        topologia.push_back(E);
        i++;
        ident++;

        if(i >= routers) break;
        Router F(ident);
        topologia.push_back(F);
        i++;
        ident++;

        if(i >= routers) break;
        Router G(ident);
        topologia.push_back(G);
        i++;
        ident++;

        if(i >= routers) break;
        Router H(ident);
        topologia.push_back(H);
        i++;
        ident++;

        if(i >= routers) break;
        Router I(ident);
        topologia.push_back(I);
        i++;
        ident++;

        if(i >= routers) break;
        Router J(ident);
        topologia.push_back(J);
        i++;
        ident++;

        if(i >= routers) break;
        Router K(ident);
        topologia.push_back(K);
        i++;
        ident++;*/

    }


    for(auto rout : topologia){
        std::cout << rout.idRouter << std::endl;
    }


    for(auto& rout : topologia){//HACE FOR EACH JAJAJAJAJA
        bool asies;
        int numvecs = 1 + rand() % ((i + 1) - 1);
        for(int j = 0; j <= numvecs; j++){
            int vecino = rand() % (i);
            int cont = 0;
            for(auto& vec : topologia){
                Router* vecptr = &vec;
                Router* routptr = &rout;
                asies = verificarVecino(vecptr, rout);
                char idvec = vec.idRouter;
                char idrout = rout.idRouter;
                if((vecino == cont) && (!asies) && (idvec != idrout)){
                    int costovec = 1 + rand() % (11 - 1);
                    rout.nuevoVecino(vecptr, costovec);
                    vec.nuevoVecino(routptr, costovec);
                }
                cont++;
            }
        }
    }

    std::cout << std::endl;

    for(auto& rout : topologia){
        verVecinos(rout);
        std::cout<< std::endl;
    }

}

bool verificarExistenciaRouter(std::list <Router>& topologia, char& nombre, Router*& puntero){
    for(auto& c_router: topologia){
        if(c_router.idRouter == nombre){
            puntero= &c_router;
            return true;
        }
    }
    std::cout<<"La id ingresada no existe"<<std::endl;
    return false;
}

void Buscando_camino(std::list <Router>& topologia){
    char id_router_fuente, id_router_destino;
    bool ban=true;
    bool existencia_fuente, existencia_destino;
    Router* puntero_fuente;
    Router* puntero_destino;
    while(ban){
        std::cout<<"Ingrese la Id del router fuente: ";std::cin>>id_router_fuente;
        existencia_fuente= verificarExistenciaRouter(topologia, id_router_fuente, puntero_fuente);
        while(existencia_fuente){
            std::cout<<"Ingrese la Id del router destino: ";std::cin>>id_router_destino;
            existencia_destino= verificarExistenciaRouter(topologia, id_router_destino, puntero_destino);
            if(existencia_destino){
                dijkstra(puntero_fuente, puntero_destino, topologia);
                ban= false;
                existencia_fuente = false;

            }
        }
    }
}

void crearRouters(std::list <Router>& topologia){
    bool entrando = true;
    char nuevo;

    while(entrando){
        std::cout << "Ingrese el identificador del router (una letra del alfabeto) a agregar en la red: "; std::cin >> nuevo;
        for(auto& requisa : topologia){
            char idrequisa = requisa.idRouter;
            if(idrequisa == nuevo){
                entrando = false;
                break;
            }
        }
        if(entrando){
            int conexiones = 0;
            Router N(nuevo);
            topologia.push_back(N);
            int tamaño = topologia.size();
            recibirConexiones(conexiones, tamaño);
            for(int k = 0; k < conexiones;){
                char vecinodelnuevo;
                std::cout <<"Nombre del vecino del router a agregar en la red: "; std::cin >> vecinodelnuevo;
                Router* nuevoptr = &N;
                Router* requisaptr = nullptr;
                bool existe_vecino = verificarExistenciaRouter(topologia, vecinodelnuevo, requisaptr);
                if(existe_vecino){
                    if((requisaptr->idRouter)==(nuevoptr->idRouter)){
                        std:: cout<<"No le coloques un valor distinto de cero al costo de el mismo"<<std::endl;
                    }
                    for(auto& vec: topologia){
                        if(vec.idRouter== nuevo){
                            nuevoptr= &vec;
                        }
                    }
                    bool ya_es_vecino= verificarVecino(requisaptr,(*nuevoptr));
                    if(existe_vecino && (!ya_es_vecino)){
                        k++;
                        int costodelnuevo = 0;
                        std::cout <<"Ingrese el costo del nuevo router al vecino: "; std::cin >> costodelnuevo;
                        for(auto& vec: topologia){
                            if(vec.idRouter== nuevo){
                                nuevoptr= &vec;
                                vec.nuevoVecino(requisaptr, costodelnuevo);
                            }
                        }
                        (*requisaptr).nuevoVecino(nuevoptr, costodelnuevo);

                    }else if(ya_es_vecino){
                        std::cout<<"Este router ya es vecino del nuevo router"<<std::endl;
                    }
                }
            }

            entrando = false;

        }else{
            std::cout << "Ese router ya existe. Intente otro nombre." << std::endl;
            entrando = true;
        }
    }

    for(auto& rout : topologia){
        verVecinos(rout);
        std::cout<< std::endl;
    }
}

void recibirConexiones(int& conexiones, int tamaño){
    while(true){
        std::cout << "Ingrese la cantidad de vecinos: "; std::cin >> conexiones; std::cout << std::endl;
        if(conexiones < tamaño){
            break;
        }else{
            std::cout << "Cantidad invalida (no hay suficientes routers). Trate de nuevo." << std::endl;
        }
    }
}

void eliminarRouter(std::list <Router>& topologia){
    bool entrando = true;
    char nuevo;
    Router *puntero;
    while(entrando){
        std::cout << "Ingrese el identificador del router (una letra del alfabeto) a borrar en la red: "; std::cin >> nuevo;
        bool existe= verificarExistenciaRouter(topologia, nuevo, puntero);
        if(existe){
            for(auto& vec: topologia){
                for(auto& iter : vec.vecinos){
                    if(iter.first->idRouter== nuevo){
                        vec.vecinos.erase(std::remove_if(vec.vecinos.begin(), vec.vecinos.end(),
                        [iter](const std::pair<Router*, int>& par){return par== iter;}), vec.vecinos.end());
                    }
                }
            }
            topologia.remove((*puntero));
            entrando= false;
        }
    }

    for(auto& rout : topologia){
        verVecinos(rout);
        std::cout<< std::endl;
    }
}
