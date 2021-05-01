/* Given an array arr[] of N non-negative integers representing the height of blocks.
If width of each block is 1,
compute how much water can be trapped between the blocks during the rainy season. */

#include <iostream>

using namespace std;

int main()
{
  long long n;
  cout<<"Enter the number of buildings: ";
  cin>>n;
  long long arr[n];
  cout<<"Enter the size of buildings: ";
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  long long left[n];
  long long right[n];
  left[0]=arr[0];
  right[n-1]=arr[n-1];
  for(long long i=1;i<n;i++)
  {
      if(arr[i-1] > left[i-1])
      {
          left[i]=arr[i-1];
      }
      else{
        left[i]=left[i-1];
      }
  }
  for(long long i=n-2;i>=0;i--)
  {
      if(arr[i+1] > right[i+1])
      {
          right[i]=arr[i-1];
      }
      else{
        right[i]=right[i+1];
      }
  }
  int ans=0;
  for(long long i=0;i<n;i++)
  {
      if(left[i]>arr[i] && right[i]>arr[i])
      {
          ans+=min(left[i],right[i])-arr[i];
      }
  }
  cout<<"Amount of water that can be saved(in litres): "<<ans<<"\n";
  return 0;
}
