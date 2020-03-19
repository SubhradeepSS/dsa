#include <bits/stdc++.h>
#include<time.h>
using namespace std;

int randomselect(int x){
    static int res,count=0;
    count++;
    if(count==1)
        res=x;
    else{
        int i=rand()%count;
        if (i==count-1)
            res=x;
    }
    return res;
}

int main() {
	int arr[]={1,2,3,4,5};
	srand(time(NULL));
	int n=sizeof(arr)/sizeof(arr[0]);
	for(int i=0;i<n;i++)
	    cout<<randomselect(arr[i])<<" ";
}
