class Solution {
public:
    string getHint(string secret, string guess) {
        int x=0,y=0;
        map<char,int>s;
        map<char,int>g;
        for(int i =0;i<secret.length();i++){
            if(secret[i]==guess[i])
                x++;
            else{
                s[secret[i]]++;
                g[guess[i]]++;
            }
        }
        auto it = s.begin();
        auto it1 = g.begin();
        
        for (auto it = s.begin(); it != s.end(); ++it) {
            char key = it->first;
            if (g.find(key) != g.end()) {
                y += min(it->second, g[key]);
            }
        }

        
        string ans = to_string(x)+'A'+to_string(y)+'B';
        return ans;
    }
};
