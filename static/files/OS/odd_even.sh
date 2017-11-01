# 115A1018
# odd even
echo "enter a number"
read a
if [ `expr $a % 2` -eq 0 ]
then
echo "$a is even"
else
echo "$a is odd"
fi
