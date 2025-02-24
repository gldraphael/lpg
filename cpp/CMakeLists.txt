cmake_minimum_required(VERSION 3.30)
project(lpg VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)


add_library(lpg-lib

        src/dto/MessageDto.hpp
        src/dto/StatusDto.hpp

        src/controller/StaticController.hpp
        src/controller/HelloApiController.hpp

        src/AppComponent.hpp
        src/SwaggerComponent.hpp
        src/ErrorHandler.cpp
        src/ErrorHandler.hpp
)


find_package(oatpp          1.3.0 REQUIRED)
find_package(oatpp-swagger  1.3.0 REQUIRED)

target_link_libraries(lpg-lib
        PUBLIC oatpp::oatpp
        PUBLIC oatpp::oatpp-swagger
)

add_definitions(
    ## define path to swagger-ui static resources folder
    -DOATPP_SWAGGER_RES_PATH="${oatpp-swagger_INCLUDE_DIRS}/../bin/oatpp-swagger/res"
)

if(CMAKE_SYSTEM_NAME MATCHES Linux)
    find_package(Threads REQUIRED)
    target_link_libraries(lpg-lib INTERFACE Threads::Threads ${CMAKE_DL_LIBS})
endif()


# Add executable
add_executable(lpg 
    src/App.cpp
)

target_link_libraries(lpg 
    lpg-lib
)
