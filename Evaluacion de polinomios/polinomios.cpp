#include "polinomio.hpp"
#include <cmath>

double eval_standard(const vector<double>& a, double x) {
    const size_t n = a.size() - 1;
    double sum = 0.0;
    for (size_t i = 0; i <= n; ++i) {
        // término a[i] * x^i
        sum += a[i] * pow(x, static_cast<double>(i));
    }
    return sum;
}

double eval_horner(const vector<double>& a, double x) {
    const size_t n = a.size() - 1;
    double result = a[n];
    for (size_t i = n; i-- > 0; ) {
        result = result * x + a[i];
    }
    return result;
}
