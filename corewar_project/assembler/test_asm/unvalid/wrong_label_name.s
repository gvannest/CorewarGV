.name "zork"
.comment "just a basic living prog"

		sti r1,%:li*ve,%1
		and r1,%0,r1

live:   live %1
        zjmp %:elive
