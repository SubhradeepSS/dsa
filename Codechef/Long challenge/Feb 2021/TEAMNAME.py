# cook your dish here
t = int(input())
for _ in range(t):
    __ = input()
    words = input().split(' ')
    tails = {}
    
    for word in words:
        key = word[1:]
        if key in tails:
            tails[key].append(word[0])
        else:
            tails[key] = [word[0]]
    
    ans = 0
    
    tails_keys = list(tails.keys())
    l = len(tails)
    ans = 0
    for i in range(0,l):
        for j in range(i+1,l):
            a,b = tails[tails_keys[i]],tails[tails_keys[j]]
            c = len(set(a+b))
            ans += (c-len(a))*(c-len(b))
        
    print(2*ans)