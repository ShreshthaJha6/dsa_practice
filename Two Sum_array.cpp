//Given an array of integer nums and an integer target, return indices of the two numbers such that they add up to the target.
//Assume that each input has exactly one solution and that you may not use the same element twice.

//MY APPROACH: Basic
#include <iostream>;
using namespace std;
bool twoSum(int A[], int size. int target){
  for(int i=0;i<size-1;i++){
    for(int j=(i+1);j<size-1;j++){
      if(A[i]+A[j]==target){
        return 1;
      }
    }
  }
  return 0;
}
//Time=O(n^2) Space=o(1)
//check
int main(){
  int Arr[]={2,7,11,15};
  int target=9;
  int size=sizeof(A)/sizeof(A[0]);
  if(twoSum(A,size,target)==1){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
  return 0;
}
