def stringShift(self, s, shift):
        """
        :type s: str
        :type shift: List[List[int]]
        :rtype: str
        """
        for i in range(len(shift)):
            f=shift[i][0]
            v=shift[i][1]
            if f==0:
                while v!=0:
                    a=s[0]
                    s=s[1:]
                    s+=a
                    v-=1
            else:
                while v!=0:
                    a=s[-1]
                    s=s[:-1]
                    s=a+s
                    v-=1
        return s
