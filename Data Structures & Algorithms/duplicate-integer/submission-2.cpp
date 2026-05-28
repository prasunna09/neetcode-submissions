class Solution {
public:
    // bool hasDuplicate(vector<int>& nums) {
    //     for(int i=0; i<nums.size(); i++){
    //         for(int j = i+1; j< nums.size(); j++){
    //             if (nums[i]==nums[j])
    //                 return true;
    //         }
    //     }
    //     return false;
        
    // }
    bool hasDuplicate(vector<int>& nums) {
        //define a map
        //iterate through nums and insert in map
        //first fine id m.find(key) == m.end()
        //then insert 
        //else return true

        map<int, int> m;
        for (int i=0; i<nums.size(); i++){
            if(m.find(nums[i]) == m.end()){
                m.insert({nums[i], 1});
            }else{
                return true;
            }
        }
        return false;
        
    }
    
};