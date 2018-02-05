# 查找相关命令

## find

```
# 在当前目录下查找文件名前缀为 shell 的所有文件
find . -name "shell*"i
# 在当前目录下查找文件名为 names 的文件的详细路径
#! /bin/bash
path=$(pwd)
find $path -name "names"

```

## grep

```
# 在当前目录下查找字符串 653022934034081923  出现的所有文件
#! /bin/bash
a=$(ls);
grep "653022934034081923" $a


# 查找文件 ./testData1/userID 中是否含有字符串 653022934034081923 
#! /bin/bash
a=$(grep "653022934034081923" userID)
if [ -n $a ]
        then
			echo "Found!"
		lse
			echo "Not found!"
fi


# 在文件 ./testData1/userID 文件中查找字符串 653022934034081923  出现的行数
#! /bin/bash
grep -c "653022934034081923" userID


# 在当前路径下查找不包含字符串 653022934034081923 的所有文件
cd testData1
for i in $(ls)
	do
		a=$(grep "653022934034081923" $i)
		if [ -z  $a ]
			then
				echo $i
		fi
	done

# 查找文件  ./testData1/userID 中字符串 653022934034081923 及其上下 5 行内容
grep "653022934034081923" -C 5 userID

```
