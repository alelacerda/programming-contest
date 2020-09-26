catalan = list(range(301))
catalan[0] = 1
catalan[1] = 1
for i in range(2,301):
    catalan[i] = 0;
    for j in range(i):
        catalan[i] = catalan[i] + catalan[j] * catalan[i-j-1]

fat = list(range(301))
fat[0] = fat[1] = 1
for i in range(2,301):
    fat[i] = fat[i-1] * i
n = int(input())
while n != 0:
    ans = catalan[n]*fat[n]
    print(ans)
    n = int(input())