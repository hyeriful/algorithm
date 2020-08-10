[백준 1406 에디터](https://www.acmicpc.net/problem/1406)
======================
해결 아이디어
---------------------
- linked list  
  
주의사항: 명령어가 'B'인 경우에서 마지막 줄 이유
```c++
if (cursor != aditor.begin()) {
    cursor--;
    cursor = aditor.erase(cursor);
}
```
list는 (vector와 달리) 해당원소가 삭제되면 iterator가 갈 곳을 잃는다.  
erase함수의 리턴값은 삭제 원소 사음에 있는 원소 iterator임을 이용한다.
