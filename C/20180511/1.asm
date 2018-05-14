#I/O  参考mips教程  话说清华这课什么都不给就这么留作业真的好吗？ 不过mars挺好用的。。。
.data
    A:  .asciiz "Alpha "   
    B:  .asciiz "Bravo "  
    C:  .asciiz "Charlie "  
    D:  .asciiz "Delta "  
    E:  .asciiz "Echo "  
    F:  .asciiz "Foxtrot "  
    G:  .asciiz "Golf "  
    H:  .asciiz "Hotel "  
    I:  .asciiz "India "  
    J:  .asciiz "Juliet "  
    K:  .asciiz "Kilo "  
    L:  .asciiz "Lima "  
    M:  .asciiz "Mike "  
    N:  .asciiz "November "  
    O:  .asciiz "Oscar "  
    P:  .asciiz "Papa "  
    Q:  .asciiz "Quebec "  
    R:  .asciiz "Romeo "  
    S:  .asciiz "Sierra "  
    T:  .asciiz "Tango "  
    U:  .asciiz "Uniform "  
    V:  .asciiz "Victor "  
    W:  .asciiz "Whisky "  
    X:  .asciiz "X-ray "  
    Y:  .asciiz "Yankee "  
    Z:  .asciiz "Zulu "  
    
    a:  .asciiz "alpha "    
    b:  .asciiz "bravo "  
    c:  .asciiz "charlie "  
    d:  .asciiz "delta "  
    e:  .asciiz "echo "  
    f:  .asciiz "foxtrot "  
    g:  .asciiz "golf "  
    h:  .asciiz "hotel "  
    i:  .asciiz "india "  
    j:  .asciiz "juliet "  
    k:  .asciiz "kilo "  
    l:  .asciiz "lima "  
    m:  .asciiz "mike "  
    n:  .asciiz "november "  
    o:  .asciiz "oscar "  
    p:  .asciiz "papa "  
    q:  .asciiz "quebec "  
    r:  .asciiz "romeo "  
    s:  .asciiz "sierra "  
    t:  .asciiz "tango "  
    u:  .asciiz "uniform "  
    v:  .asciiz "victor "  
    w:  .asciiz "whisky "  
    x:  .asciiz "x-ray "  
    y:  .asciiz "yankee "  
    z:  .asciiz "zulu "  
    
    n1:  .asciiz "one "  
    n2:  .asciiz "two "  
    n3:  .asciiz "three "  
    n4:  .asciiz "four "  
    n5:  .asciiz "five "  
    n6:  .asciiz "six "  
    n7:  .asciiz "seven "  
    n8:  .asciiz "eight "  
    n9:  .asciiz "nine "  
    n10: .asciiz "zero "  
 
  
.text

 
  

main:   li $v0, 12  # li是加载立即数  $v0 中包含调用号（共12个）： 其中第12个是Read Char $a0 = character read
        syscall     #系统调用
        sub $t1, $v0, 63 #63是问号
        beqz $t1, exit
        #48-57
        sub $t2, $v0, 57
        sle $s2, $t2, $0 
        sub $t3, $v0, 48 
        sge $s3, $t3, $0 
        and $s0, $s2, $s3 
        bnez $s0, printn
        #65-90
        sub $t4, $v0, 90
        sle $s4, $t4, $0 
        sub $t5, $v0, 65 
        sge $s5, $t5, $0 
        and $s0, $s4, $s5 
        bnez $s0, printuw       
        #97-122
        sub $t6, $v0, 122
        sle $s6, $t6, $0 
        sub $t7, $v0, 97
        sge $s7, $t7, $0 
        and $s0, $s6, $s7
        bnez $s0, printlw
        j printo
          

printn:     beq $t3, 1,l1
            beq $t3, 2,l2
            beq $t3, 3,l3
            beq $t3, 4,l4
            beq $t3, 5,l5
            beq $t3, 6,l6
            beq $t3, 7,l7
            beq $t3, 8,l8
            beq $t3, 9,l9
            beq $t3, $zero,l10
           

l1: la $a0, n1
    j print
l2: la $a0, n2
    j print
l3: la $a0, n3
    j print
l4: la $a0, n4
    j print
l5: la $a0, n5
	j print
l6: la $a0, n6
	j print
l7: la $a0, n7
	j print
l8: la $a0, n8
	j print
l9: la $a0, n9
	j print
l10: la $a0, n10
	j print
	
printuw:    beq $t5, $zero,Al
            beq $t5, 1,Bl
            beq $t5, 2,Cl
            beq $t5, 3,Dl
            beq $t5, 4,El
            beq $t5, 5,Fl
            beq $t5, 6,Gl
            beq $t5, 7,Hl
            beq $t5, 8,Il
            beq $t5, 9,Jl
            beq $t5, 10,Kl
            beq $t5, 11,Ll
            beq $t5, 12,Ml
            beq $t5, 13,Nl
            beq $t5, 14,Ol
            beq $t5, 15,Pl
            beq $t5, 16,Ql
            beq $t5, 17,Rl
            beq $t5, 18,Sl
            beq $t5, 19,Tl
            beq $t5, 20,Ul
            beq $t5, 21,Vl
            beq $t5, 22,Wl
            beq $t5, 23,Xl
            beq $t5, 24,Yl
            beq $t5, 25,Zl
Al:la $a0, A
    j print
Bl:la $a0, B
    j print
Cl:la $a0, C
    j print
Dl:la $a0, D
    j print
El:la $a0, E
    j print
Fl:la $a0, F
    j print
Gl:la $a0, G
    j print
Hl:la $a0, H
    j print
Il:la $a0, I
    j print
Jl:la $a0, J
    j print
Kl:la $a0, K
    j print
Ll:la $a0, L
    j print
Ml:la $a0, M
    j print
Nl:la $a0, N
    j print
Ol:la $a0, O
    j print
Pl:la $a0, P
    j print
Ql:la $a0,Q
    j print  
Rl:la $a0, R
    j print
Sl:la $a0, S
    j print
Tl:la $a0, T
    j print
Ul:la $a0, U
    j print
 Vl:la $a0, V
    j print
    Wl:la $a0, W
    j print
    Xl:la $a0, X
    j print
    Yl:la $a0, Y
    j print
    Zl:la $a0, Z
    j print

printlw:    beq $t7, $zero,al
            beq $t7, 1,bl
            beq $t7, 2,cl
            beq $t7, 3,dl
            beq $t7, 4,el
            beq $t7, 5,fl
            beq $t7, 6,gl
            beq $t7, 7,hl
            beq $t7, 8,il
            beq $t7, 9,jl
            beq $t7, 10,kl
            beq $t7, 11,ll
            beq $t7, 12,ml
            beq $t7, 13,nl
            beq $t7, 14,ol
            beq $t7, 15,pl
            beq $t7, 16,ql
            beq $t7, 17,rl
            beq $t7, 18,sl
            beq $t7, 19,tl
            beq $t7, 20,ul
            beq $t7, 21,vl
            beq $t7, 22,wl
            beq $t7, 23,xl
            beq $t7, 24,yl
            beq $t7, 25,zl
al:la $a0, a
    j print
bl:la $a0, b
    j print
cl:la $a0, c
    j print
dl:la $a0, d
    j print
el:la $a0, e
    j print
fl:la $a0, f
    j print
gl:la $a0, g
    j print
hl:la $a0, h
    j print
il:la $a0, i
    j print
jl:la $a0, j
    j print
kl:la $a0, k
    j print
ll:la $a0, l
    j print
ml:la $a0, m
    j print
nl:la $a0, n
    j print
ol:la $a0, o
    j print
pl:la $a0, p
    j print
ql:la $a0,q
    j print  
rl:la $a0, r
    j print
sl:la $a0, s
    j print
tl:la $a0, t
    j print
ul:la $a0, u
    j print
 vl:la $a0, v
    j print
    wl:la $a0, w
    j print
    xl:la $a0, x
    j print
    yl:la $a0, y
    j print
    zl:la $a0, z
    j print   

print:  li $v0, 4 #print string
        syscall
        j main

printo:     and $a0, $0, $0
            add $a0, $a0, 42 
            li $v0, 11
            syscall
            j main

exit:    li $v0, 10 #  同上v0 10是 Exit Program
         syscall

