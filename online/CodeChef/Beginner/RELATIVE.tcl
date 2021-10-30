for {gets stdin T} {$T} {incr T -1} {
    lassign [gets stdin] g c
    puts [expr {$c*$c/2/$g}]
}
