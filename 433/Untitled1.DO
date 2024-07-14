# ACCEL PCB V19.01.7431 Auto-Generated DO File
# Mon Mar 22 16:16:00 2010
#
bestsave on $\best.w
status_file $\progress.sts
#
unit mm
#
grid wire 2.540000 
grid via 2.540000 
#
rule pcb (width 0.254)
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
write wire $\Zak-laba-dpp.w
spread 
miter
write wire $\Zak-laba-dpp.m
#
write session $\Zak-laba-dpp.ses
report status $\Zak-laba-dpp.sts
