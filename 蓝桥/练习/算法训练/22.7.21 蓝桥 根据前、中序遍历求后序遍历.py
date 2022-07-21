s1 = input()#前序
s2 = input()#中序
list1 = []
root = ""
def postOrder(s1,s2):
    if(s1!=""):
        len_s = len(s1)
        root = s1[0]
 
        list1.append(s1[0])#根
 
        index_s = s2.find(root)
        s2_left = s2[0:index_s]
        s2_right = s2[index_s+1:len_s]
        # print("s2_left=",s2_left)
        # print("s2_right=",s2_right)
 
        len_left = len(s2_left)
        len_right = len(s2_right)
        s1_left = s1[1:len_left+1]
        s1_right = s1[len_left+1:len_s]
        # print("s1_left=",s1_left)
        # print("s1_right=",s1_right)
 
        if(len_right>0):
            postOrder(s1_right,s2_right)#右子树
        if (len_left > 0):
            postOrder(s1_left, s2_left)#左子树
postOrder(s1,s2)
 
for i in range(len(list1)):
    print(list1.pop(),end='')
print()