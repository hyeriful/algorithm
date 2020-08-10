백준 9093 단어 뒤집기
======================
해결 아이디어
---------------------
### solution1 (main1.cpp)
- string.find 로 띄어쓰기 부분 반복문을 통해 찾기  
  
주의사항
```c++
int testcase;
string str;
scanf_s("%d", &testcase);
getline(cin, original);
```
이때 처음 scanf_s 마지막에 남아있는 엔터가 처음 getline의 입력으로 들어감.
따라서 아래와 같이 cin.ignore()을 추가해주어야 함.
```c++
int testcase;
string str;
scanf_s("%d", &testcase);
cin.ignore();
getline(cin, original);
```
  
### solution2 (main2.cpp)
- stack 사용  
띄어쓰기 나오기 전까지 단어 push, 띄어쓰기 나오면 pop
