d1=3
a1=[2,2,2,2,2,2,3,4,4,4,4,4,4,4,4]
"""
3
"""

d2=2
a2=[2,2,2,2,2,2,3,4,4,4,4]
"""
3
"""
d3=1
a3=[1,1,3,4,5,6]
"""
2
"""

d4=2
a4=[3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8]
"6"
d5=2
a5=[3,3,3,4,4,4,4]
"""
3
"""
p=0
def foo(S, a,d):
    p=0
    cars_so_far=1
    waiting_in_line=0 #ειναι η μταβλητη που μετράμε τα αμάξια που περιμένουν να φορτίστούνε
    jumps=0 #ειναι τα χρονικά διαστήματα που περνάνε , τα μετράμε γιατι η ουρα αλλάζει ΚΑΙ με βάση τον χρόνο
    continuous_number_of_cars=0 #μεταβλητη που μετρά τα συνεχόμενα αμάξια .
    cars_charging=1 #μετρα τα αμάξια που φορτίζουν
    for i  in range(0,len(a)-1):
        if(a[i+1]==a[i] ):
            cars_so_far+=1
            if(cars_charging>=S):
                waiting_in_line+=1
            else:
                cars_charging+=1
        else:
            cars_so_far+=1
            jumps+=a[i+1]-a[i]
            cars_so_far=cars_so_far-S*(jumps)
            if (cars_so_far>S): # αν τα αμαξια στο σταθμό , αυτα που περιμένουν και αυτα που φορτίζουν ειναι περισσότερα απο S
                cars_charging=S
                waiting_in_line=cars_so_far-S
            elif(cars_so_far<=S and cars_so_far>0):#ολη η ουρα εξυπηρετέιται
                waiting_in_line=0
                cars_charging=cars_so_far
                """elif(cars_so_far==0):
                cars_so_far=0
                cars_charging=0
                waiting_in_line=0"""
            elif(cars_so_far<=0): #αν δεν εχεις εχουμε αυτοκινητα στο σταθμό
                #print("BOMB:: for i=",i," a[i]=",a[i] , " waiting=",waiting_in_line," cars charging=",cars_charging," cars_so_far= ",cars_so_far," S=",S, " jumps=",jumps)  
                cars_so_far=1
                jumps=0 #επανέφερε την αρχική των διαστημάτων 
                cars_charging=1
                waiting_in_line=0
                continuous_number_of_cars=0
        if(waiting_in_line>(d-1)*S):
            print("this is not the S")
            p=1
            break
        print("for i=",i," a[i]=",a[i] , " waiting=",waiting_in_line," cars charging=",cars_charging," cars_so_far= ",cars_so_far," S=",S, " jumps=",jumps)
    if(p==0):
        print("found S :)")

foo(3,a5,d5)
