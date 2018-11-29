struct IllegalArgumentException {};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.empty() || nums.size() % 2 == 0) {
            throw IllegalArgumentException();
        } else if (nums.size() == 1) {
            return nums[0];
        }
        
        std::sort(nums.begin(), nums.end());
        
        int x = nums[0];
        if (x != nums[1]) {
            return x;
        }
        
        for (int i = 2; i < nums.size(); i += 2) {
            if (nums[i] != nums[i + 1]) {
                return nums[i];
            }
        }
        return nums.back();
    }
};

