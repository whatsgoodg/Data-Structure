#include <iostream>
#include <vector>
using namespace std;
// 벡터와 포인터를 이용한 일반 트리 
// 중복된 키가 없다고 가정

/*
* Node: 부모 노드와 모든 자식 노드의 포인터 list
* Tree: root 노드, 모든 노드의 포인터 list

* insert: 
1. nodes list 삽입
2. 부모 chil 삽입
3. 삽입된 노드의 부모 포인터 초기화

* remove
1. 삭제될 노드의 자식들을 부모에게 전달
2. 삭제할 노드의 부모 list에서 삭제
3. nodes list에서 삭제.
*/
class Node {
private:
	int data; //원소 값
	Node* par; //부모 포인터
	vector<Node*> chil; // 자식 노드
	friend class Tree; 
public:
	Node(int data) {
		this->data = data;
		this->par = NULL;
	}
};

class Tree {
private:
	Node* root; //root 노드
	vector<Node*> nodes; //tree의 모든 노드들
public:
	Tree(int data) {
		Node* new_node = new Node(data); //root 초기화
		root = new_node;
		nodes.push_back(new_node);
		root->par = NULL;
	}
	void insert(int par_data, int data) {//부모 key에 새로운 노드 할당
		for (int i = 0; i < nodes.size(); i++) {
			if (nodes[i]->data = par_data) { 
				Node* new_node = new Node(data);
				nodes.push_back(new_node);
				new_node->par = nodes[i];
				nodes[i]->chil.push_back(new_node);
				return;
			}
		}
	}
	
	void remove(int data) { //key가 data인 노드 삭제
		Node* cur_node;
		Node* par_node;
		for (int i = 0; i < nodes.size(); i++) {
			if (nodes[i]->data == data) {
				if (nodes[i] == root) { //루트 노드일 시 예외처리
					return;
				}
			}
			//삭제할 노드의 부모에게 자식 전달
			cur_node = nodes[i];
			par_node = cur_node->par;
			for (Node* child : cur_node->chil) {
				par_node->chil.push_back(child);
				child->par = par_node;
			}
			//삭제할 노드의 부모의 벡터에서 삭제
			for (int j = 0; j < par_node->chil.size(); j++) {
				if (par_node->chil[i]->data = data) {
					par_node->chil.erase(par_node->chil.begin() + j);
				}
			}
			//nodes에서 삭제
			nodes.erase(nodes.begin() + i);
			delete cur_node;
			return;
		}
	}
	Node* parent(int x) { //x 키를 가진 노드의 부모 노드
		if (root->data == x) {
			return NULL;
		}
		for (int i = 0; i < nodes.size(); i++) {
			if (nodes[i]->data == x) {
				return nodes[i]->par;
			}
		}
		return NULL;
	}
	vector<Node*>* child(int x) { //x 키를 가진 node의 자식들
		for (int i = 0; i < nodes.size(); i++) {
			vector<Node*> chil_list;
			if (nodes[i]->data == x) {
				if (nodes[i]->chil.size() == 0) {
					return NULL; //size is 0;
				}
				for (int j = 0; j < nodes[i]->chil.size(); j++) {
					chil_list.push_back(nodes[i]->chil[j]);
				}
				return &(chil_list);
			}
		}
	}
	Node* get_root() { return root; }
	void preorder(Node* node) { //전위 순회
		if (!node) return;

		cout << node->data << ' ';
		for (int i = 0; i < node->chil.size(); i++) {
			preorder(node->chil[i]);
		}
	}
	void postorder(Node* node) {//후위 순회
		if (!node) return;

		for (int i = 0; i < node->chil.size(); i++) {
			postorder(node->chil[i]);
		}
		cout << node->data << ' ';
	}
};
