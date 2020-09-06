#include<iostream>
#include<algorithm>
#include <cfloat>
#define inf 10000
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

bool inside(point polygon[],int n,point p){
	if(n<3)
		return false;
	point INF = point{inf,p.y};
	int i=0,next,count=0;
	do{
		next=(i+1)%n;
		if(intersect(p,INF,polygon[i],polygon[next])){
			count++;
			if(orientation(p,polygon[i],polygon[next])==0)
				return onsegment(polygon[i],p,polygon[next]);
		}
		i=next;
	}while(i!=0);
	return count&1;
}

int main(){
	point polygon1[] = {{0, 0}, {10, 0}, {10, 10}, {0, 10}}; 
    int n = sizeof(polygon1)/sizeof(polygon1[0]); 
    point p = {20, 20}; 
    inside(polygon1, n, p)? cout << "Yes \n": cout << "No \n"; 
  
    p = {5, 5}; 
    inside(polygon1, n, p)? cout << "Yes \n": cout << "No \n"; 
  
    point polygon2[] = {{0, 0}, {5, 5}, {5, 0}}; 
    p = {3, 3}; 
    n = sizeof(polygon2)/sizeof(polygon2[0]); 
    inside(polygon2, n, p)? cout << "Yes \n": cout << "No \n"; 
  
    p = {5, 1}; 
    inside(polygon2, n, p)? cout << "Yes \n": cout << "No \n"; 
  
    p = {8, 1}; 
    inside(polygon2, n, p)? cout << "Yes \n": cout << "No \n"; 
  
    point polygon3[] =  {{0, 0}, {10, 0}, {10, 10}, {0, 10}}; 
    p = {-1,10}; 
    n = sizeof(polygon3)/sizeof(polygon3[0]); 
    inside(polygon3, n, p)? cout << "Yes \n": cout << "No \n"; 
  
    return 0; 
}
