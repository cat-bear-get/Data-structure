# Set the project name
project (LinkList)

# Add a library with the above sources
aux_source_directory(./src SOURCES_CPP)

add_library(${PROJECT_NAME} STATIC ${SOURCES_CPP})

add_library(LinkListLib ALIAS ${PROJECT_NAME})

target_include_directories( ${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/inc
)
