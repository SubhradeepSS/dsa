echo -n "Enter no: "
read n
ans=1
for((i=1;i<=n;i++))
do
    ans=$(($ans * $i))
done

echo "Factorial (iterative) of $n = $ans"

fact(){
    if (($1 <= 1)); then
        echo $1
    else    
        last=$(fact $(($1 - 1)))
        echo $(($last * $1))
    fi
}

echo -n "Factorial (recursive) of $n = "
fact $n