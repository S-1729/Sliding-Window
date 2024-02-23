class Solution {
public:
    typedef pair<int,int>P;
    int constrainedSubsetSum(vector<int>& nums, int k) {
        priority_queue<P>pq;
        pq.push({nums[0],0});
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            while(!pq.empty() && i-pq.top().second>k)
                pq.pop();
            nums[i]=max(nums[i],nums[i]+pq.top().first);
            ans=max(ans,nums[i]);
            pq.push({nums[i],i});
        }
        return ans;
    }
};

/*
	Given an integer array nums and an integer k, return the maximum sum of a non-empty subsequence of that array 
	such that for every two consecutive integers in the subsequence, nums[i] and nums[j], where i < j, the condition j - i <= k is satisfied.

	A subsequence of an array is obtained by deleting some number of elements (can be zero) from the array, leaving the remaining elements in their original order.

	Example 1:
	Input: nums = [10,2,-10,5,20], k = 2
	Output: 37
	Explanation: The subsequence is [10, 2, 5, 20].
	
	Example 2:
	Input: nums = [-1,-2,-3], k = 1
	Output: -1
	Explanation: The subsequence must be non-empty, so we choose the largest number.
	
	Example 3:
	Input: nums = [10,-2,-10,-5,20], k = 2
	Output: 23
	Explanation: The subsequence is [10, -2, -5, 20].

	T.C : O(n)
	S.C : O(n)
*/
