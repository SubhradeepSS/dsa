/* In an alien language, surprisingly they also use english lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.
Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographicaly in this alien language.

Example 1:
Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.

Example 2:
Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.

Example 3:
Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
Output: false
Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character (More info).

Constraints:
    1 <= words.length <= 100
    1 <= words[i].length <= 20
    order.length == 26
    All characters in words[i] and order are English lowercase letters.
 */

// Link: https://leetcode.com/problems/verifying-an-alien-dictionary/

vector<int> pos;

bool f(string a, string b)
{
    string min_s = (a.length() < b.length() ? a : b);
    string max_s = (min_s == a ? b : a);
    for (int i = 0; i < min_s.length(); i++)
    {
        if (min_s[i] == max_s[i])
            continue;
        if (pos[min_s[i] - 'a'] < pos[max_s[i] - 'a'])
            return (min_s == a);
        else if (pos[min_s[i] - 'a'] > pos[max_s[i] - 'a'])
            return (min_s != a);
    }
    return (min_s == a);
}

class Solution
{
public:
    bool isAlienSorted(vector<string> &words, string order)
    {
        pos = vector<int>(26);
        for (int i = 0; i < 26; i++)
        {
            pos[order[i] - 'a'] = i;
        }
        vector<string> util(words.begin(), words.end());
        sort(words.begin(), words.end(), f);
        return (util == words);
    }
};