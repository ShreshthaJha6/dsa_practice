//given any integer array- nums. 
//returns TRUE if any value appears at least twice and FALSE if every statement is distinct
//MY IDEA: can use linear search. make int count=0 and in case of duplicate- count++. if count>0 return true; else return false;
// time: O(n^2) memory: O(1)
//SORTING: all the duplicates will come adjacent to each other. so we will have to move through the array once.
//time: O(nlong) memory: O(1)
// USE HASHSET
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++){
            if(s.find(nums[i])!=s.end()){
                return true;
            }
            s.insert(nums[i]);
        }
        return false;
    }
};
