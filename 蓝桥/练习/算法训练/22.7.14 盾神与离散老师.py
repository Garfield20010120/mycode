n=int(input())
nums=[]
for i in range(n):
    num=list(map(int,input().split()))
    nums.append(num)
for i in range(n):
    nums[i][i]=1
s=2
while s>0:
    for i in range(n):
        for j in range(n):
            if nums[i][j]:
                k=0
                while k<n:
                    if nums[j][k]:
                        nums[i][k]=1
                    k+=1
    s-=1
for num in nums:
    for j in range(n):
        print(num[j],end=" ")
    print()