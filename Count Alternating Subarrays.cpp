class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long ans=0,i=0;
        for(int j=0;j<nums.size();j++){
            if(j!=0 && nums[j]==nums[j-1])
                i=j;
            ans+=(j-i+1);
        }
        return ans;
    }
};

/*
	You are given a binary array nums.
	We call a subarray alternating if no two adjacent elements in the subarray have the same value.
	Return the number of alternating subarrays in nums.

	Example 1:
	Input: nums = [0,1,1,1]
	Output: 5
	Explanation:
	The following subarrays are alternating: [0], [1], [1], [1], and [0,1].
	
	Example 2:
	Input: nums = [1,0,1,0]
	Output: 10
	Explanation:
	Every subarray of the array is alternating. There are 10 possible subarrays that we can choose.

	T.C : O(n)
*/
