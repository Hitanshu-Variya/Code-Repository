class MyStack {
  private:
  queue<int> queue;

  public:
  MyStack() {}

  void push(int x) {
    int size = queue.size();
    queue.push(x);

    for (int i = 0; i < size; i++) {
      queue.push(queue.front());
      queue.pop();
    }
  }

  int pop() {
    if (queue.empty())
      return -1;

    int num = queue.front();
    queue.pop();
    return num;
  }

  int top() {
    if (queue.empty())
      return -1;
    return queue.front();
  }

  bool empty() { return queue.empty(); }
};
