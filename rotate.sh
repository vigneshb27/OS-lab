file='items.txt'
ref='reff.txt'
new='neww.txt'
head -n 5 $file > $ref
tac $ref > $new
i=1
while read line;
do
	if [ $i -gt 5 ]
	then
		echo "$line" >> $new
	fi
	(( i++ ))
done < $file
