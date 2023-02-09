# Лабораторная работа по теме Лексер

Лексические единицы

| Название                 | Регулярное выражение     | Код лексемы |
|--------------------------|--------------------------|-------------|
| Комментарий              | `#.*$`                   | *N\A*       |
| Идентификатор            | `\w[\w&#124;\d]*`        | ID          |
| Число(бинарное)          | `0b[0&#124;1]+`          | INT         |
| Число(десятичное)        | `\d+`                    | INT         |
| Число(восьмиричное)      | `0o[0-7]+`               | INT         |
| Число(шестнадцатиричное) | `0h[0-9&#124;a-h]+`      | INT         |
| Вещественное число       | `\d+.\d`                 | FLOAT       |
| Разделитель              | `,`,`;`                  | SEPARATOR   |
| Присвоение               | `=`                      | ASSIGN      |
| Строка                   | `'.*'`                   | STRING      |
| Тип данных               | `int`, `float`, `string` | TYPE        |
| Арифметический оператор  | `+`, `-`, `*`, `/`       | ARITH_OP    |
| Скобки                   | `(.*)`                   | BRACKET     |
| Операторы чтения/записи  | `READ`, `WRITE`          | IO_OP       |
