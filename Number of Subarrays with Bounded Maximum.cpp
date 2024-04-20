class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int windowSize=0,ans=0,i=0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]>right){
                i=j+1;
                windowSize=0;
            }
            if(nums[j]>=left && nums[j]<=right)
                windowSize=j-i+1;
                
            ans+=windowSize;
        }
        return ans;
    }
};

/*
	Given an integer array nums and two integers left and right, return the number of contiguous non-empty subarrays such that the value of the maximum array element in that subarray is in the range [left, right].
	The test cases are generated so that the answer will fit in a 32-bit integer.
	
	Example 1:
	Input: nums = [2,1,4,3], left = 2, right = 3
	Output: 3
	Explanation: There are three subarrays that meet the requirements: [2], [2, 1], [3].
	
	Example 2:
	Input: nums = [2,9,2,5,6], left = 2, right = 8
	Output: 7
	
	T.C : O(n)
*/
