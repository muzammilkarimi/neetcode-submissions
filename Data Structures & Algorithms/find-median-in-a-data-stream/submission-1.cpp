class MedianFinder {
public:
    priority_queue<int> mx_heap;
    priority_queue<int, vector<int>, greater<int>> mn_heap;
    MedianFinder() {
    }
    
    void addNum(int num) {
       if (mx_heap.empty() || num <= mx_heap.top()) {
            mx_heap.push(num);
        } else {
            mn_heap.push(num);
        }

        if(mn_heap.size()>mx_heap.size()) {
            mx_heap.push(mn_heap.top());
            mn_heap.pop();
        }
        else if(mn_heap.size()+1<mx_heap.size()){
            mn_heap.push(mx_heap.top());
            mx_heap.pop();
        }
    }
    
    double findMedian() {
        if(mx_heap.size()>mn_heap.size()){
            return (double)mx_heap.top();
        }
        return (double)((mx_heap.top()+mn_heap.top())/2.0);
    }
};
