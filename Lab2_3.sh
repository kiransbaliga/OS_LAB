#Write a program to sort a set of arr using for loop
arr=(10 -29 33 67 -6 7 -10)

for (( i=0 ; i < ${#arr[@]}; i++ )) 
do
    for (( j=0 ; j < ${#arr[@]}; j++ )) 
    do
      if [[ ${arr[$j]} -gt  ${arr[$i]} ]]
      then
        tmp=${arr[$i]}
        arr[$i]=${arr[$j]}
        arr[$j]=${tmp}
      fi
    done
done

for n in "${arr[@]}"
do
    echo "$n"
done