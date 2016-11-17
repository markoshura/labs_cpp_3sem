#include <iostream>
using namespace std;
template<int L, int Kg,int S, int A, int K, int Mol, int Cd>
class DimQ {

public:
    double value;

    DimQ(double x) {
        value = x;
    }

    DimQ<L, Kg, S, A, K, Mol, Cd> operator-() {
        return DimQ<L, Kg, S, A, K, Mol, Cd>(-value);
    };
    DimQ <L,Kg,S,A,K,Mol,Cd> operator+(DimQ <L,Kg,S,A,K,Mol,Cd> &other){
        return DimQ <L,Kg,S,A,K,Mol,Cd>(value+other.value);
    };
    template<int L1, int Kg1,int S1, int A1, int K1, int Mol1, int Cd1>
            DimQ <L+L1,Kg+Kg1,S+S1, A+A1,K+K1, Mol+Mol1, Cd+Cd1> operator*(DimQ <L1,Kg1,S1,A1,K1,Mol1,Cd1> other){
        return DimQ<L+L1,Kg+Kg1,S+S1, A+A1,K+K1, Mol+Mol1, Cd+Cd1>(value*other.value);

    };
    template<int L1, int Kg1,int S1, int A1, int K1, int Mol1, int Cd1>
    DimQ <L-L1,Kg-Kg1,S-S1, A-A1,K-K1, Mol-Mol1, Cd-Cd1> operator/(DimQ <L1,Kg1,S1,A1,K1,Mol1,Cd1> other){
       return  DimQ <L-L1,Kg-Kg1,S-S1, A-A1,K-K1, Mol-Mol1, Cd-Cd1>(value/other.value);
    };
};
typedef DimQ <1,0,0,0,0,0,0> Length;
typedef DimQ <1,0,1,0,0,0,0> Velocity;
typedef DimQ <1,0,2,0,0,0,0> Acceleration;
typedef DimQ <0,0,0,0,0,0,0> dimensionless;
typedef DimQ <0,0,1,0,0,0,0> Time;



int main(){
// Длина
    Length l = {100};
// Время
    Time t = {20};

// Скорость
    Velocity v = l/t;

// Ускорение
    Acceleration a = v/t;

// Размерная величина
    auto smth = v*a*a/t;
// Безразмерная величина
    auto dimensionless = v/v;}
