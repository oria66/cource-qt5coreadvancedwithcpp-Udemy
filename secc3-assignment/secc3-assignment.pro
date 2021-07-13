QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../LibraryForSecc3/release/ -lLibraryForSecc3
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../LibraryForSecc3/debug/ -lLibraryForSecc3

INCLUDEPATH += $$PWD/../LibraryForSecc3
DEPENDPATH += $$PWD/../LibraryForSecc3

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../LibraryForSecc3/release/libLibraryForSecc3.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../LibraryForSecc3/debug/libLibraryForSecc3.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../LibraryForSecc3/release/LibraryForSecc3.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../LibraryForSecc3/debug/LibraryForSecc3.lib
