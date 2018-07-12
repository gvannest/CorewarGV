#!/bin/bash
clear && printf '\e[3J'
name='valid'
repo='valid'
list_file=`find ./$repo -type f -name "*.s"`
rm $name.txt 2> /dev/null || true
echo "\033[0;35mChecking valid champs\n\033[0m"
for file in $list_file
do
	str=$((basename $file) | awk '{print toupper($0)}')
	echo "\033[1;32m$str\033[0m: $(head -1 $file)\n\033[1;34mExpected oupout:\033[0m" >> $name.txt
	./../original_asm $file >> $name.txt
	echo "\033[1;34mYour output:\033[0m" >> $name.txt
	./../asm $file >> $name.txt
	echo "" >> $name.txt
#	diff zazs.txt asm.txt >> difference.txt	
#	rm zazs.txt asm.txt 
done
rm ./$repo/*.cor
cat $name.txt
echo "\nThanks for using that script, good luck ;)"
