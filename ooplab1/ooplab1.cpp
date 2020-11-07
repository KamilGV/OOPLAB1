// ooplab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <conio.h>


class point
{
private:
    int x;
public:
    int y;
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
    void change(int chx, int chy) {
        x = x + chx;
        y = y + chy;
    }
    void reset();
};

void point::reset() {
    x = 0;
    y = 0;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    {
        printf("Статически созданные объкты: \n");
        point p1;
        point p2(1, 2);
        point p3(p2);
    }

    printf("\nДинамически созданные объекты: \n");
    point* p4 = new point;
    point* p5 = new point(1, 2);
    point* p6 = new point(*p5);

    p4->y=5555;  // работает
    //p4->x=11111   - не работает, так как x - private

    delete p4;
    delete p5;
    delete p6;

    printf("\nРабота с методами:\n");
    point* p7 = new point(1,2);
    p7->reset();
    p7->change(5, 5);
    delete p7;
    _getch();
}

