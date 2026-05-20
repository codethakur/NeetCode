class MedianFinder {

    // smaller half
    priority_queue<int> maxHeap;

    // larger half
    priority_queue<
        int,
        vector<int>,
        greater<int>
    > minHeap;

public:

    MedianFinder() {

    }


    void addNum(int num) {

        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        if(minHeap.size() > maxHeap.size()) {

            maxHeap.push(minHeap.top());

            minHeap.pop();
        }
    }


    double findMedian() {
        // odd count
        if(maxHeap.size() > minHeap.size()) {

            return maxHeap.top();
        }


        // even count
        return (maxHeap.top() + minHeap.top()) / 2.0;

    }
};
