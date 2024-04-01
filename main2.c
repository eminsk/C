// Даное целое число. Произвести цикличесский слвиг этого числа вправо на шест разрядов
#include <iostream>
#include <tuple>
#include <cmath>

std::tuple<int, int, int, int> four_squares(int n) {
    for (int a = 0; a <= std::sqrt(n); a++) {
        for (int b = 0; b <= std::sqrt(n - a * a); b++) {
            for (int c = 0; c <= std::sqrt(n - a * a - b * b); c++) {
                int d = std::sqrt(n - a * a - b * b - c * c);
                if (a * a + b * b + c * c + d * d == n) {
                    return std::make_tuple(a, b, c, d);
                }
            }
        }
    }
    return std::make_tuple(0, 0, 0, 0);
}

int main() {
    int n = 106369249365575352836589875696130383747; // Замените на ваше значение n
    std::tuple<int, int, int, int> result = four_squares(n);
    
    std::cout << "a: " << std::get<0>(result) << std::endl;
    std::cout << "b: " << std::get<1>(result) << std::endl;
    std::cout << "c: " << std::get<2>(result) << std::endl;
    std::cout << "d: " << std::get<3>(result) << std::endl;

    return 0;
}