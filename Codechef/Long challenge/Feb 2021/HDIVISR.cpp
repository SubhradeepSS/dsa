#include <iostream>
using namespace std;

int div(int n)
{
    for (int i = 10; i >= 1; i--)
    {
        if (n % i == 0)
        {
            return i;
        }
    }
    return 1;
}

int main()
{
    // your code goes here
    int n;
    cin >> n;
    cout << div(n);
    return 0;
}
