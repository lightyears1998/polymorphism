# Pass or Fail
# https://www.codechef.com/problems/PASSORFAIL

gets stdin T
while {$T > 0} {
    lassign [gets stdin] N X P
    if {3*$X-($N-$X) >= $P} {
        puts PASS
    } else {
        puts FAIL
    }
    incr T -1
}
