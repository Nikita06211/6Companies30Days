class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int result = 0;
        for (int l = 0, r = 0; r < nums.size(); r++) {
            freq[nums[r]]++;
            while (freq[nums[r]] > k){
                freq[nums[l++]]--;
            } 
            result = max(result, r - l + 1);
        }
        return result;
    }
};