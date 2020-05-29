// Jarvis' algorithm
#include<iostream>
#include <vector>

using namespace std;

struct point{
	float x;
	float y;
};

int orientation(point p,point q,point r){
	int val=(q.y-p.y)*(r.x-p.x)-(q.x-p.x)*(r.y-p.y);
	if(val==0)
		return 0;
	return (val>0?1:-1);
}

void hull(point points[],int n){
	if(n<3)
		return;
	vector<point> hull;
	int l=0;
	for(int i=1;i<n;i++)
	{
		if(points[i].x<points[l].x)
			l=i;
	}
	int p=l,next;
	do{
		hull.push_back(points[p]);
		next=(p+1)%n;
		for(int i=0;i<n;i++){
			if(orientation(points[p],points[i],points[next])==1)
				next=i;
		}
		p=next;
	}while(p!=l);
	for(int i=0;i<hull.size();i++)
		cout<<hull[i].x<<" "<<hull[i].y<<endl;
}

int main(){
	point points[] = {{0, 3}, {2, 2}, {1, 1}, {2, 1}, 
                      {3, 0}, {0, 0}, {3, 3}}; 
    int n = sizeof(points)/sizeof(points[0]); 
    hull(points, n); 
    return 0; 
}

// Graham scan
#include<iostream>
#include<stdlib.h>
#include <stack>

using namespace std;

struct point{
	float x;
	float y;
};

float dist(point a,point b){
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

int orientation(point p,point q,point r){
	int val=(q.y-p.y)*(r.x-p.x)-(q.x-p.x)*(r.y-p.y);
	if(val==0)
		return 0;
	return (val>0?1:2);
}

void swap(point &p1,point &p2){
	point t=p1;
	p1=p2;
	p2=t;
}

point nextToTop(stack<point> &st){
	point t=st.top();
	st.pop();
	point a=st.top();
	st.push(t);
	return a;
}

point p0;
int compare(const void *v1,const void *v2){
	point *p1=(point *)v1;
	point *p2=(point *)v2;
	if(orientation(p0,*p1,*p2)==0){
		return (dist(p0,*p1)>=dist(p0,*p2)?1:-1);
	}
	return (orientation(p0,*p1,*p2)==2?-1:1);
}

void hull(point points[],int n){
	float ymin=points[0].y;
	int min=0;
	for(int i=1;i<n;i++){
		if(points[i].y<ymin||(points[i].y==ymin&&points[i].x<points[min].x)){
			min=i;
			ymin=points[i].y;
		}
	}
	swap(points[0],points[min]);
	p0=points[0];
	qsort(&points[1],n-1,sizeof(point),compare);

	int j=1;
	for(int i=1;i<n;i++){
		while(i<n-1&&orientation(p0,points[i],points[i+1])==0)
			i++;
		points[j++]=points[i];
	}

	if(j<3)
		return;
	stack<point> st;
	st.push(points[0]);
	st.push(points[1]);
	st.push(points[2]);

	for(int i=3;i<j;i++){
		while(orientation(nextToTop(st),st.top(),points[i])!=2)
			st.pop();
		st.push(points[i]);
	}
	while(!st.empty()){
		cout<<st.top().x<<" "<<st.top().y<<endl;
		st.pop();
	}
}

int main(){
	int n;
	cin>>n;
	point points[n];
	for(int i=0;i<n;i++)
		cin>>points[i].x>>points[i].y;
	hull(points,n);
}
