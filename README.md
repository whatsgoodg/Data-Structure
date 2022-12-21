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
예를 들어, 긴 숫자를 가진 주민등록번호와 이에 대응되는 성명을 해시 테이블로 저장하는 경우를 보자.

![image](https://user-images.githubusercontent.com/86244920/208908067-81bde8b0-cd97-4b51-bf56-22f7eeee2821.png)

위의 이미지와 같이 마지막 **네 개**의 정수에 대응되는 `index`를 통해 관리한다. 이를 `해시 테이블`이라 부른다.
하지만 해시 테이블은 이렇게 간단하게 사용되지 않는다. 해시 테이블을 사용하는 이유는 중복되는 key값을 하나의 테이블에 `분산`시켜 관리하기 위함이다.
위에서 본 것과 같이 key값을 mod 연산을 통해 index로 바꾸듯이 **더 복잡한** 해시함수를 통해 key가 담긴 entry를 분산시켜야 한다.
해시 테이블은 `충돌 관리`가 중점적으로 다뤄진다.

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
#### Separate Chaining
해시함수를 거쳐 나온 index가 중복되는 경우를 **`Collision(충돌)`**이라 칭한다. 
이 충돌을 해결하기 위한 방법 중 하나가 **`Separate Chaining`**이다. 
이는 중복된 index에 `list`를 가리키는 `포인터`를 저장하여 list로 중복되는 key를 가진 entry를 관리하는 방법이다.
이는 최악의 경우 O(N)의 시간복잡도를 가진다.
구현은 간단하지만 이는 추가적인 메모리가 필요하다는 것을 고려해야 한다.
#### Open Addressing
충돌이 일어났을 경우 entry를 다른 index에 저장하는 방법이다. 해시함수를 거친 index와 저장되는 index가 다르다.
##### Example
>* h(x) = x mod 13
![image](https://user-images.githubusercontent.com/86244920/208910032-ebd324e7-ab97-4b64-946a-2db07507be7f.png)

위의 이미지와 같이 18 mod 13 == 44 mod 13 일 경우 18 저장 이후 44에서 충돌이 발생한다. 이를 18의 다음 index에 저장하는 모습을 볼 수 있다.
Open Addressing 방법을 사용한 해시 테이블을 순회하는 방법을 **`Linear Probing`**이라 부른다.
##### 수도코드
![image](https://user-images.githubusercontent.com/86244920/208910704-884a85b5-23ef-4873-b7fa-a05b6030a495.png)

#### Linear Probing
Open Addressing 방법을 사용한 table은 충돌이 일어나 중간에 삭제된 entry가 있는 경우
삭제가 되었다는 표시를 테이블에 남겨야한다. 이를 **`AVAILABLE`**이라 칭한다.
선형 탐색 중 AVAILABLE이 일어난 경우 **empty 또는 key를 찾을 때 까지** 탐색을 해야한다.
충돌이 다중으로 일어나 찾고자 하는 key가 **테이블 뒷쪽**에 저장되어 있을 경우가 있기 때문이다.
선형 탐색을 위한 **`ADT`**는 아래와 같다
>* **`find(key)`**: cell의 h(k)에서 시작하여 선형탐색을 한다. 
> 1. 찾고자하는 key가 발견되었을 경우.
> 2. empty cell이 발견되었을 경우.
> 3. 마지막 지점까지 모두 탐색한 경우(unsuccessful)

> * **`put(key, value)`**: table에 entry를 삽입한다.
> 1. 테이블이 꽉 찼을 경우 예외처리를 한다.
> 2.  마지막 지점까지 모두 탐색한 경우 예외처리를 한다. 
> 3. h(k)에서 시작하여 empty 또는 AVAILABLE cell이 발견된다면 entry를 삽입한다.

> * **`erase(key)`**: key값과 일치하는 entry를 삭제한다.
> 1. 마지막 시점까지 모두 탐색한 경우 예외처리를 한다.
> 2. key값과 일치하는 entry를 찾은 경우, 삭제 후 AVAILABLE를 저장한다.

### Double Hashing
**`Double Hashing`이란 추가의 해시함수를 충돌**이 일어났을 경우에**만** 사용한다.
예시로 **``h'(k)=q-(k mod q)(q < N and q is prime)`**와 **`(i + j * h'(k)) mod N(for j = 0, 1, .. ,N-1)`**를 알아보자.
>* 이중해시함수는 0을 가질 수 없다.
>* N은 무조건 소수여야한다.(모든 cell을 탐색하기 위함)
>* h`(k)는 1, 2, ..,q값을 가진다.

#### Example
![image](https://user-images.githubusercontent.com/86244920/208913309-bbc2022c-b732-4cc5-accb-ed2859f642ac.png)
>* N = 13
>* h(k) = k mod 13
>* h'(k) = 7 - k mod 7 
#### Cost
>* **remove()**: `O(N)` => 모든 entry가 충돌이 일어났을 때
>* **`load factor`**: n/N은 해시 테이블 performance에 영향을 끼친다. n은 entry의 개수이다.
>* 나머진 사전의 경우와 같이 N개의 cell이 있으므로 `O(N)`의 시간복잡도를 가진다.
## Graph
