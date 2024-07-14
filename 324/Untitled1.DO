# ACCEL PCB V19.01.7431 Auto-Generated DO File
# Mon Jan 25 15:41:10 2010
#
bestsave on $\best.w
status_file $\progress.sts
#
unit mil
#
grid wire 100.000000 
grid via 100.000000 
#
rule pcb (width 10.0)
#
bus diagonal
route 50
clean 4
route 50 16
clean 4
filter 5
route 100 16
clean 2
delete conflicts
#
write wire $\Untitled1.w
spread 
miter
write wire $\Untitled1.m
#
write session $\Untitled1.ses
report status $\Untitled1.sts
