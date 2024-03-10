class Solution {
public:
    int maxVowels(string s, int k) {
        int ans=INT_MIN,i=0,count=0;
        for(int j=0;j<s.size();j++){
            if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u')
                count++;
            if(j>=k){
                if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
                    count--;
                i++;
            }
            ans=max(ans,count);
        }
        return ans;
    }
};

/*
	Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.
	Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

	Example 1:
	Input: s = "abciiidef", k = 3
	Output: 3
	Explanation: The substring "iii" contains 3 vowel letters.
	
	Example 2:
	Input: s = "aeiou", k = 2
	Output: 2
	Explanation: Any substring of length 2 contains 2 vowels.
	
	Example 3:
	Input: s = "leetcode", k = 3
	Output: 2
	Explanation: "lee", "eet" and "ode" contain 2 vowels.

	T.C : O(n)
*/
