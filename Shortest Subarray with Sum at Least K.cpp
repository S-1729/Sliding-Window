class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque<pair<int,long long>>dq;
        int ans=INT_MAX;
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            while(!dq.empty() && dq.back().second>=sum)
                dq.pop_back();
            dq.push_back({i,sum});
            sum+=nums[i];
            while(!dq.empty() && dq.front().second<=sum-k){
                ans=min(ans,i-dq.front().first+1);
                dq.pop_front();
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};

/*
	Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. If there is no such subarray, return -1.
	A subarray is a contiguous part of an array.

	Example 1:
	Input: nums = [1], k = 1
	Output: 1
	
	Example 2:
	Input: nums = [1,2], k = 4
	Output: -1
	
	Example 3:
	Input: nums = [2,-1,2], k = 3
	Output: 3
	
	T.C : O(n)
	S.C : O(n)
*/
