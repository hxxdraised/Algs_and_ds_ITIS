#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    int numSum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        numSum += a[i];
    }
    cout << numSum << endl;

    return 0;
}