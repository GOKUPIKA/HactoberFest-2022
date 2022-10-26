// Question: Permutation
// Platform: Leetcode
// Diffulty: Medium

// **2 APPROACHES:**
// * **OPTIMIZE APPROACH**
// * **BRUTE FORCE APPROACH**

// **OPTIMIZE APPROACH: Using Recursion without any extra space**

class Solution {
public:
    
    //RECURSIVE FUNCTION
    void recurPermutation(int ind, vector<int>&nums, vector<vector<int>>&ans){
        if(ind==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=ind;i<nums.size();i++){
            swap(nums[ind],nums[i]);
            recurPermutation(ind+1, nums, ans);
            swap(nums[ind],nums[i]);
        }
    }
    
    //MAIN FUNCTION
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        recurPermutation(0,nums,ans);
        return ans;
    }
    
};


// **EXPLANATION:**
// We do this question using the recursive approach

// * **Main Function:**
// 1. First we make the answer vector which will store the answer permutations.
// 2. Then we call the recursive function passing index=0; given vector=nums; answer vector=ans;

// * **Recursive Function:**
// 1. The return type of function is void because we are not returning, we are making changes in the given data.
// 2. The base condition of the function is the when our index reaches the end of given vector (nums) then we push the given vector (with changes) in answer vector.
// 3. Then we iterate the given vector named nums from index ---n-1.
// 4. In the for loop we swap the index and value and i value so that its allow all the possible permutation
// 5. Then we call the recursive function again with increment in index by 1 (ind+1).
// 6. In last we return the value to their origina places so that its stay the original after recursive call



// **BRUTE FORCE: Using Recursion + Extra Storage**

class Solution {
public:
    
    //RECURSIVE FUNCTION
    void recurPermutation(vector<int>&ds, vector<int>&nums, vector<vector<int>>&ans, int freq[]){
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }        
        for(int i=0;i<nums.size();i++){
            if(!freq[i]){
                ds.push_back(nums[i]);
                freq[i]=1;
                recurPermutation(ds, nums, ans, freq);
                freq[i]=0;
                ds.pop_back();
            }
        }
    }
    
    //MAIN FUNCTION
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        int freq[nums.size()];
        for(int i=0;i<nums.size();i++){
            freq[i]=0;
        }
        recurPermutation(ds, nums, ans, freq);
        
        return ans;
    }

};


// **EXPLANATION:**
// We do this question using the recursive approach with extra space.

// * **Main Function:**
// 1. First we make the answer vector which will store the answer permutations.
// 2. Then we make the frequency array to store the visited index 
// 3. Then we make the ds vector to store the permutation of every recursive call
// 4. Then we call the recursive function passing permutation vector =ds; given vector=nums, answer vector=ans; frequency array=freq;

// * **Recursive Function:**
// 1. The return type of function is void because we are not returning, we are making changes in the given data.
// 2. The base condition of the function is the when our index reaches the end of given vector (nums) then we push the given vector (with changes) in answer vector.
// 3. We iterate over the given vector (nums) till end using for loop
// 4. In loop we first check the if we already visited the current index in freq array in yes then we move to next iteration; if not visited that means this is the first time we are visiting this index.
// 5. If the index is not visited; then we push the current index value in the permutation vector, after that we mark the current index in frequency array as visited.
// 6. Then we call the recursive call and after the recursive call we remove the element from permutation vector (to make its the original vector for further recursion calls)
