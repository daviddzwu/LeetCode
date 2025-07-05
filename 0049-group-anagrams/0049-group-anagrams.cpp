#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    
        // Handle empty input
        if(strs.empty()) return {};

        unordered_map<string, vector<string>> map;

        // Process each string
        for(int i = 0; i < strs.size(); i++){
            string sorted = strs[i];  // Copy the original string
            sort(sorted.begin(), sorted.end());  // Sort the copy
            map[sorted].push_back(strs[i]);
        }

        // Extract all values from map, insert into return list 
        vector<vector<string>> result;
        for(const auto& pair : map) {
            result.push_back(pair.second);
        }

        return result;
    }
};
