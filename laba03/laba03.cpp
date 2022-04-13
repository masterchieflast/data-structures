#include <iostream>
#include <string>
#include <fstream>
#include "windows.h"

using namespace std;

struct Node {
    char word[40];
    int count;
    Node* next; // ссылка на следующий узел
};
typedef Node* PNode;

PNode CreateNode(char NewWord[])
{
    PNode NewNode = new Node; // указатель на новый узел
    strcpy_s(NewNode->word, NewWord); // записать слово
    NewNode->count = 1; // счетчик слов = 1
    NewNode->next = NULL; // следующего узла нет
    return NewNode; // результат функции – адрес узла
}

PNode Find(PNode Head, char NewWord[])
{
    PNode q = Head;
    while (q && strcmp(q->word, NewWord))
        q = q->next;
    return q;
}

void AddFirst(PNode& Head, PNode NewNode)
{
    NewNode->next = Head;
    Head = NewNode;
}

void AddAfter(PNode p, PNode NewNode)
{
    NewNode->next = p->next;
    p->next = NewNode;
}

void AddBefore(PNode& Head, PNode p, PNode NewNode)
{
    PNode q = Head;
    if (Head == p) {
        AddFirst(Head, NewNode); // вставка перед первым узлом
        return;
    }
    while (q && q->next != p) // ищем узел, за которым следует p
        q = q->next;
    if (q) // если нашли такой узел,
        AddAfter(q, NewNode); // добавить новый после него
}

void AddLast(PNode& Head, PNode NewNode)
{
    PNode q = Head;
    if (Head == NULL) { // если список пуст,
        AddFirst(Head, NewNode); // вставляем первый элемент
        return;
    }
    while (q->next) q = q->next; // ищем последний элемент
    AddAfter(q, NewNode);
}

void PrintNode(Node* b) {
    Node* print = b;
    while (print != NULL) {
        cout << print->word << endl;
        print = print->next;
    }
}

void PrintNodeKey(Node* b) {
    Node* print = b;
    while (print != NULL) {
        cout << print->word << " " << print->count << endl;
        print = print->next;
    }
}

void DeleteNode(PNode& Head, PNode OldNode)
{
    PNode q = Head;
    if (Head == OldNode)
        Head = OldNode->next; // удаляем первый элемент
    else {
        while (q && q->next != OldNode) // ищем элемент
            q = q->next;
        if (q == NULL) return; // если не нашли, выход
        q->next = OldNode->next;
    }
    delete OldNode; // освобождаем память
}

void ClearNode(PNode& Head) {
    while (Head)
    {
        Node* next = Head->next;
        delete Head;
        Head = next;
    }
}

struct Birthday {
    int day;
    int mounth;
    int year;
};

struct PeopleJobInfo {
    char LastName[50];
    char JobTitle[50];
    int salary = 0;
    Birthday birthday;
    PeopleJobInfo* next;
};

void AddFirst(PeopleJobInfo*& Head, PeopleJobInfo* NewNode)
{
    NewNode->next = Head;
    Head = NewNode;
}

void AddAfter(PeopleJobInfo* p, PeopleJobInfo* NewNode)
{
    NewNode->next = p->next;
    p->next = NewNode;
}

PeopleJobInfo* CreateJobNode(char NewLastName[], char NewJobTitle[], int NewSalary, int Day, int Mounth, int Year)
{
    PeopleJobInfo* NewNode = new PeopleJobInfo; // указатель на новый узел
    strcpy_s(NewNode->LastName, NewLastName);
    strcpy_s(NewNode->JobTitle, NewJobTitle);
    NewNode->salary = NewSalary;
    NewNode->birthday.day = Day;
    NewNode->birthday.mounth = Mounth;
    NewNode->birthday.year = Year;
    NewNode->next = NULL; // следующего узла нет
    return NewNode; // результат функции – адрес узла
}

void AddFirstJOB(PeopleJobInfo*& Head, PeopleJobInfo* NewNode)
{
    PeopleJobInfo* q = Head;
    if (Head == NULL) { // если список пуст,
        AddFirst(Head, NewNode); // вставляем первый элемент
        return;
    }
    while (q->next) q = q->next; // ищем последний элемент
    AddAfter(q, NewNode);
}

PeopleJobInfo* FindLastName(PeopleJobInfo*& Head, char NewLastName[])
{
    PeopleJobInfo* q = Head;
    while (q && strcmp(q->LastName, NewLastName))
        q = q->next;
    return q;
}

PeopleJobInfo* FindJobTitle(PeopleJobInfo*& Head, char NewJobTitle[])
{
    PeopleJobInfo* q = Head;
    while (q && strcmp(q->JobTitle, NewJobTitle))
        q = q->next;
    return q;
}

PeopleJobInfo* FindJobsalary(PeopleJobInfo*& Head, int Newsalary)
{
    PeopleJobInfo* q = Head;
    while (q && q->salary != Newsalary)
        q = q->next;
    return q;
}

PeopleJobInfo* Findyear(PeopleJobInfo*& Head, int Newyear)
{
    PeopleJobInfo* q = Head;
    while (q && q->birthday.year != Newyear)
        q = q->next;
    return q;
}

PNode Head = NULL, p, where;
PeopleJobInfo* HeadJ = NULL, * pJ, * whereJ;

int main()
{
    int select, key = 1, len = 0, len1 = 0, lenz;
    system("cls");
    fstream in;
    ofstream fout("study.txt", ios_base::app);

    while (true)
    {
        int sum = 0, i1;
        char x[50], LastName[50],z, s[50], s2[50];
        char JobTitle[50];
        int salary = 0, day, mounth, year;
        bool flag = false;
        cout << "********************************************\n"
            << "********************************************\n"
            << "** 1) добавить элемент в начало           **\n"
            << "** 2) добавить элемент в конец            **\n"
            << "** 3) вывести элементы списка в консоль   **\n"
            << "** 4) найти элемент по заданному значению **\n"
            << "** 5) удалить заданный элемент            **\n"
            << "** 6) удалить n элементов                 **\n"
            << "** 7) очистить список                     **\n"
            << "** 8) поиска людей старше 40 лет          **\n"
            << "** 9) подсчета среднего возраста          **\n"
            << "** 10) подсчета суммарной зарплаты        **\n"
            << "** 11) выход                              **\n"
            << "** 12) добавить узел в структуру JOB      **\n"
            << "** 13) Поиск по элементам                 **\n"
            << "** 14) записать структуру в файл          **\n"
            << "** 15) взять значение из файла            **\n"
            << "** Denis Drugakov                         **\n"
            << "********************************************\n"
            << "********************************************\n";
        cin >> select;
        system("cls");

        switch (select)
        {
        case 1:
            cin >> x;
            p = CreateNode(x);
            p->count = key;
            key++;
            len++;
            AddFirst(Head, p);
            system("cls");
            break;

        case 2:
            cin >> x;
            p = CreateNode(x);
            p->count = key;
            key++;
            len++;
            AddLast(Head, p);
            system("cls");
            break;
        
        case 3:
            PrintNode(Head);
            system("PAUSE");
            system("cls");
            break;

        case 4:
            cin >> x;
            p = Find(Head, x);
            if (p == NULL)
                cout << "узла с таким значение нет\n";
            else
                cout << "узел с значение " << x << " имеется в списке, его ключ " << p->count << "\n";
            system("PAUSE");
            system("cls");
            break;

        case 5:
            PrintNodeKey(Head);
            cin >> x;
            p = Find(Head, x);
            if (p == NULL)
                cout << "узла с таким значение нет\n";
            else {
                DeleteNode(Head, p);
                len--;
            }
            system("cls");
            break;

        case 6:
            int n;
            PrintNodeKey(Head);
            cout << "количество элементов которые надо удалить и значение элемента с каторого начать удалять\n";
            cin >> n >> x;
            p = Find(Head, x);

            for (int i = 0; i < n; i++) {
                //Node* p1;
                where = p->next;
                DeleteNode(Head, p);
                p = where;
                len--;
            }

            system("cls");
            break;

        case 7:
            ClearNode(Head);
            break;

        case 8:
            pJ = HeadJ;
            for (int i = 0; i < len1; i++) {
                whereJ = pJ;
                if (2022 - whereJ->birthday.year > 40) {
                    cout << whereJ->LastName << " Старше 40 лет\n";
                }
                pJ = pJ->next;
            }
            system("PAUSE");
            system("cls");
            break;

        case 9:
            sum = 0;
            pJ = HeadJ;
            for (int i = 0; i < len1; i++) {
                whereJ = pJ->next;
                sum += 2022 - pJ->birthday.year;
                pJ = whereJ;
            }
            cout << "Средний возраст " << sum / len1 << "\n";
            system("PAUSE");
            system("cls");
            break;

        case 10:
            sum = 0;
            pJ = HeadJ;
            for (int i = 0; i < len1; i++) {
                whereJ = pJ->next;
                sum += pJ->salary;
                pJ = whereJ;
            }
            cout << "Сумма зарплаты " << sum << "\n";
            system("PAUSE");
            system("cls");
            break;


        case 11:
            cout << "завершение";
            for (int i = 0; i < 15; i++) {
                cout << '.';
                Sleep(500);
            }
            cout << "\n";
            flag = true;
            break;
        
        case 12:
            cout << "Фамилия, название работы, зарплата, день, месяц, год рождения\n";
            cin >> LastName >> JobTitle >> salary >> day >> mounth >> year;
            pJ = CreateJobNode(LastName, JobTitle, salary, day, mounth, year);
            AddFirstJOB(HeadJ, pJ);
            len1++;
            system("cls");
            cout << "Записать результаты в файл ? Y / N\n";
            cin >> z;
            if (z == 'Y') {
                fout.open("study.txt", ios_base::app); // открываем файл для добавления информации к концу файла
                    fout << pJ->LastName << ' ' << pJ->JobTitle << ' ' << pJ->salary << ' ' << pJ->birthday.day << ' ' << pJ->birthday.mounth << ' ' << pJ->birthday.year << endl;
                fout.close(); // закрываем файл
            }
            system("cls");
            break;

        case 13:
            cout << "********************************************\n"
                << "********************************************\n"
                << "** 1) Поиск по Фамилии                    **\n"
                << "** 2) Поиск по названию работы            **\n"
                << "** 3) Поиск по зарплате                   **\n"
                << "** 4) Поиск по году рождения              **\n"
                << "** Denis Drugakov                         **\n"
                << "********************************************\n"
                << "********************************************\n";
            cin >> select;
            system("cls");
            
            switch (select)
            {
            case 1:
                cin >> x;
                pJ = FindLastName(HeadJ, x);
                if (pJ == NULL)
                    cout << "узла с таким значение нет\n";
                else {
                    cout << pJ->LastName << " " << pJ->JobTitle << " " << pJ->salary << " " << pJ->birthday.year << endl;
                    while (pJ != NULL)
                    {
                        if (FindLastName(pJ->next, x) != NULL) {
                            pJ = pJ->next;
                        }
                        else
                            break;
                        pJ = FindLastName(pJ, x);
                        cout << pJ->LastName << " " << pJ->JobTitle << " " << pJ->salary << " " << pJ->birthday.year << endl;
                    }
                }
                system("PAUSE");
                system("cls");
                break;

            case 2:
                cin >> x;
                pJ = FindJobTitle(HeadJ, x);
                if (pJ == NULL)
                    cout << "узла с таким значение нет\n";
                else {
                    cout << pJ->LastName << " " << pJ->JobTitle << " " << pJ->salary << " " << pJ->birthday.year << endl;
                    while (pJ != NULL)
                    {
                        if (FindJobTitle(pJ->next, x) != NULL) {
                            pJ = pJ->next;
                        }
                        else
                            break;
                        pJ = FindJobTitle(pJ, x);
                        cout << pJ->LastName << " " << pJ->JobTitle << " " << pJ->salary << " " << pJ->birthday.year << endl;
                    }
                }
                system("PAUSE");
                system("cls");
                
            case 3:
                cin >> salary;
                pJ = FindJobsalary(HeadJ, salary);
                if (pJ == NULL)
                    cout << "узла с таким значение нет\n";
                else {
                    cout << pJ->LastName << " " << pJ->JobTitle << " " << pJ->salary << " " << pJ->birthday.year << endl;
                    while (pJ != NULL)
                    {
                        if (FindJobsalary(pJ->next, salary) != NULL) {
                            pJ = pJ->next;
                        }
                        else
                            break;
                        pJ = FindJobsalary(pJ, salary);
                        cout << pJ->LastName << " " << pJ->JobTitle << " " << pJ->salary << " " << pJ->birthday.year << endl;
                    }
                }
                system("PAUSE");
                system("cls");
                break;

            case 4:
                cin >> salary;
                pJ = Findyear(HeadJ, salary);
                if (pJ == NULL)
                    cout << "узла с таким значение нет\n";
                else {
                    cout << pJ->LastName << " " << pJ->JobTitle << " " << pJ->salary << " " << pJ->birthday.year << endl;
                    while (pJ != NULL)
                    {
                        if (Findyear(pJ->next, salary) != NULL) {
                            pJ = pJ->next;
                        }
                        else
                            break;
                        pJ = Findyear(pJ, salary);
                        cout << pJ->LastName << " " << pJ->JobTitle << " " << pJ->salary << " " << pJ->birthday.year << endl;
                    }
                }
                system("PAUSE");
                system("cls");
                break;
      
           
            default:
                cout << "Такого пунка нет";
                break;
            }
            break;

             case 14:
                 fout.open("study.txt", ios_base::out); // открываем файл для добавления информации к концу файла

                 whereJ = HeadJ;
                 for (int i = 0; i < len1; i++) {
                     fout << whereJ->LastName << ' ' << whereJ->JobTitle << ' ' << whereJ->salary << ' ' << whereJ->birthday.day << ' ' << whereJ->birthday.mounth << ' ' << whereJ->birthday.year << endl;
                     whereJ = whereJ->next;
                 }

                 fout.close(); // закрываем файл
                 break;
             case 15:
                 in.open("study.txt");
                 while (!in.eof()) {
                     in >> LastName;
                     in >> JobTitle;
                     in >> salary;
                     in >> day;
                     in >> mounth;
                     in >> year;

                     pJ = CreateJobNode(LastName, JobTitle, salary, day, mounth, year);
                     AddFirstJOB(HeadJ, pJ);
                     len1++;
                 }
                 in.close();
                 break;
        default:
            system("cls");
            break;
        }

        if (flag)
            break;
    }

}