# 자료구조
이 레포는 자료구조의 개념적 구현 코드가 저장된 공간입니다.        
    
코드 순서
    
* 배열
* 리스트(단일)
* 스택
* 큐
* 벡터
* 리스트(이중)
* 트리
* 우선순위 큐
* 힙
* 이진 탐색 트리
* 해시 테이블
* 그래프 
## Array
## Singly Linked-List
## Double Linked-List
## Tree
## Priority Queue
## Heap
## Binary Search Tree
## Hash Table
`Hash Table`이란 `Hash Function`을 이용하여 (key, value) 형태의 entry중 key를 특정 정수로 mapping하여 index를 관리하는 배열이다.([0, N-1])
해시 함수의 예시로 `h(x) = x mod N`가 있다. h(x)는 key x의 `Hash Value`라 부른다.
해시 테이블은 대략 두 개의 요소로 구성되어 있다.
>* **Hash Function _h_**
>* **Array(called table) of size N**
>* _entry는 table의 index i=h(k)에 저장한다.

해시함수는 대개 두 가지의 함수를 사용하여 mapping한다. 
>* **`Hash Code`**: **h_1: kets -> integers**
>* **`Compression Function`**: **h_2: integers -> [0, N-1]**
이렇게 두 번의 절차를 걸치는 이유는 key를 임의적으로 `분산`시키기 위함이다.
**`Integer Cast`**
>* 어느 종류의 key더라도 정수형태로 나타낼 수 있다.(bits)
**`Component Sum`**
>* key의 bits를 나누고 모두 고정된 크기로 나누고 모두 더하여 정수형태로 나타낸다.
>* integer type의 bits 수보다 크거나 같은 고정된 크기의 numeric key에 적합하다. ex) long and double
### Hash Code Example
**`polynomial accumulation`**의 직역은 다항식 형태의 축적이다.
>* key의 bits를 고정된 크기의 다항식 형태(`a_0,a_1,,a_n-1`)로 나눈다.
>* 특정 함수로 다항식을 계산한다. `p(z) = a_0 + a_1*z + a_2*z^2 + .. + a_n-1 * z^n-1`
> 이 방법은 string key에 적합하다. <u>이 방법은 최대 6개의 충돌을 일으킨다.</u>
### Compression FunctionH
정수화한 key를 해시함수를 사용하여 **index**를 만드는 과정이다.
간단한 해시함수를 소개한다.
**`Division`**
>* h_2(y) = y mod N(<u>테이블 크기 N은 대개 소수로 결정한다.</u>)
**`Multiply, Add and Divide(MAD)`**
>* h_2(y) = (ay + b) Mod N(<u>a와 b는 음이 아닌 정수이며 a mod N != 0을 충족한다.</u>)
### Collision Handling
## Graph
