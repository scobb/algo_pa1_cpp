INPUT='\.in$'
OUTPUT='([0-9]+)\.out$'
IN_DIRS=(small med large)
for dir in ${IN_DIRS[@]}; do
    echo DIR: $dir
    for file in $(ls $dir); do
        if $(echo $file|egrep -q $INPUT); then
            ./Algo_PA1 $dir/$file
        fi
    done
    for file in $(ls $dir); do
        if [[ $file =~ $OUTPUT ]]; then
            key_file="${dir}_sol/$file"
            if [[ $(diff ${dir}/$file $key_file) != "" ]]; then
                echo FAIL: $file: $(diff $dir/$file $key_file)
            fi
        fi
    done
done
