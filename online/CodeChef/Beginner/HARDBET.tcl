proc sort {a b} {
    return [expr {[lindex $a 0] - [lindex $b 0]}]
}

for {gets stdin T} {$T} {incr T -1} {
    lassign [gets stdin] S_A S_B S_C
    set questions "{{$S_A} Draw} {{$S_B} Bob} {{$S_C} Alice}"
    set questions [lsort -command sort $questions]
    puts [lindex $questions 0 1]
}
