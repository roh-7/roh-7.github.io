# 115A1018
# sum of digits
echo "Enter a number"
read number

sd=0
sum=0

while [ $number -gt 0 ]
do
	sd=$(( $number % 10 ))
	number=$(( $number / 10 ))
	sum=$(( $sum + $sd ))
done
echo "sum is $sum"
