no=1
col=0

while [ $col -lt 4 ]
do
    row=0
    while [ $row -lt `expr $col + 1` ]
    do   
        echo -n "$no "
        no=`expr $no + 1`
        row=`expr $row + 1`
    done
    echo ""
    col= `expr $col + 1`
done
