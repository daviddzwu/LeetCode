using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen; // Use unordered_set for faster lookups and reduced memory overhead

        for (int num : nums) {
            if (seen.count(num)) { // Check if the number already exists in the set
                return true; // Duplicate found
            }
            seen.insert(num); // Add the number to the set
        }

        return false; // No duplicates found
    }
};
