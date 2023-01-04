# 자료구조
이 레포는 자료구조의 개념적 구현 코드가 저장된 공간입니다.        
    
코드 순서
    
* [배열](https://github.com/whatsgoodg/Data-Structure/blob/main/README.md#array)
* [단일연결리스트](https://github.com/whatsgoodg/Data-Structure/blob/main/README.md#singly-linked-list)
* [스택](https://github.com/whatsgoodg/Data-Structure/blob/main/README.md#stack)
* [큐](https://github.com/whatsgoodg/Data-Structure/blob/main/README.md#queue)
* [벡터]()
* [이중연결리스트]()
* [트리](https://github.com/whatsgoodg/Data-Structure/blob/main/README.md#tree)
* [이진 트리](https://github.com/whatsgoodg/Data-Structure/blob/main/README.md#binary-tree)
* [이진 탐색 트리](https://github.com/whatsgoodg/Data-Structure/blob/main/README.md#binary-search-tree)
* [AVL 트리](https://github.com/whatsgoodg/Data-Structure/blob/main/README.md#avl-tree)
* [우선순위 큐](https://github.com/whatsgoodg/Data-Structure/blob/main/README.md#binary-search-tree)
* [힙]()
* [해시 테이블](https://github.com/whatsgoodg/Data-Structure/blob/main/README.md#hash-table)
* [그래프]()
# ADT
**`ADT`** (Abstract Data Types)란 자료구조의 **`추상화`** 이다. 이는 구현이 아니라 **`기능`** 에 초점을 맞춘 것으로                
어떻게가 아닌 **무엇** 을 수행하느냐이다. 예를 들어, Stack은 배열과 리스트로 모두 구현 가능하다.             
둘의 내부동작 방식은 엄연히 다르나, 구현된 기능은 두 구현 모두 동일한 동작을 수행할 수 있다.                        
이의 반대개념은 ***`CDT`*** (Concrete Data Types) 이다. 이는 **ADT**의 **구현**도 포함하고 있는 data type이다. 예를들어, **`단일연결리스트`** 가 존재한다.            
<br><br><br><br>                                   
                                          
                                              
                                              
# Array    
**`배열`** 이란 같은 타입(**homogeneous**)의 data를 지니는 자료구조이다.             
>* **`data type arrayname[N]`** 의 형태로 구현되며 하나의 데이터 타입만을 가진다.~~C~~
>* **`arrayname`** 은 첫 번째 원소의 **주소**를 가진다.~~C~~ 
>* 0부터 N-1의 index를 가진다.
>* size는 고정되어 있으며 변경할 수 없다.
![image](https://user-images.githubusercontent.com/86244920/208943982-1415cf53-19b6-4e9e-9b27-d99819356652.png)
<br><br>                         
## The Array ADT
>* **`insertion(i, e)`**: index i에 e를 삽입한다.    
>![image](https://user-images.githubusercontent.com/86244920/208944542-22a4e452-7f69-4356-8a15-05b9e4f3f991.png)             
>             
> 위와 같이 **`right shift`**, 즉 삽입하는 자리부터 오른쪽으로 한칸씩 이동한다. 그러므로 **cost**는 `O(N)`이다.
>* **`remove(i)`**: index i의 원소를 삭제한다. 
삭제하는 원소의 오른쪽 원소부터 왼쪽으로 한 칸씩 이동하는 **`left shift`** 가 발생한다. 그러므로 **cost는** `O(N)`이다.
>* **`at(i)`**: 배열의 index i의 원소를 반환한다. C++의 indexing은 주소를 이용하기 때문에 **cost**는 `O(1)`이다.
<br><br>                                    
### 구현              
[**소스코드**](https://github.com/whatsgoodg/Data-Structure/blob/main/array.cpp)                  
<br><br><br><br>                      
                      
                      
                      
                      
# Singly Linked-List
**`단일연결리스트`** 란 **`Concrete Data Structure`** 로 **`node`** 라는 개념이 포함된다.                        
`node`란 **`element`** 와 **`next`** 를 포함하는 하나의 **구조체**이다.                                
`element`란 node에 저장할 data이고, `next`란 다음 node의 주소를 가지는 **`포인터`** 이다.    
                        
![image](https://user-images.githubusercontent.com/86244920/209289410-657f9ed2-2672-443c-ad3d-654256c80c26.png)            
                
위와 같은 형태를 node라 칭하며 `단일연결리스트`란 이 노드들의 집합을 뜻한다.          
                            
![image](https://user-images.githubusercontent.com/86244920/209289518-02b73de0-2274-4d0b-94a2-34ddb91b76e0.png)               
                          
위와 같은 형태가 `단일연결리스트`이다.               
단일연결리스트는 맨 앞과 뒤를 가리키는 포인터 **`head`** 와 **`tail`** 을 가진다.        
<br><br>                  
## ADT
단일연결리스트의 `ADT`는 아래와 같다.              
**`addFront(element)`**
>1. 새로운 노드를 할당하고, next를 head로 업데이트 한다.
>2. head 포인터를 새로운 노드로 업데이트 한다.
>3. Cost: **`O(1)`**
            
**`removeFront()`**
>1. head 포인터를 next node의 주소로 업데이트 한다.
>2. 기존의 head 노드를 할당해제 한다.
>3. Cost: **`O(1)`**
               
**`addTail()`**
>1. 새로운 노드를 할당하고, tail의 next를 업데이트 한다.
>2. 새로운 노드의 next를 NULL로 초기화하고 tail을 새로운 노드로 업데이트한다.
>3. Cost: **`O(1)`**
                       
</u>중간삽입, 마지막 노드 삭제 등은 **선형시간** 시간복잡도를 가지기 때문에 효율적이지 않다.                
이를 해결하기 위해 **`prev`** (이전 노드를 가리키는 포인터)를 추가한 **`이중연결리스트`** 를 알아보자</u> 
## 구현
[**소스코드**](https://github.com/whatsgoodg/Data-Structure/blob/main/singly-linked%20list.cpp)               
<br><br><br><br>




# Stack
**`Stack`** 이란 **`LIFO`** (last-in first-out) 방식의 자료구조이다. 쉽게 말해 데이터가 **쌓이는** 형태의 자료구조이다.     
예를 들어, C++의 **`run-time stack`** 을 알아보자.         
                
![image](https://user-images.githubusercontent.com/86244920/210340171-ae4a9556-9ccd-4c27-b5b8-5a643857771e.png)         
            
```cpp
void bar() {}
void foo() { bar(); }
int main() { foo(); }
```
대략적으로 위와 같은 함수 호출 위의 이미지이다. **main()->foo()->bar()** 순서로 함수가 호출되고 반대 순서로 종료된다.        
이는 **가장 늦게** 호출된 함수(last-in)가 **가장 먼저** 종료(first-out)되는 Stack의 특징에 적합하다.              
stack의 구현은 `배열`을 사용하여 굉장히 간단하게 할 수 있다.               
<br><br>               
## ADT             
>* push(value): 값을 stack에 저장한다.
>* pop(): 가장 늦게 저장된 값을 삭제한다. 
>* top(): 가장 늦게 저장된 값을 반환한다.
>* size(), empty() 
>* 모든 연산의 시간 복잡도는 `O(1)`이다.             
                  
Stack 구현에 있어 가장 중요한 점은 top 원소를 가리키는 **`포인터`** 이다.         
배열로 구현되기 때문에 크기가 한정되어 있기에 **예외처리**가 필요하다.           
~~Stack의 응용은 사칙연산, 괄호 매칭이 있다.~~                  
<br><br>                
## 구현
[**소스코드**](https://github.com/whatsgoodg/Data-Structure/blob/main/stack.cpp)                  
<br><br><br><br>





# Queue             
**`Queue`** 란 Stack과 조금 다른 자료구조이다.                    
**`FIFO`** (first-in first-out)방식으로 동작하며 맨 처음 들어온 데이터가 가장 먼저 나간다.               
그래서 Queue(line)이다. 버스정류장의 줄을 생각해보면 된다.                   
<br><br>            
## ADT           
>* **`enqueue(value)`**: 값을 큐에 저장한다.
>* **`dequeue()`**: 가장 먼저 저장된 값을 삭제한다.
>* **`front()`**: 가장 먼저 저장된 값을 반환한다.
>* **`size()`**, **`empty()`**
>* 모든 연산의 시간 복잡도는 **`O(1)`** 이다.
              
Stack과 마찬가지로 배열로 구현이 가능하며, 맨 앞과 뒤를 가리키는 두 가지의 **`포인터`** 가 필요하다.            
`enqueue`와 `dequeue`에 있어서, **mod 연산** 을 사용한다. 이는 **`환형 큐`** 를 구현하기 위함이다.            
만약 삽입과, 삭제를 반복한다면 맨 앞을 가리키는 포인터가 뒤로 이동할 것이다.            
그냥 포인터가 **뒤로** 움직이는 방식으로 구현한다면 삭제된 이후 배열의 공간은 사용되지 않아 **메모리 누수**가 일어난다.             
이를 방지하기 위해 두 개의 포인터가 큐를 **도는 것**처럼 구현한다.         
                     
![image](https://user-images.githubusercontent.com/86244920/210345495-bd4ec3a7-a15b-4685-adf6-4f6341b1901b.png)                      
                  
위의 이미지와 같이 f,r 포인터가 움직이며 삽입 삭제를 수행한다.     
              
**`enqueue`** 의 C++ 구현은 아래와 같다.(예외처리x)             
```cpp
void enqueue(int val){
    arr[r] = val;
    r = (r + 1) % N;
    n++; //size n
}
```
위의 코드를 보면 알 수 있듯이, 두 포인터는 index 0에서 시작하여, r에 삽입을 하고 r을 한 칸 옮기는 방식으로 수행한다.               
r이 인덱스를 벗어날 경우 0으로 돌아간다.(**환형 큐**)              
                 
**`dequeue`** 구현(예외처리X)
```cpp
void dequeue(){
    f = (f + 1) % N;
    n++; //size n
}
```                
`enqueue`와 동일하게 f 포인터를 한 칸 옮기기만 하면 된다. 똑같이 인덱스를 벗어날 시, 0으로 돌아간다.(**환형 큐**)    

Stack과 동일하게 배열의 크기는 한정적이므로, **예외처리**가 필요하다.               
`Queue`의 **`응용`** 은 그래프 자료구조의 **BFS** 구현과, [**Round Robin Scheduler**](https://ko.wikipedia.org/wiki/%EB%9D%BC%EC%9A%B4%EB%93%9C_%EB%A1%9C%EB%B9%88_%EC%8A%A4%EC%BC%80%EC%A4%84%EB%A7%81) 등이 있다.   
<br><br>
## 구현 
[**소스코드**](https://github.com/whatsgoodg/Data-Structure/blob/main/queue.cpp)
<br><br><br><br>





# Tree
**`Tree`** 란 node가 **부모-자식** 관계를 가지는 자료구조이다. 이는 조직구조, file system 등을 예로 들 수 있다.          
                        
![image](https://user-images.githubusercontent.com/86244920/210497251-664ad776-98aa-4b93-9485-5be7284c84c2.png)            
<br><br>            
## 용어
>* **`Depth`**: tree의 깊이. 특정 노드의 부모의 최대 개수
>* **`Height`**: tree의 높이. 특정 노드의 자식의 최대 개수
>* **`Root`**: 부모가 없는 맨 위의 노드
>* **`Internal node`**: 최소 하나의 자식이 있는 노드
>* **`External node`**(leaf): 자식이 없는 노드
>* **`Anceators of node`**: 자기 자신을 포함한 Depth에 포함되는 노드
>* **`Descendant of node`**: 자기 자신을 포함한 Height에 포함되는 노드
>* **`Subtree`**: 특정 노드와 모든 자식들이 구성하는 tree           
>                 
>* #### 예시               
>![image](https://user-images.githubusercontent.com/86244920/210565348-32c3ccf7-7e9b-4961-893d-45abfb56d6ad.png)                
            
<br><br>             
### Depth and Height
>* **`Edge(u, v)`**: 두 노드를 연결하는 간선이다. u는 v의 부모이다.
>* **`Path(v1, v2, v3,..)`**: 노드들의 연결을 뜻 한다. 두 개의 노드 **하나**의 간선을 형성한다.
>* **`Depth of node v`**: v가 root이면 0으로 본다. Root부터 v의 부모노드 Sequence의 개수로 계산한다.(만약 부모가 하나면 v의 depth는 1이다.
>* **`Height of node v`**: v가 leaf 노드이면 0이다. v부터 자식노드 Sequence의 최댓값으로 계산한다.(자식 연결이 2,3,4일 경우 4로 계산한다.)
<br><br>               
## Tree ADT
>* **`Size()`**
>* **`empty()`**
>* **`Node root()`**: root node를 반환한다.
>* **`list<Node> nodes()`**: 모든 node를 list에 저장하여 반환한다.
>* **`Node p.parent()`**: p node의 부모를 반환한다.
>* **`list<Node> p.children()`**: p node의 모든 자식을 list에 저장하여 반환한다.
>* **`p.isRoot()`**: p node가 root node이면 true를 반환한다.
>* **`p.isExternal()`**: p node가 leaf node이면 true를 반환한다.
>            
>#### 예시
>![image](https://user-images.githubusercontent.com/86244920/210565562-61e16d08-cf52-47d7-a4f2-e15c155fdb77.png)               
                    
<br><br>              
## Preorder Traversal       
**`Preorer Traversal`** 이란 특정 노드를 기준으로 자식들보다 먼저 탐색하는 것을 의미한다.              
#### 수도코드                
![image](https://user-images.githubusercontent.com/86244920/210502372-529e9ae8-fc47-45a1-a7b6-4441844e63b5.png)       
           
#### 예시
![image](https://user-images.githubusercontent.com/86244920/210502516-98d336bb-5af6-4197-bbdf-74387f8feab9.png)     
             
위의 순서로 방문한다.
#### 응용
구조화된 문서 탐색 

<br><br>         
## Postorder Traversal
**`Postorer Traversal`** 이란 특정 노드를 기준으로 자식부터 탐색하는 것을 의미한다.
#### 수도코드               
![image](https://user-images.githubusercontent.com/86244920/210502748-5e76af39-1155-4e9a-9da1-05fc1b315e0c.png)      
           
#### 예시
![image](https://user-images.githubusercontent.com/86244920/210502800-b0df355f-f924-4960-a9a1-8389a583db3a.png)
          
#### 응용
폴더, 파일의 저장공간 계산

<br><br><br><br>







# Binary Tree
**`Binary Tree`** 란 부모 노드의 자식이 2개 이하인 tree를 뜻 한다. 자식이 0개 또는 2개만 존재하는 tree를 **`Proper Binary Tree`** 라고 칭한다.         
자식이 최대 2개이니, **`left child`**(왼쪽 자식), **`right child`**(오른쪽 자식)으로 구분할 수 있다.              
                         
![image](https://user-images.githubusercontent.com/86244920/210503686-376f8704-fb8f-4ad8-8699-d18cfddfc151.png)               
<br><br>           
## Arithmetic Expression Tree
이진 트리는 사칙연산을 수행할 수 있다.
>* **`Internal nodes`**: 연산자
>* **`External nodes`**: 피연산자
         
![image](https://user-images.githubusercontent.com/86244920/210504085-79ddc27d-af6d-4ec7-a4cf-dc269bc8e522.png)            
             
위와 같이 (2 x (a - 1) + (3 x b))를 계산할 수 있다.
<br><br>          
## Properties
**`Notation`**
>* **n**: 총 노드의 개수
>* **m**: internal 노드의 개수
>* **l**: leaf 노드의 개수
>* **h**: hegiht
               
![image](https://user-images.githubusercontent.com/86244920/210504449-113fe789-9a1c-42b3-ad59-75bff3c86ebd.png)            
                      
위의 두 이진 트리에서 밑과 같은 성질을 도출한다.         
                
![image](https://user-images.githubusercontent.com/86244920/210504415-16938cef-3eea-4190-bdf0-31bc265d6f81.png)               
                   
----------------------------------------------------------------                   
![image](https://user-images.githubusercontent.com/86244920/210504931-806e5bee-5bf9-4528-8b0f-fc803e7c0973.png)       
![image](https://user-images.githubusercontent.com/86244920/210510207-98f8a434-089c-409a-9357-2da5b2b3dcee.png)              
                     
위의 두 이진 트리에서 다음과 같은 성질을 도출한다.               
                 
![image](https://user-images.githubusercontent.com/86244920/210505159-fad48ea9-3183-44cf-bac6-422748e5ebd2.png)
<br><br>
## ADT
ADT는 기존 tree에서 **`Node p.left()`** , **`Node p.right()`** 가 추가된다. 각각 특정 노드의 왼쪽, 오른쪽 자식을 반환한다.           
 <br><br>
## Inorder Traversal
**`Inorder Traversal`** 이란 특정노드를 기준으로 왼쪽 자식 이후, 오른쪽 자식 이전에 탐색하는 것을 의미한다.      
#### 수도코드
![image](https://user-images.githubusercontent.com/86244920/210506122-adcf9dbc-aa34-46c2-a314-300163d85c0c.png)               
                              
![image](https://user-images.githubusercontent.com/86244920/210506269-7cfbc428-58b3-4ab8-802a-f8fbe9bdad95.png)              
              
위와 같은 순서로 탐색한다.   
<br><br>
## Euler Tour Traversal 
preorder, postorder, inorder 탐색을 모두 포함한 탐색 방법이다.     
Internal node를 세 번씩 방문한다.           
![image](https://user-images.githubusercontent.com/86244920/210508419-9e666986-a49a-4553-a916-103aab9da43a.png)            
왼쪽(**preorder**), 밑(**inorder**), 오른쪽(**postorder**)에서 한 번씩 방문한다.                 
특정노드가 세 번 탐색될 때 **왼쪽**은 부모로부터, **밑**은 왼쪽 자식으로 부터, **오른쪽**은 오른쪽 자식으로 부터 방문된다.           
<br><br>              
## Types of binary tree
#### Full binary tree
![image](https://user-images.githubusercontent.com/86244920/210506381-59fdf9b1-7cea-46d4-b354-f666d30912ba.png)         
             
0 또는 2개의 자식만을 가지는 이진 트리이다.
#### Complete binary tree
![image](https://user-images.githubusercontent.com/86244920/210506479-cf8fa021-2ceb-46b0-8445-c2435b071669.png)          
             
leaf node 부분을 제외하고 모두 두 개의 자식을 가지는 이진 트리이다.         
#### Perfect binary tree 
![image](https://user-images.githubusercontent.com/86244920/210506746-a7172387-6de7-4734-9f52-747633fd35e3.png)            
          
모든 leaft 노드가 같은 level에 있고, internal node가 무조건 두 개의 자식을 가지는 이진 트리이다.    
#### Balanced binary tree
![image](https://user-images.githubusercontent.com/86244920/210507082-28a3a7db-ddb7-4fd5-b4c4-a7d0e01d2683.png)           
모든 노드의 왼쪽 오른쪽 subtree의 height가 최대 1이 차이나는 이진트리이다.             
#### Degenerate binary tree
![image](https://user-images.githubusercontent.com/86244920/210507305-afab6501-ed23-4d07-8bd1-2bab3835829a.png)           
이진 트리의 조건을 충족하지만, 성능이 가장 나쁜 이진 트리이다.(이진 검색 트리에서 알아보자.)            
이를 해결하기 위한 방법은 AVL, Red black tree이다.          

<br><br><br><br>


# Binary Search Tree
**`Binary Search Tree`** 란 **key** 또는 **entry**(keym value)를 저장하는 이진 트리이다.             
#### Property 
**node v와 왼쪽 자식 u, 오른쪽 자식 w가 있다고 하자.**
>* **`key(u) <= key(v) <= key(w)`** 를 충족해야한다.     
>* leaf node는 원소를 저장하지 않은 상태로 존재한다.(원소 삽입, 삭제를 위해 사용된다.)
                       
_**`Inorder Traversal`을 수행할 시, key를 오름차순으로 탐색한다.**_             
#### 예시
![image](https://user-images.githubusercontent.com/86244920/210521254-31317a7e-bd0f-4ba4-99a8-61b6981804d7.png)          
<br><br>              
## Search
이진 검색 트리의 탐색 방법을 알아보자.
#### 수도코드       
![image](https://user-images.githubusercontent.com/86244920/210521438-cdda4d81-ef9e-4491-b1aa-a7bda102b191.png)        
특정 노드를 탐색하는 알고리즘은 위의 수도코드와 같다. 
>* Root node에서 탐색을 시작한다.
>* 찾고자 하는 key가 특정 노드의 key보다 **작을** 경우, 왼쪽 자식을 탐색한다.
>* 찾고자 하는 key가 특정 노드의 key보다 **클** 경우, 오른쪽 자식을 탐색한다.
>* 찾고자 하는 key가 특정 노드의 key와 **같을** 경우 해당 node를 반환한다.
>* 찾고자 하는 key를 찾지 **못하고** leaf node에 도달할 시, leaf node를 반환한다.
>* #### 예시
>![image](https://user-images.githubusercontent.com/86244920/210522131-3efaa2a1-72d2-41a9-b62d-4b02de2cc3ec.png)     
>                      
>* **TreeSearch(4, root)**           

<br><br>
## Insertion
>* 원소 삽입을 위해 삽입 하고자 하는 key를 찾아야한다.(**Search**) 
>* 이진 탐색 트리의 성질을 충족하며 탐색을 해, leaf node에 도달한다.
>* leaf node에 도달한 후, 원소를 삽입하고 자식 노드를 할당한다.
>* 만약 동일 key가 이미 존재할 경우, 예외처리를 한다.(수정 or error)     
>* #### 예시
>![image](https://user-images.githubusercontent.com/86244920/210522821-d9248771-07cf-45fc-9c05-c1f794d2c9f5.png)   
>                        
>* **insert(5)**
              
<br><br>                 
## Deletion
**자식 노드가 한 개일 경우(하나는 원소가 없고 다른 하나는 있다.)**              
            
>* 원소 삭제를 위해 삭제 하고자 하는 ket를 찾아야한다.(**Search**)
>* 해당 노드와 leaf node(자식)을 삭제하고 leaf node가 아닌 자식을 해당노드의 부모와 이어준다.(**removeAboveExternal(w)** 사용)
>* 삭제하고자 하는 key가 존재하지 않을 경우 예외처리를 한다.
>* #### 예시
>![image](https://user-images.githubusercontent.com/86244920/210523568-49ad07af-c042-44da-85a2-cc2e8f3d46b7.png)
>                 
>* **remove(4)**
             
<br><br>
               
**자식 노드가 두 개일 경우(자식 노드 둘 다 원소가 있다.)**              
>* Inorder Traversal을 통해 노드를 찾는다.**(오른쪽->왼쪽->왼쪽->...)**
>* 해당 노드를 삭제 하고자 하는 노드와 바꾼다.
>* 그렇다면 **모든 상황**에 바뀐 노드는 하나의 자식이 있거나 또는 존재하지 않는다. 
>* 해당 노드와 하나의 leaf 노드를 삭제하고, 삭제된 노드의 부모와 남은 자식과 이어준다.(**removeAboveExternal(z)** 사용)
>* #### 예시
>![image](https://user-images.githubusercontent.com/86244920/210526165-4d75a557-0c93-4ff1-beda-89ccd55e78c0.png)          
>              
>* **remove(3)**
> 첫 번째 과정은, 삭제하고자 하는 노드의 key보다 큰 노드 중, 가장 작은 ke를 가진 노드이기에, 이진 검색 트리의 성질을 유지하며 삭제한다.  
                        
<br>

**`removeAboveExternal(w)`** 는 w와 부모를 삭제하고 w의 형제 노드를 부모 자리에 놓는다.                    

<br>
              
## Performance
>* 공간 복잡도: **`O(n)`**
>* 모든 연산: **`O(h)`**             
                      
>* **최선의 경우**            
>![image](https://user-images.githubusercontent.com/86244920/210528087-7ac00741-04cd-4695-b46c-3851e96ccc0b.png)   
>                             
>위와 같은 트리의 경우 h는 log n이기에, 모든 연산은 **`O(log n)`** 이다.           
                                         
>* **최악의 경우(Degenerate binary tre)**              
>![image](https://user-images.githubusercontent.com/86244920/210527877-f44eaeb0-48d6-4f5a-a1cb-5851195119c3.png)         
>                   
>위와 같은 트리의 경우 h는 n이기에, 모든 연산은 **`O(n)`** 이다.            
>위와 같은 문제점은 노드들이 key의 **오름차순**으로 삽입될 때 이다.      
>이를 해결하기 위한 **`AVL tree`** 를 알아보자.  
                                    
<br><br><br><br>                 
# AVL Tree
**`AVL Tree`** 란 **`Balanced Binary Search Tree`** 이다. 모든 Subtree의 height가 **최대 1**까지 차이나는 트리이다.            
AVL Tree는 이진 탐색 트리 중, height가 **어떠한 상황**에서도 **log n**이 보장되는 Tree이다. ~~증명은 하지 않는다.~~    
위에서 본 h가 n인 경우의 이진 탐색 트리는 `선형 자료구조`인 리스트와 다를게 없다.               
노드가 key가 오름차순으로 이진 탐색 트리에 삽입될 경우, 이와 같은 상황이 발생할 수 있다.                 
이를 해결하기 위해 `AVL tree` 는 삽입, 삭제가 일어날 때마다, height를 log n으로 유지하기 위해 **`Restructuring`** 이 필요하다.           
**C++의 이진 탐색 트리는 이와 비슷한 레드 블랙 트리로 구현되어 있다.**                 
<br><br>
## Insertion  
이진 검색 트리의 insertion을 수행한 이후, AVL tree는 **`Trinode Restructuring`** 를 수행한다.          
<br><br>
### Single Rotation
**`Single Rotation`** 이란 **하나**의 subtree가 이동하는 것을 의미한다.        
                  
![image](https://user-images.githubusercontent.com/86244920/210549380-5a1b49a2-8900-45fa-b494-367cd46dd54c.png)           
            
a가 b의 왼쪽 자식 subtree가 되며 AVL Tree의 성질을 만족한다.           
                    
![image](https://user-images.githubusercontent.com/86244920/210549409-03d84b20-ed38-4753-aaec-f3d5afa4db6d.png)           
              
c가 b의 오른쪽 자식 subtree가 되며 AVL Tree의 성질을 만족한다.           
<br><br>
### Double Rotation
**`Double Rotation`** 이란 **두 개**의 subtree가 이동하는 것을 의미한다.          
               
![image](https://user-images.githubusercontent.com/86244920/210550040-e731d265-7902-4c44-bca5-877acbe7358d.png)            
            
a와 c가 각각 b의 왼쪽, 오른쪽 subtree가 된다.             
               
![image](https://user-images.githubusercontent.com/86244920/210550287-ee767ed7-28db-4b7d-b07a-bd52309f3fc4.png)              
              
(위와 비슷하다.)           
<br><br>
## Removal
`AVL Tree`의 삭제는 이진 탐색 트리의 삭제를 진행 한 이후, 삽입과 동일하게 추가적으로 성질을 만족하기 위해 **`Rebalancing`** 을 수행한다.         
           
![image](https://user-images.githubusercontent.com/86244920/210551315-2edade5b-b281-4912-94de-0408b8c62cc1.png)            
               
위의 이미지와 같이 삭제 이후 AVL tree의 성질을 충족하지 못해, `Rebalancing`을 수행해야한다.         
<br><br>
### Rebalancing
#### 예시
![image](https://user-images.githubusercontent.com/86244920/210556561-a262e9de-c66b-479b-acf4-dbb6967e9bfb.png)             
             
~~과정은 생략하겠습니다.. 예외도 많고 복잡하다..~~

## Performance
>* find: **`O(log n)`**
>* insert: **`O(log n)`**
>* erase: **`O(log n)`**
>* Restructuring: **`O(log n)`**
             
<br><br><br>



                                    
# Hash Table
**`Hash Table`** 이란 **`Hash Function`** 을 이용하여 (key, value) 형태의 entry중 key를 특정 정수로 **mapping**하여 index를 관리하는 배열이다.([0, N-1])            
해시 함수의 예시로 **`h(x) = x mod N`** 가 있다. h(x)는 key x의 **`Hash Value`** 라 부른다.             
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
                        
## Hash Code Example            
**`polynomial accumulation`** 의 직역은 다항식 형태의 축적이다.          
>* key의 bits를 고정된 크기의 다항식 형태(**`a_0,a_1,,a_n-1`**)로 나눈다.                    
>* 특정 함수로 다항식을 계산한다. **`p(z) = a_0 + a_1*z + a_2*z^2 + .. + a_n-1 * z^n-1`**             
> 이 방법은 string key에 적합하다. <u>이 방법은 최대 6개의 충돌을 일으킨다.</u>             
                    
## Compression FunctionH              
정수화한 key를 해시함수를 사용하여 **index**를 만드는 과정이다.            
간단한 해시함수를 소개한다.                
**`Division`**                 
>* h_2(y) = y mod N(<u>테이블 크기 N은 대개 소수로 결정한다.</u>)                        
**`Multiply, Add and Divide(MAD)`**              
>* h_2(y) = (ay + b) Mod N(<u>a와 b는 음이 아닌 정수이며 a mod N != 0을 충족한다.</u>)                 
                      
## Collision Handling
### Separate Chaining
해시함수를 거쳐 나온 index가 중복되는 경우를 **`Collision(충돌)`** 이라 칭한다.              
이 충돌을 해결하기 위한 방법 중 하나가 **`Separate Chaining`** 이다.            
이는 중복된 index에 `list`를 가리키는 `포인터`를 저장하여 list로 중복되는 key를 가진 entry를 관리하는 방법이다.             
이는 최악의 경우 O(N)의 시간복잡도를 가진다.                     
구현은 간단하지만 이는 추가적인 메모리가 필요하다는 것을 고려해야 한다.             
                    
### Open Addressing                
충돌이 일어났을 경우 entry를 다른 index에 저장하는 방법이다. 해시함수를 거친 index와 저장되는 index가 다르다.               
               
#### Example
>* h(x) = x mod 13                         
![image](https://user-images.githubusercontent.com/86244920/208910032-ebd324e7-ab97-4b64-946a-2db07507be7f.png)                         
                        
위의 이미지와 같이 18 mod 13 == 44 mod 13 일 경우 18 저장 이후 44에서 충돌이 발생한다. 이를 18의 다음 index에 저장하는 모습을 볼 수 있다.               
Open Addressing 방법을 사용한 해시 테이블을 순회하는 방법을 **`Linear Probing`** 이라 부른다.    
#### 수도코드               
                         
![image](https://user-images.githubusercontent.com/86244920/208910704-884a85b5-23ef-4873-b7fa-a05b6030a495.png)                 
                         
### Linear Probing
Open Addressing 방법을 사용한 table은 충돌이 일어나 중간에 삭제된 entry가 있는 경우             
삭제가 되었다는 표시를 테이블에 남겨야한다. 이를 **`AVAILABLE`** 이라 칭한다.                    
선형 탐색 중 AVAILABLE이 일어난 경우 **empty 또는 key를 찾을 때 까지** 탐색을 해야한다.                
충돌이 다중으로 일어나 찾고자 하는 key가 **테이블 뒷쪽** 에 저장되어 있을 경우가 있기 때문이다.                
선형 탐색을 위한 **`ADT`** 는 아래와 같다               
                         
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
         
#### 구현
[**소스코드**](https://github.com/whatsgoodg/Data-Structure/blob/main/hashtable.cpp)          
                     
### Double Hashing
**`Double Hashing`이란 추가의 해시함수를 충돌**이 일어났을 경우에**만** 사용한다.           
예시로 **`h'(k)=q-(k mod q)(q < N and q is prime)`** 와 **`(i + j * h'(k)) mod N(for j = 0, 1, .. ,N-1)`** 가 있다.               
>* 이중해시함수는 0을 가질 수 없다.
>* N은 무조건 소수여야한다.(모든 cell을 탐색하기 위함)
>* h`(k)는 1, 2, ..,q값을 가진다.
                          
#### Example
![image](https://user-images.githubusercontent.com/86244920/208913309-bbc2022c-b732-4cc5-accb-ed2859f642ac.png)
>* N = 13
>* h(k) = k mod 13
>* h'(k) = 7 - k mod 7 
                        
#### 구현
[**소스코드**](https://github.com/whatsgoodg/Data-Structure/blob/main/hashtable2.cpp)                
                    
### Cost
>* **remove()**: `O(N)` => 모든 entry가 충돌이 일어났을 때            
>* **`load factor`**: n/N은 해시 테이블 performance에 영향을 끼친다. n은 entry의 개수이다.            
>* 나머진 사전의 경우와 같이 N개의 cell이 있으므로 `O(N)`의 시간복잡도를 가진다.           
