class Solution {
public:
    bool compHashmaps(unordered_map<char,int>&hashmap,unordered_map<char,int>&hashmap2) {
        int cnt = 0;
        for(auto entry: hashmap2) {
            // cout << "entry.first " << entry.first << " and entry.second " << entry.second << endl;
            // cout << "entry.first " << entry.first << " and hashmap[entry.first] "<< hashmap[entry.first] << endl;
            if(hashmap.find(entry.first) != hashmap.end())
                if(entry.second <= hashmap[entry.first])
                cnt++;
        }
        // for(auto entry: hashmap) {
        //     cout << entry.first << " --------> " << entry.second << endl;
        // }
        // cout <<"cnt is " << cnt << endl;
        if(hashmap2.size() == cnt) {
         return true;
        }
        
         return false;
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