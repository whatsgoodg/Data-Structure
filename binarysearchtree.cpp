#include <iostream>
using namespace std;

struct node {
	int key; // 노드의 key 값
	node* parent; // 부모 포인터
	node* right; // 오른쪽 자식 포인터
	node* left; // 왼쪽 자식 포인터
	node(int key) {
		this->key = key;
		parent = right = left = NULL;
	}
};

class BST {
private:
	node* root; //root 노드 포인터
public:
	BST() {
		root = NULL;
	}
	node* search(node* cur_node, int key) {
		if (cur_node == NULL) return NULL;

		if (cur_node->key == key) //key 가 같은 경우
			return cur_node;
		else if (cur_node->key > key) //찾는 key가 더 작은 경우
			return search(cur_node->left, key); // left
		else // 큰 경우 
			return search(cur_node->right, key); //right
	}

	void insert(int key) { //key를 삽입
		if (search(this->root, key) != NULL) return; //이미 존재할 경우

		node* new_node = new node(key); //새로운 노드 생성
		if (root == NULL) { //루트가 비어 있을 경우 
			root = new_node; 
			return;
		}

		node* cur_node = root;
		node* par_node = NULL;

		while (cur_node != NULL) { // leaf까지 탐색(대소 비교 오름차순)
			par_node = cur_node;
			if (cur_node->key < key) // 클 경우
				cur_node = cur_node->right;
			else // 작을 경우
				cur_node = cur_node->left;
		}

		new_node->parent = par_node; // 부모 지정
		if (par_node->key < key) //부모보다 크다면 
			par_node->right = new_node;
		else //부모보다 작다면
			par_node->left = new_node;
	}

	void remove(int key) { //key 노드 삭제
		node* del_node = search(root, key); // 삭제할 노드 
		if (del_node == NULL) return; // 없다면 예외

		node* par_node = del_node->parent; //삭제할 노드의 부모
		node* chil_node; //삭제할 노드의 자식식

		if (del_node->left == NULL && del_node->right == NULL) { //없을 경우
			chil_node = NULL;
		}
		else if (del_node->left == NULL && del_node->right != NULL) {//오른쪽에만 존재할 경우
			chil_node = del_node->right;
		}
		else if (del_node->left != NULL && del_node->right == NULL) {//왼쪽에만 존재할 경우
			chil_node = del_node->left;
		}
		else {//둘 다 존재할 경우
			chil_node = del_node->right; //오른쪽 한 칸(이진탐색트리의 성질)
			while (chil_node->left != NULL) { //왼쪽->leaf까지
				chil_node = chil_node->left;
			}
			del_node->key = chil_node->key; //오른->왼->왼..노드의 key를 삭제할 노드에 복사
			del_node = chil_node; //chil가 삭제될 노드를 대체(자식을 삭제)
			par_node = del_node->parent; //삭제를 위해 부모를 삭제할 부모로 
			chil_node = del_node->right; //오른쪽 자식과 대체(삭제를 위함)
		}

		if (par_node == NULL) { //부모가 없을 경우, root 삭제
			root = chil_node; //오른쪽 자식이 root로
			if (chil_node != NULL) { //부모를 NULL로
				root->parent = NULL;
			}
		}
		else if (del_node == par_node->left) { //삭제할 노드가 부모의 왼쪽 자식일 경우
			par_node->left = chil_node; //chil을 부모의 왼쪽 자식으로
			if (chil_node != NULL) //왼쪽 자식의 부모 업데이트
				chil_node->parent = par_node;
		}
		else {//오른쪽 자식일 경우
			par_node->right = chil_node;
			if (chil_node != NULL)//오른쪽 자식의 부모 업데이트
				chil_node->parent = par_node;
		}
		delete del_node;
	}
};
