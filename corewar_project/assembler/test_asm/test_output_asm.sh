#!/bin/bash
clear && printf '\e[3J'
make -C ../
rm asm
cp ../asm .
#Creation des fichiers de travail
output="difference.txt"
path="valid/"
origin="origin.txt"
asm1="asm.txt"

list_file=`find valid/ -type f -name "*.s"`
rm $output 2> /dev/null || true
echo "\033[0;35mChecking unvalid champs\n\033[0m"
for file in $list_file
do
	rm $origin $asm1 2> /dev/null || true
	str=$((basename $file) | awk '{print toupper($0)}')
	./original_asm $file >> $origin
	s=$file
	s=${s##*/}
	s=${s%.*}
	t="test1"
	mv $path$s.cor $path$t.cor 2> /dev/null || true
	./asm $file >> $asm1
	#Retrieve first line of each output and stock it into var
	s1=$(head -1 $origin)
	s2=$(head -1 $asm1)
	if [ "$s1" == "$s2" ]; then
		echo "$str\033[1;32m OK\033[0m\n" >> $output
	else
		echo "\033[1;32m$str:\033[0m\033[1;31m ERROR\n$(head -1 $file)\n\033[1;34mExpected oupout:\033[0m" >> $output
		echo "$s1" >> $output
		echo "\033[1;34mYour output:\033[0m" >> $output
		echo "$s2" >> $output
		echo "" >> $output
	fi
	diff $path$s.cor $path$t.cor >> $output 2> /dev/null || true
done
rm  -r $path*.cor $origin $asm1
echo "\nThanks for using that script, good luck ;)"
