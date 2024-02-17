class TimeMap {
public:
    unordered_map<string, vector<pair<string,int>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        vector<pair<string, int>> &v = mp[key]; //to avoid TLE using reference of the vector in the map
        string ans;
        // v = mp[key];
        int start = 0;
        int end = v.size()-1;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(v[mid].second == timestamp)
                return v[mid].first;
            if(v[mid].second < timestamp){
                ans=v[mid].first; //possible answer, if exact timestamp value is not found
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return ans;
    }

    
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */