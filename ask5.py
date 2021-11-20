a=[1,2,3,4]
s=[]

def make_s(s,a):
    for i in a:
        for j in a:
            if (j-i>0):
                s.append(j-i)
make_s(s,a)
print("s=",s)
              

def foo(l):
    temp=-1
    print(temp)
