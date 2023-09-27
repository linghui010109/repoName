#include <iostream>
using namespace std;

double power(double x, int n)
{
	if (n == 0)
		return 1;
	double p = power(x, n / 2);
	if (n % 2 == 0)
		return p * p;
	else return p * p * x;
}

int main()
{
	double x;
	int n;
	cout << "Please Enter the number and power:" << endl;
	cin >> x >> n;
	cout << power(x, n);
	return 0;
}
