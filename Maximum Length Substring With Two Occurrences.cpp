class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int>mp;
        int i=0,maxLen=0;
        for(int j=0;j<s.size();j++){
            mp[s[j]]++;
            while(mp[s[j]]>2){
                mp[s[i]]--;
                i++;
            }
            maxLen=max(maxLen,j-i+1);
        }
        return maxLen;
    }
};

/*
	Given a string s, return the maximum length of a substring such that it contains at most two occurrences of each character.
	
	Example 1:
	Input: s = "bcbbbcba"
	Output: 4
	Explanation:
	The following substring has a length of 4 and contains at most two occurrences of each character: "bcbbbcba".
	
	Example 2:
	Input: s = "aaaa"
	Output: 
	Explanation:
	The following substring has a length of 2 and contains at most two occurrences of each character: "aaaa".

	T.C : O(n)
	S.C : O(n)
*/
