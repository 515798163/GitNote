# 查找相关命令

## sed

```
# 对 GitNote/shell/testData1/lineID 文件，每行行首增加 line_id_ （不改变元文件内容）
  
sed 's/^/line_id_&/g' lineID

# 对 GitNote/shell/testData1/lineID 文件，每行行尾增加 _line_id  （不改变元文件内容）
sed 's/$/&line_id_/g' lineID
 
# 对 GitNote/shell/testData1/lineID 文件，每行行尾增加 &abc   （注：特殊字符处理。不改变元文件内容）
sed 's/$/&\&abc/g' lineID

# 打印 GitNote/shell/testData1/lineID 文件 中含有 825809521443074059 的行
sed -n '/825809521443074059/ p' lineID
 
# 打印  GitNote/shell/testData1/lineID 文件中不含 825809521443074059 的行
  sed -n '/825809521443074059/ !p' lineID
 
# 对 GitNote/shell/testData1/userID 文件，去掉含有user_id的行
 sed -e '/user_id/d' userID
  
# 对 GitNote/shell/testData1/logs 文件，删除每行 & 及其后面的所有内容。ex ： 653022934034081923&xxx  期望得到 653022934034081923
sed 's/\(.*&\).*/\1/' logs

```


