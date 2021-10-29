# LUCKYFR
# https://www.codechef.com/problems/LUCKYFR

gets stdin T
while {$T > 0} {
    gets stdin n
    set ans 0
    while {$n > 0} {
        if {$n % 10 == 4} {
            incr ans
        }
        set n [expr {$n / 10}]
    }
    puts $ans
    incr T -1
}
