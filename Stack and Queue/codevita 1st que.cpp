#include <iostream>
#include <queue>

using namespace std;

int fun(queue<char> a,queue<char> b){
	
	while(!a.empty()){
		char f=a.front();
		int c=0;

		while(!b.empty()){
			c++;
			char s=b.front();
			if(c>b.size())
				return a.size();
			if(s==f){
				b.pop();
				a.pop();
				break;
			}
			else{
				b.pop();
				b.push(s);
			}
		}
	}
	return 0;
}

int main(){
	int n;
	cin>>n;

	queue<char> a,b;

	string x,y;
	cin>>x>>y;

	for(auto c:x)
		a.push(c);
	for(auto c:y)
		b.push(c);
	

	cout<<fun(a,b);
}	
