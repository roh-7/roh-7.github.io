echo "Enter the number :"
read number
num=$number
sum=0
while (( $num >0 ))
 do
  x=`expr $num % 10`
  sum=`expr $sum + $x`
  num=`expr $num / 10`
 done
echo "Sum of digits of $number is $sum"

# Output:
# anushka@anushka-HP-Pavilion-Notebook:~$ gedit Digit.sh
# anushka@anushka-HP-Pavilion-Notebook:~$ ./Digit.sh
# Enter the number :
# 214
# Sum of digits of 214 is 7

