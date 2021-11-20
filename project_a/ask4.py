import numpy as np
import array

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

def foo(a,d):
   """
   Μια συναρτηση που εχει ως εισοδο:
   a={πίνακας με στοιχεία που περιέχουν τους χρονους αυξησης των αυτοκινητων στο σταθμόμας}
   d={ο μεγιστος χρόνος που πρέπει να μεινει ενα αμάξι στο σταθμό μας, δηλαδη αν ερθει την στιγμή a[i], πρεπει να φύγει a[i]+d}
   """
   S=1 #ξεκινάμε με S=1
   cars_so_far=0 #ενω δεν εχουμε συναντήσει ακομα κανενα αμαξι , δηλαδη δεν εχουμε αρχισει να τρέχουμε τον πίνακα 
   #αρχικοποιούμε την μεταβλητη αυτη με 1 γιατι συγκρίνουμε πάντα το επόμενο , αρα καποιο στοιχειο , εδω το 1ο ,δεν θα μετρηθεί
   waiting_in_line=0 #ειναι η μταβλητη που μετράμε τα αμάξια που περιμένουν να φορτίστούνε
   jumps=0 #ειναι τα χρονικά διαστήματα που περνάνε , τα μετράμε γιατι η ουρα αλλάζει ΚΑΙ με βάση τον χρόνο
   continuous_number_of_cars=0 #μεταβλητη που μετρά τα συνεχόμενα αμάξια .
   cars_charging=0 #μετρα τα αμάξια που φορτίζουν
   for i  in range(0,len(a)-1):
      
      if(a[i+1]-a[i]>=d):
         cars_so_far=0
      #print((a[i] > a[i+1]+d),(a[i] <= a[i+1]+d))
      if (a[i+1] == a[i] ): # αν το επόμενο χρονικό διάστημα που ερχετε το επόμενο αμάξι ειναι ίδιο
         cars_so_far+=1 #συναντήσαμε και αλλο αμάξι
         
         continuous_number_of_cars+=1 #εχουμε σύγουρα 1 παραπάνω ίδιο
         if(cars_charging>=S): #αν τα αμάξια που φορτίζουν ειναι περισσότερα απο (το μέγιστο αριθμό που πρεπει να φορτίζουν στο σταθμό)
            waiting_in_line+=1 #αυξησε την ουρά κατα 1
         else: #αλλιώς
            cars_charging+=1
            waiting_in_line=0 # αν οχι τοτε δεν εχεις ουρα , και αυξησε τα αμάξια που φορτίζουν
         if (continuous_number_of_cars==1):
            print("found first element of a serries")
            continuous_number_of_cars+=1
            cars_so_far+=1
            if(i!=0):
               
               
               jumps+=a[i+1]-a[i]
               temp=cars_so_far-S*(jumps) #ανανέωσε τα αμάξια που υπάρχουν στο σταθμό
               
               if (temp>S): # αν τα αμαξια στο σταθμό , αυτα που περιμένουν και αυτα που φορτίζουν ειναι περισσότερα απο S
                  cars_charging=S
                  waiting_in_line=temp-S
               elif(temp<=S and temp>0):#ολη η ουρα εξυπηρετέιται
                  waiting_in_line=0
                  cars_charging=temp
                  """elif(cars_so_far==0):
                  cars_so_far=0
                  cars_charging=0
                  waiting_in_line=0"""
               elif(temp<=0): #αν δεν εχεις εχουμε αυτοκινητα στο σταθμό
                  #print("BOMB:: for i=",i," a[i]=",a[i] , " waiting=",waiting_in_line," cars charging=",cars_charging," cars_so_far= ",cars_so_far," S=",S, " jumps=",jumps)  
                  cars_so_far=0
                  jumps=0 #επανέφερε την αρχική των διαστημάτων 
                  cars_charging=0
                  waiting_in_line=0
                  continuous_number_of_cars=0
               print("START OF A DIF SERIES:: for i=",i," a[i]=",a[i]," cont=",continuous_number_of_cars , " waiting=",waiting_in_line," cars charging=",cars_charging," cars_so_far= ",cars_so_far," S=",S, " jumps=",jumps)
            
            if(cars_charging>=S): #αν τα αμάξια που φορτίζουν ειναι περισσότερα απο (το μέγιστο αριθμό που πρεπει να φορτίζουν στο σταθμό)
               waiting_in_line+=1 #αυξησε την ουρά κατα 1
            else: #αλλιώς
               cars_charging+=1
               waiting_in_line=0 # αν οχι τοτε δεν εχεις ουρα , και αυξησε τα αμάξια που φορτίζουν
         print("end of 1st if::for i=",i," a[i]=",a[i]," cont=",continuous_number_of_cars , " waiting=",waiting_in_line," cars charging=",cars_charging," cars_so_far= ",cars_so_far," S=",S," jumps=",jumps)
      elif(a[i+1]!=a[i] and a[i]==a[i-1])   :
         
         
         print("LAST ELEMENT:: for i=",i," a[i]=",a[i]," cont=",continuous_number_of_cars , " waiting=",waiting_in_line," cars charging=",cars_charging," cars_so_far= ",cars_so_far," S=",S," jumps=",jumps)
      
      else: # αν το επόμενο χρονικό διάστημα που ερχετε το επόμενο αμάξι ΔΕΝ ειναι ίδιο
         cars_so_far+=0 #συναντήσαμε και αλλο αμάξι
          #αυξησε τα χρονικά διαστηματα που πέρασαν μέχρι τότε
         
         """if(cars_charging>=S): #αν τα αμάξια που φορτίζουν ειναι περισσότερα απο (το μέγιστο αριθμό που πρεπει να φορτίζουν στο σταθμό)
               waiting_in_line+=1 #αυξησε την ουρά κατα 1
            else:
               cars_charging+=1
               waiting_in_line=0""" # αν οχι τοτε δεν εχεις ουρα και αυξησε τα αμάξια που φορτίζουν
         if(a[i]!=a[i+1]): # αν εχουμε 1 διαφορετικό στοιχείο σε σχεση με το προηγούμενο και το επόμενο
            cars_so_far+=1
            jumps+=a[i+1]-a[i]
            continuous_number_of_cars=0
            temp=cars_so_far-S*(jumps)
            print("FOUND FIRST AND LAST:: for i=",i," a[i]=",a[i]," cont=",continuous_number_of_cars , " waiting=",waiting_in_line," cars charging=",cars_charging," cars_so_far= ",cars_so_far," S=",S, " jumps=",jumps)
            if (temp>S): # αν τα αμαξια στο σταθμό , αυτα που περιμένουν και αυτα που φορτίζουν ειναι περισσότερα απο S
               cars_charging=S
               waiting_in_line=temp-S
            elif(temp<=S and temp>0):#ολη η ουρα εξυπηρετέιται
               waiting_in_line=0
               cars_charging=temp
               """elif(cars_so_far==0):
               cars_so_far=0
               cars_charging=0
               waiting_in_line=0"""
            elif(temp<=0): #αν δεν εχεις εχουμε αυτοκινητα στο σταθμό
               #print("BOMB:: for i=",i," a[i]=",a[i] , " waiting=",waiting_in_line," cars charging=",cars_charging," cars_so_far= ",cars_so_far," S=",S, " jumps=",jumps)  
               cars_so_far=0
               jumps=0 #επανέφερε την αρχική των διαστημάτων 
               cars_charging=0
               waiting_in_line=0
               continuous_number_of_cars=0
            
            
         
            
            #γιατί εχεις εξυπηρετήσει ολα τα αυτοκινητα μεχρι στιγμης
            
         print("end 2nd if:: for i=",i," a[i]=",a[i]," cont=",continuous_number_of_cars , " waiting=",waiting_in_line," cars charging=",cars_charging," cars_so_far= ",cars_so_far," S=",S, " jumps=",jumps)
      
      
      if (waiting_in_line>(d-1)*S): #αν αυτα που περιμενουν κανουν ειναι παραπάνω απο αυτα που ΕΠΡΕΠΕ να περιμένουν 
         # ΣΕ d χρόνο θα πρέπει να έχουν φύγει τα αμάξια που ηρθαν a[i]
         # αρα ενα αμάξι μπορει να περιμένει d-1 
         # και ο σταθμός πέρνει καθε φορά S αμάξια 
         # αρα μπορούν να περιμένουν (d-1)*S
         S+=1 # αυξησε τις θέσεις φόρτησης
         temp=cars_so_far-S*(jumps)
         print("new cars for new s",temp)
          #ανανέωσε τα αμάξια που περιμένουν
         if(temp<=S):
            cars_charging=temp
            waiting_in_line=0
            
         else:
            waiting_in_line=temp-S
            cars_charging=S
         
         if(waiting_in_line<0):
            waiting_in_line=0
         print("NEW:: for i=",i," a[i]=",a[i]," cont=",continuous_number_of_cars , " waiting=",waiting_in_line," cars charging=",cars_charging," cars_so_far= ",cars_so_far," S=",S, " jumps=",jumps)
      
   print("ΤΟ ΕΛΑΧΙΣΤΟ S , ΜΕ d=",d,"ΕΙΝΑΙ ",S)

foo(a1,d1)