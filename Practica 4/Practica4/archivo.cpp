#include "archivo.h"

bool comprobarLectura( string nombredelarchivo){
    ifstream archivo;
    archivo.open(nombredelarchivo);
    if(!archivo){
        cerr << "\nNo se puede abrir el archivo. No se encuentra.\n" << endl;
        return false;
    }else{
        archivo.close();
        cout << "\nVerificacion exitosa\n" <<endl;
        return true;
    }
}

bool leer_red_archivo(list <Router>& topologia){
    string nombre_archivo;
    string linea;
    std::cout<<"Ingrese el nombre del archivo a leer: "; cin>> nombre_archivo;
    nombre_archivo+= ".txt";
    if(comprobarLectura(nombre_archivo)){
        ifstream archivo;
        archivo.open(nombre_archivo);
        topologia.clear();
        while(getline(archivo, linea)){
            Router A(linea[0]);
            topologia.push_back(A);
        }
        archivo.close();
        archivo.open(nombre_archivo);
        while(getline(archivo, linea)){
            char id_trabajando= linea[0];
            for(auto& router_fuente: topologia){
                if(router_fuente.idRouter== id_trabajando){
                    for(int i=2; i< linea.length(); i+=2){
                        char id_vecino= linea[i];
                        int costo_vecino= (linea[i+1])-48;
                        for(auto&router_vecino: topologia){
                            Router* ptr_router_vecino= &router_vecino;
                            if(router_vecino.idRouter== id_vecino){
                                router_fuente.nuevoVecino(ptr_router_vecino, costo_vecino);
                            }
                        }
                    }
                }
            }
        }
        archivo.close();
        return true;
    }
    return false;
}

void menus(list <Router>& topologia){
    string respuesta_menu;
    bool menu= true;
    while(menu){
        std::cout<<"Menu"<<std::endl;
        std::cout<<"\t1. Agregar un router"<<std::endl;
        std::cout<<"\t2. Eliminar un router"<<std::endl;
        std::cout<<"\t3. Mostrar camino y costo mas eficiente"<<std::endl;
        std::cout<<"\t4. Salir del menu\n"<<std::endl;
        std::cout<<"Seleccione una opcion: ";std::cin>>respuesta_menu;
        if(respuesta_menu=="1"){
            crearRouters(topologia);
        }else if(respuesta_menu=="2"){
            eliminarRouter(topologia);
        }else if(respuesta_menu=="3"){
            Buscando_camino(topologia);
        }else if(respuesta_menu=="4"){
            menu= false;
        }else{
            std::cout<<"Ingresaste una opcion invalida"<<std::endl;
        }
    }
}

