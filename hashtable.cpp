/* 
linear probing을 사용한 해시 테이블이다.
삭제시 dummy node를 위한 AVAILABLE이 필요하다. 

삽입 시: OCCUP
삭제 시: AVAIL
초기화전: EMPTY
Open addressing + Linear probing
충돌 시과 탐색은 한 칸씩 오른쪽으로 움직이며 원소를 저장한다.
충돌 시 탐색의 횟수가 크기를 넘어가면 예외처리
insert: key 중복시 값 수정

*/
#include <iostream>
#define EMPTY 0
#define OCCUP 1
#define AVAIL 2
using namespace std;

struct entry {
	int key; 
	string value;
	int valid; //table의 status

	entry() {
		key = 0;
		value = "";
		valid = EMPTY;
	}
	entry(int key, string value) {
		this->key = key;
		this->value = value;
		valid = OCCUP;
	}
	void erase() {
		valid = AVAIL;
	}
};

class hashTable {
private:
	entry* table;
	int capacity;
	int hashFunc(int key) {
		return (capcity + key % capacity) % capacity;
	}
public:
	hashTable(int N) {
		capacity = N;
		table = new entry[capacity];
	}
  
	int find(int key) {
		int index = hashFunc(key);
		int probe = 1;

		while (table[index].valid != EMPTY && probe <= capacity) {// 비어 있지 않을 경우
			if (table[index].valid == OCCUP && table[index].key == key) { // entry가 있고 key가 같을 경우
				return index;
			}
			index = hashFunc(index + 1);
			probe++;
		}
		return -1;
	}
  
	void put(int key, string value) {
		int index = find(key); 
		if (index != -1) { //값이 중복될 시
			table[index].value = value;
			return;
		}
		index = hashFunc(key);
		int probe = 1;

		while (table[index].valid == OCCUP && probe <= capacity) {
			index = hashFunc(index + 1);
			probe++;
		}
		if (probe > capacity) return; // 크기를 넘어 돌았을 경우
		table[index] = entry(key, value);
	}
  
	void erase(int key) {
		int index = hashFunc(key);
		int probe = 1;

		while (table[index].valid != EMPTY && probe <= capacity) { //비어 있지 않을 시
			if (table[index].valid == OCCUP && table[index].key == key) { //entry가 있고 key가 같을 경우
				table[index].erase();
				return;
			}
			index = hashFunc(index + 1);
			probe++;
		}
	}
  
	int size() {
		int cnt = 0;
		for (int i = 0; i < capacity; i++) {
			if (table[i].valid == OCCUP) cnt++;
		}
		return cnt;
	}
};
