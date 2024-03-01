vector<long long> printFirstNegativeInteger(long long int A[],
    long long int N, long long int K) {
    deque<long long>dq;
    vector<long long>ans;
    long long i=0;
	for(long long j=0;j<N;j++){
    	if(A[j]<0)
        	dq.push_back(A[j]);
        if(j-i+1==K){
        	if(!dq.empty())
				ans.push_back(dq.front());
            else
	    		ans.push_back(0);
                          
            if(A[i]==dq.front())
                dq.pop_front();
            i++;
        }
    }
	return ans;
 }
 
 /*
 	Given an array A[] of size N and a positive integer K, find the first negative integer for each and every window(contiguous subarray) of size K.
 	
 	Input : 
	N = 8
	A[] = {12, -1, -7, 8, -15, 30, 16, 28}
	K = 3
	Output :
	-1 -1 -7 -15 -15 0 
	
	T.C : O(n)
	S.C : O(k)
*/
