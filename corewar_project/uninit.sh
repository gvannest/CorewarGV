#!bin/zsh

root=`pwd`

echo "Desinisialisation des liens..."

rm -f $root/asm_dir/libs/libft.a
rm -f $root/vm/libs/libft.a
rm -rf $root/asm_dir/libs
rm -rf $root/vm/libs
rm -rf $root/libs

echo "Désinitialisation effectuee..."
