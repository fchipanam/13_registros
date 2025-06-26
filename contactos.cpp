#include<iostream>
using namespace std;

struct correo{
    string user;
    string domain;
};

struct contactoEmail{
    string nom;
    char sex;
    int edad;
    correo email;
};

void leerCorreo(correo &, string, string);
void leerContacto(contactoEmail &, string, char, int, correo);
void imprimeContacto(contactoEmail &);
void modificarContacto(contactoEmail &);

int main(){
    int n, op, pos;
    string nom, user, domain;
    char sex;
    int edad;
    correo email;
    contactoEmail cont, lista[100];
    n = 0;
    do{
        system("cls");
        cout<<"Menu de opciones -------------------------"<<endl;
        cout<<"1. Agregar contacto"<<endl;
        cout<<"2. Mostrar contactos"<<endl;
        cout<<"3. Modificar contacto"<<endl;
        cout<<"0. Salir"<<endl;
        cout<<"Elige una opcion: "; cin>>op;
        switch(op){
            case 1:
                cout<<"Ingrese los datos de un usuario: "<<endl;
                cin.ignore();
                cout<<"Ingrese el nombre del contacto: "; getline(cin,nom);
                cout<<"Ingrese el sexo (M/F): "; cin>>sex;
                cout<<"Ingrese la edad: "; cin>>edad;
                cout<<"Ingrese el correo electronico (usuario@dominio): "<<endl;
                cout<<"\tIngrese el usuario: "; cin>>user;
                cout<<"\tIngrese el dominio: "; cin>>domain;
                
                leerCorreo(email,user,domain);
                leerContacto(cont,nom,sex,edad,email);
                //imprimeContacto(cont);

                lista[n] = cont;
                n++;
                system("pause");
                break;
            case 2:
                for(int i = 0; i < n; i++){
                    cout<<"Contacto #"<<i<<endl;
                    imprimeContacto(lista[i]);
                    cout<<endl;
                }
                system("pause");
                break;
             case 3:
                if(n == 0){
                    cout<<"No hay contactos para modificar."<<endl;
                } else {
                    cout<<"Ingrese la posicion del contacto a modificar (0-" << n-1 << "): ";
                    cin>>pos;
                    if(pos >= 0 && pos < n){
                        modificarContacto(lista[pos]);
                        cout<<"Contacto modificado exitosamente."<<endl;
                    } else {
                        cout<<"Posicion invalida."<<endl;
                    }
                }
                system("pause");
                break;
            case 0:
                cout<<"Esta seguro de salir? (S/N): ";
                break;
            default:
                cout<<"Opcion no valida!"<<endl;
                system("pause");
                break;
        }
    } while(op != 0);
    return 0;
}

void leerContacto(contactoEmail &c, string n, char s, int e, correo em){
    c.nom = n;
    c.sex = s;
    c.edad = e;
    c.email = em;
}

void leerCorreo(correo &c, string u, string d){
    c.user = u;
    c.domain = d;
}

void imprimeContacto(contactoEmail &c){
    cout<<"Nombre: "<<c.nom<<endl;
    cout<<"Sexo: "<<c.sex<<endl;
    cout<<"Edad: "<<c.edad<<endl;
    cout<<"Email: "<<c.email.user<<"@"<<c.email.domain<<endl;
}
void modificarContacto(contactoEmail &c){
    string nom, user, domain;
    char sex;
    int edad;
    
    cout<<"Modificando contacto:"<<endl;
    imprimeContacto(c);
    cout<<endl;
    
    cin.ignore();
    cout<<"Nuevo nombre (actual: " << c.nom << "): ";
    getline(cin, nom);
    if(!nom.empty()) c.nom = nom;
    
    cout<<"Nuevo sexo (M/F) (actual: " << c.sex << "): ";
    cin>>sex;
    if(sex == 'M' || sex == 'F') c.sex = sex;
    
    cout<<"Nueva edad (actual: " << c.edad << "): ";
    cin>>edad;
    if(edad > 0) c.edad = edad;
    
    cout<<"Nuevo correo electronico (usuario@dominio)"<<endl;
    cout<<"Usuario (actual: " << c.email.user << "): ";
    cin>>user;
    if(!user.empty()) c.email.user = user;
    
    cout<<"Dominio (actual: " << c.email.domain << "): ";
    cin>>domain;
    if(!domain.empty()) c.email.domain = domain;
}