#include "Menu.h"

using namespace std;

int main()
{
    bool bandera= false;
    string nombre_del_archivo= "sumo.txt";
    int semilla_De_codificacion=4; int longitud=4;
    vector <int> longitudes_nombres_usuarios;
    vector <int> longitudes_nombres_usuarios;
    vector <int> longitudes_nombres_usuarios;
    int longitud_clave_usuario=4;
    int longitud_usuario=4;
    int longitud_saldo=4;

    ComprobacionDeArchivo(nombre_del_archivo, bandera, semilla_De_codificacion, longitud);

    while(bandera){
        int eleccion_menu_ingreso=0;
        cout << "\nBIENVENIDO A NUESTRO SISTEMA! \n" << endl;
        cout << "Seleccione un modo de ingreso: " <<endl;
        cout << "1. Administrador" <<endl;
        cout << "2. Usuario" <<endl;
        cout << "3. Salir del sistema" <<endl;

        try{

            if(!(cin >> eleccion_menu_ingreso)){
                throw 1;

            }else if(eleccion_menu_ingreso!=1 && eleccion_menu_ingreso!=2 && eleccion_menu_ingreso!=3){
                throw 2;

            }else if(eleccion_menu_ingreso==1){
                bool bandera_menu_admin= true;
                while(bandera_menu_admin){
                    cout << "Ingrese la contraseña"<<endl;
                    bool verificacion_administrador= verificacionAdministrador(nombre_del_archivo, semilla_De_codificacion, longitud);
                    if(verificacion_administrador){
                        bool menu_interno_admin=true;
                        char respuesta_menu_admin = ' ';
                        while(menu_interno_admin){
                            cout << "\nSeleccione una opción: " <<endl;
                            cout << "1. Crear usuarios"<<endl;
                            cout << "2. Salir de la cuenta" <<endl;

                            string verificar_tamaño= "";
                            cin >> verificar_tamaño;
                            if(verificar_tamaño.length() > 1){
                                cout << "Solo puedes ingresar una letra" <<endl;
                            }else if (verificar_tamaño.length() ==1 && verificar_tamaño != "\n"){
                                respuesta_menu_admin= verificar_tamaño[0];
                                switch(respuesta_menu_admin){
                                case '1':{
                                    cout<<"\nCreando usuario..."<<endl;
                                    CrearUsuario(nombre_del_archivo, semilla_De_codificacion, longitud_usuario, longitud_clave_usuario, longitud_saldo);
                                }
                                break;
                                case '2':
                                    bandera_menu_admin=false;
                                    menu_interno_admin= false;
                                    break;
                                default:
                                    cout << "\nIngresaste una opcion invalida" <<endl;
                                    cin.clear();
                                    cin.ignore(255, '\n');
                                    break;
                                }
                            }
                        }
                    }else{
                        cout <<"Contraseña incorrecta"<<endl;
                    }
                }

            }else if(eleccion_menu_ingreso==2){
                char salir_usuario=' ';
                bool bandera_validacion_usuario= true;
                int numero_de_linea_principal;
                bool bandera_repetir_menu_usuario= false;


                while(bandera_validacion_usuario){
                    if(ValidacionUsuario(nombre_del_archivo, semilla_De_codificacion, numero_de_linea_principal, longitud_usuario)){
                        bool validacion_clave_usuario=true;
                        while(validacion_clave_usuario){
                            string clave;
                            cout<<"Ingrese la clave: ";cin >> clave;
                            string clave_guardada= leerUnaLinea(numero_de_linea_principal+1, nombre_del_archivo);
                            clave_guardada= decodificarM2(clave_guardada, semilla_De_codificacion);
                            clave_guardada= quitarCeros(clave_guardada, longitud_clave_usuario);
                            clave_guardada= convBinInt(clave_guardada);
                            if(clave==clave_guardada){
                                bandera_repetir_menu_usuario= true;;
                                validacion_clave_usuario=false;
                                bandera_validacion_usuario=false;

                            }else{
                                cout<<"Clave incorrecta"<<endl;
                            }
                        }



                    }else{
                        cout<< "La cedula ingresada no se encuentra registrada. "<<endl;
                        bool miban=true;
                        while(miban){
                            cout <<"Quiere volver a intentarlo? (s/n): ";
                            salir_usuario= VerificarTamaño();
                                switch(salir_usuario){
                            case 's':{
                                miban=false;
                            }
                            break;
                            case 'n':
                                bandera_validacion_usuario=false;
                                miban=false;
                                break;
                            default:
                                cout << "\nIngresaste una opcion invalida" <<endl;
                                cin.clear();
                                cin.ignore(255, '\n');
                                break;
                            }

                        }
                    }
                }


                while(bandera_repetir_menu_usuario){
                    cout << "\nSeleccione una opción: " <<endl;
                    cout << "1. Consultar saldo"<<endl;
                    cout << "2. Retirar dinero" <<endl;
                    cout << "3. Salir de la cuenta"<<endl;
                    char respuesta_menu_usuario= ' ';

                    string verificar_tamaño= "";
                    cin >> verificar_tamaño;
                    if(verificar_tamaño.length() > 1){
                        cout << "Solo puedes ingresar una letra" <<endl;
                    }else if (verificar_tamaño.length() ==1 && verificar_tamaño != "\n"){
                        respuesta_menu_usuario= verificar_tamaño[0];
                        switch(respuesta_menu_usuario){
                        case '1':{
                            int valorsaldo=0;
                            bool verificacion_saldo= VerificarSaldo(valorsaldo, numero_de_linea_principal+2, nombre_del_archivo, semilla_De_codificacion, longitud_saldo);

                            if(verificacion_saldo){
                                cout << "\nSu saldo es de: " << valorsaldo << " pesos\n" <<endl;
                                cout <<"Se le cobraran 1000 pesos por consultar su saldo\n"<<endl;
                                valorsaldo-= 1000;
                                ActualizarSaldo(valorsaldo, nombre_del_archivo, numero_de_linea_principal+2, semilla_De_codificacion);
                            }else{
                                cout<<"Tiene menos de mil pesos, por lo tanto no puede consultar su saldo"<<endl;
                            }

                        }
                            break;
                        case '2':

                            break;

                        case '3':
                            bandera_repetir_menu_usuario=false;
                            break;
                        default:
                            cout << "\nIngresaste una opcion invalida" <<endl;
                            cin.clear();
                            cin.ignore(255, '\n');
                            break;

                        }
                    }
                }


            }else if(eleccion_menu_ingreso==3){
                bandera=false;
            }

        } catch(int n){
            if(n==1){
                cout<<"\n Ingresate una opcion invalida. Solo puede ingresar numeros\n"<<endl;
            }if(n==2){
                cout<<"\nSeleccione 1 o 2 para ingresar\n"<<endl;
            }
        }
        cin.clear();
        cin.ignore(255, '\n');
    }

    cout<<"\nGracias por usar nuestros servicios!"<<endl;
    cout <<"Vuelva pronto!"<<endl;

    return 0;
}
