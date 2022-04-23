#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:

    // Time - O(n) | Memory - O(1)
    int lengthOfLongestSubstring(string s) {
        
        vector<int>freq(256, 0);
        int L = 0, R = 0, dupCount = 0;
        int longestLen = 0;
        
        while(R < s.size()) {
            freq[s[R]]++;
            if(freq[s[R]] > 1) {
                dupCount++;
            }
            R++;
            
            while(dupCount > 0) {
                freq[s[L]]--;
                if(freq[s[L]] == 1) {
                    dupCount--;
                }
                L++;
            }
            longestLen = max(longestLen, R - L);
        }
        
        return longestLen;
    }
};

int main()
{
    Solution sln;
    int res = sln.lengthOfLongestSubstring("");
    cout<<res<<endl;
    return 0;
}