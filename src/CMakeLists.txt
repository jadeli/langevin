
# Compile everything except the main source file into a static lib to be linked
# to both the main executable and the tests.
add_library(${LIBRARY_NAME} STATIC
  random.cxx
  avatar.cxx
  particle.cxx
  sample.cxx
  nucleus.cxx
)
set_target_properties(${LIBRARY_NAME} PROPERTIES PREFIX "")

# Compile the actual executable.
set(MAIN ${PROJECT_NAME}.cxx)
set_source_files_properties(${MAIN} PROPERTIES
  COMPILE_DEFINITIONS "LANGEVIN_VERSION=\"${PROJECT_VERSION}\"")

message(STATUS "Version: ${PROJECT_VERSION}")
message(STATUS "Main: ${MAIN}")

add_executable(${PROJECT_NAME} ${MAIN})

#target_link_libraries(${PROJECT_NAME} ${LIBRARY_NAME} ${Boost_LIBRARIES} ${HDF5_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${LIBRARY_NAME} -lgsl -lgslcblas)

#install(TARGETS ${PROJECT_NAME} DESTINATION bin)