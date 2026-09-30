#
# Версия CMake
cmake_minimum_required(VERSION 3.15)  

# Плата и микроконтроллер
set(PICO_BOARD pico) 
set(PICO_PLATFORM rp2040)

# Подключение SDK
include(pico_sdk_import.cmake)

project(121_blink_reg) # создается переменна ${PROJECT_NAME}

pico_sdk_init()

# Из чего собирать
add_executable(${PROJECT_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/main.c
)

# С какими библиотеками
target_link_libraries(${PROJECT_NAME}
    pico_stdlib
)

# По каким правилам размещать
pico_set_linker_script(${PROJECT_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/memmap_rp2040.ld
)

# В каких форматах выдать результат
pico_add_extra_outputs(${PROJECT_NAME})




