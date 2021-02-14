#include <iostream>
#include <math.h>
#include <unordered_map>
using namespace std;

int main()
{
	// your code goes here
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int weight[n], jump[n];
		unordered_map<int, int> pos;

		for (int i = 0; i < n; i++)
		{
			cin >> weight[i];
			pos[weight[i]] = i + 1;
		}

		for (int i = 0; i < n; i++)
			cin >> jump[i];

		int ans = 0;

		for (int i = 2; i <= n; i++)
		{
			int a = pos[i], b = pos[i - 1];
			if (a <= b)
			{
				int inc = ceil(float(b - a + 1) / float(jump[a - 1]));
				ans += inc;
				pos[i] += inc * jump[a - 1];
			}
		}
		cout << ans << endl;
	}
	return 0;
}
