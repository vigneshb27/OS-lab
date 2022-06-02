while read line;
do
	for i in $line
	do
		echo $i
	done
done < lorem.txt

cd ../shell\ scripting/check
pwd
cat alpha_num.txt