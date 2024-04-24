#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "function.h"
using namespace std;

void fillArrayRandom(int arr[], int size, int minVal, int maxVal) {

    srand(time(nullptr));

    for (int i = 0; i < size; ++i) {
        arr[i] = minVal + rand() % (maxVal - minVal + 1);
    }
}// Функция для заполнения массива случайными значениями


void printArray(const int arr[], int size) {

    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

}// Функция для вывода значений массива на консоль
