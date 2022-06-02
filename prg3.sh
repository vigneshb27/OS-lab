str="KakashiHatake"
len=${#str}
rough=""
for (( i=0; i<len; i++ ))
do
if [ $((i % 2)) == 0 ]
then
	echo $rough >> "ex$i.txt"
	rough=""
fi
a=${str:i:1}
rough=$rough$a
done
echo $rough >> "ex$i.txt"