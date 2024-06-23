class Solution {
public:
    typedef pair<int,int>P;
    int longestSubarray(vector<int>& nums, int limit) {
        priority_queue<P>pq1;
        priority_queue<P,vector<P>,greater<P>>pq2;
        int i=0,ans=0;
        for(int j=0;j<nums.size();j++){
            pq1.push({nums[j],j});
            pq2.push({nums[j],j});
            while(abs(pq1.top().first-pq2.top().first)>limit){
                i=min(pq1.top().second,pq2.top().second)+1;
                while(pq1.top().second<i)
                    pq1.pop();
                while(pq2.top().second<i)
                    pq2.pop();
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};

/*
    Given an array of integers nums and an integer limit, return the size of the longest non-empty subarray such that the absolute difference between any two elements of this subarray is less than or equal to limit.
    
    Example 1:
    Input: nums = [8,2,4,7], limit = 4
    Output: 2 
    Explanation: All subarrays are: 
    [8] with maximum absolute diff |8-8| = 0 <= 4.
    [8,2] with maximum absolute diff |8-2| = 6 > 4. 
    [8,2,4] with maximum absolute diff |8-2| = 6 > 4.
    [8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
    [2] with maximum absolute diff |2-2| = 0 <= 4.
    [2,4] with maximum absolute diff |2-4| = 2 <= 4.
    [2,4,7] with maximum absolute diff |2-7| = 5 > 4.
    [4] with maximum absolute diff |4-4| = 0 <= 4.
    [4,7] with maximum absolute diff |4-7| = 3 <= 4.
    [7] with maximum absolute diff |7-7| = 0 <= 4. 
    Therefore, the size of the longest subarray is 2.
    
    Example 2:
    Input: nums = [10,1,2,4,7,2], limit = 5
    Output: 4 
    Explanation: The subarray [2,4,7,2] is the longest since the maximum absolute diff is |2-7| = 5 <= 5.
    
    Example 3: 
    Input: nums = [4,2,2,2,4,4,2,2], limit = 0
    Output: 3

    T.C : O(nlogn)
    S.C : O(n)
*/
