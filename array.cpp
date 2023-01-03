#include <iostream>
using namespace std;
//STL에서 사용되는 배열의 insert와 erase에서 필요한 shift 연산을 어느정도 이해할 수 있는 소스코드이다.
class Array {
private:
	int* arr;
	int arrSize;
public:
	//중요
	Array(int arrSize);
	~Array();
	void insert(int idx, int value);
	void erase(int idx);
	//덜 중요
	int at(int idx);
	void set(int idx, int value);
	void print();
};

Array::Array(int arrSize) {
	this->arrSize = arrSize;
	this->arr = new int[arrSize];
	for (int i = 0; i < arrSize; i++) arr[i] = 0;
}

Array::~Array() { delete[] arr; }

void Array::insert(int idx, int value) {
	for (int i = arrSize - 2; i >= idx; i--) //arrSize - 2 번째 원소부터 오른쪽으로 모두 shift.
		arr[i + 1] = arr[i];
	arr[idx] = value;//원소 삽입
}

void Array::erase(int idx) {
	for (int i = idx + 1; i < arrSize; i++)//삭제할 원소 - 1 번째 원소부터 왼쪽으로 모두 shift
		arr[i - 1] = arr[i];
	arr[arrSize - 1] = 0; //마지막 원소 0으로 초기화
}
//STL 기본 함수들
int Array::at(int idx) { return arr[idx]; }

void Array::set(int idx, int value) { arr[idx] = value; }

void Array::print() { for (int i = 0; i < arrSize; i++) cout << arr[i] << " "; cout << "\n"; }
