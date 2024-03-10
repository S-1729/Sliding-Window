class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int sum=0,i=0,ans=0;
        unordered_set<int>s;;
        for(int j=0;j<nums.size();j++){
            while(s.find(nums[j])!=s.end()){
                sum-=nums[i];
                s.erase(nums[i]);
                i++;
            }
            s.insert(nums[j]);
            sum+=nums[j];
            ans=max(ans,sum);
        }
        return ans;
    }
};


//Code-2
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int sum=0,i=0,ans=0;
        unordered_map<int,int>mp;
        for(int j=0;j<nums.size();j++){
            mp[nums[j]]++;
            while(mp[nums[j]]>1){
                sum-=nums[i];
                mp[nums[i]]--;
                i++;
            }
            sum+=nums[j];
            ans=max(ans,sum);
        }
        return ans;
    }
};

/*
	You are given an array of positive integers nums and want to erase a subarray containing unique elements. The score you get by erasing the subarray is equal to the sum of its elements.
	Return the maximum score you can get by erasing exactly one subarray.
	An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).

	Example 1:
	Input: nums = [4,2,4,5,6]
	Output: 17
	Explanation: The optimal subarray here is [2,4,5,6].
	
	Example 2:
	Input: nums = [5,2,1,2,5,2,1,2,5]
	Output: 8
	Explanation: The optimal subarray here is [5,2,1] or [1,2,5].

	T.C : O(n)
	S.C : O(n)
*/
