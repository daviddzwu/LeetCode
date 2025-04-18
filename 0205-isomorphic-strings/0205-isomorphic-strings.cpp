class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, char> st; // s -> t mapping
        unordered_map<char, char> ts; // t -> s mapping

        for (int i = 0; i < s.length(); i++) {
            char c1 = s[i], c2 = t[i];

            // If c1 is already mapped, check if it maps to c2
            if (st.count(c1)) {
                if (st[c1] != c2) return false;
            } else {
                // If c2 is already mapped to a different character, return false
                if (ts.count(c2)) {
                    if (ts[c2] != c1) return false;
                }
                // Create the new mapping
                st[c1] = c2;
                ts[c2] = c1;
            }
        }
        return true;
    }
};
