class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        vector<pair<int, int>> temp;
        unordered_map<int, int> m;
        for(int i=0; i<nums.size(); i++){
            if(m.find(nums[i]) == m.end()){
                m.insert({nums[i], 1});
            }else{
                m[nums[i]]++;
            }
        }
        for(auto const& [key, val]: m){
            temp.push_back({val, key});
        }
        sort(temp.rbegin(), temp.rend());
        for(int j=0;j<k; j++){
            res.push_back(temp[j].second);
        }
        if(res.size()==0){
            res = nums;
        }

        return res;
        
    }
};
