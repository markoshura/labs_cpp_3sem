#include <stdlib.h>
#include <time.h>
#include <stdio.h>

struct Node       //Структура являющаяся звеном списка
{
    int x;
    int y;    //Значение x будет передаваться в список
    struct Node *next,*prev; //Указатели на адреса следующего и предыдущего элементов списка
} typedef Node;


struct List   //Создаем тип данных Список
{
    Node *head;
    Node *tail;  //Указатели на адреса начала списка и его конца
} typedef List;


void add( List *list, int x, int y )
{
    Node *temp = new Node(); // Выделение памяти под новый элемент структуры
    temp->next = NULL;       // Указываем, что изначально по следующему адресу пусто
    temp->x = x;
    temp->y = y;            // Записываем значение в структуру

    if ( list->head != NULL ) // Если список не пуст
    {
        temp->prev = list->tail; // Указываем адрес на предыдущий элемент в соотв. поле
        list->tail->next = temp; // Указываем адрес следующего за хвостом элемента
        list->tail = temp;       //Меняем адрес хвоста
    }
    else //Если список пустой
    {
        temp->prev = NULL; // Предыдущий элемент указывает в пустоту
        list->head = list->tail = temp;    // Голова=Хвост=тот элемент, что сейчас добавили
    }
}

void print( List * list )
{
    Node * temp = list->head;  // Временно указываем на адрес первого элемента
    while( temp != NULL )      // Пока не встретим пустое значение
    {
        printf("(%d,%d) ", temp->x, temp->y); //Выводим значение на экран
        temp = temp->next;     //Смена адреса на адрес следующего элемента
    }
    printf("\n");
}

void make(List *list, int n) {
    int i, x, y;
    for(i = 0; i < n; i++) {
        x = rand()%10;
        y = rand()%10;
        add(list, x, y);
    }
}

Node * first_search (List *list, int x, int y) {
    Node *temp = list->head;
    while(temp->next != NULL){
        if (temp->x == x & temp->y == y){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void past(List *list, int k, int x, int y) {
    int i;
    Node *temp = list->head;
    for (i = 0; i < k - 2; i++) temp = temp->next;
    Node *temp1 = new Node();
    temp1->x = x;
    temp1->y = y;
    temp1->next = temp->next;
    temp1->prev = temp;
    temp->next->prev = temp1;
    temp->next = temp1;
}
void delet(List *list, int k) {
    int i;
    Node *temp = list->head;
    for (i = 0; i < k - 1; i++) temp = temp->next;
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
}

int
main(void)
{
    List *list =new List();
    list->head = list->tail = NULL;
    //randomize();
    time_t t;
    srand((unsigned) time(&t));
    make(list, 5);

    print(list);
    past(list, 4, 5, 10);
    print(list);
    delet(list,2);
    print(list);
    Node *first = new Node();
    first = first_search(list, 5,10);
    printf("%d %d", first->next->x, first->next->y);
    return 0;
}
