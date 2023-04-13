#include <stdio.h>
#include <string.h>
#define p printf
#define s scanf
#define MAX 100

char queue[MAX];
int front = -1, rear = -1;

void enqueue_front(char ch)
{
    if (front == 0)
    {
        p("\nCola llena (Frente)!\n");
        return;
    }
    else if (front == -1)
    {
        front = rear = 0;
        queue[front] = ch;
    }
    else
    {
        front--;
        queue[front] = ch;
    }
}

void enqueue_rear(char ch)
{
    if (rear == MAX - 1)
    {
        p("\nCola llena (Trasero)!\n");
        return;
    }
    else if (rear == -1)
    {
        front = rear = 0;
        queue[rear] = ch;
    }
    else
    {
        rear++;
        queue[rear] = ch;
    }
}

char dequeue_front()
{
    if (front == -1)
    {
        p("\nCola vacia (Frente)!\n");
        return '\0';
    }
    else
    {
        char ch = queue[front];
        if (front == rear)
            front = rear = -1;
        else
            front++;
        return ch;
    }
}

char dequeue_rear()
{
    if (rear == -1)
    {
        p("\nCola vacia (Trasero)!\n");
        return '\0';
    }
    else
    {
        char ch = queue[rear];
        if (front == rear)
            front = rear = -1;
        else
            rear--;
        return ch;
    }
}

int is_palindrome(char str[])
{
    int len = strlen(str);
    int i = 0;
    for (i = 0; i < len; i++)
    {
        enqueue_rear(str[i]);
    }
    while (front != rear && front < rear)
    {
        if (dequeue_front() != dequeue_rear())
            return 0;
    }
    return 1;
}

int main()
{
    char str[MAX];
    p("Bienvenido al Revisor de Palabras");
    p("\n\nIngrese una palabra: ");
    s("%s", str);
    if (is_palindrome(str))
        p("\nLa palabra '%s' es un palindromo!!\n", str);
    else
        p("\nLa palabra '%s' no es un palindromo!!\n", str);
    return 0;
}