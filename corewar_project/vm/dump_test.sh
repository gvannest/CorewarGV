#!/bin/bash
clear && printf '\e[3J'
arg=$1
case $arg in
	    ''|*[!0-9]*) echo "Utilise un nombre a defaut d'utiliser ta tete" ;;
		    *) 
output="difference.txt"
origin="origin.txt"
asm="asm.txt"
num=$arg
list_file=`find ../../Resources/champs/ -type f -name "*.cor"`
rm $output 2> /dev/null || true
for file in $list_file
do
	str=$((basename $file) | awk '{print toupper($0)}')
	#remove les anciens log
	rm $origin $asm 2> /dev/null || true

	#send results of original asm and yours in two txt file.
	./../../original_corewar -d $num $file >> $origin
	./../../corewar -d $num $file >> $asm
	#compare var
	echo "$str:" >> $output
	diff $asm $origin >> $output
	echo "" >> $output
	rm $origin $asm 2> /dev/null || true
done

#rm useless files
cat $output
echo "Thanks for using that script, good luck ;)"
			esac
