for {gets stdin T} {$T} {incr T -1} {
    lassign [gets stdin] X Y Z
    puts [expr {($Y - $X) <= 2 * $Z} ? YES : NO]
}
