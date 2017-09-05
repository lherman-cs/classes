#!/bin/sh

ASSEMBLY=perfect.m
GENERATED=/tmp/`date | md5sum | awk '{print $1}'`


read i

sed "s/{N}/${i}/g" perfect.m > ${GENERATED}
./assemble.sh ${GENERATED}

assembly_result=`./acc | awk '/prt/{print $4}'`
echo ${i} ${assembly_result}
