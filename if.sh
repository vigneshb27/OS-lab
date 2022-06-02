read -p "Enter the mark : " marks

if [ $marks -gt 80 ];
then
	echo "A"
	if [ $marks -gt 90 ];
	then
		echo "Mass da nee"
	fi
elif [ $marks -gt 60 ];
then
	echo "B"
else
	echo "C"
fi