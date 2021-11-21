a=[1,2,3,4]
s=[]

def make_s(s,a):
    for i in a:
        for j in a:
            if (j-i>0):
                s.append(j-i)
make_s(s,a)
print("s=",s)


#------------------------- quickshort--------------------
def partition(arr, low, high):
    i = (low-1)         # index of smaller element
    pivot = arr[high]     # pivot
  
    for j in range(low, high):
  
        # If current element is smaller than or
        # equal to pivot
        if arr[j] <= pivot:
  
            # increment index of smaller element
            i = i+1
            arr[i], arr[j] = arr[j], arr[i]
  
    arr[i+1], arr[high] = arr[high], arr[i+1]
    return (i+1)
  
# The main function that implements QuickSort
# arr[] --> Array to be sorted,
# low  --> Starting index,
# high  --> Ending index
  
# Function to do Quick sort
  
  
def quickSort(arr, low, high):
    if len(arr) == 1:
        return arr
    if low < high:
  
        # pi is partitioning index, arr[p] is now
        # at right place
        pi = partition(arr, low, high)
  
        # Separately sort elements before
        # partition and after partition
        quickSort(arr, low, pi-1)
        quickSort(arr, pi+1, high)
  
  
# ----------------------end quickshort------------------

n = len(a)
quickSort(a, 0, n-1)

p = len(s)
quickSort(s, 0, p-1)
print("quickshort-ed s=",s)
print("quickshort-ed a=",a)

temp=0
j=0
def foo(l,a,n):
    temp=0
    j=0
    i=0
    for i in range(0,len(a)-1):
        while( j<=n-1 and a[j]-a[i]<=l):  
            j+=1
        temp+=j-1-i
    
    print(temp)

foo(0,a,n)
foo(1,a,n)
foo(2,a,n)