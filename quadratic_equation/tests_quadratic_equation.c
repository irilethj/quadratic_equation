#include <check.h>

#include "quadratic_equation.h"

START_TEST(test_solve_equation_1) {
  QuadraticRoots roots = solve_equation(1.0, -3.0, 2.0);
  ck_assert_double_eq_tol(roots.discriminant, 1.0, 0.00001);
  ck_assert_double_eq_tol(roots.root1, 2.0, 0.00001);
  ck_assert_double_eq_tol(roots.root2, 1.0, 0.00001);
  ck_assert_double_nan(roots.one_real_root);
}
END_TEST

// Когда дискриминант равен 0
START_TEST(test_solve_equation_2) {
  QuadraticRoots roots = solve_equation(1.0, -4.0, 4.0);
  ck_assert_double_eq_tol(roots.discriminant, 0, 0.00001);
  ck_assert_double_eq_tol(roots.one_real_root, 2.0, 0.00001);
  ck_assert_double_nan(roots.root1);
  ck_assert_double_nan(roots.root2);
}
END_TEST

// Когда дискриминант равен 0
START_TEST(test_solve_equation_3) {
  QuadraticRoots roots = solve_equation(1.0, 4.0, 4.0);
  ck_assert_double_eq_tol(roots.discriminant, 0, 0.00001);
  ck_assert_double_eq_tol(roots.one_real_root, -2.0, 0.00001);
  ck_assert_double_nan(roots.root1);
  ck_assert_double_nan(roots.root2);
}
END_TEST

// Когда дискриминант меньше 0
START_TEST(test_solve_equation_4) {
  QuadraticRoots roots = solve_equation(7.8, 8.9, 4.7);
  ck_assert_double_eq_tol(roots.discriminant, -67.43, 0.00001);
  ck_assert_double_nan(roots.root1);
  ck_assert_double_nan(roots.root2);
  ck_assert_double_nan(roots.one_real_root);
}
END_TEST

START_TEST(test_solve_equation_5) {
  QuadraticRoots roots = solve_equation(0.3, 3.4, 2);
  ck_assert_double_eq_tol(roots.discriminant, 9.16, 0.00001);
  ck_assert_double_eq_tol(roots.root1, -0.62241, 0.00001);
  ck_assert_double_eq_tol(roots.root2, -10.71091, 0.00001);
  ck_assert_double_nan(roots.one_real_root);
}
END_TEST

int main() {
  Suite *s1 = suite_create("Core");
  TCase *tc_core = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;
  suite_add_tcase(s1, tc_core);

  tcase_add_test(tc_core, test_solve_equation_1);
  tcase_add_test(tc_core, test_solve_equation_2);
  tcase_add_test(tc_core, test_solve_equation_3);
  tcase_add_test(tc_core, test_solve_equation_4);
  tcase_add_test(tc_core, test_solve_equation_5);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf ? 1 : 0;
}