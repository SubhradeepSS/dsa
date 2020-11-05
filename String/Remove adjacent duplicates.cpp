#include<bits/stdc++.h>
using namespace std;

char* util(char *s,char *last_removed){
    if(s[0]=='\0'||s[1]=='\0')
        return s;
    if(s[0]==s[1]){
        *last_removed=s[0];
        while(s[1]&&s[0]==s[1])
            s++;
        s++;
        return util(s,last_removed);
    }
    char* rem_str=util(s+1,last_removed);
    if(rem_str[0]=='\0'&&*last_removed==s[0])
        return rem_str;
    if(rem_str&&s[0]==rem_str[0])
        return rem_str+1;
    rem_str--;
    rem_str[0]=s[0];
    return rem_str;
}

char* remove(char* s){
    char last_removed='\0';
    return util(s,&last_removed);
}

int main() 
{ 
    char str1[] = "geeksforgeeg"; 
    cout << remove(str1) << endl; 
  
    char str2[] = "azxxxzy"; 
    cout << remove(str2) << endl; 
  
    char str3[] = "caaabbbaac"; 
    cout << remove(str3) << endl; 
  
    char str4[] = "gghhg"; 
    cout << remove(str4) << endl; 
  
    char str5[] = "aaaacddddcappp"; 
    cout << remove(str5) << endl; 
  
    char str6[] = "aaaaaaaaaa"; 
    cout << remove(str6) << endl; 
  
    char str7[] = "qpaaaaadaaaaadprq"; 
    cout << remove(str7) << endl; 
  
    char str8[] = "acaaabbbacdddd"; 
    cout << remove(str8) << endl; 
  
    char str9[] = "acbbcddc"; 
    cout << remove(str9) << endl; 
  
    return 0; 
} 
