class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty()){
            return true;
        }
        string anumS = "";

        for(int i = 0; i < s.size(); i++){
            if(isalnum(s[i])){
                anumS += tolower(s[i]);
            }
        }
        int left = 0;
        int right = anumS.size() - 1;

        while(left < right){
            if(anumS[left] != anumS[right]){
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};