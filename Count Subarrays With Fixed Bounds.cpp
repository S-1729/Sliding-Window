class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans=0;
        int minkPosition=-1;
        int maxkPosition=-1;
        int culpritIdx=-1;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]<minK || nums[i]>maxK)
                culpritIdx=i;
            if(nums[i]==minK)
                minkPosition=i;
            if(nums[i]==maxK)
                maxkPosition=i;
            int smaller=min(minkPosition,maxkPosition);
            int temp=smaller-culpritIdx;
            ans+= temp<=0 ? 0 : temp;
        }
        return ans;
    }
};

/*
	You are given an integer array nums and two integers minK and maxK.
	A fixed-bound subarray of nums is a subarray that satisfies the following conditions:
		The minimum value in the subarray is equal to minK.
		The maximum value in the subarray is equal to maxK.
	Return the number of fixed-bound subarrays.
	A subarray is a contiguous part of an array.

	Example 1:
	Input: nums = [1,3,5,2,7,5], minK = 1, maxK = 5
	Output: 2
	Explanation: The fixed-bound subarrays are [1,3,5] and [1,3,5,2].
	
	Example 2:
	Input: nums = [1,1,1,1], minK = 1, maxK = 1
	Output: 10
	Explanation: Every subarray of nums is a fixed-bound subarray. There are 10 possible subarrays.

	T.C : O(n)
*/
