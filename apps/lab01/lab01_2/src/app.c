#include "app.h"

/*
  Віріант: 9
 
  x^(2a) - b
  -------------------
  tg(1 - e^(a+x/b))
 
  - b != 0
  - tg(1 - e^(a+x/b)) != 0
  - x > 0

 */

int main()
{
	double a, b, x;

	printf("Enter a, b, x: ");

	int ret = scanf("%lf %lf %lf", &a, &b, &x);

	if (ret != 3)
	{
		printf("Error! Cannot read 3 arguments but only %d\n", ret);
		return -1;
	}

	printf("\n");

	if (b == 0.0) {
		printf("Error: Variable b cannot be zero\n");
		return 1;
	}

	if (x <= 0.0) {
		printf("Error: Variable x must be positive\n");
		return 1;
	}


	double numerator = pow(x, 2 * a) - b;

	double exp_arg = (a + x) / b;
	double tan_arg = 1.0 - exp(exp_arg);
	double denominator = tan(tan_arg);

	if (fabs(denominator) < 1e-9)
	{
		printf("Error\n", denominator);
		return 1;
	}

	double result = numerator / denominator;

	printf("x^(2a) - b\n----------------- = %.10f", result);
	printf("\ntg(1 - e^(a+x/b))");

	printf("\n a = %.2f, b = %.2f, x = %.2f\n", a, b, x);

	return 0;
}