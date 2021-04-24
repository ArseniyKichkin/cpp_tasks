#include <iostream>
#include <vector>

using namespace std;

class Point2D {
protected:
    double _x;
    double _y;

public:
    // Конструктор точки с заданными координатами
    Point2D(double x, double y) : _x(x), _y(y) {
    }

    // Получить координату X точки
    double x() const {
        return _x;
    }

    // Получить координату Y точки
    double y() const {
        return _y;
    }
};

class Polygon {
protected:
    unsigned int numberOfTops;
    vector<Point2D> points;
public:
    // Конструктор, создаёт полигон из набора точек.
    // Точки передаются в порядке обхода полигона по контуру.
    Polygon(vector<Point2D> &points) {
        this->numberOfTops = points.size();
        for (int i = 0; i < numberOfTops; ++i) {
            this->points.push_back(points[i]);
        }
    }

    // Деструктор, если нужен

    // Возвращает площадь полигона
    double area() {
        double square = 0;
        for (int i = 1; i < numberOfTops - 1; ++i) {
            if (((points[i].x() - points[0].x()) * (points[i + 1].y() - points[0].y()) -
                 (points[i + 1].x() - points[0].x()) * (points[i].y() - points[0].y())) >= 0) {
                square +=
                        (points[i].x() - points[0].x()) * (points[i + 1].y() - points[0].y()) -
                        (points[i + 1].x() - points[0].x()) * (points[i].y() - points[0].y());
            } else {
                square +=
                        ((points[i].x() - points[0].x()) * (points[i + 1].y() - points[0].y()) -
                         (points[i + 1].x() - points[0].x()) * (points[i].y() - points[0].y())) * (-1);
            }
        }
        return 0.5 * square;
    }

    // Возвращает количество вершин полигона
    unsigned int size() const{
        return numberOfTops;
    }

    // Возвращает N-ую вершину полигона
    // (вершины нумеруются в том же порядке, в котором были переданы)
    Point2D vertex(unsigned int N) {
        return this->points[N];
    }
};

int main() {
    std::vector<Point2D> points = {{-1.0, -1.0},
                                   {-1.0, 1.0},
                                   {1.0,  1.0},
                                   {1.0,  -1.0}};
    Polygon p(points);
    cout << "Points:" << endl;
    for (unsigned int i = 0; i < p.size(); i++) {
        cout << p.vertex(i).x() << " " << p.vertex(i).y() << endl;
    }
    cout << "Area: " << p.area() << endl;
    return 0;
}

