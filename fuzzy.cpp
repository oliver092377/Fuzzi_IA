#include <iostream>
#include <cmath>

using namespace std;

// Funciones de membresía
double funcionMembresiaGoles(int goles) {
    if (goles >= 30.0) {
        return 1.0;
    } else if (goles < 10.0) {
        return 0.0;
    } else {
        return (goles - 10.0) / (30.0 - 10.0);
    }
}

double funcionMembresiaAsistencias(int asistencias) {
    if (asistencias >= 20.0) {
        return 1.0;
    } else if (asistencias < 5.0) {
        return 0.0;
    } else {
        return (asistencias - 5.0) / (20.0 - 5.0);
    }
}

double funcionMembresiaTiros(int tiros) {
    if (tiros >= 15.0) {
        return 1.0;
    } else if (tiros < 3.0) {
        return 0.0;
    } else {
        return (tiros - 3.0) / (15.0 - 3.0);
    }
}
double funcionMembresiaValorMercado(double valorMercado) {
    if (valorMercado >= 70.0) {
        return 1.0;
    } else if (valorMercado < 30.0) {
        return 0.0;
    } else {
        return (valorMercado - 30.0) / (70.0 - 30.0);
    }
}
double calcularPuntuacion(int goles, int asistencias, double valorMercado, int tiros) {
    double gradoGoles = funcionMembresiaGoles(goles);
    double gradoAsistencias = funcionMembresiaAsistencias(asistencias);
    double gradoValorMercado = funcionMembresiaValorMercado(valorMercado);
    double gradoTiros = funcionMembresiaTiros(tiros);
    // Ponderación de los grados de pertenencia 
    double pesoGoles = 0.4;
    double pesoAsistencias = 0.25;
    double pesoTiros = 0.2;
    double pesoValorMercado = 0.15;
   

    // Calcular la puntuación
    double puntuacion = (gradoGoles * pesoGoles + gradoAsistencias * pesoAsistencias +
                        gradoValorMercado * pesoValorMercado + gradoTiros * pesoTiros) * 100.0;

    return puntuacion;
}

int main() {
    int goles, asistencias, tiros;
    double valorMercado;

    cout << "Ingrese la cantidad de goles marcados: ";
    cin >> goles;

    cout << "Ingrese la cantidad de asistencias realizadas: ";
    cin >> asistencias;

    cout << "Ingrese el valor de mercado (Millones): ";
    cin >> valorMercado;

    cout << "Ingrese el promedio de tiros por partido: ";
    cin >> tiros;

    double puntuacion = calcularPuntuacion(goles, asistencias, valorMercado, tiros);
    cout << "La puntuación del delantero es: " << puntuacion << endl;
    if (puntuacion>80) {
        cout << "El delantero es muy bueno." << endl;
    }else if(puntuacion>60 && puntuacion<=80){
        cout << "El delantero es bueno." << endl;
    }else if(puntuacion>40 && puntuacion<=60){
        cout << "El delantero es regular." << endl;
    }else if(puntuacion>20 && puntuacion<=40){
        cout << "El delantero es malo." << endl;
    }else{
        cout << "El delantero es muy malo." << endl;
    }
    return 0;
}

