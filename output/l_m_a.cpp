#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>

class Solution{
  public:
    int longestMountain(vector<int>& arr){ // Method to find the longest mountain subarray
      int n=arr.size(); // Get array size
      if (n<3) {return 0}; // Check array size is as expected (greater or equal to 3)

      int longest=0;
      for (int i=0;i<n; ++i){ // Look for peaks (number greater than both neighbors)
        if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
          int left=i-1; // We go to the left in search of beginning of sequence
          while (left>0 && arr[left]>arr[left-1]){
            --left;
          }

          int right=i+1; // Similarly, expand right in contrary case
          while (right>0 && arr[right]>arr[right-1]){
            ++right;
          }

          int mount_length = right-left+1; // We need the length of current mountain
          longest = max(longest, mount_length); 
          i=right;
        }
      }
      return longest; // Return desired value
    }
}






int main(){
  // Give some tests to try and see if any error arises
  Solution solution; // Object of defined class
  vector<vector<int>> testCases = {
    {1,2,3,4,5,6,7}, // Simple one, asc
    {7,6,5,4,3,2,1}, // Simple ones, desc
    {1,1,1}, // All equal, limit size
    {1,2,3}, // Limit size
    {2,4,0,2,4,0,2,4,8,0,2,4}, // Longer one, several changes
    {8,4,2,0,2,4}, // Desc
    {0,0,0,2,3,4,0,0,8,7,6,5} // Long, diverse
    //{100,200,300,400,300,100}
  }

  vector<int> expect = {
    0, // No peak, simply asc
    0, // No peak, simply desc
    0, // All elements same
    0, // Only two different
    3, // Given by {2,4,0} 
    0,
    6
  }

  for (size_t i=0; i<testCases.size(); i++){
    int res = solution.longestMountain(testCases[i]);
    cout << "Test " << i+1 << ": ";
    /*
    if(result == expect[i]){
      cout << "Correct";
    } else {
      cout << "Failed (Expect: )" << expect[i] << " but get " << res << ")";
    }
    */
   cout << res;
   cout << endl;
  }

  return 0;
}