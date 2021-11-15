message(${CMAKE_CURRENT_BINARY_DIR})

qt5_generate_dbus_interface(
    ../qdbus/test.h
    ${CMAKE_CURRENT_BINARY_DIR}/com.scorpio.test.xml
)

qt5_add_dbus_adaptor(
    QDBUS_ADAPTOR_SRCS 
    ${CMAKE_CURRENT_BINARY_DIR}/com.scorpio.test.xml
    test.h
    test
    valueAdaptor
    
)

include_directories(../qdbus)

aux_source_directory(. QDBUS_ADAPTOR_SRCS)
aux_source_directory(../qdbus QDBUS_ADAPTOR_SRCS)

foreach(_var ${QDBUS_ADAPTOR_SRCS})
	message("当前变量是：${_var}")
endforeach()

add_executable(adaptor ${QDBUS_ADAPTOR_SRCS})

# target_include_directories(
#     adaptor
#     PRIVATE ../qdbus
# )

target_link_librarieS(adaptor Qt5::DBus) 