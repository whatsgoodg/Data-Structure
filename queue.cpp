#include <iostream>
using namespace std;

class Q {
private:
	int* arr; //배열
	int front; //맨 앞 포인터
	int rear; //맨 뒤 포인터
	int size; //크기
public:
	Q(int size) {
		this->size = size + 1;
		arr = new int[this->size];
		front = rear = 0;
	}
	bool empty() {
		return front == rear;
	}
	int Size() {
		return (rear - front + size) % size;
	}
	bool full() {
		return Size() + 1 == size;
	}
	void enqueue(int value) {//삽입
		if (full()) {//꽉 차 있을 시
			cout << "Full" << endl;
			return;
		}
		rear = (rear + 1) % size;
		arr[rear] = value;
	}
	void dequeue() {//삭제
		if (empty()) {//비어 있을 시 
			cout << "Empty" << endl;
			return;
		}
		cout << arr[(++front) % size] << endl;
		front = front % size;
	}
};
