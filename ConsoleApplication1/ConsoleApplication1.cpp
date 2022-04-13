#include <iostream>//подлючаем библиотеку iostream

using namespace std;//подключаем пространсво имён std(cout,cin...)

const float pi = 3.14;//создаём константу для pi

void Vconus(int r, int h, float &V, float &S) {//объявили функцию
    V = 0.3 * pi * r * r * h;
    S = pi * r * r;
}

int main()
{
    int r1, r2;
    int h1, h2;
    float V1, V2;
    float S1, S2;

    cout << "r1: ";
    cin >> r1;
    cout << endl << "h1: ";
    cin >> h1;
    cout << endl << "r2: ";
    cin >> r2;
    cout << endl << "h2: ";
    cin >> h2;

    Vconus(r1, h1, V1, S1);
    Vconus(r2, h2, V2, S2);
    
    cout << endl << "V1: " << V1;
    cout << endl << "S1: " << S1<< endl;
    
    cout << endl << "V2: " << V2;
    cout << endl << "S2: " << S2;
    
    return 0;
}
