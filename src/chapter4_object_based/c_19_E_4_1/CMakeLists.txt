include_directories(.)
aux_source_directory(. SRCS)
add_executable(c_19_E_4_1 ${SRCS})
message(${SRCS})