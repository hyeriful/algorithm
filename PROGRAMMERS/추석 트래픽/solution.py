from datetime import datetime, timedelta

log = []


def cmp(cur, i):
    start = cur
    end = cur+timedelta(seconds=0.999)
    cnt = 1
    for j in range(i+1, len(log)):
        # 1. 구간 안에 시작점, 끝점이 모두 있는 경우
        # 2. 구간 안에 시작점은 없지만 끝점이 있는 경우
        # 3. 구간엔에 시작점 있고 끝점이 없는 경우
        if log[j][0] >= start and log[j][1] <= end:
            cnt += 1
        elif log[j][0] <= start and log[j][1] >= start:
            cnt += 1
        elif log[j][0] <= end and log[j][1] >= end:
            cnt += 1
    return cnt


def solution(lines):
    answer = 0
    for date in lines:
        temp = date.split(' ')
        end = temp[0] + ' ' + temp[1]
        end = datetime.strptime(end, '%Y-%m-%d %H:%M:%S.%f')    # string to datetime
        sec = float(temp[2][0:-1])  # 초 끝에 s제거
        start = end - timedelta(seconds=sec-0.001)
        log.append([start, end])
    # print(log)

    for i in range(len(log)):
        for d in log[i]:
            cnt = cmp(d, i)
            answer = max(answer, cnt)

    return answer
