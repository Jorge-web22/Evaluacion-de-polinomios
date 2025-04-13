#ifndef POLINOMIO_HPP_INCLUDED
#define POLINOMIO_HPP_INCLUDED

#include <vector>

using namespace std;

// Evalúa P(x) con el método estandar
double eval_standard(const vector<double>& a, double x);

// Evalúa P(x) con el metodo de Horner:
double eval_horner(const vector<double>& a, double x);

#endif // POLINOMIO_HPP_INCLUDED
