# Banker-s-Algorithm

## Objectives :
•Assignment 2 is intended to help you better understand the banker’s 
algorithm and how it determines the presence or absence of the safe state.
Instructions:
• You are required to implement the banker’s algorithm in the programming 
language of your choice (preferably C or C++) using the following pseudo 
code :
P - set of processes
Mp - maximal requirement of resources for process p
Cp - current resources allocation process p 
A - currently available resources
```
while (P != ∅) {
found = False
foreach (p ∈ P) {
if (Mp − Cp ≤ A) {
/* p can obtain all it needs. */
/* assume it does so, terminates, and */
/* releases what it already has. */
A = A + Cp
P = P − {p}
found = True
}
}
if (!found) return UNSAFE
}
return SAFE
```
## Inputs :
A filename from the keyboard, read the file for the pertinent data.The file 
contains the snapshot of a system at a certain time.The system has 5 processes 
and 3 resource types.
The first 5 lines (each line representing a process) in the input file will 
contain the current Allocation matrix for the system (with 3 resources).The 
second 5 lines in the input file will be the maximum possible resource request 
for each of the 5 process.The final line will contain the available resources at 
the time of the snapshot.
## Outputs: 
A prompt for which file is to be read. Then the output will be if the current 
state is safe and a possible execution sequence for the system.
## Deliverables:
• Complete source code, commented thoroughly and clearly.
• A report that includes:
➢ A description of the overall organization of your code and the 
major functions.
➢ Sample runs and screenshots.
## Notes:
• Languages used: C/C++.
• Operating System: Linux
• Students will work in groups of 4-5
