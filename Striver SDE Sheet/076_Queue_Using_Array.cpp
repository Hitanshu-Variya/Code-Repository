class MyQueue {
  private:
  int arr[100005];
  int front;
  int rear;

  public:
  MyQueue() {
    front = 0;
    rear = 0;
  }

  void push(int);
  int pop();
};

void MyQueue::push(int x) {
  arr[front] = x;
  front++;
}

int MyQueue::pop() {
  if (rear == front)
    return -1;

  int num = arr[rear];
  rear++;
  return num;
}
