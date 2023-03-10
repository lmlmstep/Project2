#include <iostream>
#include <vector>
using namespace std;

class Square;
class Circle;
class Rectangle;

// Абстрактный класс посетитель
class Visitor {
public:
    virtual void visit(Square& square) = 0;
    virtual void visit(Circle& circle) = 0;
    virtual void visit(Rectangle& rectangle) = 0;
};

// Абстрактный класс фигуры
class Shape {
public:
    virtual void accept(Visitor& visitor) = 0;
};

// Конкретные классы фигур
class Square : public Shape {
public:
    Square(double side) : m_side(side) {}

    double area() const { return m_side * m_side; }

    void accept(Visitor& visitor) override {
        visitor.visit(*this);
    }
    double getM_side()
    {
        return m_side;
    }
private:
    double m_side;
};

class Circle : public Shape {
public:
    Circle(double radius) : m_radius(radius) {}

    double area() const { return 3.14159265359 * m_radius * m_radius; }

    void accept(Visitor& visitor) override {
        visitor.visit(*this);
    }
    double getM_radius()
    {
        return m_radius;
    }

private:
    double m_radius;
};

class Rectangle : public Shape {
public:
    Rectangle(double width, double height) : m_width(width), m_height(height) {}

    double area() const { return m_width * m_height; }

    void accept(Visitor& visitor) override {
        visitor.visit(*this);
    }
    double getM_width()
    {
        return m_width;
    }

    double getM_height()
    {
        return m_height;
    }
private:
    double m_width;
    double m_height;
};

// Конкретный класс посетителя, реализующий операцию расчета периметра для каждой фигуры
class PerimeterVisitor : public Visitor {
public:
    void visit(Square& square) override {
        m_perimeter += 4 * square.getM_side();
    }

    void visit(Circle& circle) override {
        m_perimeter += 2 * 3.14159265359 * circle.getM_radius();
    }

    void visit(Rectangle& rectangle) override {
        m_perimeter += 2 * (rectangle.getM_width() + rectangle.getM_height());
    }

    double perimeter() const { return m_perimeter; }

private:
    double m_perimeter = 0.0;
};

class DrawVisitor : public Visitor {
public:
    void visit(Square& square) override {
        for (size_t i = 0; i < square.getM_side(); i++)
        {
            for (size_t i = 0; i < square.getM_side(); i++)
            {
                cout << '*';
            }
            cout << endl;
        }
    }

    void visit(Circle& circle) override {
        cout << "Drawing Circle!\n";
    }

    void visit(Rectangle& rectangle) override {
        for (size_t i = 0; i < rectangle.getM_width(); i++)
        {
            for (size_t i = 0; i < rectangle.getM_height(); i++)
            {
                cout << '*';
            }
            cout << endl;
        }
    }
};


// Пример использования паттерна посетитель
int main() {
    std::vector<Shape*> shapes = { new Square(3), new Circle(2), new Rectangle(4, 5) };

    PerimeterVisitor perimeterVisitor;
    for (auto shape : shapes) {
        shape->accept(perimeterVisitor);
    }

    std::cout << "Total perimeter: " << perimeterVisitor.perimeter() << std::endl;

    DrawVisitor drawVisitor;
    for (auto shape : shapes) {
        shape->accept(drawVisitor);
    }

    // Очистка памяти
    for (auto shape : shapes) {
        delete shape;
    }
}

