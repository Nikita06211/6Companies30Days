//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string S){
        // code here 
        stack<int>s;
        string ans;
        int cnt = 1;
        
        for(int i =0;i<S.length();i++){
            if(S[i]=='D'){
               s.push(cnt);
               cnt++;
           }
           else{
               s.push(cnt);
               cnt++;
               while(!s.empty()){
                   ans+=to_string(s.top());
                   s.pop();
               }
           }
        }
        
        s.push(cnt);
        while(!s.empty()){
            ans+=to_string(s.top());
            s.pop();
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 

// } Driver Code Ends
