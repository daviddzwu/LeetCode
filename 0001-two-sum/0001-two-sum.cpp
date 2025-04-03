using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> targetIdx;
        unordered_map<int, int> hashTable;

        for(int i = 0; i < nums.size(); i++){
            int secondInt = target - nums.at(i);

            if(hashTable.find(secondInt) != hashTable.end()){
                targetIdx.push_back(i);
                targetIdx.push_back(hashTable.find(secondInt)->second);
                break;
            }
            else{
                hashTable[nums.at(i)] = i;
            }
        }
        return targetIdx;
    }
};