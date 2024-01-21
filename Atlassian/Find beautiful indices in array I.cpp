class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        
        int position = s.find(a);
        int pos2 = s.find(b);
        
        vector<int>a1;
        vector<int>b1;
        vector<int>ans;
    
        while (position != string::npos) {
            
            if(position <= s.length()-a.length())
                a1.push_back(position);

            position = s.find(a, position + 1);
        }
        cout<<endl;
        while (pos2 != string::npos) {
            
            if(pos2 <= s.length()-b.length())
                b1.push_back(pos2);

            pos2 = s.find(b, pos2 + 1);
        }
        
        for(int i =0;i<a1.size();i++){
            // cout<<a1[i]<<" ";
            for(int j =0;j<b1.size();j++){
                // cout<<b1[i]<<" ";
                if(abs(a1[i]-b1[j])<=k){
                    ans.push_back(a1[i]);
                    break;
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
        
        
        

    }
};