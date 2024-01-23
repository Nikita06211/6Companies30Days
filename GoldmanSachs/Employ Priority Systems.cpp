class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        map<string,vector<int>>mp;
        for(int i =0;i<access_times.size();i++){
            mp[access_times[i][0]].push_back(std::stoi(access_times[i][1]));
        }
        
        vector<string>ans;
        for(auto& i:mp){
            if(i.second.size()<3)
                continue;
            sort(i.second.begin(),i.second.end());
            
            for(int j = 0;j<i.second.size()-2;j++){
                if(i.second[j+2]-i.second[j] <100){
                    ans.push_back(i.first);
                    break;
                }
                    
            }
        }
        return ans;
    }
};
