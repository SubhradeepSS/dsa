# brute - gives tle in leetcode

class Solution:
    def longestDupSubstring(self, S: str) -> str:
        
        l = len(S) - 1                  # possible max common substr will be of length len(S)-1
        found = set()
        
        while l >= 1:
            for i in range(len(S)-l+1):
                j = i+l-1
                
                curr = S[i:j+1]
                
                if curr in found:
                    return curr
                
                found.add(curr)
                
            l -= 1
        
        return ""
