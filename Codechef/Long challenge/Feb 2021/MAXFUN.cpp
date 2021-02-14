#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	// your code goes here
	long long int t;
	cin >> t;
	while (t--)
	{
		long long int n;
		cin >> n;
		long long int a[n];
		for (long long int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		sort(a, a + n);
		long long int x = a[0], y = a[1], z = a[n - 1];
		cout << max(2 * (z - x), 2 * (z - y)) << endl;
	}
	return 0;
}
