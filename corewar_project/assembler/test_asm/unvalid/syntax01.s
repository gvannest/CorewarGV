#->2 virgules qui se suivente
 .name                      " zork" #loolololtestttt
#test
.comment "just a basic living prog"

label: sti r1,,%:live,%1
		sti r1   ,%:live,%1
		and r1,%0,r1

live:   live %1
        zjmp %:live
