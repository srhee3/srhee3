.section .text

.globl multiply

multiply: # main caller function 
  pushl %ebp
  movl %esp, %ebp
  pushl %ebx
  pushl %esi    # pushes into top of the stack 

  movl 8(%ebp), %eax    
  movl 12(%ebp), %ebx   # we create two numbers called n1 and n2 and load them into the %eax and %ebx register 
  xorl %ecx, %ecx       
  xorl %edx, %edx       # initalize these registers to 0 
 
  testl %eax, %eax      
  jz set_zero   
  testl %ebx, %ebx      
  jz set_zero     # testing whether or not registers are 0 
  test %eax, %eax       
  js check_error       # SF = 1 if eax or ebx is equal to negative integer; otherwise jump 
  test %ebx, %ebx       
  js check_error    

  mul_loop:  # callee function
    testl %eax, %eax    
    jz test_overflow    # test if there is overflow 
    testl %ebx, %ebx    # test if the registers are set to 0
    jz test_overflow    
    movl %eax, %esi     
    andl $1, %esi       
    jz skip_add         # jump to the skip_add function 
    addl %ebx, %ecx     
    jo check_error

  skip_add:
    addl %ebx, %ebx     # skip add will double the %ebx register 
    shrl $1, %eax       
    jmp mul_loop        # return or jump to mul_loop function 

  test_overflow:
    cmpl $0, %eax       
    jne check_error    
    cmpl $0, %edx       
    jne check_error    # go to check_error function 
    movl %ecx, %eax     # move %eax and set to -1 
    addl $0, %eax       # addl will add 0 to the testing flag 
    jo check_error 
    test %eax, %eax     
    js check_error     # js will jump if the SET FLAG is equal to 1 
    popl %esi
    popl %ebx
    popl %ebp
    ret

  set_zero: # purpose of this function is to return 0 for the registers 
    movl $0, %eax
    popl %esi
    popl %ebx
    popl %ebp
    ret

  check_error:       # we test if there's an overflow, if overflow, then print -1 
    movl $-1, %eax      
    popl %esi
    popl %ebx
    popl %ebp
    ret