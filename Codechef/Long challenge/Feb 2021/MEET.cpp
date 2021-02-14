#include <iostream>
using namespace std;

int t_24(string t, string hr)
{
	int h = (t[0] - '0') * 10 + (t[1] - '0');
	int m = (t[3] - '0') * 10 + (t[4] - '0');
	if (hr == "AM")
	{
		if (h == 12)
		{
			return m;
		}
		return h * 100 + m;
	}
	if (h == 12)
	{
		return h * 100 + m;
	}
	return (h + 12) * 100 + m;
}

int main()
{
	// your code goes here
	int t;
	cin >> t;
	while (t--)
	{
		string p, hr;
		cin >> p >> hr;
		int n;
		cin >> n;
		int P = t_24(p, hr);
		while (n--)
		{
			string l, l_hr, r, r_hr;
			cin >> l >> l_hr >> r >> r_hr;
			int L = t_24(l, l_hr), R = t_24(r, r_hr);
			// cout<<endl<<L<<" "<<R<<" "<<P<<" "<<endl;
			if (L <= P && P <= R)
			{
				cout << 1;
			}
			else
			{
				cout << 0;
			}
		}
		cout << endl;
	}
	return 0;
}
