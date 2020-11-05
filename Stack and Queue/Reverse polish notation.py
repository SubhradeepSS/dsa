class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        l=[]
        for i in tokens:
            if i not in "-+/*":
                l.append(int(i))
            else:
                num2=l.pop()
                num1=l.pop()
                if i=='*':
                    l.append(num1*num2)
                elif i=='/':
                    l.append(int(num1/num2))
                elif i=='+':
                    l.append(num1+num2)
                else:
                    l.append(num1-num2)
        return l.pop()
