#!/bin/sh  
exe="gamesever"
des="/home/cking/gamesever/bin/lib"
deplist=$(ldd $exe | awk  '{if (match($3,"/")){ printf("%s "),$3 } }')  
cp $deplist $des
