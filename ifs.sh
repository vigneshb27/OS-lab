read -p "Enter your name, rollno, age separated by comma : " det
IFS=','
read -a arr <<< $det
for i in ${arr[@]}
do
	echo $i
done