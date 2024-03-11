class Solution{
public:	
  /*
  Complexity Analysis:-)
  Time Complexity - O(mlog(m))
  Space Complexity - O(m)
  where m is total number of element in the matrix i.e. m = n^2.
  */	
	int countPairs(vector<vector<int>>&mat1,vector<vector<int>>&mat2,
	int n, int x){
	    vector<int> arr1;
	    vector<int> arr2;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            arr1.push_back(mat1[i][j]);
	            arr2.push_back(mat2[i][j]);
	        }
	    }
	    int count=0;
	    for(int i=0;i<arr1.size();i++){
	        int ele1=arr1[i];
	        int rem=x-ele1;
	        if(binary_search(arr2.begin(),arr2.end(),rem)){
	            count++;
	        }
	    }
	return count;
	}
};
