#include "app.h"

/*
  Віріант: 9

  x^(2a) - b
  -------------------
  tg(1 - e^(a+x/b))

  a = -2.01, b = 10.01, x = 12.13

 */

int main()
{
	double a = -2.01;
	double b = 10.01;
	double x = 12.13;

	double numerator = pow(x, 2 * a) - b;

	double exp_arg = (a + x) / b;
	double tan_arg = 1.0 - exp(exp_arg);
	double denominator = tan(tan_arg);

	if (fabs(denominator) < 1e-9) {
		printf("Обчислення неможливе\n");
		return 1;
	}

	double result = numerator / denominator;

	printf("x^(2a) - b\n------------------ = %.10f", result);
	printf("\ntg(1 - e^(a+x/b))");
	printf("\n a = %.2f, b = %.2f, x = %.2f\n", a, b, x);

	return 0;
}