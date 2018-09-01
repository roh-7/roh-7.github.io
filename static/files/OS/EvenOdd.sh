echo "Enter the number :"
read num
rem=`expr $num % 2`
if [ $rem == 0 ]
 then 
  echo "$num is an even number."
else
  echo "$num is a odd number."
fi


# Output :
# anushka@anushka-HP-Pavilion-Notebook:~$ gedit EvenOdd.sh
# anushka@anushka-HP-Pavilion-Notebook:~$ chmod 777 EvenOdd.sh
# anushka@anushka-HP-Pavilion-Notebook:~$ ./EvenOdd.sh
# Enter the number :
# 5
# 5 is a odd number.

