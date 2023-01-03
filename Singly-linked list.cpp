#include <iostream>
using namespace std;
// delete 처리 x
class Node {
private:
	int elem; // 데이터
	Node* next; // 다음 노드를 가리키는 포인터
	friend class Slist;
public:
	Node(int data) {
		this->elem = data;
		next = NULL;
	}
};

class Slist {
private:
	Node* tail; // 맨 마지막 노드
	Node* head; // 맨 처음 노드
public:
	Slist() {
		tail = NULL;
		head = NULL;
	}
	bool empty() { return tail == NULL && head == NULL; }
	void print() { // 모든 노드 출력
		if (empty()) {
			cout << "empty" << endl;
			return;
		}
		Node* cur_node = head;
		while (cur_node != tail) {
			cout << cur_node->elem << " ";
			cur_node = cur_node->next;
		}
		cout << cur_node->elem << endl;
	}
	int list_size() { // 리스트 크기
		int count = 0;
		if (empty()) {
			cout << count << endl;
			return count;
		}
		Node* cur_node = head;
		while (cur_node != tail) {
			cur_node = cur_node->next;
			count++;
		}
		return ++count;

	}
	void append(int data) { // 맨 뒤에 삽입
		if (empty()) { // 비어있을 때
			Node* node = new Node{ data };
			tail = node;
			head = node;
		}
		else { // 비어있지 않을 때
			Node* node = new Node{ data };
			tail->next = node;
			tail = node;
		}
	}
	void Insert(int i, int x) { // 삽입
		if (i > list_size()) {
			cout << "OutOfBound" << endl;
			return;
		}
		else if (i == list_size()) { // 맨 뒤에 삽입
			append(x);
			return;
		}
		else { // 중간에 삽입
			if (i == 0) {
				if (empty()) { // 맨 앞 삽입이지만 비어있을 때
					append(x);
				}
				else { // 비어있지 않을 때
					Node* node = new Node{ x };
					node->next = head;
					head = node;
				}
			}
			else { // 노드 사이에 삽입
				int count = 0;
				Node* cur_node = head;
				Node* pre_node = NULL;
				while (count != i) {
					pre_node = cur_node;
					cur_node = cur_node->next;
					count++;
				}
				Node* node = new Node{ x };
				pre_node->next = node;
				node->next = cur_node;

			}
		}
	}
	void remove(int i) {
		int a;
		if (empty() || i >= list_size()) { //예외
			cout << -1 << endl;
			return;
		}
		else if (i == 0) { // 맨 앞 삭제
			if (list_size() == 1) { // 크기가 1일 때
				a = head->elem;
				head = NULL;
				tail = NULL;
			}
			else { // 1이 아닐 때 
				a = head->elem;
				head = head->next;
			}
		}
		else { // 노드 사이에 있을 때
			Node* node = head;
			Node* pre_node = NULL;
			int cnt = 0;
			while (cnt != i) { //노드를 찾음
				pre_node = node;
				node = node->next;
				cnt++;
			}
			if (node == tail) { // 마지막 노드일 때
				a = node->elem;
				tail = pre_node;
			}
			else { // 마지막 노드가 아닐 때
				a = node->elem;
				pre_node->next = node->next;
			}
		}
	}
};
