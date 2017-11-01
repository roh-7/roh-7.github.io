# 115A1018
# factorial
echo "enter number"
read a
fact=1
while [ $a -gt 1 ]
do
	fact=`expr $fact \* $a`
	a=`expr $a - 1`
done
echo "$fact"

