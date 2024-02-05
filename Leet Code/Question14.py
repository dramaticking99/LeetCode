class Solution:
    def longestCommonPrefix(self, L: List[str]) -> str:
        a=L[0]
        if L.count(a) == len(L):
            return a
        for i in range(1,len(L)):
            w=''
            if a!= L[i]:
                for j in range(len(a)):
                    if j<len(L[i]):
                        if a[j] == L[i][j]:
                            w+=a[j]
                        else:
                            break
                    else:
                        break
                a=w
                if w=='':
                    return w
                if i==len(L)-1:
                    return a
            if i==len(L)-1:
                return a
