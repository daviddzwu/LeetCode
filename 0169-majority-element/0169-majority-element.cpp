class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> hashTable;
        
        for(int i = 0; i < nums.size(); i++){
            hashTable[nums[i]]++;
        }
        int n = (nums.size()) / 2;

        for (auto x : hashTable) {
            if (x.second > n) {
                return x.first;
            }
        }
        return 0;
    }
};