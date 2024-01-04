//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int>& arr, int n) {
        unordered_map<int, int> freqMap;

        int missingElement, repeatingElement;
        for (int i = 0; i < n; i++) {
            freqMap[arr[i]]++;
        }

        for (int i = 1; i <= n; i++) {
            if (freqMap.find(i) == freqMap.end()) {
                missingElement = i;
            } else if (freqMap[i] == 2) {
                repeatingElement = i;
            }
        }

        return {repeatingElement, missingElement};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends
