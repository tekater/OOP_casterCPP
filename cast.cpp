#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream> // ifstream + ofstream
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>
#include <direct.h>

using namespace std;

void func(const int *ptr) {
    int* temp = const_cast<int*>(ptr);
    *temp = 100;
}

class A {
public:
    virtual void test() {
        cout << "Test A\n";
    }

};

class B : public A {
public:
    virtual void test() {
        cout << "Test B\n";
    }
};

int main()
{
    setlocale(0, "");
    srand(time(nullptr));
    int a = 5;
    int b = 2;

    

    //static_cast
    cout << double(a) / b << endl;              // Язык C
    cout << static_cast<double>(a) / b << endl; // Язык C++



    int x = 5;
    //const_cast
    cout << "Before[x]: " << x << endl;

    func(&x);

    cout << "After[x]: " << x << endl;



    //dynamic_cast
    A* ptrA, objA;
    B* ptrB, objB;

    ptrA = dynamic_cast<A*>(&objA);
    if (ptrA) {
        ptrA->test();
    }
    else {
        cout << "ERROR\n";
    }

    ptrA = dynamic_cast<A*>(&objB);
    if (ptrA) {
        ptrA->test();
    }
    else {
        cout << "ERROR\n";
    }

    ptrB = dynamic_cast<B*>(&objB);
    if (ptrB) {
        ptrB->test();
    }
    else {
        cout << "ERROR\n";
    }

    ptrB = dynamic_cast<B*>(&objA);
    if (ptrB) {
        ptrB->test();
    }
    else {
        cout << "ERROR\n";
    }


    //reinterpret_cast
    char str[20] = "Hello wordl!\n";
    int y = reinterpret_cast<int>(str);
    cout << y << endl;
}
