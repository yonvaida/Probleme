double factorial(int a) {
	if (a == 0 || a == 1) return 1;
	double factorialTemp = a*factorial(a - 1);
	return factorialTemp;
}
