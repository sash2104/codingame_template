#!/bin/bash

if [[ $# -lt 1 ]] || [[ $# -gt 1 ]]; then
    echo "usage: $0 input_file"
    exit 1
fi

input_file=$1
date_str=`date '+%m%d.%H%M.%S'`
output_dir="submit"
output_file=${output_dir}"/"${date_str}".cpp"
echo $output_file
python merge_codes_cpp.py -i $input_file -o $output_file
cat $output_file | pbcopy
