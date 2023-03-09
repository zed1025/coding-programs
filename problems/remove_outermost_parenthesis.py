
def removeOuterParentheses(s):
    s_ = list(s)
    count = 0
    output = []
    for i in range(len(s_)):
        if s_[i] == '(':
            if count == 0:
                count = 1
                continue
            output.append(s_[i])
            count = count + 1
            continue
        if s_[i] == ')' and count <= 1:
            count = 0
        else:
            output.append(s_[i])
            count = count - 1
    s_ = ''.join(output)
    return s_

s = "(()())(())"
print(removeOuterParentheses(s))