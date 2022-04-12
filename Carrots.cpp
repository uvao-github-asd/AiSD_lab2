#include <stdlib.h> 
#include <iostream> 
#include <Windows.h>


struct Node {
    int x;
    Node* Next, * Prev;
};  class List
{
Node* First, * Last; public:
    List() :First(NULL), Last(NULL) {};
    ~List();     
    void Print();
    void insert(int n);
    void Add(int x);
    void del(int y);
    void delnode();
};

List::~List()
{
    while (First)
    {
        Last = First->Next;
        delete First;
        First = Last;
    }
}
void List::Add(int x)
{
    Node* temp = new Node;
    temp->Next = NULL;
    temp->x = x;
    if (First != NULL) {
        temp->Prev = Last;
        Last->Next = temp;
        Last = temp;
    }
    else {
        temp->Prev = NULL;
        First = Last = temp;
    }
}

void List::Print()
{

    Node* temp = First;
    printf("Вывод: ");
    while (temp != NULL)
    {
        printf("%d ", temp->x);
        temp = temp->Next;
    }    
    printf("\n");
}
void List::insert(int n)
{
    Node* tmp = new Node;
    int t = 0;
    Node* temp = First;
    while (temp != NULL)
    {
        if (n < 0) {
            Last->Prev->Next = NULL;
            Last->Next = temp;
            Last->Prev = NULL;
            temp->Prev = Last;
            First = Last;
            n = 0;
        }
        else if (t == n && temp->Next != NULL) {

            Last->Prev->Next = NULL;
            Last->Next = temp->Next;
            temp->Next->Prev = Last;
            temp->Next = Last;
            Last->Prev = temp;
        }          if (temp->Next == NULL) 
            Last = temp;         
            temp = temp->Next;
            t++;
    }

}
void List::del(int y)
{
    bool r = false;
    Node* temp = First;
    while (temp != NULL)
    {
        if (temp->x == y) {
            if (temp->Next == NULL) {
                Last = temp->Prev;
                temp->Prev->Next = NULL;
                free(temp);
            }
            else if (temp->Prev == NULL)
            {
                temp->Next->Prev = NULL;
                First = temp->Next;
                free(temp);
            }
            else {
                temp->Prev->Next = temp->Next;
                temp->Next->Prev = temp->Prev;
                free(temp);
            }             
            r = true;
        }
        if (r == false)temp = temp->Next;
        else temp = NULL;
    }
    if (r == true) 
        printf("%s\n", "True");
    else 
        printf("%s\n", "false");
} 
int main() {
    setlocale(LC_ALL, ("RUS"));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int a, n, y, choice, c = 0;
    List lst;
    printf("Введите элементы в список:\n");
    do {
        scanf_s("%d", &a);        
        lst.Add(a);
    } 
    while ((getchar()) != '\n');     
    do {
        printf("\n1.Вставить элемент в конец списка"            
            "\n2.Вставить элемент перед заданным индексом"
            "\n3.Вставить элемен после заданного индексау"
            "\n4.Удалить элемент по значению"
            "\n5.Печать списка"
            "\n6.Завершить"
            "\n\n Пожалуйста, выберите нужный вариант: ");

        scanf_s("%d", &choice);
        switch (choice) {
        case 1:
            printf("Введите данные-:\t");
            scanf_s("%d", &a);
            lst.Add(a);
            break;
        case 2:

            printf("Введите индекс-:\t");
            scanf_s("%d", &n);
            printf("Введите данные-:\t");
            scanf_s("%d", &a);
            lst.Add(a);
            lst.insert(n - 1);
            break;
        case 3:
            printf("Введите индекс-:\t");
            scanf_s("%d", &n);
            printf("Введите данные-:\t");
            scanf_s("%d", &a);
            lst.Add(a);
            lst.insert(n);
        break;
        case 4:
            printf("Введите ключ:");
            scanf_s("%d", &y);
            lst.del(y);
            break;
        case 5:
            lst.Print();
            break;
        case 6: //
            c = 1;
            break;
        default:
            printf("Недействительный ввод\n");
        }

    } while (c != 1);
}
