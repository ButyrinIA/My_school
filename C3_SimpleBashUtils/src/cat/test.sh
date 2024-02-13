SUCCESS=0
FAIL=0
TOTAL=0

testing() 
{
    t=$(echo $i | sed "s/FLAG/$flag/")
    echo $t
    ./s21_cat $t > s21_cat.log
    cat $t > system_cat.log
    RES="$(diff -s s21_cat.log system_cat.log)"
    (( TOTAL++ ))
    if [ "$RES" == "Files s21_cat.log and system_cat.log are identical" ]
    then
      (( SUCCESS++ ))
      echo "Test $TOTAL: SUCCESS cat $t"
    else
      (( FAIL++ ))
      echo "Test $TOTAL: FAIL cat $t"
    fi
    rm s21_cat.log system_cat.log
}

declare -a tests=(
"FLAG s21_cat.c"
)


for flag_1 in b e n s t v
do
    for i in "${tests[@]}"
    do
        flag="-$flag_1"
        testing $i
    done

done

for flag_1 in b e n s t v
do
    for flag_2 in b e n s t v
    do
        if [ $flag_1 != $flag_2 ]
        then
            for i in "${tests[@]}"
            do
                flag="-$flag_1 -$flag_2"
                testing $i
            done
        fi
    done
done

for flag_1 in b e n s t v
do
    for flag_2 in b e n s t v
    do
      for flag_3 in b e n s t v
        do
            if [ $flag_1 != $flag_2 ] && [ $flag_2 != $flag_3 ] && [ $flag_1 != $flag_3 ]
            then
                for i in "${tests[@]}"
                do
                    flag="-$flag_1 -$flag_2 -$flag_3"
                    testing $i
                done
            fi
        done
    done
done



echo "TOTAL: $TOTAL | SUCCESS: $SUCCESS | FAIL: $FAIL" 