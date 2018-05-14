#利用系统功能调用从键盘输入一个字符串，然后输入单个字符，查找该字符串中是否有该字符（区分大小写）。主要是明白循环怎么写吧        
# mars4.5 20180511 on ubuntu18.04            
            .data 
s:          .asciiz "\nSuccess! Location: "
f:          .asciiz "\nFail!\n"
end:        .asciiz "\n"
buf:        .space 256

            .text
            .globl main
main:       la $a0, buf # 读取字符串
            la $a1, 256 # 字符串u长度
            li $v0, 8 # 读取命令
            syscall

ichar:      li $v0, 12 #载入char
            syscall
            addi $t5, $0, 63  #?退出
            sub $t6, $t5, $v0 #比较
            beq $t6, $0, exit #退出
            add $t0, $0, $0
            la $s1, buf

loop:       lb $s0, 0($s1) #按位查找
            sub $t1, $v0, $s0 #比较
            beq $t1, $0, suc #成功
            addi $t0, $t0, 1 #位移
            slt $t4, $t0, $a1#若到了末尾
            beq $t4, $0, fai #失败
            addi $s1 $s1, 1
            j loop #循环

suc:    la $a0, s  #成功输出位置
            li $v0, 4 
            syscall
            addi $a0, $t0, 1
            li $v0, 1 
            syscall
            la $a0, end
            li $v0, 4
            syscall
            j ichar

fai:        la $a0, f #到头了没找到
            li $v0, 4
            syscall
            j ichar

exit:       li $v0, 10
            syscall