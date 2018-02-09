# awk

1. 对 ./testData1/log 文件使用 awk 处理，输出 & 前的一列内容。

awk -F '&' '{print $1}' logs

2. 对 ./testData1/userInfos 文件使用 awk 命令处理，输出第一列和第三列。（列之间空格分割）
awk '{print $1" "$3}' userInfos
    * 期望输出示例：
    
    ```
    Beth 0
    Dan 0
    kathy 10
    Mark 20
    Mary 22
    Susie 18
    ```
    
    
    
3. 对./testData1/userInfos 文件使用 awk 命令处理，输出第一列和第2列+第3列+第4列的和。（列之间空格分割）
awk 'BEGIN {count=0} {count=$2+$3+$4} {print $1" "count}' userInfos
    * 期望输出示例：

    ```
    Beth 24
    Dan 33.75
    kathy 54
    Mark 75
    Mary 87.5
    Susie 52.25
    ```
