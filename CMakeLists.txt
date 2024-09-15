cmake_minimum_required(VERSION 3.16)

project(test_work LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(test_work main.cpp
    movingobject.h movingobject.cpp
    common.h
    player.h player.cpp
    bird.h bird.cpp
    gamemaster.h gamemaster.cpp
    bomber.h bomber.cpp
    bullet.h bullet.cpp
    fighter.h fighter.cpp
    bulletfactory.h bulletfactory.cpp)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(GLUT REQUIRED)
#include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

#target_link_libraries(test_work ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
target_link_libraries(test_work
    OpenGL::GL
    OpenGL::GLU
    GLUT::GLUT
    GLEW::GLEW
    )


include(GNUInstallDirs)
install(TARGETS test_work
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)


