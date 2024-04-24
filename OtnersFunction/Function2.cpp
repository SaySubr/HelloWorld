#include <iostream>
#include <windows.h>
#include <conio.h>
#include <math.h>
#include <time.h>
using namespace std;
                        // строки  столбцы
int** initMatrix (int** a, int n, int m){
    a = new int* [n]; // разметка строков
    for (int i = 0; i<n;i++){
        a[i]= new int [m]; // разметка столбцов
        }
    return a;
    } // 1) функция распределение памяти (инициализация)

void FillMatrix (int** a, int n, int m){
    for ( int i = 0; i<n;i++){
        for (int c = 0; c<m; c++){
            a[i][c] = 10 + rand() % (50-10+1);
        }
    }
}// 2) фунцкия заполнения элементов матрицы

void ShowMatrix (int** a, int n, int m){
    for ( int i = 0; i<n;i++){
        for (int c = 0; c<m; c++){
            a[i][c] = 10 + rand() % (50-10+1);
                cout << a[i][c] << "\t";
        }
    cout << "\n";
    }
}//3) показывает матрицу

void DeleteMatrix (int** a, int n){
    for(int i = 0; i<n; i++){
        delete [] a[i];
    }
    delete [] a;
}//4) функция освобождение памяти

void AddRow(int **&a, int& n, int m, int index){
    int** new_arr = nullptr;
    new_arr = initMatrix(new_arr,n+1,m);
        for (int i = 0; i<n+1; i++){

            for (int c = 0; c<m; c++){

                if(i < index)
                    new_arr[i][c] = a[i][c];

            else if (i == index)
                new_arr[i][c] = 0;

            else
                new_arr[i][c] = a[i-1][c];

            }
        }
    DeleteMatrix(a,n);
    n = n+1;//изменяем количество строк матрицы на единицу
    a = new_arr;
}// 5)функция по добавлению новой строки в матрицу



int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    srand(time(NULL));
    int n = 3; // строки
    int m = 3; // столбцы
    int **a = nullptr;
    a = initMatrix (a,n,m);
    cout << "Исходная матрица: " << endl;

    FillMatrix (a,n,m);
        ShowMatrix(a,n,m);

    AddRow(a,n,m,2);
    cout << "Добавили новую строку: " << endl;
    ShowMatrix(a,n,m);
    DeleteMatrix (a,n);
    return 0;
}
