def isCorrectString(s):
    # 올바른 문자열인지 판단하는 함수
    stack = []
    for a in s:
        if a == '(':
            stack.append('(')
        else:
            if len(stack) != 0:
                stack.pop()
    return (stack == [])


def solution(p):
    answer = ''
    if p == '':
        return ''
    # 군형잡은 문자열 u,v로 분리
    u = ''
    v = ''
    bal = False
    for s in p:
        if bal:
            v += s
        elif u != '' and u.count('(') == u.count(')'):
            bal = True
            v += s
        else:
            u += s

    if isCorrectString(u):
        answer += u
        answer += solution(v)
    else:
        temp = '('
        temp += solution(v)
        temp += ')'
        # u의 첫번째와 마지막 문자 제거
        u = u[1:len(u)-1]
        # 괄호방향 뒤집기
        for s in u:
            if s == '(':
                temp += ')'
            else:
                temp += '('
        answer += temp
    return answer


print(solution('()))((()'))
