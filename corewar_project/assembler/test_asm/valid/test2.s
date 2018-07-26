.name		"the knock puncher"
.comment	"il va vous les briser"

		st	r1,9
		fork	%:roulo
		live	%42
		fork	%:label_367

roulo:		ld	%0,r15
		sti	r1, %28, %1
		sti	r1, %349, %1
		sti	r1, %178, %1
		st	r1, r10
		live	%42
		ld	%655339, r7
		ld	%655329, r8
		ld	%655319, r9
		ld	%655309, r10
		ld	%655299, r11
		ld	%40, r1
		ld	%45, r2
		ld	%50, r3
		ld	%55, r4
		ld	%55, r5
		xor	r16, r16, r16
		zjmp	%:label_367

label_367:	live	%42
		fork	%:label_367
