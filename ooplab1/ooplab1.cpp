// ooplab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <conio.h>


class point
{
private:
    int x;
    int y;
public:
    point() {
        printf("Конструктор\n");
        x = 0;
        y = 0;
   }
    point(int x, int y) {
        printf("Конструктор с параметром\n");
        this->x = x;
        this->y = y;
    }
    point(const point& p) {
        printf("Конструктор копирования\n");
        x = p.x;
        y = p.y;
    }
    ~point() {
        printf("%d, %d\n", x, y);
        printf("Деструктор\n");
    }

};
int main()
{
    setlocale(LC_ALL, "Russian");
    {
        printf("Статически созданные объкты: \n");
        point p1;
        point p2(1, 2);
        point p3(p2);
    }

    

    _getch();
}

