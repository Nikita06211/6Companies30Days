class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mp;
        for (int i = 0; i < s.length(); i++) {
            mp[s[i]]++;
        }

        vector<pair<int,char>>v;
        for(auto i:mp){
            v.push_back({i.second,i.first});
        }
        
        sort(v.rbegin(), v.rend());

        s.clear();

        for(auto i:v){
            s+=string(i.first,i.second);
        }

        return s;
    }
};
