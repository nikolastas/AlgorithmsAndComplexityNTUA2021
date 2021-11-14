import numpy as np
import array

d=1
S=1
temp=1
change=0
a=[2,2,2,4,4]
for i  in range(0,len(a)-1):
   print("compare1= ",a[i] ,"compare2= ",a[i+1])
   #print((a[i] > a[i+1]+d),(a[i] <= a[i+1]+d))
   if (a[i+1] == a[i]):
       temp+=1
       #change=1
       print("1")
   else: 
      temp=1
   """elif (a[i+1] >= a[i]+d) and temp!=0:
       temp-=1
       print("2a")
       if change==1:
           temp=1
           change=0
           print("2b")"""
        
   if temp>d:
        S+=1
        print("3")

print("temp= ",temp," S= ",S)