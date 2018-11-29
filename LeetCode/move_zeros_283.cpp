class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size() <= 1) return;
        
        int c = 1;
        for (int l = 0; c < nums.size(); ++c) {
            if (nums[c] == 0) {
                if (nums[l] != 0) l = c;
            } else if (nums[l] == 0) {
                swap(nums[l++], nums[c]);
            }
        }
    }
};

