.name "zork"
.comment "just a basic living prog"

		sti %1,r2,r1
		and r1,%0,r1

live:   live %1
        zjmp %:live
