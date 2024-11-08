.globl fibonacci

fibonacci:
    cmpl $1, %eax         # cmpl = compare. Compare if input is less than or equal to 1. 
    jle test_negative       # test for negative 
    decl %eax             
    pushl %eax            
    call fibonacci         # Fibonacci formula : fibonacci(n-1) as well as calling the function 
    xchg %eax, 0(%esp)    # used to reset register 
    decl %eax             
    call fibonacci         # fibonacci(n-2); calls function 
    popl %ecx             
    addl %ecx, %eax       
    jo test_overflow # overflow 
        
test_negative:
    test %eax, %eax       # tests if a non negative value is return
    js test_overflow     
    jmp exit          

test_overflow:
    movl $-1, %eax        # test for overflow and return -1 if there is overflow 
    jmp exit

exit:
    ret          # returns either 0 or 1  
                          