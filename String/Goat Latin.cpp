/* A sentence S is given, composed of words separated by spaces. Each word consists of lowercase and uppercase letters only.

We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin.)

The rules of Goat Latin are as follows:

    If a word begins with a vowel (a, e, i, o, or u), append "ma" to the end of the word.
    For example, the word 'apple' becomes 'applema'.
     
    If a word begins with a consonant (i.e. not a vowel), remove the first letter and append it to the end, then add "ma".
    For example, the word "goat" becomes "oatgma".
     
    Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.
    For example, the first word gets "a" added to the end, the second word gets "aa" added to the end and so on.

Return the final sentence representing the conversion from S to Goat Latin. 

Example 1:

Input: "I speak Goat Latin"
Output: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
*/
class Solution {
public:
    bool isV(char a){
        return (
            a=='a'||a=='e'||a=='i'||a=='o'||a=='u'||a=='A'||a=='E'||a=='I'||a=='O'||a=='U'
        );
    }
    string toGoatLatin(string S) {
        vector<string> words;
        string curr="";
        for(int i=0;S[i];i++){
            if(S[i]!=' ')
                curr+=S[i];
            else{
                words.push_back(curr);
                curr="";
            }
        }
        if(curr!="")
            words.push_back(curr);
        // for(auto w:words)
        //     cout<<w<<" ";
        string ans="";
        int i=1;
        for(string w:words){
            if(isV(w[0]))
                ans+=w+"ma";
            else{
                ans+=w.substr(1)+w[0]+"ma";
            }
            for(int c=0;c<i;c++)
                ans+="a";
            i++;
            // ans+=w;
            ans+=" ";
        }
        return ans.substr(0,ans.length()-1);
    }
};
