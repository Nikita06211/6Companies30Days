class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int ans =-1,window=0, left = 0;
        
        for(int right = 0;right<s.length();right++){
            window+=abs(s[right]-t[right]);
            while(window>maxCost){
                window-=abs(s[left]-t[left]);
                left++;
            }
            ans = max(ans,right-left+1);
        }
        return ans;
    }
};
