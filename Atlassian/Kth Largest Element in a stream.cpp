class KthLargest {
public:
   priority_queue<int> minHeap;
    int key;
    KthLargest(int k, vector<int>& nums) {
        key=k;
        for(auto elm: nums)
        {
            minHeap.push(-elm);
        }
    }
    
    int add(int val) {
        minHeap.push(-val);
        while(minHeap.size()>key)
        {
            minHeap.pop();
        }
        return -minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */