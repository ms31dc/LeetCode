tr -d '[:punct:]' < words.txt | tr -s ' ' '\n' | sort | uniq -c | sort -nr | sed 's/ *\([0-9]*\) \(.*\)/\2 \1/'
