# 操作手册

## 数据库操作

| 操作 | 命令 |
| ---- | ---- |
| 查询数据库 | `cassel databases` |
| 创建数据库 | `cassel create database database_name` |
| 进入数据库 | `cassel open database_name` |
| 删除数据库 | `cassel delete database_name` |
| 获取数据库信息 | `cassel database_info_of database_name` |

## 数据表操作

| 操作           | 命令                                        |
| -------------- | ------------------------------------------- |
| 查看当前数据库 | `cassel now_database`                       |
| 查看所有数据表 | `cassel tables`                             |
| 创建数据表     | `cassel create_table table_name`            |
| 显示数据表结构 | `cassel show_table_struct table_name`       |
| 显示数据表     | `cassel show_table table_name`              |
| 复制数据表     | `cassel cp_table table_name new_table_name` |
