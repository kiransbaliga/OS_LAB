function floyd_triangle(){
# echo "Enter a number"
# read num
num=4
n=1
echo "floyd triangle"
for((i=1;i<=num;i++))
{
  for((j=1;j<=$i;j++)){
      echo -n "$n "
      n=$((n+1))
  }
  echo ""
}
}
floyd_triangle