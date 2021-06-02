# Write a program to check whether a given year is yr year or not.

echo "enter the year: "
read yr

if [ `expr $yr % 400` -eq 0 ]
then
echo leap year
elif [ `expr $yr % 100` -eq 0 ]
then
echo not a leap year
elif [ `expr $yr % 4` -eq 0 ]
then
echo leap year
else
echo not a leap year
fi