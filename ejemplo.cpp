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

    cout << "\nEmpleados con ventas inferiores a 30 en diciembre:" << endl;
    bool encontrados = false;
    for (int i = 0; i < n; i++) {
        if (EMPLEADOS[i].ven[11] < 30){
            cout << "Numero: "<<EMPLEADOS[i].num<<endl;
            cout << "Nombre: "<<EMPLEADOS[i].nom<<endl;
            cout << "Ventas diciembre: "<< EMPLEADOS[i].ven[11] << "\n" << endl;
            encontrados = true;
        }
    }
    if (encontrados == false){
        cout<<"Ningun empleado tuvo ventas inferiores a 30 en diciembre"<<endl;
    }

    float ventas_max = -1;
    int indice_max= -1;

    for (int i=0; i<n; i++){
        float total = 0;
        for (int j=0; j<12; j++){
            total = total + EMPLEADOS[i].ven[j];
        }
        
        if(total > 100){
            EMPLEADOS[i].sal = EMPLEADOS[i].sal +(EMPLEADOS[i].sal * 0.1);
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
        cout<<"Ventas totales: "<<ventas_max<<endl;
    }
    else{
        cout<<"No hay empleados registrados"<<endl;
    }
}