read -p "Enter the value of a : " a
read -p "Enter the value of b : " b
c=$(( a + b ))
echo $c
echo
(( a += 5 ))
echo $a