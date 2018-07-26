#!/bin/bash
clear
list_file=`find . -type f -name "comment*"`
var=0
for file in $list_file
do
	cp "$file" "name$var.s"
	var=$((var+1))
	#	diff zazs.txt asm.txt >> difference.txt
	#	rm zazs.txt asm.txt
done
