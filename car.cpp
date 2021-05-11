#include <iostream>

using namespace std;

class Car {
   public:
    string color;
    string engine;
    float gas_tank;
    unsigned int wheel;

    void fill_tank(float liter);
    void running(void);
    Car(void);
    ~Car();  //析构器,释放内存用
};

void Car::fill_tank(float liter) {
    gas_tank += liter;
}