#include<iostream>
#include<algorithm>
using namespace std;

struct point{
	float x;
	float y;
};

// b in between a and c
bool onsegment(point a,point b,point c){
	return (b.x<=max(a.x,c.x)&&b.x>=min(a.x,c.x)&&b.y<=max(a.y,c.y)&&b.y>=min(a.y,c.y));
}

int orientation(point p,point q,point r){
	int val=(q.y-p.y)*(r.x-p.x)-(q.x-p.x)*(r.y-p.y);
	if(val==0)
		return 0;
	return (val>0?1:-1);
}

bool intersect(point p1,point q1,point p2,point q2){
	int o1=orientation(p1,p2,q1);
	int o2=orientation(p1,q2,q1);
	int o3=orientation(p2,q1,q2);
	int o4=orientation(p2,p1,q2);
	if(o1!=o2&&o3!=o4)
		return true;
	if(o1==0&&onsegment(p1,p2,q1))
		return true;
	if(o2==0&&onsegment(p1,q2,q1))
		return true;
	if(o3==0&&onsegment(p2,q1,q2))
		return true;
	if(o4==0&&onsegment(p2,q2,q2))
		return true;
	return false;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		point p1,q1,p2,q2;
		cin>>p1.x>>p1.y>>q1.x>>q1.y>>p2.x>>p2.y>>q2.x>>q2.y;
		intersect(p1,q1,p2,q2)?cout<<"1\n":cout<<"0\n";
		}
	return 0;
}
