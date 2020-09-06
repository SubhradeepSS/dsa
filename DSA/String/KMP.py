def make_lps(pattern):
    m=len(pattern)
    lps=[0]*m
    i=1
    length=0
    while i<m:
        if pattern[i]==pattern[length]:
            length+=1
            lps[i]=length
            i+=1
        else:
           if length!=0:
               length=lps[length-1]
           else:
               lps[i]=0
               i+=1
    return lps

def kmp(pattern,text):
    m=len(pattern)
    n=len(text)
    lps=make_lps(pattern)
    i=0
    j=0
    while i<n:
        if pattern[j] == text[i]:
            i+=1
            j+=1
        if j==m:
            print("Pattern found at "+str(i-j))
            j=lps[j-1]
        elif i<n and pattern[j]!=text[i]:
            if j!=0:
                j=lps[j-1]
            else:
                i+=1
text = "ABABDABACDABABCABAB"
pattern = "ABAB"
kmp(pattern,text)
