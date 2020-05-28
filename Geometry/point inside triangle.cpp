#include<iostream>
using namespace std;

struct point{
	float x;
	float y;
};

float area(point a,point b,point c){
	return abs(a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y));
}


int main(){
	point p,t1,t2,t3;
	cin>>p.x>>p.y;
	cin>>t1.x>>t1.y>>t2.x>>t2.y>>t3.x>>t3.y;
	if(area(t1,t2,p)+area(t1,t3,p)+area(t2,t3,p)==area(t1,t2,t3))
		cout<<"1";
	else
		cout<<"0";
	return 0;
}
