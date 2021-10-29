# Summer Heat
# https://www.codechef.com/problems/COCONUT

gets stdin T
while {$T > 0} {
    gets stdin line
    lassign $line x_a x_b X_a X_b
    puts [expr {($X_a / $x_a) + ($X_b / $x_b)}]
    incr T -1
}
