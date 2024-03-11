#ifndef QUADRATIC_EQUATION_H
#define QUADRATIC_EQUATION_H

#include <math.h>
#include <stdio.h>

// Структура для хранения корней квадратного уравнения
typedef struct {
  double one_real_root;
  double root1;
  double root2;
  double discriminant;
} QuadraticRoots;

// Функция для решения квадратного уравнения
QuadraticRoots solve_equation(double a, double b, double c);

#endif  // QUADRATIC_EQUATION