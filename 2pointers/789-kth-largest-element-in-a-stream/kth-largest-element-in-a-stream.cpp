class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<int> > minhp;
    KthLargest(int kthindex, vector<int>& nums) {
        k = kthindex;
        for(int i=0;i<nums.size();i++){
            minhp.push(nums[i]);
            if(minhp.size() > k){
                minhp.pop();
            }
        }
    }
    
    int add(int val) {
        minhp.push(val);
        if(minhp.size() > k){
            minhp.pop();
        }
        return minhp.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */