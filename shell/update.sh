#:<<!

#假设用户目录下有多个 git 仓库，写脚本实现同时更新在当前目录下的所有git仓库#代码。
#要求脚本需要接收一个参数 branch ， 当不传 branch 时，仅更新代码；当传 #branch 时，需要切换当分支 branch ，然后再更新代码。

#!
#! /bin/bash
for i in $(ls)
	do
		if [ -d $i ]
		then
			cd $i
			read a
			if [ -n $a ]
				then
					git pull
					cd ..
				else
					git checkout $a
				fi
		fi
		done
