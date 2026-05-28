class Solution {
public:

    string encode(vector<string>& strs) {
        string s;
        for(int i=0; i<strs.size(); i++){
            int size = strs[i].length();
            s.append(to_string(size));
            s.append("#");
            s.append(strs[i]);
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> str;

        int i = 0;

        while (i < s.length()) {

            int j = i;
            while (s[j] != '#') {
                j++;
            }
            int size = stoi(s.substr(i, j - i));
            j++;
            string temp = s.substr(j, size);

            str.push_back(temp);
            i = j + size;
        }

        return str;
    }
};
