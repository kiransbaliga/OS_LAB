# Write   programs to implement
# I.   test Command
# II.  shift Command
# III.  until Command

echo "#test command"
test 1 -gt 2 && echo "true." || echo "false."
echo
echo "#shift command"
echo $*
shift
echo $*
echo
echo "#until command"
echo
i=0
until((i>5))
do
echo $i
((i++))
done
