SUCCESS=0
FAIL=0
TOTAL=0

testing() 
{
    t=$(echo $i | sed "s/FLAG/$flag/")
    echo $t
    ./s21_grep $t > s21_grep.log
    grep $t > system_grep.log
    RES="$(diff -s s21_grep.log system_grep.log)"
    (( TOTAL++ ))
    if [ "$RES" == "Files s21_grep.log and system_grep.log are identical" ]
    then
      (( SUCCESS++ ))
      echo "Test $TOTAL: SUCCESS grep $t"
    else
      (( FAIL++ ))
      echo "Test $TOTAL: FAIL grep $t"
    fi
    rm s21_grep.log system_grep.log
}

declare -a tests=(
"FLAG for s21_grep.c"
"FLAG -e while -e for s21_grep.c"
"FLAG -f patterns s21_grep.c"
)

for flag_1 in i v c l n h s o
do
    for i in "${tests[@]}"
    do
        flag="-$flag_1"
        testing $i
    done

done

for flag_1 in i v c l n h s o
do
    for flag_2 in i v c l n h s o
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

for flag_1 in i v c l n h s o
do
    for flag_2 in i v c l n h s o
    do
      for flag_3 in i v c l n h s o
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
