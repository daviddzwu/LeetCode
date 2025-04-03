class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> hashTable;
        for(int i = 0; i < nums.size(); i++){
            if(hashTable.find(nums[i]) != hashTable.end()){
                hashTable[nums[i]]++;
            }
            else{
                hashTable[nums[i]] = 0;
            }
        }
        int maxKey = -1;
        int maxValue = INT_MIN;

        for (const auto& pair : hashTable) {
            if (pair.second > maxValue) {
                maxValue = pair.second;
                maxKey = pair.first; 
            }
        }
        return maxKey;
    }
};