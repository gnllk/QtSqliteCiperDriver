QT += sql

TEMPLATE = lib
CONFIG += c++11 plugin

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Include QT private classes
INCLUDEPATH += \
    $$[QT_INSTALL_HEADERS]/QtCore/$$[QT_VERSION]/QtCore \
    $$[QT_INSTALL_HEADERS]/QtSql/$$[QT_VERSION]/QtSql \
    $$[QT_INSTALL_HEADERS]/QtCore/$$[QT_VERSION] \
    $$[QT_INSTALL_HEADERS]/QtSql/$$[QT_VERSION]

# SQLITE_DQS                    Setting for the double-quoted string literal misfeature (default: disabled)
# SQLITE_ENABLE_CARRAY          C array extension
# SQLITE_ENABLE_COLUMN_METADATA	Access to meta-data about tables and queries
# SQLITE_ENABLE_CSV             CSV extension
# SQLITE_ENABLE_DEBUG           Enable additional debug features (default: off)
# SQLITE_ENABLE_DESERIALIZE	Option to enable the serialization interface
# SQLITE_ENABLE_EXPLAIN_COMMENTS	Enable additional comments in EXPLAIN output
# SQLITE_ENABLE_FTS3            Version 3 of the full-text search engine
# SQLITE_ENABLE_FTS3_PARENTHESIS	Additional operators for query pattern parser
# SQLITE_ENABLE_FTS4            Version 4 of the full-text search engine
# SQLITE_ENABLE_FTS5            Version 5 of the full-text search engine
# SQLITE_ENABLE_GEOPOLY         Geopoly extension
# SQLITE_ENABLE_JSON1           JSON SQL functions
# SQLITE_ENABLE_REGEXP          Regular expression extension
# SQLITE_ENABLE_RTREE           R*Tree index extension
# SQLITE_ENABLE_EXTFUNC         Extension with mathematical and string functions
# SQLITE_ENABLE_FILEIO          Extension with file I/O SQL functions
# SQLITE_ENABLE_SERIES          Series extension
# SQLITE_ENABLE_SHA3            SHA3 extension
# SQLITE_ENABLE_UUID            Extension for handling handling RFC-4122 UUIDs
# SQLITE_MAX_ATTACHED=10	Maximum Number Of Attached Databases (max. 125)
# SQLITE_SECURE_DELETE          Overwrite deleted content with zeros
# SQLITE_SOUNDEX                Enable soundex SQL function
# SQLITE_THREADSAFE             Setting the multithreading mode (default: serialized)
# SQLITE_USE_URI                Enable URI file names
# SQLITE_USER_AUTHENTICATION	User authentication extension

# set CODEC_TYPE to below value to select a cipher, read more https://github.com/utelle/wxsqlite3
# define CODEC_TYPE_UNKNOWN   0
# define CODEC_TYPE_AES128    1
# define CODEC_TYPE_AES256    2
# define CODEC_TYPE_CHACHA20  3
# define CODEC_TYPE_SQLCIPHER 4
# define CODEC_TYPE_RC4       5
# define CODEC_TYPE_MAX       5
DEFINES += \
    SQLITE_ENABLE_COLUMN_METADATA \
    SQLITE_SOUNDEX \
    SQLITE_SECURE_DELETE \
    SQLITE_ENABLE_JSON1 \
    SQLITE_ENABLE_REGEXP \
    SQLITE_ENABLE_EXTFUNC \
    SQLITE_ENABLE_FTS5 \
    CODEC_TYPE=CODEC_TYPE_AES256

# compile under Qt 5.12.12(windows)
win32{
    Debug:TARGET = SQLITEEXD
    Release:TARGET = SQLITEEX
    DEFINES += DISABLE_AES_HARDWARE OS_WIN
    SOURCES += qsql_sqliteex.cpp
    HEADERS += qsql_sqliteex_p.h
}
# compile under Qt 5.6.0(linux)
unix{
    TARGET = SQLITEEX
    SOURCES += qsql_sqliteex_qt5.6.0.cpp
    HEADERS += qsql_sqliteex_p_qt5.6.0.h
}

SOURCES += \
    mysqlitecipherplugin.cpp \
    sqlite3mc_amalgamation.c

HEADERS += \
    mysqlitecipherplugin.h \
    sqlite3mc_amalgamation.h

DISTFILES += MySqliteCipher.json

# Default rules for deployment.
unix {
    target.path = $$[QT_INSTALL_PLUGINS]/sqldrivers
}
!isEmpty(target.path): INSTALLS += target

# output
CONFIG(debug, debug|release){
    DESTDIR = $$PWD/../output/debug/sqldrivers
} else {
    DESTDIR = $$PWD/../output/release/sqldrivers
}


