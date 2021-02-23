#include <iostream>
using namespace std;

int power(int x, int p)
{
	if (p == 0)
		return 1;
	if (p % 2 == 1)
		return power(x, p - 1) * x;
	else
	{
		int b = power(x, p / 2);
		return b * b;
	}
}

int main()
{
	int x, p;
	cout << "Число: ";
	cin >> x;
	cout << "Степень: ";
	cin >> p;
	cout << power(x, p) << endl;

	return 0;
}