.globl fibonacci

fibonacci:   # main caller function is called fibonacci 
    pushl %ebp          
    movl %esp, %ebp    
    pushl %ebx          
    pushl %ecx          
    pushl %edx          # all three of these registers are callee-save 

    movl 8(%ebp), %eax  # implements n (input)
    movl $0, %ebx       
    movl $1, %ecx       # set %ebx and %ecx fibonacci function (n-2) or (n-1)
                
    cmpl $0, %eax       # compares 0 and 1 to n and returns 0 or 1 
    je base_zero_fib           
    cmpl $1, %eax       
    je no_error         # we return 0 or 1 if n = 0 or n = 1. Therefore we used the cmpl instruction 

    decl %eax           # decrement 

.loop:
    addl %ecx, %ebx     # add the two registers: fibonacci(n-2) + fibonacci(n-1)
    jo test_overflow    # overflow 
    movl %ecx, %edx     
    movl %ebx, %ecx     
    movl %edx, %ebx     
    decl %eax           
    jnz .loop           # loop 

check_error:   # check if there is no error and return fibonacci(n)
    test %eax, %eax     
    js test_overflow    
    movl %ecx, %eax     
    jmp exit

test_overflow:  # test for overflow and return -1 if there is overflow 
    movl $-1, %eax     
    jmp exit

base_zero_fib:
    movl $0, %eax       # 0 is the base case so we will return 0. F(0) = 0 

exit:           # callee-saved registers: stack 
    popl %edx           
    popl %ecx           
    popl %ebx           
    leave               
    ret                