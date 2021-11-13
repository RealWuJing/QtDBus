message(${CMAKE_CURRENT_BINARY_DIR})

qt5_add_dbus_interface(QDBUS_SRCS ../qdbus/com.scorpio.test.xml valueInterface)

include_directories(.
    ${CMAKE_CURRENT_BINARY_DIR})

aux_source_directory(. qdbus_proxy_src)

add_executable(proxy ${qdbus_proxy_src} ${QDBUS_SRCS})

target_link_librarieS(proxy Qt5::DBus) 