message(${CMAKE_CURRENT_BINARY_DIR})

qt5_add_dbus_adaptor(QDBUS_SRCS ../qdbus/com.scorpio.test.xml test.h test valueAdaptor)

include_directories(.
    ../qdbus
    ${CMAKE_CURRENT_BINARY_DIR})

aux_source_directory(. qdbus_adaptor_src)

aux_source_directory(${CMAKE_CURRENT_BINARY_DIR} qdbus_adaptor_src)
aux_source_directory(../qdbus qdbus_adaptor_src)

foreach(_var ${qdbus_adaptor_src})
	message("当前变量是：${_var}")
endforeach()

add_executable(adaptor ${qdbus_adaptor_src} ${QDBUS_SRCS})

target_link_librarieS(adaptor Qt5::DBus) 