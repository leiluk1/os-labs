mkdir -p ../week01
echo "Leila" > ../week01/file.txt
mkdir -p ../week10
link ../week01/file.txt ../week10/_ex2.txt
find .. -inum $(stat -c %i ../week01/file.txt) > ../week10/ex2.txt
find .. -inum $(stat -c %i ../week01/file.txt) -exec rm {} \;

