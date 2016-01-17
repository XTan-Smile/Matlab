class Queue {
private:
  std::stack<int> curr;
public:
  // Push element x to the back of queue.
  void push(int x) {
    curr.push(x);
  }

  // Removes the element from in front of queue.
  void pop(void) {
    std::stack<int> temp_store;
    int len = curr.size();
    if (len <= 0) return;
    for (int i = 0; i < len; i++) {
      temp_store.push(curr.top());
      curr.pop();
    }
    temp_store.pop();
    for (int i = 0; i < len-1; i++) {
      curr.push(temp_store.top());
      temp_store.pop();
    }
  }

  // Get the front element.
  int peek(void) {
    std::stack<int> temp_store;
    int len = curr.size();
    if (!curr.empty()) {
      for (int i = 0; i < len-1; i++) {
	temp_store.push(curr.top());
	curr.pop();
      }
      int res = curr.top();
      for (int i = 0; i < len-1; i++) {
	curr.push(temp_store.top());
	temp_store.pop();
      }
      return res;
    }
  }

  // Return whether the queue is empty.
  bool empty(void) {
    return curr.empty();
  }
};
