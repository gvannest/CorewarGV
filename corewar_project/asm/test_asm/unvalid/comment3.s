#Nada comment     
.name                      " 
zork" #loolololtestttt
#test
.comment 

		sti r1,%:live,%1
		and r1,%0,r1

live:   live %1
        zjmp %:live
