class Solution {
public:
    bool compHashmaps(unordered_map<char, int> &hashmap, unordered_map<char, int> &hashmap1)
    {
        for (auto entry : hashmap1)
        {
            if (hashmap.find(entry.first) == hashmap.end() || hashmap[entry.first] < hashmap1[entry.first])
            {
                return false;
            }
        }
        return true;
    }


    string minWindow(string s, string t) {
        if(t.size() > s.size()) 
        return "";
        // initiate two pointer 
        int i = 0; 
        int j = 0;
        unordered_map<char,int>hashmap2;
        for(char c : t) 
        hashmap2[c]++;
        int resSize = INT_MAX;
        int resi = 0;
        unordered_map<char,int>hashmap;
        while(j < s.size()) {
            // If the condition is true
            hashmap[s[j]]++;
            // cout << "Included " << s[j] << " into the hashmap and made hashmap[" << s[j] << "] = " << hashmap[s[j]] << endl;
            while(compHashmaps(hashmap,hashmap2)) {
                // cout << "I'm in" << endl;
                if(resSize > j-i+1) {
                // cout << s[i] << "," << s[j] << endl;
                resSize = j-i+1;
                resi = i;
                // cout <<  s.substr(resi,resSize) << endl;
                }
                hashmap[s[i]]--;
                i++;  
        }
        j++;   
     }
        if(resSize != INT_MAX)
        return s.substr(resi,resSize);

        return "";
}
};