# reids 常用命令

## linux 安装redis
apt-get update
apt-get install redis-server

## 连接redis命令
redis-server
redis-cli
ping
## 在redis中设置 key = test_key 的值为 10
set test_key 10

## 查看redis中key = test_key 的值是多少
get test_key

## 设置 key = test_key 的 有效期为 600s
expire test_key 600
成功返回1
## 查看 key = test_key 的有效期
ttl test_key
返回剩余时间（秒）
## 在redis中删除 key = test_key 
del test_key
删除后再查看有效期，返回-2
