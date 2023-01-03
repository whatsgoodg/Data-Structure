#include <iostream>
using namespace std;

class Stack {
private:
	int topIndex; //마지막으로 들어온 원소의 인덱스
	int* arr; //배열
	int size; // 크기
public:
	Stack(int size) {
		topIndex = -1;
		this->size = size;
		arr = new int[size];
	}
	bool empty() {
		return topIndex == -1;
	}
	int s_size() {
		return topIndex + 1;
	}
	bool full() {
		return topIndex + 1 == size;
	}
	void push(int value) {
		if (full()) { // 꽉 차있을 경우
			cout << "Full" << endl;
			return;
		}
		arr[++topIndex] = value;
	}
	void pop() {
		if (empty()) { // 비어있을 경우 
			cout << -1 << endl;
			return;
		}
		cout << arr[topIndex] << endl;
		topIndex--;
	}
	void top() {
		if (empty()) { // 비어있을 경우
			cout << -1 << endl;
			return;
		}
		cout << arr[topIndex] << endl;
	}
};
