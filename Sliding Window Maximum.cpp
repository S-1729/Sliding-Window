class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        deque<int>dq;
        for(int i=0;i<nums.size();i++){
            if(!dq.empty() && i-k==dq.front())
                dq.pop_front();
            while(!dq.empty() && nums[i]>=nums[dq.back()])
                dq.pop_back();
            dq.push_back(i);
            if(i+1>=k)
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};

/*
	You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. 
	You can only see the k numbers in the window. Each time the sliding window moves right by one position.

	Return the max sliding window.
	
	Example :
	Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
	Output: [3,3,5,5,6,7]
	Explanation: 
	Window position                Max
	---------------               -----
	[1  3  -1] -3  5  3  6  7       3
	 1 [3  -1  -3] 5  3  6  7       3
	 1  3 [-1  -3  5] 3  6  7       5
	 1  3  -1 [-3  5  3] 6  7       5
	 1  3  -1  -3 [5  3  6] 7       6
	 1  3  -1  -3  5 [3  6  7]      
	 
	T.C : O(n)
	S.C : O(k)
*/
