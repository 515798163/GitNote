#!/bin/bash

#:<<!

#大文件按行去重

#思路：

#统计文件总行数，计算将文件分为20行的话每个文件的行数row

#将大文件按每个文件row行进行切分，切分后的文件命名为 __part_sortFileName_00 , 依次类推，最后不足row行的文件单独占一个文件。也就是最后切分后的文件个数是 20 或 21 个。 -d 参数 macos 不支持，含义是文件结尾用数字命名而不是字母，即 00 01 而不是 xaa xab

#遍历子文件，对子文件进行排序。sort 仅仅是排序，不去重。

#merge排序后的子文件，merge的过程中去重。 -u 是 uniq 去重的意思， -m 是merge 的意思， -s 是保持按重复中的某个key排序。

#最后删除了多余的split后的文件及排序后的文件。


#!
mkdir xx
cp books.txt xx
cd xx
line=$(sed -n '$=' books.txt);
eachLine=$((line/20));
split -l $eachLine books.txt -d -a 2  __part_sortFileName_
for i in __part*
do
	sort $i > sort_$i
done

sort -smu sort_* > file_sorted
rm -f __part*
rm -f sort_*
