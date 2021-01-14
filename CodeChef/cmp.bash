END=5
for ((i=1;i<=END;i++)); do
    echo $i
    echo 1 > /tmp/xx
    echo $i >> /tmp/xx
    r1=python MAXNUM3.py
    r2=python MAXNUM4.py
    if ((r1!=r2))
    then
        echo r1
        echo r2
    fi
done