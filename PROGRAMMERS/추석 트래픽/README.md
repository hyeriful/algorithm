# [프로그래머스 - 추석 트래픽](https://programmers.co.kr/learn/courses/30/lessons/17676)

## 해결 아이디어

1. _datatime_ 을 사용해서 날짜/시간 연산을 할 수 있다.

```python
from datetime import datetime, timedelta
date = datetime.strptime(str_date, '%Y-%m-%d %H:%M:%S.%f')    # string to datetime
gap = date - timedelta(seconds=3.14)
```

2. 말 그대로 1초를 빼면 안된다.  
   문제에서 시작시간과 끝시간을 포함한다고 했으므로  
   끝시간으로부터 시작시간을 구할 때, 소요된 시간에서 0.001초를 빼주었고 (30line)  
   시작시간에서 1초지난 끝시간을 구할 때, 0.999초(1-0.001초)를 더해주어야 한다. (8line)

3. 시작과 끝에서만 따져도 된다.  
   각 로그의 시작시간과 끝시간에서의 1초에서 초당 처리량을 구하면 된다.
