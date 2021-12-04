# CasselDB

> This time, wo creare a Databases!

## How to creare a databases?

1. save data
2. read data
3. find data
4. delete data
5. update data
6. that's all!

It's a file system!

## How to create a file?

Different language has different key to create files!

This time, I will using C Plus Plus to realition create file system!

```mermaid

graph TB

C11[CreateDB]
C12[CreateTB]


D11[DeleteDB]
D12[DeleteTB]

F11[FindData]

U11[UpdateData]
U12[UpdateDB]
U13[UpdateTB]

C[Create]


D[delete]
F[Find]
U[Update]

A[File]

C11 --> C
C12 --> C

D11 --> D
D12 --> D

F11 --> F

U11 --> U
U12 --> U
U13 --> U

C --> A
D --> A
F --> A
U --> A

```
