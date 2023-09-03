//TWO SUM using vectors and HASHMAP: given is an array of integers and an integer value= target. return the indices of the two numbers such that they add up to the target number.
//each input will have exactly one solution.

//we are using a hashmap. we will map each of value to the index of each value. VALUE:INDEX
//instead of adding the entire array to the hashmap first and then looking for the element... I will take the first element and add it to the hashmap and then look for the second element.
// search and then add to the hashmap
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n= nums.size();
        unordered_map<int, int> mp; //val->index
        for(int i=0;i<n;i++){
            int compliment= target-nums[i];
            if(mp.find(compliment)!=mp.end()){
                return {mp[compliment],i};
            }
            mp.insert({nums[i],i});
        }
        return {};
    }
};
