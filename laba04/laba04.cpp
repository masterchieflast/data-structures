#include <iostream>
#include <string>

using namespace std;

struct stock {
    string name;
    float value;
    int index;
};

stock* AddStock(stock *a, int &n, int &index) {
    string name;
    float value;
    cout << "Введите:\n"
         << "имя:\n";
    cin >> name;
    cout << "цена:\n";
    cin >> value;
    stock* b = new stock[n + 1];

    for (int i = 0; i < n; i++) {
        b[i].name = a[i].name;
        b[i].value = a[i].value;
        b[i].index= a[i].index;
    }

    b[n].name = name;
    b[n].value = value;
    b[n].index = index;
    index++;
    n++;

    return b;
}

void ShowStock(stock* a, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Имя: " << a[i].name << "\n";   
        cout << "Цена: " << a[i].value << "\n";
        cout << "Индекс: " << a[i].index << "\n\n";
    }

    system("pause");
}

void FindIndex(stock* a, int n, int index) {
    bool fg = true;
    for (int i = 0; i < n; i++) {
        if (a[i].index == index) {
            fg = false;
            cout << "name: " << a[i].name << "\n"
                << "value: " << a[i].value << "\n";
            system("pause");
            break;
        }
    }

    if (fg) {
        cout << "нету элемента с таким индексом";
    }
}

stock* arr = new stock;

int main()
{

    int index = 0, l = 0;

    int select;
    while (true) {
        bool fg = false;
        int inx;
        system("cls");
        cout << "0.выход\n"
            << "1. добавить в массив ещё одну акцию\n"
            << "2. вывести все акции\n"
            << "3. поиск по индексу\n";
        
        cin >> select;

        system("cls");
        switch (select)
        {
        case 0:
            fg = true;
            break;

        case 1:
            arr = AddStock(arr, l, index);
            break;
        
        case 2:
            ShowStock(arr, l);
            break;
        case 3:
            cin >> inx;
            FindIndex(arr,l , inx);
            break;
        default:
            break;
        }

        system("cls");
        if (fg) break;
    }
}
