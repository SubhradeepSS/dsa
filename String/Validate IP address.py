# Logical
class Solution:
    def validIPAddress(self, IP: str) -> str:
        ipv4 = IP.split('.')
        f=0
        
        for i in ipv4:
            if 3>=len(i)>0 and i[0]!='+' and i[0]!='-':
                try:
                    if i[0]!='0' and 0<int(i,10)<=255:
                        f+=1
                    elif int(i,10)==0 and len(i)==1:
                        f+=1
                except:
                    f-=1
            else:
                f-=1
                    
        if f==4:
            return "IPv4"
        
        ipv6 = IP.split(':')
        f=0
        for i in ipv6:
            if 1<=len(i)<=4:
                try:
                    if i[0]!='-' and i[0]!='+' and int(i,16)>=0:
                        f+=1
                except:
                    f-=1
            else:
                f-=1
                
        if f==8:
            return "IPv6"
        
        return "Neither"

# Inbuilt in Python
from ipaddress import ip_address, IPv6Address
class Solution:
    def validIPAddress(self, IP: str) -> str:
        try:
            return "IPv6" if type(ip_address(IP)) is IPv6Address else "IPv4"
        except ValueError:
            return "Neither"
