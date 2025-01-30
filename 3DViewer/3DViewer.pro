macx {  
    QT       += core gui openglwidgets
    LIBS     += -framework GLUT -framework OpenGL -framework Cocoa
} else {
    QT       += core gui opengl
    LIBS     += -lOpenGL -lGLU
}

include(3rdparty/src/gifimage/qtgifimage.pri)
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    command/moveCommand.cc \
    command/rotateCommand.cc \
    command/scaleCommand.cc \
    controller/controller.cc \
    model/model.cc \
    parallel_projection.cc \
    parser/parser.cc \
    perspective_projection.cc \
    render_shape.cc \
    shader_settings.cc \
    transformations/transformations.cc \
    circle_vertex.cc \
    dashed_render_strategy.cc \
    main.cpp \
    solid_render_strategy.cc\
    square_vertex.cc \
    render_config.cc\
    widget.cpp \
    mainwindow.cpp
HEADERS += \
    command/command.h \
    command/moveCommand.h \
    command/rotateCommand.h \
    command/scaleCommand.h \
    controller/controller.h \
    model/model.h \
    parallel_projection.h \
    parser/parser.h \
    perspective_projection.h \
    render_shape.h \
    shader_settings.h \
    transformations/transformations.h \
    circle_vertex.h \
    dashed_render_strategy.h \
    render_config.h\
    render_strategy.h \
    solid_render_strategy.h \
    square_vertex.h \
    vertex_strategy.h \
    widget.h \
    projection_matrix_strategy.h\
    mainwindow.h

FORMS += mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
