# mysql 相关命令

## linux安装mysql

## linux连接mysql

## 查看本机mysql有哪些数据库

## 新建 test 数据库

## 使用 test 数据库

## 查看 test 数据库中有哪些数据表

## 导入 ./test.sql 文件（tag数据库，及其内容）

## 查看 tag 表的数据结构

## 查看 tag 表 总共的记录数

## 查看 用户 user_id=653022934034081923 的标签有哪些

## 查看拥有标签tag='同学' 的用户有哪些

## 查看 `2017-12-01` 前创建的标签


## 在test库中，新建一张表，表结构如下：

```sql

CREATE TABLE `user_like` (
  `id` bigint(64) unsigned NOT NULL AUTO_INCREMENT,
  `user_id` varchar(36) NOT NULL DEFAULT ' ' COMMENT '用户id',
  `user_like` smallint(4) NOT NULL DEFAULT '0' COMMENT '喜欢:1喜欢,0取消喜欢',
  `record_id` bigint(20) NOT NULL COMMENT '标识来自记录id',
  `type` smallint(4) NOT NULL COMMENT '喜欢类型',
  `ext` varchar(256) NOT NULL DEFAULT ' ' COMMENT 'ext',
  `create_time` int(10) unsigned NOT NULL COMMENT '创建记录时间',
  `update_time` int(10) unsigned NOT NULL COMMENT '更新记录时间',
  PRIMARY KEY (`id`),
  UNIQUE KEY `idx_uniq_uid_reid` (`user_id`,`record_id`),
  KEY `idx_record_id` (`record_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='喜欢';   

```

## 向 user_like 表中插入一条记录

## 将 当前数据库 test 导出（表结构及其内容 - mysqldump）


## 新建数据库 friend

## 将上述导出的test数据库导入到 friend 库

## 删除test数据库的表 `user_like`

## 删除数据库test