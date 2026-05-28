class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //define 2d vector
        vector<vector<string>> res;
        // if strs is empty, return empty double vector
        if(strs.size()==0){
            return res;
        }
        //if strs size is one, return the double vector with single item
        else if(strs.size()==1){
            res.push_back({strs[0]});
            return res;
        }
        else{
            //define new mutable vec with strs
            //iterate through strs, i
            // j = i+1
            //for each i - get the unordered list
            //check for j's unordered list, and then if same store it in temp vec
            //define temp vec to store the anagrams
            //after each valid grouping, remove the anagrams from the replica vec<strings>
            // vector<string> m = strs;
            for(int i=0; i< strs.size(); i++){
                unordered_map<char, int> a;
                unordered_map<char, int> b;
                vector<string> temp;
                temp.push_back(strs[i]);
                for(int t=0; t<strs[i].size(); t++){
                    if(a.find(strs[i][t]) == a.end()){
                        a.insert({strs[i][t], 1});
                    }
                    else{
                        a[strs[i][t]]++;
                    }
                }

                for(int j=i+1; j<strs.size(); j++){
                     b.clear();
                    for(int u=0; u<strs[j].size(); u++){
                        if(b.find(strs[j][u]) == b.end()){
                            b.insert({strs[j][u], 1});
                        }
                        else{
                            b[strs[j][u]]++;
                        }
                    }

                    if(a==b){
                        temp.push_back(strs[j]);
                        //remove the strs[j] from the replica vector
                        strs.erase(strs.begin()+j);
                        j--;
                        
                    }
                   

                }
                res.push_back(temp);
                
            }





            return res;

        }

    }
};
