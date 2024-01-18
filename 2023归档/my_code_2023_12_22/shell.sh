name=a.out
i=1
id=$(pidof $name)
while [ $i -le 31 ]
do 
    if [ $i -eq 9 ];then
        let i++
        continue
    fi
    if [ $i -eq 19 ];then
        let i++
        continue
    fi

    kill -$i $id
    echo "send signal $i:kill -$i $id"
    let i++
    sleep 1
done