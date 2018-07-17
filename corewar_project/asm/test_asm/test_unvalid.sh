#!/bin/bash
clear && printf '\e[3J'
output="difference.txt"
origin="origin.txt"
asm="asm.txt"
list_file=`find ./unvalid -type f -name "*.s"`
rm $output 2> /dev/null || true
echo "\033[0;35mChecking unvalid champs\n\033[0m"
for file in $list_file
do
	str=$((basename $file) | awk '{print toupper($0)}')
	#remove les anciens log
	rm $origin $asm 2> /dev/null || true

	#send results of original asm and yours in two txt file.
	./../original_asm $file >> $origin
	./../asm $file >> $asm

	#Retrieve first line of each output and stock it into var
	s1=$(head -1 $origin)
	s2=$(head -1 $asm)

	#compare var
	if [ "$s1" == "$s2" ]; then
		echo "$str\033[1;32m OK\033[0m\n" >> $output
	else
		#print both output
		echo "\033[1;32m$str:\033[0m\033[1;31m ERROR\n$(head -1 $file)\n\033[1;34mExpected oupout:\033[0m" >> $output
		./../original_asm $file >> $output
		echo "\033[1;34mYour output:\033[0m" >> $output
		./../asm $file >> $output
		echo "" >> $output
	fi
done

#rm useless files
rm ./unvalid/*.cor
rm $origin $asm 2> /dev/null || true

cat $output
echo "\nThanks for using that script, good luck ;)"
