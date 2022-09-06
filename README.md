## A Qt Sqlite driver wrapper for wxSQLite3

There are two versions of sqlite driver, one is for Qt5.12.12(Windows 10 MinGW), 
the other one is for Qt5.6.0(Linux ARM gcc-linaro-7.5.0-2019.12).
The default 

read more wxSQLite3: https://github.com/utelle/wxsqlite3

## Usage

Copy the "output/release/sqldrivers" folder to your exe folder first.

auto db = QSqlDatabase::addDatabase("QSQLITEEX", "qt_sql_default_connection");
db.setPassword("123456");
db.setDatabaseName("test.db");
db.open();

## License

**wxSQLite3** is free software: you can redistribute it and/or modify it
under the terms of the GNU Lesser General Public License version 3
or later as published by the Free Software Foundation,
with the wxWindows 3.1 exception.