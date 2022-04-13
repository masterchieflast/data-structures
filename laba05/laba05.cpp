#include "Header.h"

using namespace JobStructur;

job* arr = new job;

int main()
{
    int select, len = 0;
    bool Exit = true;

    while (Exit)
    {
        system("cls");
        cout << "0)выход\n"
            << "1)добавить в массив\n"
            << "2)вывести весь массив\n"
            << "3)меню работы с файлами\n"
            << "4)удаление\n"//laba06
            << "5)изменение\n"//laba06
            << "6)меню сортировки\n"//laba07
            << "7)поиск подстрок\n"//laba08
            << "8)меню поиска\n";//laba09

        cin >> select;
        system("cls");
        switch (select)
        {
        case 0:
            Exit = false;
            break;
        case 1:
            Add(arr, len);
            break;
        case 2:
            Print(arr, len);
            break;
        case 3:
            filePrint(arr, len);
            break;
        case 4:
            Delete(arr, len);
            break;
        case 5:
            Change(arr, len);
            break;
        case 6:
            Sort(arr, len);
            break;
        case 7:
            FindStr(arr, len);
            break;
        default:
            break;
        }
    }
}
