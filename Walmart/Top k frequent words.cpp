class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>mp;
        
        for(int i =0;i<words.size();i++){
            mp[words[i]]++;
        }
        
        vector<pair<int,string>>v;
        for(auto i:mp){
            v.push_back({i.second,i.first});
        }
        sort(v.begin(), v.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
            return (a.first == b.first) ? (a.second < b.second) : (a.first > b.first);
        });
        
        vector<string>ans;
        for(int i =0;i<k;i++){
            ans.push_back(v[i].second);
        }
        return ans;
    }
};
