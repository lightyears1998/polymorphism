# Adding Two Numbers
# https://www.codechef.com/problems/FLOW001

set T [gets stdin]
while {$T > 0} {
    set nums [gets stdin]
    foreach {a b} $nums {
        puts [expr {$a + $b}]
    }
    incr T -1
}
