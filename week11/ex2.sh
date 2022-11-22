cd lofsdisk
sudo touch file1 file2
sudo sh -c 'echo "Leila" > file1'
sudo sh -c 'echo "Khaertdinova" > file2'

sudo mkdir -p ./lib/x86_64-linux-gnu/ ./lib64 ./usr/bin
sudo cp /usr/bin/bash ./usr/bin/bash
sudo cp /usr/bin/cat ./usr/bin/cat
sudo cp /usr/bin/echo ./usr/bin/echo
sudo cp /usr/bin/ls ./usr/bin/ls
sudo cp /lib/x86_64-linux-gnu/libtinfo.so.6 ./lib/x86_64-linux-gnu/libtinfo.so.6
sudo cp /lib/x86_64-linux-gnu/libdl.so.2 ./lib/x86_64-linux-gnu/libdl.so.2
sudo cp /lib/x86_64-linux-gnu/libc.so.6 ./lib/x86_64-linux-gnu/libc.so.6
sudo cp /lib64/ld-linux-x86-64.so.2 ./lib64/ld-linux-x86-64.so.2
sudo cp /lib/x86_64-linux-gnu/libselinux.so.1 ./lib/x86_64-linux-gnu/libselinux.so.1
sudo cp /lib/x86_64-linux-gnu/libpcre2-8.so.0 ./lib/x86_64-linux-gnu/libpcre2-8.so.0
sudo cp /lib/x86_64-linux-gnu/libpthread.so.0 ./lib/x86_64-linux-gnu/libpthread.so.0

cd ..
sudo gcc -Wall -static -o lofsdisk/ex2.out ex2.c
echo "Files in /" > ex2.txt
sudo chroot lofsdisk ./ex2.out >> ex2.txt
echo "Files in ./lofsdisk" >> ex2.txt
./lofsdisk/ex2.out >> ex2.txt
