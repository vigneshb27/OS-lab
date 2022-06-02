file='lorem.txt'

content=`cat $file`

for i in $content
do
	len=${#i}
	a=0
	b=$(( len - 1))
	flag=1
	while [ $a -lt $b ]
	do
		if [ ${i:$a:1} != ${i:$b:1} ]
		then
			flag=0
			break
		fi
		(( a++ ))
		(( b-- ))
	done
	if [ $flag == 1 ] && [ ! -z "$i" ]
	then
		echo "$i " >> "ans.txt"
	fi
done