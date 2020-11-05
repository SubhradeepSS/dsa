// https://classroom.codingninjas.com/app/classroom/me/2617/content/54608/offering/618180/problem/7009
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll count(string a, string b) 
{ 
    int m = a.length(); 
    int n = b.length();  
    ll lookup[m + 1][n + 1] = { { 0 } }; 
  
    for (int i = 0; i <= n; ++i) 
        lookup[0][i] = 0; 
  
    for (int i = 0; i <= m; ++i) 
        lookup[i][0] = 1; 
  
    for (int i = 1; i <= m; i++) 
    { 
        for (int j = 1; j <= n; j++) 
        { 
            if (a[i - 1] == b[j - 1]) 
                lookup[i][j] = lookup[i - 1][j - 1] +  
                               lookup[i - 1][j]; 
                  
            else
                lookup[i][j] = lookup[i - 1][j]; 
        } 
    } 
  
    return lookup[m][n]; 
} 
int main(){
    // write your code
    string s;
    cin>>s;
    
    int q;
    cin>>q;
    while(q--){
        char x;
        int n;
        cin>>x>>n;
        if(x=='p')
        	cout<<count(s.substr(0,n),"ninjas")<<endl;
        else{
            string s1=s;
            reverse(s1.begin(),s1.end());
            string t=s1.substr(0,n);
            reverse(t.begin(),t.end());
            cout<<count(t,"ninjas")<<endl;
        }      
    }
    return 0;
}
