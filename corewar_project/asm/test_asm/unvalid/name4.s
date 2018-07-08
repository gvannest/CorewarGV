#instruction after .name

.comment "This is a comment"
.name                      " 
zork" sti r1,%:live,%1
#loolololtestttt
		and r1,%0,r1

live:   live %1
        zjmp %:live
