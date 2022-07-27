QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

#LIBS += -L$$PWD/Lua535 -llua53 # MotherFucking line don't forget that
LIBS += -L$$PWD/Lua514 -llua5.1 # MotherFucking line don't forget that

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        Bitch.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Lua514/lua5.1.dll \
    Lua514/lua5.1.lib \
    Lua535/liblua53.a \
    Lua535/lua53.dll

HEADERS += \
    Bitch.h \
    Functions.h \
    L_Functions.h \
    Lua514/include/lauxlib.h \
    Lua514/include/lua.h \
    Lua514/include/lua.hpp \
    Lua514/include/luaconf.h \
    Lua514/include/lualib.h \
    Lua535/include/lauxlib.h \
    Lua535/include/lua.h \
    Lua535/include/lua.hpp \
    Lua535/include/luaconf.h \
    Lua535/include/lualib.h
