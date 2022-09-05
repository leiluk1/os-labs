date
sleep 3
mkdir f1
date
sleep 3
mkdir f2
cd f1
date
sleep 3
touch root.txt
cd ..
cd f2
date
sleep 3
touch home.txt
ls -rt ~ > home.txt
cd ..
cd f1
ls -rt / > root.txt

