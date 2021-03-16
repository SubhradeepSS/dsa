// https://www.codechef.com/SSC72021/problems/MAZE100
/*
You are given a maze which can be represented as 2D matrix, where source block is upper left most block i.e, maze[0][0] and destination block is lower right most block i.e, maze[N-1][N-1]. “0s” are walkable areas and “1s” represent walls. Size of maze is 6*6.

Create a function that prints “Yes” if you can walk from one end of the maze to the other. Else prints “No”.
Each of the 6 lines of inputs maze[N] contains 6 space separated integers array[N][N]

Output Format:
Print “Yes” if you can walk from one end of the maze to the other. Else print “No”.

Sample input:
0 1 1 1 1 1
0 0 0 1 1 1
1 0 0 1 0 0
0 1 0 0 1 1
1 1 1 0 0 0
1 0 0 1 1 0

Sample Output:
Yes

Sample Input:
0 1 0 1 1 1
1 0 0 1 1 1
1 0 0 1 0 0
0 1 0 0 1 1
1 1 1 0 0 1
0 0 0 1 0 1

Sample Output:
No
*/

#include <iostream>
using namespace std;

const int n = 6;

bool valid(int a[][n], int r, int c)
{
    return (
        r >= 0 && c >= 0 && r < n && c < n && a[r][c] == 0);
}

bool backtrack(int a[][n], int i, int j)
{
    if (i == 0 && j == 0 && a[i][j] == 0)
    {
        return true;
    }
    if (!valid(a, i, j))
    {
        return false;
    }
    if (backtrack(a, i - 1, j) || backtrack(a, i, j - 1) || backtrack(a, i - 1, j - 1))
    {
        return true;
    }
    return false;
}

int main()
{
    // your code goes here
    int a[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << (backtrack(a, n - 1, n - 1) ? "Yes" : "No");
    return 0;
}
