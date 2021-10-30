# Find the Direction
# https://www.codechef.com/problems/FACEDIR

set directions {North East South West}

for {gets stdin T} {$T} {incr T -1} {
    gets stdin X
    puts [lindex $directions [expr {$X % 4}]]
}
