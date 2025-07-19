class SortedStack {
  public:
  stack<int> s;
  void sort();
};

void insert(stack<int> &s, int &num) {
  if (s.empty() || num > s.top()) {
    s.push(num);
    return;
  }

  int top_num = s.top();
  s.pop();
  insert(s, num);

  s.push(top_num);
}

void SortedStack::sort() {
  if (!s.empty()) {
    int num = s.top();
    s.pop();
    sort();

    insert(s, num);
  }
}