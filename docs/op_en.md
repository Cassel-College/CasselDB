# 操作手册

## 数据库操作


| Operation | Command |
| --------- | ------- |
| Query databases | `cassel databases` |
| Create database | `cassel create database database_name` |
| Enter database | `cassel open database_name` |
| Delete database | `cassel delete database_name` |
| Get database information | `cassel database_info_of database_name` |

## 数据表操作


| Operation                 | Command                                     |
| ------------------------- | ------------------------------------------- |
| View current database     | `cassel now_database`                       |
| View all data tables      | `cassel tables`                             |
| Create data table         | `cassel create_table table_name`            |
| Show data table structure | `cassel show_table_struct table_name`       |
| Show data table           | `cassel show_table table_name`              |
| Copy data table           | `cassel cp_table table_name new_table_name` |