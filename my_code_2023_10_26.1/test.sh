while :
    do ps ajx | head -1 && ps ajx | grep a.out |grep -v grep
    echo '------------'
    sleep 1
done