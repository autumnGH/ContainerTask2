#include <iostream>
#include <cmath>

class Polygon {
protected:
    int* xCoords = new int[100];
    int* yCoords = new int[100];
    int size;

public:
    Polygon() {
        std::cin >> size;
        for (int i = 0; i < size; i++) {
            std::cin >> xCoords[i];
        }
        for (int i = 0; i < size; i++) {
            std::cin >> yCoords[i];
        }
    }

    double calculateArea() {
        double area = 0;

        for (int i = 0; i < size - 1; i++) {
            area += ((xCoords[i] - xCoords[i + 1]) * (yCoords[i] + yCoords[i + 1])) / 2.0;
        }

        area += ((xCoords[size - 1] - xCoords[0]) * (yCoords[size - 1] + yCoords[0])) / 2.0;
        area = std::abs(area);
        return area;
    }

    float calculatePerimeter() {
        double perimeter = 0;

        for (int i = 0; i < size - 1; i++) {
            perimeter += std::sqrt(std::pow((xCoords[i + 1] - xCoords[i]), 2) + std::pow((yCoords[i + 1] - yCoords[i]), 2));
        }

        perimeter += std::sqrt(std::pow((xCoords[size - 1] - xCoords[0]), 2) + std::pow((yCoords[size - 1] - yCoords[0]), 2));

        return perimeter;
    }

    void display() {
        std::cout << "abscissa ";

        for (int i = 0; i < size; i++) {
            std::cout << xCoords[i] << " ";
        }

        std::cout << "ordinata ";

        for (int i = 0; i < size; i++) {
            std::cout << yCoords[i] << " ";
        }

        std::cout << " Perimetr= " << calculatePerimeter() << " Ploshad= " << calculateArea() << std::endl;
    }

    friend bool doPolygonsIntersect(Polygon poly1, Polygon poly2) {
        bool left1 = false, right1 = false, top1 = false, bottom1 = false;
        bool left2 = false, right2 = false, top2 = false, bottom2 = false;
        bool intersection = false;

        for (int i = 0; i < poly1.size; i++) {
            for (int j = 0; j < poly2.size; j++) {
                if (poly1.xCoords[i] < poly2.xCoords[j]){ left1 = true; }

                if (poly1.xCoords[i] > poly2.xCoords[j]){ right1 = true; }

                if (poly1.yCoords[i] > poly2.yCoords[j]){ top1 = true; }

                if (poly1.yCoords[i] < poly2.yCoords[j]){ bottom1 = true; }
            }

            if (left1 && right1 && bottom1 && top1) { intersection = true; }

            left1 = false;
            right1 = false;
            top1 = false;
            bottom1 = false;
        }

        for (int i = 0; i < poly2.size; i++) {
            for (int j = 0; j < poly1.size; j++) {
                if (poly2.xCoords[i] < poly1.xCoords[j]){ left2 = true; }

                if (poly2.xCoords[i] > poly1.xCoords[j]){ right2 = true; }

                if (poly2.yCoords[i] > poly1.yCoords[j]){ top2 = true; }

                if (poly2.yCoords[i] < poly1.yCoords[j]){ bottom2 = true; }
            }

            if (left2 && right2 && bottom2 && top2)
                intersection = true;

            left2 = false;
            right2 = false;
            top2 = false;
            bottom2 = false;
        }

        return intersection;
    }
};

int main() {
    Polygon poly1;
    Polygon poly2;

    std::cout << "Poligon1= ";

    poly1.display();

    std::cout << "Poligon2= ";

    poly2.display();

    bool intersect = doPolygonsIntersect(poly1, poly2);
    if (intersect) {
        std::cout << "Poligon1 peresekaet Poligon2" << std::endl;
    } else {
        std::cout << "Poligon1 ne peresekaet Poligon2" << std::endl;
    }

    return 0;
}
