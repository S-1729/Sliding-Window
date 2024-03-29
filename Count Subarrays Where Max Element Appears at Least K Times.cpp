class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans=0,c=0,n=nums.size(),i=0;
        int maxm=*max_element(begin(nums),end(nums));
        for(int j=0;j<n;j++){
            if(nums[j]==maxm)
                c++;
            while(c>=k){
                ans+=(n-j);
                if(nums[i]==maxm)
                    c--;
                i++;
            }
        }
        return ans;
    }
};

/*
	You are given an integer array nums and a positive integer k.
	Return the number of subarrays where the maximum element of nums appears at least k times in that subarray.
	A subarray is a contiguous sequence of elements within an array.

	Example 1:
	Input: nums = [1,3,2,3,3], k = 2
	Output: 6
	Explanation: The subarrays that contain the element 3 at least 2 times are: [1,3,2,3], [1,3,2,3,3], [3,2,3], [3,2,3,3], [2,3,3] and [3,3].
	
	Example 2:
	Input: nums = [1,4,2,1], k = 3
	Output: 0
	Explanation: No subarray contains the element 4 at least 3 times.

	T.C : O(n)
*/
