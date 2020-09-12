# echo -n "Enter name of student: "
# read name

echo -n "Enter no of subjects: "
read no

i=0
total=0
while [ $i -lt $no ]
do
    echo -n "Enter marks of $i th subject: "
    read a[$i]
    total=`expr $total + ${a[$i]}`
    i=`expr $i + 1`
done

aggregate=`expr $no \* 100`
percentage=`expr $total \* 100 / $aggregate`
echo $percentage