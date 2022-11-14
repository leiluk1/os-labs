touch _ex3.txt
echo "Leila" > _ex3.txt
chmod a-x _ex3.txt
ls -l _ex3.txt > ex3.txt
chmod uo+rwx _ex3.txt
ls -l _ex3.txt >> ex3.txt
chmod g+rwx _ex3.txt
ls -l _ex3.txt >> ex3.txt
echo "660 in octal notation is -rw-rw----. It means that file can be read and written only for the owner and group." >> ex3.txt 
echo "775 is -rwxrwxr-x. It means that the owner and group are permitted to read, write, execute and others are allowed to read and execute." >> ex3.txt 
echo "775 is -rwxrwxr-x. It means that everyone are granted to read, write, execute." >> ex3.txt 
