class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(auto& n:strs){
            string sorted = n;
            sort(sorted.begin(),sorted.end());
            mp[sorted].push_back(n);
        }
        vector<vector<string>> ans;
        for(auto & i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};
