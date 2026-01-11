t = int(input().strip())
for _ in range(t):
    n = int(input().strip())
    arr = list(map(int, input().split()))
    even_count = 0
    first_even = None
    second_even = None
    for num in arr:
        if num % 2 == 0:
            even_count += 1
            if even_count == 1:
                first_even = num
            elif even_count == 2:
                second_even = num
                break
    if even_count >= 2:
        print(first_even, second_even)
        continue
        
    if arr[0] == 1:
        print(1, arr[1])
        continue
        
    odds = []
    for num in arr:
        if num % 2 == 1:
            odds.append(num)
    if len(odds) < 2:
        print(-1)
    else:
        if len(odds) > 31:
            odds = odds[:31]
        found = False
        for i in range(len(odds)):
            for j in range(i+1, len(odds)):
                if (odds[j] % odds[i]) % 2 == 0:
                    print(odds[i], odds[j])
                    found = True
                    break
            if found:
                break
        if not found:
            print(-1)