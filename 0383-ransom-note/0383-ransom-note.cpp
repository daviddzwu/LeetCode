class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> letters;

        for(int i = 0; i < magazine.length(); i++){
            letters[magazine[i]] += 1;
        }
        for(int i = 0; i < ransomNote.length(); i++){
            if(letters.find(ransomNote[i]) == letters.end()){
                return false;
            }
            else if(letters[ransomNote[i]] <= 0) return false;
            else letters[ransomNote[i]] -= 1;
        }
        return true;
    }
};