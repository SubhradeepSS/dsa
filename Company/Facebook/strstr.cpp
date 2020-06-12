int strstr(string s, string x)
{
     //Your code here
     int i=0,j;
     while(i<s.length()){
         int st=i;
         if(s[i]==x[0]){
             i++;
             for(j=1;i<s.length()&&j<x.length()&&s[i]==x[j];i++,j++);
         }
         if(j==x.length())
            return st;
        i++;
     }
     return -1;
}
