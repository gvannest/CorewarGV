#No .name at all  
.comment                      " 
zork" #loolololtestttt
		sti r1,%:live,%1
		and r1,%0,r1

live:   live %1
        zjmp %:live
