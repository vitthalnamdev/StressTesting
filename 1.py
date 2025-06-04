import sys

def main():
    input = sys.stdin.read
    data = input().split()
    t = int(data[0])
    index = 1
    for _ in range(t):
        x = int(data[index])
        y = int(data[index+1])
        index +=2
        
        if (y & x) != y:
            print(-1)
            continue
        
        if y == 0:
            if x == 0:
                print(1)
            else:
                k = bin(x).count('1')
                if k == 1:
                    print(-1)
                else:
                    print(1 << k)
        else:
            k = bin(x).count('1')
            if k == 1:
                if x == y:
                    print(2)
                else:
                    print(-1)
            else:
                print((1 << k) -1)

if __name__ == "__main__":
    main()