/* You are given points on the 2D plane and you are given 2 Bombs. You can drop these bombs at coordinates A and B. Each point on the 2D plane is represented by where and

are integers.

Being an expert Bomber you want to cover all the points with the two bombs given to you.

If a bomb with radius
is droped at any point (), all points You can control the radius of each Bomb. Now since you are a strategic bombing expert you would like to minimize the sum of squared radius of the two bombs. Meaning if Bomb at destination A has a radius R1 and Bomb at destination B has a radius R2. Then you want to minimize (

).

Input Format

N AX AY BX BY

P1X P1Y

P2X P2Y

P3X P3Y

.


PNX PNY

Constraints

2 ≤ N ≤ 106

1 ≤ X, Y ≤ 109

Output Format

Single line which is the minimum possible value of (R1^2 + R2^2). */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int ll;

struct point{
    int x;
    int y;
};

point A,B;

ll dist(point a,point b){
    int X=a.x-b.x,Y=a.y-b.y;
    return X*X+Y*Y;
}

bool cmp(point p1,point p2){
   return dist(p1,A)<dist(p2,A); 
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n>>A.x>>A.y>>B.x>>B.y;
    point Points[n];
    for(int i=0;i<n;i++)
        cin>>Points[i].x>>Points[i].y;
    sort(Points,Points+n,cmp);
    
    ll ans=dist(Points[n-1],A),R_B=0;
    for(int i=n-2;i>=0;i--){
        ans=min(ans,dist(Points[i],A)+R_B);
        R_B=max(R_B,dist(B,Points[i]));
    }
    cout<<ans;
    return 0;
}
