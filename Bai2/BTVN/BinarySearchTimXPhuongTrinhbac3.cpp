#include <iostream>
#include <cmath>
#include <limits>

// �?nh nghia h�m t�nh gi� tr? c?a phuong tr�nh b?c ba t?i x
double cubicEquationValue(double a, double b, double c, double d, double x) {
    return a * pow(x, 3) + b * pow(x, 2) + c * x + d;
}

// T�m gi� tr? l?n nh?t v� nh? nh?t c?a phuong tr�nh b?c ba trong kho?ng [start, end]
void findExtremesOfCubicEquation(double a, double b, double c, double d, double start, double end, double& minVal, double& maxVal) {
    minVal = std::numeric_limits<double>::infinity();
    maxVal = -std::numeric_limits<double>::infinity();

    for (double x = start; x <= end; x += 0.1) { // �i?u ch?nh bu?c nh?y t�y v�o d? ch�nh x�c mong mu?n
        double val = cubicEquationValue(a, b, c, d, x);
        if (val > maxVal) {
            maxVal = val;
        }
        if (val < minVal) {
            minVal = val;
        }
    }
}

// H�m t�m x?p x? nghi?m b?ng thu?t to�n t�m ki?m nh? ph�n
double approximateCubicSolution(double a, double b, double c, double d, double left, double right, double epsilon) {
    while (fabs(right - left) > epsilon) {
        double mid = (left + right) / 2;
        if (cubicEquationValue(a, b, c, d, mid) == 0) {
            return mid;
        } else if (cubicEquationValue(a, b, c, d, mid) * cubicEquationValue(a, b, c, d, left) < 0) {
            right = mid;
        } else {
            left = mid;
        }
    }
    return (left + right) / 2;
}

int main() {
    // C�i d?t c�c h? s? c?a phuong tr�nh b?c ba: ax^3 + bx^2 + cx + d = 0
    double a = 1;
    double b = 2;
    double c = 3;
    double d = 4;

    // T�m gi� tr? l?n nh?t v� nh? nh?t c?a phuong tr�nh b?c ba trong kho?ng [-10, 10]
    double minVal, maxVal;
    findExtremesOfCubicEquation(a, b, c, d, -10.0, 10.0, minVal, maxVal);

    // S? d?ng gi� tr? l?n nh?t v� nh? nh?t d? x�c d?nh kho?ng ph?m vi t�m nghi?m x?p x?
    double leftBound = minVal;
    double rightBound = maxVal;
    double epsilon = 0.0001;

    // T�m nghi?m x?p x? trong kho?ng d� cho
    double approxSolution = approximateCubicSolution(a, b, c, d, leftBound, rightBound, epsilon);

    std::cout << "Nghi?m x?p x? c?a phuong tr�nh l�: " << approxSolution << std::endl;

    return 0;
}

