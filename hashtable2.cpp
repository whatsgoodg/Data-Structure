/*
삭제시 dummy node를 위한 AVAILABLE이 필요하다.
삽입 시: OCCUP
삭제 시: AVAIL
초기화전: EMPTY

Open addressing + Double hashing
충돌 시과 탐색은 추가 해시함수를 사용한다.
Linear probing: (hash1 + 1) % capacity
Double hashing: (hash1 + hash2) % capacity
충돌 시 탐색의 횟수가 크기를 넘어가면 예외처리
insert: key 중복시 값 수정

함수 설명은 hashtable.cpp 참고
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
	int divisor; //소수여야 한다.
  
	int hashFunc(int key) {
		return (capacity - key % capacity) % capacity;
	}
  
	int hashFunc2(int key) {
		return divisor - (key % divisor);
	}
public:
  
	hashTable(int N, int M) {
		divisor = M;
		capacity = N;
		table = new entry[capacity];
	}
  
  int find(int key) {
		int index = hashFunc(key);
		int probe = 1;

		while (table[index].valid != EMPTY && probe <= capacity) {

			if (table[index].key == key && table[index].valid == OCCUP) {
				return index;
			}
			index = hashFunc(index + hashFunc2(key));
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
			index = hashFunc((index + hashFunc2(key)));
			probe++;
		}
		if (probe > capacity) return;
		table[index] = entry(key, value);
	}
  
	void erase(int key) {
		int index = hashFunc(key);
		int probe = 1;

		while (table[index].valid != EMPTY && probe <= capacity) {

			if (table[index].key == key && table[index].valid == OCCUP) {
				cout << table[index].value << endl;
				table[index].erase();
				return;
			}
			index = hashFunc(index + hashFunc2(key));
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
