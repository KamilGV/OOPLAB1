// ooplab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <conio.h>


class Point
{
protected:
    int x;
public:
    int y;
    Point() {
        printf("Конструктор точки\n");
        x = 0;
        y = 0;
   }
    Point(int x, int y) {
        printf("Конструктор точки с параметром\n");
        this->x = x;
        this->y = y;
    }
    Point(const Point& p) {
        printf("Конструктор копирования точки \n");
        x = p.x;
        y = p.y;
    }
    ~Point() {
        printf("%d, %d\n", x, y);
        printf("Деструктор точки\n");
    }
    void change(int chx, int chy) {
        x = x + chx;
        y = y + chy;
    }
    void reset();
};



void Point::reset() {
    x = 0;
    y = 0;
}

class Circle: public Point
{
protected:
    int radius;
public:
    Circle() : Point(){
        printf("Конструктор окружности\n");
        radius = 0;
    }
    Circle(int x, int y, int radius):Point(x,y){
        printf("Конструктор окржуности с параметром\n");
        this->radius = radius;
    }
    Circle(const Circle& p) {
        printf("Конструктор копирования окружности\n");
        radius = p.radius;
        x = p.x;
        y = p.y;
    }
    ~Circle() {
        printf("%d, %d, Радус = %d \n", x, y, radius);
        printf("Деструктор окружности\n");
    }
    void change_radius(int new_radius) {
        radius = new_radius;
    }
};

class Rectangle
{
protected:
    Point* p1;
    Point* p2;
public:
    Rectangle() {
        printf("Конструктор треугольника\n");
        p1 = new Point;
        p2 = new Point;
    }
    Rectangle(int x1, int y1, int x2, int y2) {
        printf("Конструктор треугольника с параметром\n");
        p1 = new Point(x1, y1);
        p2 = new Point(x2, y2);
    }
    Rectangle(const Rectangle& s) {
        printf("Конструктор копирования треугольника \n");
        p1 = new Point(*(s.p1));
        p2 = new Point(*(s.p2));
    }
    ~Rectangle() {
        printf("Деструктор треугольника\n");
        delete p1;
        delete p2;
    }
};
int main()
{
    setlocale(LC_ALL, "Russian");
    {
        printf("Статически созданные объкты: \n");
        Point p1;
        Point p2(1, 2);
        Point p3(p2);
    }

    printf("\nДинамически созданные объекты: \n");
    Point* p4 = new Point;
    Point* p5 = new Point(1, 2);
    Point* p6 = new Point(*p5);

    p4->y=5555;  // работает
    //p4->x=11111   - не работает, так как x - private

    delete p4;
    delete p5;
    delete p6;

    printf("\nРабота с методами:\n");
    Point* p7 = new Point(1,2);
    p7->reset();
    p7->change(5, 5);
    delete p7;
    
    printf("\nСоздание объекта класса-наследника\n");
    Circle* c = new Circle(); 
    delete c;

    printf("\nКомпозиция:\n");
    Rectangle* r1 = new Rectangle(1, 2, 3, 4);
    Rectangle* r2 = new Rectangle(*r1);

    delete r1;
    delete r2;
    _getch();
}

