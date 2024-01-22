class Solution
{
    public:
    unordered_set<string> st;
    bool isPossible(string& s)
    {
        int n=s.length();
        for (int i=0;i<n;i++)
        {
            string temp="";
            for (int j=0;j<n;j++)
            {
                if (j==i)
                    continue;
                temp.push_back(s[j]);
            }
            if (st.find(temp)!=st.end())
                return true;
        }
        return false;
    }
    int wordCount(vector<string>& arr, vector<string>& target)
    {
        int n=target.size();
        for (auto& i:arr)
        {
            sort(i.begin(),i.end()); 
            st.insert(i);
        }
        
        int count=0;
        for (int i=0;i<n;i++)
        {
            sort(target[i].begin(),target[i].end());
            if (isPossible(target[i]))
                count++;
        }
        return count;
    }
};
