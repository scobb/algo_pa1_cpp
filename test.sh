INPUT='\.in$'
OUTPUT='([0-9]+)\.out$'
for file in $(ls small); do
    if echo $file|egrep -q $INPUT; then
        ./Algo_PA1 small/$file
        echo $file
    fi
done
for file in $(ls small); do
    if [[ $file =~ $OUTPUT ]]; then
        key_file="small_sol/$file"
        echo $(diff small/$file $key_file)
    fi
done
