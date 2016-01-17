class Stack {
private:
  std::queue<int> curr_queue;
public:
  // Push element x onto stack.
  void push(int x) {
    curr_queue.push(x);
  }

  // Removes the element on top of the stack.
  void pop() {
    std::queue<int> temp_queue;
    if (!curr_queue.empty()) {
      int len = curr_queue.size();
      for (int i = 0; i < len-1; i++) {
	temp_queue.push(curr_queue.front());
	curr_queue.pop();
      }
      curr_queue.pop();
      swap(temp_queue, curr_queue);
    }
  }

  // Get the top element.
  int top() {
    return curr_queue.back();
  }

  // Return whether the stack is empty.
  bool empty() {
    return curr_queue.empty();
  }
};
