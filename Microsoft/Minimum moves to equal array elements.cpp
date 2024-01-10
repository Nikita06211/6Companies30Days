class Solution {
public:
    int find(vector<int>nums, int avg){
        int ans =0;
        for(int i =0;i<nums.size();i++){
            ans+=abs(avg-nums[i]);
        }
        return ans;
    }
    int minMoves2(vector<int>& nums) {
        if(nums.size()==1){
            return 0;
        }
        sort(nums.begin(),nums.end());
        
        if(nums.size()%2==0){
           return find(nums,nums[nums.size()/2]);
        }
        return min(find(nums,nums[nums.size()/2]), find(nums,nums[nums.size()/2 +1]));
    }
};
