#!/bin/bash
clear && printf '\e[3J'
cp ../asm .
output="difference.txt"
list_file=`find ./valid -type f -name "*.s"`
rm $output 2> /dev/null || true
echo "\033[0;35mChecking unvalid champs\n\033[0m"
for file in $list_file
do
	str=$((basename $file) | awk '{print toupper($0)}')
	echo "$str" >> difference.txt
	#remove les anciens log
	rm $origin $asm 2> /dev/null || true

	./original_asm $file
	s=$file
	s=${s##*/}
	s=${s%.*}
	cp valid/$s.cor valid/test1.cor
	./asm $file
	diff valid/$s.cor valid/test1.cor >> difference.txt
done

#rm useless files
rm  -r *.cor
rm $origin $asm 2> /dev/null || true
echo "\nThanks for using that script, good luck ;)"
