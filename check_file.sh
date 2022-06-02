read -p "Enter the file directory name : " dir
if [ -d $dir ]
then
	echo "The directory is present!"
else
	mkdir $dir
fi