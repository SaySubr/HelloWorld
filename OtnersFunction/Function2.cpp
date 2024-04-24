#include <iostream>
#include <windows.h>
#include <conio.h>
#include <math.h>
#include <time.h>
using namespace std;
                        // ������  �������
int** initMatrix (int** a, int n, int m){
    a = new int* [n]; // �������� �������
    for (int i = 0; i<n;i++){
        a[i]= new int [m]; // �������� ��������
        }
    return a;
    } // 1) ������� ������������� ������ (�������������)

void FillMatrix (int** a, int n, int m){
    for ( int i = 0; i<n;i++){
        for (int c = 0; c<m; c++){
            a[i][c] = 10 + rand() % (50-10+1);
        }
    }
}// 2) ������� ���������� ��������� �������

void ShowMatrix (int** a, int n, int m){
    for ( int i = 0; i<n;i++){
        for (int c = 0; c<m; c++){
            a[i][c] = 10 + rand() % (50-10+1);
                cout << a[i][c] << "\t";
        }
    cout << "\n";
    }
}//3) ���������� �������

void DeleteMatrix (int** a, int n){
    for(int i = 0; i<n; i++){
        delete [] a[i];
    }
    delete [] a;
}//4) ������� ������������ ������

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
    n = n+1;//�������� ���������� ����� ������� �� �������
    a = new_arr;
}// 5)������� �� ���������� ����� ������ � �������



int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    srand(time(NULL));
    int n = 3; // ������
    int m = 3; // �������
    int **a = nullptr;
    a = initMatrix (a,n,m);
    cout << "�������� �������: " << endl;

    FillMatrix (a,n,m);
        ShowMatrix(a,n,m);

    AddRow(a,n,m,2);
    cout << "�������� ����� ������: " << endl;
    ShowMatrix(a,n,m);
    DeleteMatrix (a,n);
    return 0;
}
