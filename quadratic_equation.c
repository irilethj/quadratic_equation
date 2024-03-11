#include "quadratic_equation.h"

QuadraticRoots solve_equation(double a, double b, double c) {
  QuadraticRoots roots;
  roots.discriminant = b * b - 4 * a * c;

  if (roots.discriminant < 0) {
    // Поскольку дискриминант меньше нуля, уравнение не имеет решений
    roots.root1 = NAN;
    roots.root2 = NAN;
    roots.one_real_root = NAN;
  } else if (roots.discriminant == 0) {
    // Поскольку дискриминант равен нулю, уравнение имеет один реальный корень
    roots.root1 = NAN;
    roots.root2 = NAN;
    roots.one_real_root = -b / (2 * a);
  } else {
    roots.one_real_root = NAN;
    roots.root1 = (-b + sqrt(roots.discriminant)) / (2 * a);
    roots.root2 = (-b - sqrt(roots.discriminant)) / (2 * a);
  }

  return roots;
}
