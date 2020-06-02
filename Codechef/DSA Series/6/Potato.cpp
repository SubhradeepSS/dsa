#include<bits/stdc++.h>
#define llu long long int
using namespace std;

typedef pair<llu,llu> Point;

llu cross_pdt(Point a,Point b,Point c){
	return (b.first-a.first)*(c.second-a.second)-(b.second-a.second)*(c.first-a.first);
}

llu area(Point a,Point b, Point c){
	return abs(a.first*(b.second-c.second)+b.first*(c.second-a.second)+c.first*(a.second-b.second));
}

vector<Point> convexHull(vector<Point> points,int n){
	if(n<=1)
		return points;

	int k=0;
	vector<Point> ans(2*n);
	sort(points.begin(),points.end());

	for(int i=0;i<n;i++){
		while(k>=2&&cross_pdt(ans[k-2],ans[k-1],points[i])<=0)
			k--;
		ans[k++]=points[i];
	}

	for(int i=n-1,t=k+1;i>0;i--){
		while(k>=t&&cross_pdt(ans[k-2],ans[k-1],points[i-1])<=0)
			k--;
		ans[k++]=points[i-1];
	}

	ans.resize(k-1);
	return ans;
}

void solve(vector<Point> points,int n){
	set<Point> s;
	for(Point p:points)
		s.insert(p);
	vector<Point> outer=convexHull(points,n);

	for(Point p:outer)
		s.erase(p);
	vector<Point> util;
	for(Point p:s)
		util.push_back(p);

	vector<Point> inner=convexHull(util,util.size());

	if(inner.size()==0){
		cout<<-1<<endl;
		return;
	}

	llu total=0;
	for(int i=1;i+1<outer.size();i++)
		total+= area(outer[0],outer[i],outer[i+1]);

	llu minA=1e18;
	int p=0;
	for(int i=0;i<outer.size();i++){
		llu IA=area(outer[i],outer[(i+1)%outer.size()],inner[p]);
		llu next, start=p;
		while(1){
			llu currIA=area(outer[i],outer[(i+1)%outer.size()],inner[(p+1)%inner.size()]);
			if(currIA<=IA){
				IA=currIA;
				p=(p+1)%inner.size();
			}
			else
				break;
			if(start==p)
			    break;
		}
		minA=min(minA,IA);
	}
	cout<<total-minA<<endl;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<Point> points(n);
		for(int i=0;i<n;i++)
			cin>>points[i].first>>points[i].second;
		solve(points,n);
	}
}
