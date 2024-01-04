class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>>st;
                int ans =0;
        for(int i =0;i<nums.size();i++){
            vector<int>s;
            int cnt = 0;
            for(int j = i;j<nums.size();j++){
                if(nums[j]%p==0){
                    cnt++;
                }
                if(cnt>k){
                    break;
                }
                s.push_back(nums[j]);
                st.insert(s);
            }
        }
        for(auto i : st){
            ans++;
        }
        return ans;
    }
};
