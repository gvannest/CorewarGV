#.name command on the same line as .comment    

.comment "just a basic living prog".name                      " 
zork"
		sti r1,%:live,%1
		and r1,%0,r1

live:   live %1
        zjmp %:live
