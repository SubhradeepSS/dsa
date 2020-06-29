""" Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

Example:

Input: "aab"
Output:
[
  ["aa","b"],
  ["a","a","b"]
] """

class Solution:
    def partition(self, s: str) -> List[List[str]]:
        
        ans = []
        
        def is_pal(S):
            return S == S[::-1]
        
        def f(S, curr_list):
            if not S:
                ans.append(curr_list)
                return
            
            for i in range(1,len(S)+1):
                if is_pal(S[:i]):
                    f(S[i:], curr_list + [S[:i]])

        
        f(s,[])
        
        return ans
