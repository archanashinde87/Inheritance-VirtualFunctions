// InheritanceQuizExample.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

class Shape
{
public:
    virtual std::ostream& print(std::ostream&) const = 0; 
    friend std::ostream& operator<<(std::ostream& out, const Shape& shape)
    {
        return shape.print(out);
    }
    virtual ~Shape() = default;
};

class Point 
{
    int m_x{};
    int m_y{};

public:
    Point(int x=0, int y=0)
        : m_x{ x }, m_y{ y }
    {}

    friend std::ostream& operator<<(std::ostream& out, const Point& p)
    {
        out << "Point(" << p.m_x << ", " << p.m_y << ")";
        return out;
    }
};
class Triangle: public Shape 
{
    Point m_point1{};
    Point m_point2{};
    Point m_point3{};

public:
    Triangle(const Point& p1, const Point& p2, const Point& p3)
        :m_point1{ p1 }, m_point2{ p2 }, m_point3{ p3 }
    {}
    std::ostream& print(std::ostream& out) const override
    {
        out << "Triangle(" << m_point1 << ", " << m_point2 << ", " << m_point3 << ")";
        return out;
    }

};
class Circle : public Shape
{
    Point m_center{};
    int m_radius{};

public:
    Circle(const Point& p1, int radius)
        :m_center{ p1 }, m_radius{ radius }
    {}
    std::ostream& print(std::ostream& out) const override
    {
        out << "Circle(" << m_center << ", "  << "radius " << m_radius << ")";
        return out;
    }

    int getRadius() const { return m_radius; }

};

int getLargestRadius(const std::vector<Shape*>& v)
{
    int largestRadius{ 0 };
    for (const auto* element : v)
    {
       const Circle* c{ dynamic_cast<const Circle*>(element) };
        if (c)
        {
            if(largestRadius<c->getRadius())
                largestRadius = c->getRadius();
        }
    }
    return largestRadius;
}
int main()
{
    Circle c{ Point{ 1, 2 }, 7 };
    std::cout << c << '\n';

    Triangle t{ Point{ 1, 2 }, Point{ 3, 4 }, Point{ 5, 6 } };
    std::cout << t << '\n';

    std::vector<Shape*> v{
      new Circle{Point{ 1, 2 }, 7},
      new Triangle{Point{ 1, 2 }, Point{ 3, 4 }, Point{ 5, 6 }},
      new Circle{Point{ 7, 8 }, 3}
    };

    // print each shape in vector v on its own line here
    for (const auto* element : v)
        std::cout << *element << '\n';

    std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // write this function

    // delete each element in the vector here
    for (const auto* element : v)
        delete element;

    return 0;
}
