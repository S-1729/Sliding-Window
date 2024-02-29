class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minSize=INT_MAX,i=0,sum=0;
        for(int j=0;j<nums.size();j++){
            sum+=nums[j];
            while(sum>=target){
                minSize=min(minSize,j-i+1);
                sum-=nums[i];
                i++;
            }
        }
        return minSize==INT_MAX?0:minSize;
    }
};

/*
	Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. 
	If there is no such subarray, return 0 instead.
	
	Example 1:
	Input: target = 7, nums = [2,3,1,2,4,3]
	Output: 2
	Explanation: The subarray [4,3] has the minimal length under the problem constraint.
	
	Example 2:
	Input: target = 4, nums = [1,4,4]
	Output: 1
	
	Example 3:
	Input: target = 11, nums = [1,1,1,1,1,1,1,1]
	Output: 0
	
	T.C : O(n)
*/
