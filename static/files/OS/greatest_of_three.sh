# 115A1018
# greatest of three numbers
echo "Enter three numbers"
read first
read second
read third
if [ $first -gt $second ] ; then
if [ $first -gt $third ] ; then
echo -e "$first is greatest"
else
echo -e "$third is greatest"
fi
else
if [ $second -gt $third ] ; then
echo -e "$second is greatest"
else
echo -e "$third is greatest"
fi
fi

