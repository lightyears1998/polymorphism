# Sum of Digits
# https://www.codechef.com/problems/FLOW006

gets stdin N
while {$N > 0} {
    gets stdin num
    set ans 0
    while {$num > 0} {
        set ans [expr {$ans + ($num % 10)}]
        set num [expr {$num / 10}]
    }
    puts $ans
    incr N -1
}
