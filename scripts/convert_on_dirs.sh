#!/bin/bash
# FC convert files in dirs

for i in 3e1 3e2 3e3 3e4 3e5 3e6 3e7 3e8 3e9
do
    echo "Start dir $i"
    mkdir $i 
    cd $i
    /opt/eee/e3sim/app/e3corsika2root.py -s 100000 -e 100999 -i /home/MC/cur/orig/$i
    cd ..
    echo "end"
done

