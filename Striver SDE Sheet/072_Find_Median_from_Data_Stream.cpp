class MedianFinder {
  private:
  priority_queue<int> maxHeap;
  priority_queue<int, vector<int>, greater<int>> minHeap;

  public:
  MedianFinder() {}
  void addNum(int num) {
    maxHeap.push(num);
    minHeap.push(maxHeap.top());
    maxHeap.pop();

    if (minHeap.size() > maxHeap.size()) {
      maxHeap.push(minHeap.top());
      minHeap.pop();
    }
  }

  double findMedian() {
    if (maxHeap.size() == minHeap.size())
      return (double)((maxHeap.top() + minHeap.top()) * 1.0) / 2;
    else
      return maxHeap.top();
  }
};