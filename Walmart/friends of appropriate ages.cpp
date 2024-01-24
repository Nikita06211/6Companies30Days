class Solution {
public:
    
    bool req(int a, int b){
        return !(b<=0.5*a+7 || b>a);
    }
    
    int numFriendRequests(vector<int>& ages) {
        unordered_map<int,int>mp;
        int res = 0;
        
        for(int i =0;i<ages.size();i++){
            mp[ages[i]]++;
        }
        
        for(auto a:mp){
            for(auto b:mp){
                if(req(a.first,b.first)){
                    res+= a.second *(b.second-(a.first==b.first?1:0));
                }
            }
        }
        return res;
    }
};
