class Solution { // can be done with dp or trie also
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>> map;
        
        int l = strs.size();
        
        for(int i=0;i<l;i++){
            
            string s = strs[i];
            
            sort(s.begin(),s.end());
            
            map[s].push_back(strs[i]);
        }
        
        vector<vector<string>> result;
        
        for(auto s: map){
            result.push_back(s.second);
        }
        
        return result;
    }
};
