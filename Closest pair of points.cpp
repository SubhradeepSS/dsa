#include <bits/stdc++.h> 
using namespace std; 

struct Point{
  int x,y;  
};

int compare_x(const void* a,const void* b){
    Point *p1=(Point *)a,*p2=(Point *)b;
    return p1->x-p2->x;
}
int compare_y(const void* a,const void* b){
    Point *p1=(Point *)a,*p2=(Point *)b;
    return p1->y-p2->y;
}

float distance(Point a,Point b){
    return sqrt((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y));
}

float bruteforce(Point p[],int n){
    float min_d=FLT_MAX;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            min_d=min(min_d,distance(p[i],p[j]));
        }
    }
    return min_d;
}

float closest_strip(Point strip[],int n,float d){
    float min_d=d;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n&&strip[j].y-strip[i].y<min_d;j++)
            min_d=min(min_d,distance(strip[i],strip[j]));
    }
    return min_d;
}

float closestutil(Point px[],Point py[],int n){
    if(n<=3)
        return bruteforce(px,n);
    int mid=n/2;
    Point midPoint=px[mid];
    Point pyl[mid+1],pyr[n-mid-1];
    int lyl=0,lyr=0;
    for(int i=0;i<n;i++){
        if(py[i].x<=midPoint.x)
            pyl[lyl++]=py[i];
        else
            pyr[lyr++]=py[i];
    }
    float dl=closestutil(px,pyl,mid);
    float dr=closestutil(px+mid,pyl,n-mid-1);
    float d=min(dl,dr);
    Point strip[n];
    int j=0;
    for(int i=0;i<n;i++){
        if(abs(py[i].x-midPoint.x)<d)
            {strip[j++]=py[i];}
    }
    return min(d,closest_strip(strip,j,d));
}

float closest(Point p[],int n){
    Point px[n],py[n];
    for(int i=0;i<n;i++)
    {
        px[i]=p[i];py[i]=p[i];
    }
    qsort(px,n,sizeof(Point),compare_x);
    qsort(py,n,sizeof(Point),compare_y);
    return closestutil(px,py,n);
}

int main() 
{ 
    Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}}; 
    int n = sizeof(P) / sizeof(P[0]); 
    cout << "The smallest distance is " << closest(P, n); 
    return 0; 
} 
