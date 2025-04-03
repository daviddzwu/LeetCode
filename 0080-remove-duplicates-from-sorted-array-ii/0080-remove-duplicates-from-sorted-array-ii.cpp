class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Handle small cases directly
        int n = nums.size();
        if (n <= 2) return n;

        // Use two-pointer technique
        int index = 2;
        for (int i = 2; i < n; ++i) {
            if (nums[i] != nums[index - 2]) {
                nums[index++] = nums[i];
            }
        }
        return index;
    }
};
