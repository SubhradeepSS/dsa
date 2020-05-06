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

/*
class Solution(object):
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        di=Counter(t)
        curr={}
        req=len(di)
        cl=0
        ans=float('inf'),None,None
        l,r=0,0
        
        while r<len(s):
            add=s[r]
            curr[add]=curr.get(add,0)+1
            if add in di and di[add]==curr[add]:
                cl+=1
            while l<=r and cl==req:
                sub=s[l]
                if r-l+1<ans[0]:
                    ans=r-l+1,l,r
                curr[sub]-=1
                
                if sub in di and curr[sub]<di[sub]:
                    cl-=1
                l+=1
            r+=1
        return "" if ans[0]==float('inf') else s[ans[1]:ans[2]+1]
  */
