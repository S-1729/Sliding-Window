class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        int minWindow=INT_MAX,requiredCount=t.size(),start=0,i=0;
        for(int i=0;i<t.size();i++)
            mp[t[i]]++;
            
        for(int j=0;j<s.size();j++){
            if(mp[s[j]]>0)
                requiredCount--;
            mp[s[j]]--;
            
            while(requiredCount==0){
                int currentWindow=j-i+1;
                if(currentWindow<minWindow){
                    start=i;
                    minWindow=currentWindow;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0)
                    requiredCount++;
                i++;
            }
        }
        return minWindow==INT_MAX?"":s.substr(start,minWindow);
    }
};

/*
	Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. 
	If there is no such substring, return the empty string "".
	The testcases will be generated such that the answer is unique.

	Example 1:
	Input: s = "ADOBECODEBANC", t = "ABC"
	Output: "BANC"
	Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
	
	Example 2:
	Input: s = "a", t = "a"
	Output: "a"
	Explanation: The entire string s is the minimum window.
	
	Example 3:
	Input: s = "a", t = "aa"
	Output: ""
	Explanation: Both 'a's from t must be included in the window.
	Since the largest window of s only has one 'a', return empty string.

	T.C : O(n)
	S.C : O(n)
*/

