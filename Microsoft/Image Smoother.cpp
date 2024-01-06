class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size();
        int m = img[0].size();
        vector<vector<int>> ans;
        vector<int> ans1;
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                int cnt =0;
                int sum =img[i][j];
                if(j-1>=0){
                    sum+=img[i][j-1];
                    cnt++;
                }
                if(j+1<m){
                    sum+=img[i][j+1];
                    cnt++;
                }
                if(i+1<n){
                    sum+=img[i+1][j];
                    cnt++;
                }
                if(i-1>=0){
                    sum+=img[i-1][j];
                    cnt++;
                }
                if(i+1<n && j+1<m){
                    sum+=img[i+1][j+1];
                    cnt++;
                }
                if(i-1>=0 && j+1<m){
                    sum+=img[i-1][j+1];
                    cnt++;
                }
                if(i+1<n && j-1>=0){
                    sum+=img[i+1][j-1];
                    cnt++;
                }
                if(i-1>=0 && j-1>=0){
                    sum+=img[i-1][j-1];
                    cnt++;
                }
                ans1.push_back(sum/(cnt+1));
            }
            ans.push_back(ans1);
            ans1.clear();
        }
        return ans;
    }
};