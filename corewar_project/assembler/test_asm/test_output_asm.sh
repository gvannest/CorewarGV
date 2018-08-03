#!/bin/bash
clear && printf '\e[3J'
cp ../asm .
output="difference.txt"
path="valid/basic_test/"
list_file=`find $path -type f -name "*.s"`
rm $output 2> /dev/null || true
echo "\033[0;35mChecking unvalid champs\n\033[0m"
for file in $list_file
do
	str=$((basename $file) | awk '{print toupper($0)}')
	echo "$str" >> $output
	#remove les anciens log
	#rm $origin $asm 2> /dev/null || true

	./original_asm $file >> $output
	s=$file
	s=${s##*/}
	s=${s%.*}
	t="test1"
	mv $path$s.cor $path$t.cor
	./asm $file >> $output
	echo "DIFF COREWAR FILE" >> $output
	diff $path$s.cor $path$t.cor >> $output
done

#rm useless files
rm  -r $path*.cor
echo "\nThanks for using that script, good luck ;)"
