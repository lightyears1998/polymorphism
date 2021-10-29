# Chef in Vaccination Queue
# https://www.codechef.com/problems/VACCINQ

for {gets stdin T} {$T} {incr T -1} {
    lassign [gets stdin] N P X Y
    gets stdin A
    set ans 0
    for {set i 0} {$i < $P} {incr i} {
        set ans [expr {$ans + ([lindex $A $i] == 0 ? $X : $Y)}]
    }
    puts $ans
}
