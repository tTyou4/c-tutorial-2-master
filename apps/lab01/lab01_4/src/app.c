#include "app.h"

/*
  Віріант: 9
 
  x^(2a) - b
  -----------------
  tg(1 - e^(a+x/b))
 
  - b != 0
  - tg != 0
  - x > 0
 
 */

#define NUMERATOR(x, a, b) (pow((x), 2 * (a)) - (b))

#define EXP_ARG(a, x, b) (((a) + (x)) / (b))

#define DENOMINATOR(a, x, b) (tan(1.0 - exp(EXP_ARG(a, x, b))))

#define EXPR(x, a, b) (NUMERATOR(x, a, b) / DENOMINATOR(a, x, b))


int main()
{
	double a, b, x;

	printf("Enter a, b, x: ");

	int ret = scanf("%lf %lf %lf", &a, &b, &x);

	if (ret != 3)
	{
		printf("Error: Cannot read 3 arguments but only %d\n", ret);
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

	double result;

	double denominator_value = DENOMINATOR(a, x, b);

	if (fabs(denominator_value) < 1e-9)
	{
		printf("Error\n", denominator_value);
		return 1;
	}

	result = NUMERATOR(x, a, b) / denominator_value;

	printf("x^(2a) - b\n------------------- = %.10f", result);
	printf("\ntg(1 - e^((a+x)/b))");

	printf("\nПри a = %.2f, b = %.2f, x = %.2f\n", a, b, x);

	return 0;
}