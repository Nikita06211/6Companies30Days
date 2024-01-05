//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends


/*You are required to complete this function */

string encode(string src)
{     
  string s = "";
  char current_char = src[0];
  int count = 1;

  for (int i = 1; i < src.length(); i++) {
    if (src[i] == current_char) {
      count++;
    } else {
      s += current_char;
      s += to_string(count);
      current_char = src[i];
      count = 1;
    }
  }
  s += current_char;
  s += to_string(count);

  return s;
}     
 
