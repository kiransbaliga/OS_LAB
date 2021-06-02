# Write a program to find the factorial of a number using functions.
echo "Enter the number: "
read num                     

f=1                    

for((i=2;i<=num;i++))
{
  f=$((f * i)) 
}

echo $f