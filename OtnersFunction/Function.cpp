#include <iostream>
#include <windows.h>
#include <conio.h>
#include <math.h>
#include <time.h>
using namespace std;

void printLine(int n)
{
    for (int i=0; i<n; i++)
    {
        cout << '-';
    }// функци€, рисующа€ линию
}




bool isprime (int i)
    {
    int counter =0;
    for (int c = 1; c <= i;c++)
        {
        if(i% c == 0)

        counter++;
        }
    if(counter == 2){
        return true;
    }
        return false;
    }//функци€ провер€ет простое ли число

bool polzavetel (int a, string b){
int password = 12345;
string login = "admin";
if (password == a && login == b){
    cout << "¬ход...";
    return true;

}
if (password != a && login != b){
    cout << "¬хода нет...";
    return false;

}
}//функци€ проверки на правильность авторизации

int * unitArray(int *a, int n){
  a = new int [n];
return a;
}//1)функци€ инициализации дин.массива
void fill_array (int *a, int n){

    for (int i = 0; i<n;i++){
        // обычный легальный способ a[i] = 10 + rand () % (50 - 10 + 1);
        *(a + i) = 10 + rand () % (50 - 10 + 1); // взаимозамен€емый с верхним только тут а указывает на 0 €чейку и с помощью i перемещаетс€ на другую €чейку пам€ти
    }
}//2)функци€ добавлени€ в массив рандомных чисел
void showArray (int *a, int Size){
    for (int i = 0; i<Size; i++)
        cout << *(a+i) << " ";
    cout << "\n\n";
}//3)функци€ вывода массива
void deleteArray (int *a){
delete [] a;
}// 4) функци€ удаление массива




void showArray_2 (int *a, int *b){
    int i = 0;
    // &a[i];...альтернатива (а+i)
    while(&*(a+i)!= &*b ){

        cout << *(a+i) << " ";
        i++;
    }
    cout << "\n\n";
}//3)альтернативна€ функци€ просмотра элемента массива


void PushBack(int*& a,int& Size, int Value ){
    int* newArray = nullptr;
    newArray = unitArray(newArray, Size + 1);

        for (int i = 0; i < Size; i++){
            newArray[i] = a[i];
        }
    newArray[Size] = Value;
    deleteArray(a);
    a = newArray;
    Size ++;
}// 5) функцци€ добавление нового элемента в конце

void insertArray(int*& a,int& Size, int Value, int index){
    int* newArray = nullptr;
    newArray = unitArray(newArray, Size + 1);

        for (int i = 0; i < index; i++){
            newArray[i] = a[i];
        }

    newArray[index] = Value;
    for (int i = index + 1; i < Size + 1; i++){
            newArray[i] = a[i - 1];
        }
    deleteArray(a);
    a = newArray;
    Size ++;
}// 6) функцци€ добавление элемента по указаному индексу

void DeletesArray(int*& a,int& Size, int Value){
    int* newArray = nullptr;
    newArray = unitArray(newArray, Size - 1);

        for (int i = 0; i < Value; i++){
            newArray[i] = a[i];
        }

    for (int i = Value + 1; i < Size + 1; i++){
            newArray[i] = a[i + 1];
        }
    deleteArray(a);
    a = newArray;
    Size --;
}// 7) удаление добавленного элемента по указаному индексу

bool ProstoChisla (int n){

    for (int i = 2; i<=sqrt(n);i++){
        if(n% i == 0)
            return false;

    }
    return true;
}// 2 zad: функци€ определ€ющиие всех простых чисел
void NotPrimeArray (int*& a, int& Size){
    int m = 0;
    for(int i=0;i<Size;i++){
        if(ProstoChisla(a[i]) == false)
            m++;

    }

    int* newArray = nullptr;
    newArray = unitArray(newArray,m);
    for(int i=0, c = 0;i<Size;i++){
        if(ProstoChisla(a[i]) == false){
            newArray[c] = a[i];
            c++;
        }
    }
    deleteArray(a);
    a = newArray;
    Size = m;

}// 2 zad 1: ‘ункци€ заполн€юща€ исходный массив сложныъ чисел


int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    srand(time(NULL));
    int n=10;
    int *a = nullptr;
    a = unitArray(a,n);
    fill_array(a,n);
    showArray_2(a,&a[n]);
    cout << "Ќовый элемент в массиве : " << endl;
    PushBack(a,n,3);
    showArray(a,n);
    cout << "Ќовый элемент по указанному индексу в массиве" << endl;
    insertArray(a,n,-5,3);
    showArray(a,n);
    cout << "”даление элемента по указанному индексу в массиве" << endl;
    DeletesArray(a,n,7);
    showArray(a,n);
    cout << "”даление простых чисел из массива: " << endl;
    ProstoChisla(n);
    NotPrimeArray(a,n);
    showArray(a,n);
    deleteArray(a);




    return 0;


























    /* const int n=4, m=4;
     int a[n][m];

 int i=0;
int j=0;


    cout << "начальный массив " << endl;

    for ( i=0; i<n;i++){
            for(j=0;j<m;j++){
        a[i][j]= 10 + rand()% (99-10+1);
       cout << a[i][j] << " " ;
    }
    cout << endl;
    }









    /*int Min = a[0][0];
    int Max = a[0][0];
    int Max_x = 0, Max_y =0;
    int Min_x =0, Min_y =0;

    for ( i=0; i<n;i++){
    for(j=0;j<m;j++){
       if(Max < a[i][j]){
        Max = a[i][j];
        Max_x = i;
        Max_y = j;
       }
       if(Min > a[i][j]){
        Min = a[i][j];
        Min_x = i;
        Min_y = j;
       }


        }
    }
    float sred = Max/2;
    int skut = Max/Min;

cout << "“ранспарт. матрица: " << endl;
int b[n][m];
 for ( i=0; i<n;i++){
    for(j=0;j<m;j++){
        b[i][j]=a[j][i];
         cout << b[i][j] << " " ;
    }
    cout << endl;
    }



cout << "минимальный элемент а[" << Min_x << "][" << Min_y << "] = " << Min << endl;
cout << "максимальный элемент а[" << Max_x << "][" << Max_y << "] = " << Max << endl;
cout << "средн€€ €ркость = " << sred << endl;
cout << "средн€€ €ркость2 = " << skut << endl;

    int pixel = 255;
    int pixel2 = 0;
    for ( i=0; i<n;i++){
    for(j=0;j<m;j++){
            if (sred>a[i][j]){
                cout << pixel << " " ;

            }
            if (sred<a[i][j]){
                a[i][j]= pixel2;
                cout << pixel2 << " ";
            }

            }
            cout << endl;
           }





    int sum

    int buff =0; // дл€ хранение переменого значаени€

    for (i=1;i<n;i++) {

        buff = a[i]; // обработка элемента

        for (int c = i-1; c >= 0 && a[c]> buff;c--){

            a[c+1] = a[c];
            a[c] = buff;
        }
    }





    cout << "\nотсортировочный массив " << endl;


     for (int i=0;i<n;i++)
     {
cout <<  a[i] << " " ;
     } */


}
