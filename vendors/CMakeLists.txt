file(
    GLOB
    VENDOR_FOLDERS
    ${CMAKE_CURRENT_SOURCE_DIR}/*
)

foreach(INSTANCE ${VENDOR_FOLDERS})
    if (IS_DIRECTORY ${INSTANCE}) 
        add_subdirectory(${INSTANCE})
    endif()
endforeach()
