def solution(s):
    if len(s) == 1:
        return 1

    answer = 1001
    # step: 압축할 단위
    for step in range(1, int(len(s)/2)+1):
        result = ""
        tempStr = s[:step]
        count = 1
        for i in range(step, len(s), step):
            if s[i: i+step] == tempStr:
                count += 1
            else:
                if count > 1:
                    result += str(count) + tempStr
                else:
                    result += tempStr
                tempStr = s[i: i+step]
                count = 1
        result += str(count) + tempStr if count > 1 else tempStr
        answer = min(answer, len(result))

    return answer
