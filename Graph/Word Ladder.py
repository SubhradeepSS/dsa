""" 
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list.
Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: 0

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
"""

class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        if endWord not in wordList or not beginWord or not endWord or not wordList:
            return 0
        
        combo_dict = collections.defaultdict(list)
        L = len(beginWord)
        
        for word in wordList:
            for i in range(L):
                combo_dict[word[:i]+'*'+word[i+1:]].append(word)
        
        queue = [(beginWord, 1)]
        visited = [beginWord]
        
        while queue:
            curr,level = queue.pop(0)
            
            for i in range(L):
                util = curr[:i]+'*'+curr[i+1:]
                
                for word in combo_dict[util]:
                    if word == endWord:
                        return level+1
                    
                    if word not in visited:
                        visited.append(word)
                        queue.append((word,level+1))
                        
                combo_dict[util] = []
        
        return 0
