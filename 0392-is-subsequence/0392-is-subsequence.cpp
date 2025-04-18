class Solution {
public:
    bool isSubsequence(string s, string t) {
        int tIdx = 0;
        int sIdx = 0;

        while(tIdx < t.size() && sIdx < s.size()){
            if(s[sIdx] == t[tIdx]){
                sIdx++;
                tIdx++;
            }
            else{
                tIdx++;
            }
        }
        if(sIdx == s.size()){
            return true;
        }
        else return false;
    }
};