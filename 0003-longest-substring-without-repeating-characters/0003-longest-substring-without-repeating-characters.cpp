class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int left = 0;
        int maxLength = 0;

        for(int right = 0; right < s.length(); right++){
            char curr = s[right];

            while(seen.find(curr) != seen.end()){
                seen.erase(s[left]);
                left++;
            }
            seen.insert(curr);
            maxLength = max(maxLength, right - left + 1);
        }
    return maxLength;
    }
};