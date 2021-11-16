init_list=[99,20,15,10,12,13,14,25,11]

s=[]
ans=[]

#the first element init_list[0] is always the greater


for i in range(1,len(init_list)):
    
    if (len(s)==0) :
        #print("s is empty for i=",i )
        s.append(init_list[i])
        ans.insert(0,init_list[0])
        #print("the temp_ans=",ans[0],"s=",s," ans=",ans)
    elif (s[-1] > init_list[i]):
        #print("next is lower for i=",i)
        ans.insert(0,s[-1])
        s.append(init_list[i])
        #print("the temp_ans=",ans[0],"s=",s," ans=",ans)
    else:
        #print("next is greater for i=",i,"s=",s," ans=",ans)
        while(s):
            if(s[-1]>init_list[i]):
                ans.insert(0,s[-1])
                s.append(init_list[i])
                break
            s.pop()
        if(len(s)==0):
            s.append(init_list[i])
            ans.insert(0,init_list[0])
        #print("the temp_ans=",ans[0],"s=",s," ans=",ans)
temp=len(ans)-1
l=[ ans[temp-i] for i in range(0,len(ans))]
print(l)