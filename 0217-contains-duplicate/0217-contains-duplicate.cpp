class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> hash;

        for(int i = 0; i < nums.size(); i++){
            if(hash.find(nums.at(i)) != hash.end()){
                return true;
            }
            else{
                hash[nums.at(i)] = i;
            }
        }
    return false;
    }
};
