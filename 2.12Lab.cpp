atomicWeightCarbon=12.0110 
atomicWeightHydrogen=1.0079 
atomicWeightOxygen=15.9994 

print("Enter the number of carbon atoms: ")

numCarbon=float(input()) 

print("Enter the number of hydrogen atoms: ")
numHydrogen=float(input()) 

print("Enter the number of oxygen atoms: ")
numOxygen=float(input()) 

molecularWeight=(atomicWeightCarbon*numCarbon+atomicWeightHydrogen*numHydrogen+atomicWeightOxygen*numOxygen) 

print("The molecular weight is "+str(molecularWeight)) 

