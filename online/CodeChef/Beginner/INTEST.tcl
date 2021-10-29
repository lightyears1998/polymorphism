# Enormous Input Test
# https://www.codechef.com/problems/INTEST

set line [gets stdin]
lassign $line n k
set ans 0
while { $n > 0 } {
    set num [ gets stdin ]
    if { $num % $k == 0} {
        incr ans
    }
    incr n -1
}
puts $ans
