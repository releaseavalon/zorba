
FILE(READ "${CMAKE_CURRENT_BINARY_DIR}/zorba_api.php" FILE_CONTENT)
STRING(REGEX REPLACE "php_zorba_api.dll" "zorba_api.dll" MODIFIED_FILE_CONTENT "${FILE_CONTENT}")
STRING(REGEX REPLACE "zorba_api.so" "libzorba_api.so" MODIFIED_FILE_CONTENT "${MODIFIED_FILE_CONTENT}")
STRING(REGEX REPLACE "'zorba_api.'" "'libzorba_api.'" MODIFIED_FILE_CONTENT "${MODIFIED_FILE_CONTENT}")
FILE(WRITE "${CMAKE_CURRENT_BINARY_DIR}/zorba_api.php" "${MODIFIED_FILE_CONTENT}")

CONFIGURE_FILE("${CMAKE_CURRENT_BINARY_DIR}/zorba_api.php" "${CMAKE_CURRENT_BINARY_DIR}/Zorba/zorba_api_wrapper.php" COPYONLY)