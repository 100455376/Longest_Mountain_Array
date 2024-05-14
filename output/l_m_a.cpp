#include <iostream>


#include <vector>
#include <algorithm>

using namespace std;

class Solution{
  public:
    int longestMountain(vector<int>& arr){ // Method to find the longest mountain subarray
      int n=arr.size(); // Get array size
      if (n<3) {return 0;} // Check array size is as expected (greater or equal to 3)

      int longest=0;
      for (int i=1;i<n-1; ++i){ // Look for peaks (number greater than both neighbors)
        if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
          int left=i-1; // We go to the left in search of beginning of sequence
          while (left>0 && arr[left]>arr[left-1]){
            --left;
          }

          int right=i+1; // Similarly, expand right in contrary case
          while (right<n-1 && arr[right]>arr[right+1]){
            ++right;
          }

          int mount_length = right-left+1; // We need the length of current mountain
          longest = max(longest, mount_length); 
          i=right;
        }
      }
      return longest; // Return desired value
    }
};

int main(){
  // Give some tests to try and see if any error arises
  Solution solution; // Object of defined class
  vector<vector<int> > test_cases={
        {1, 2, 3, 4, 5, 6, 7}, // Simple one, asc
        {7, 6, 5, 4, 3, 2, 1}, // Simple one, desc
        {1, 1, 1}, // All equal, limit size
        {1, 2, 3}, // Limit size
        {2, 4, 0, 2, 4, 0, 2, 4, 8, 0, 2, 4}, // Longer one, several changes
        {8, 4, 2, 0, 2, 4}, // Desc
        {0, 0, 0, 2, 3, 4, 0, 0, 8, 7, 6, 5}, // Long, diverse
        {2, 1, 4, 7, 3, 2, 5}, // Another
        {2, 2, 2}, // All the same
        {0, 1, 0}, // Minimal valid mountain
        {2, 3, 3, 2, 0, 2, 3, 4, 5, 2, 1, 0}, // Mixed asc and dsc
        {875, 884, 239, 731, 723, 685} // Random large numbers
    };

    vector<int> exp_res={
      0, 0, 0, 0, 5, 0, 5, 5, 0, 3, 8, 4   
    };

  for (size_t i=0; i<test_cases.size(); i++){ // Iterate over all the test cases above indicated
    int res = solution.longestMountain(test_cases[i]);
    cout << "Test " << i+1 << ": ";
    
    if(res==exp_res[i]){ // Check, by comparing, when we get desired value
      cout << "Correct";
    } else { // and when not
      cout << "Failed (Expect: " << exp_res[i] << " but get: " << res << ")";
    }
   cout << endl;
  }
  return 0;
}