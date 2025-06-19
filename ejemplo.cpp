#include <iostream>
using namespace std;

struct EMP{
    int num;
    string nom;
    float ven[12], sal;
};

int main(){
    EMP EMPLEADOS [100];
    int n;
    cout<<"Cantidad de empleados: ";
    cin>>n;
    for (int i=0; i<n; i++){
        cout<<"Numero de empleado: ";
        cin>>EMPLEADOS[i].num;
        cin.ignore(); 
        cout<<"Nombre del empleado: ";
        getline(cin, EMPLEADOS[i].nom);
        for (int j=0; j<12; j++){
            cout<<"Ventas: ";
            cin>>EMPLEADOS[i].ven[j];
        }
        cin>>EMPLEADOS[i].sal;
    }
    float ventas_max = -1;
    int indice_max= -1;

    for (int i=0; i<n; i++){
        float total = 0;
        for (int j=0; j<12; j++){
            total = total + EMPLEADOS[i].ven[j];
        }
        if (total > ventas_max){
            ventas_max = total;
            indice_max = i;
        }
    }

    if (indice_max != -1){
        cout<<"Empleado con mayores ventas: "<<endl;
        cout<<"Numero: "<<EMPLEADOS[indice_max].num<<endl;
        cout<<"Nombre: "<<EMPLEADOS[indice_max].nom<<endl;
        cout<<"Ventas totales: "<<EMPLEADOS[indice_max].ven<<endl;
    }
    else{
        cout<<"No hay empleados registrados"<<endl;
    }
}