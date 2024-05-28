class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int sum=0,j=0,ans=0;
        for(int i=0;i<s.size();i++){
            sum+=abs(s[i]-t[i]);
            while(j<=i && sum>maxCost){
                sum-=abs(s[j]-t[j]);
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};

//Code-2  S.C : O(n)
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int>arr(s.size(),0);
        for(int i=0;i<s.size();i++)
            arr[i]=abs(s[i]-t[i]);
        int sum=0,j=0,ans=0;
        for(int i=0;i<s.size();i++){
            sum+=arr[i];
            while(j<=i && sum>maxCost){
                sum-=arr[j];
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};

/*
    You are given two strings s and t of the same length and an integer maxCost.
    You want to change s to t. Changing the ith character of s to ith character of t costs |s[i] - t[i]| (i.e., the absolute difference between the ASCII values of the characters).
    Return the maximum length of a substring of s that can be changed to be the same as the corresponding substring of t with a cost less than or equal to maxCost. If there is no substring from s that can be changed to its corresponding substring from t, return 0.
    
    Example 1:
    Input: s = "abcd", t = "bcdf", maxCost = 3
    Output: 3
    Explanation: "abc" of s can change to "bcd".
    That costs 3, so the maximum length is 3.
    
    Example 2:
    Input: s = "abcd", t = "cdef", maxCost = 3
    Output: 1
    Explanation: Each character in s costs 2 to change to character in t,  so the maximum length is 1.
    
    Example 3:
    Input: s = "abcd", t = "acde", maxCost = 0
    Output: 1
    Explanation: You cannot make any change, so the maximum length is 1.

    T.C : O(n)
*/
