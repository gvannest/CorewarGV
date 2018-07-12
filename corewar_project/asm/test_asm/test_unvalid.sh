#!/bin/bash
clear && printf '\e[3J'
list_file=`find ./unvalid -type f -name "*.s"`
rm difference.txt2> /dev/null || true
echo "\033[0;35mChecking unvalid champs\n\033[0m"
for file in $list_file
do
	str=$((basename $file) | awk '{print toupper($0)}')
	echo "\033[1;32m$str\033[0m: $(head -1 $file)\n\033[1;34mExpected oupout:\033[0m" >>difference.txt
	./../original_asm $file >> difference.txt
	echo "\033[1;34mYour output:\033[0m" >> difference.txt
	./../asm $file >> difference.txt
	echo "" >> difference.txt
#	diff zazs.txt asm.txt >> difference.txt	
#	rm zazs.txt asm.txt 
done
rm ./unvalid/*.cor
cat difference.txt
echo "\nThanks for using that script, good luck ;)"
