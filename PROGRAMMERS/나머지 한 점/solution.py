from collections import deque

def solution(v):    
    q = deque(v)
    # 가운데 있는 점 찾기
    for _ in range(3):
        center = q[0]
        q.popleft()
        # 두 점을 지나는 벡터
        vec1 = [ q[0][0] - center[0], q[0][1] - center[1] ]
        vec2 = [ q[1][0] - center[0], q[1][1] - center[1] ]
        # 내적값
        pro = (vec1[0]*vec2[0] + vec1[1]*vec2[1])
        q.append(center)
        if( pro == 0):
            break
    # q 맨뒤에 있는게 center
    a, b = q[0][0] - center[0], q[0][1] - center[1]
    return (q[1][0] + a, q[1][1]+b)
        