class Solution {
public:
    bool isAnagram(string s, string t) {
        //length not same -> not an anagram
        if(s.length() != t.length())
            return false;
        //define unordered map
        unordered_map<int, int> m;
        for(int i=0; i<s.length(); i++){
            if(m.find(s[i])==m.end()){
                m.insert({s[i], 1});
            }
            else{
                m[s[i]]++;
            }
        }
        //iterate through t and insert in map - o(1)
        unordered_map<int, int> n;
        for(int i=0; i<t.length(); i++){
            if(n.find(t[i])==n.end()){
                n.insert({t[i], 1});
            }
            else{
                n[t[i]]++;
            }
        }
        //check if both are equal
        if(m==n){
            return true;
        }

        return false;
    }
};
