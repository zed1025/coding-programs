class Solution:
    def reverseWords(self, s: str) -> str:
        s = s.strip()
        s = s.split()
        s.reverse()
        s = ' '.join(s)
        return s

    def reverseWords2(self, s: str) -> str:
        print(s)
        word = []
        words = []
        s_ = list(s)
        for i in range(len(s_)):
            if s_[i] != ' ':
                word.append(s_[i])
            if s_[i] == ' ':
                if word:
                    print(''.join(word))
                    s = ''.join(word)
                    words.append(s)
                    word.clear()
        if s_[-1] != ' ':
            words.append(''.join(word))
        print(words)
        words.reverse()
        words = ' '.join(words)
        return words

    # two pointer solution
    def reverseWords3(self, s: str) -> str:
        i = 0
        words = []
        t = 0
        while t < len(s):
            if s[t] != ' ':
                i = t
                while t < len(s) and s[t] != ' ':
                    t+=1
                words.append(s[i:t])
            else:
                t += 1
        words.reverse()
        words = ' '.join(words)
        return words


if __name__ == '__main__':
    # s = "the sky is blue"
    s = "  hello world  "
    ob = Solution()
    print(ob.reverseWords3(s))