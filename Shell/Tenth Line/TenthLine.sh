# Possible solution 1 
sed '10!d' file.txt

# Possible solution 2
tail -n+10 file.txt | head -1
