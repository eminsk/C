// напиши вычисление квадратного уравнения in C

#include <iostream>
#include <cmath>

class QuadraticEquation {
private:
    double a, b, c;

public:
    QuadraticEquation() : a(0), b(0), c(0) {}

    void setCoefficients(double a, double b, double c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    void solveEquation() {
        double discriminant = b * b - 4 * a * c;

        if (discriminant > 0) {
            double x1 = (-b + std::sqrt(discriminant)) / (2 * a);
            double x2 = (-b - std::sqrt(discriminant)) / (2 * a);
            std::cout << "x1 = " << x1 << ", x2 = " << x2 << std::endl;
        } else if (discriminant == 0) {
            double x = -b / (2 * a);
            std::cout << "x1 = x2 = " << x << std::endl;
        } else {
            std::cout << "Not real roots" << std::endl;
        }
    }
};

int main() {
    double a, b, c;
    std::cout << "Enter a, b, c: ";
    std::cin >> a >> b >> c;
    QuadraticEquation equation;
    equation.setCoefficients(a, b, c);
    equation.solveEquation();

    return 0;
}

