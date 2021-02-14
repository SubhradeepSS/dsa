#include <iostream>
#include <vector>
using namespace std;

int N = 1e6;
vector<bool> prime(N + 1, true);
vector<int> prev_primes(N + 1, 0);

void sieve()
{
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i * i <= N; i++)
    {
        if (prime[i])
        {
            for (int j = i * 2; j <= N; j += i)
            {
                prime[j] = false;
            }
        }
    }
    prev_primes[0] = 0;
    prev_primes[1] = 0;
    for (int i = 2; i <= N; i++)
    {
        prev_primes[i] = prev_primes[i - 1] + prime[i];
    }
}

int main()
{
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sieve();
    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        prev_primes[x] > y ? cout << "Divyam\n" : cout << "Chef\n";
    }
    return 0;
}
