#include<bits/stdc++.h>
using namespace std;

string findSubString(string str,string pat){
    int len1=str.length(),len2=pat.length();
    int start_ind=-1,min_length=INT_MAX,count=0;
    int hash_pat[256]={0},hash_str[256]={0};
    for(int i=0;i<len2;i++)
        hash_pat[pat[i]]++;
    int start=0;
    for(int i=0;i<len1;i++){
        hash_str[str[i]]++;
        if(hash_str[str[i]]<=hash_pat[str[i]]&&hash_pat[str[i]])
            count++;
        if(count==len2){
            while(hash_str[str[start]]>hash_pat[str[start]]||hash_pat[str[start]]==0)
                {
                    if(hash_str[str[start]]>hash_pat[str[start]])
                       hash_str[str[start]]-- ;
                    start++;
                }
                if(i-start+1<min_length){
            start_ind=start;
            min_length=i-start+1;
        }
        }
    }
    if(start_ind==-1)
        return "";
    return str.substr(start_ind,min_length);
}

int main() 
{ 
    string str = "this is a test string"; 
    string pat = "tist"; 
  
    cout << "Smallest window is : \n"
        << findSubString(str, pat); 
    return 0; 
} 
