if __name__ == '__main__':
    d = {}
    maxi = -100000000
    s_maxi = -10000000
    for _ in range(int(input())):
        name = input()
        score = float(input())
        d[name] = score
        
        if(score>maxi):
            s_maxi = maxi
            maxi = score
    
    s_maxi = sorted(list(set(d.values())))[1]
    listi = sorted(d.keys())
    
    for i in listi:
        if(d[i]==s_maxi):
            print(i)
