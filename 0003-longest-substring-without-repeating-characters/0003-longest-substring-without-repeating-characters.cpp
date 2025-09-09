class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Use unordered_set to track characters in current window
        unordered_set<char> seen;
        int left = 0;  // Left boundary of our sliding window
        int maxLength = 0;  // Track the maximum length found so far
        
        // Right boundary of window expands with each iteration
        for (int right = 0; right < s.length(); right++) {
            char currentChar = s[right];
            
            // If we've seen this character, shrink window from left
            // until we remove the duplicate
            while (seen.find(currentChar) != seen.end()) {
                seen.erase(s[left]);  // Remove leftmost character
                left++;  // Move left boundary right
            }
            
            // Add current character to our window
            seen.insert(currentChar);
            
            // Update maximum length if current window is larger
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};