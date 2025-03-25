# Copyright (c) 2025 Ryan Jacoby
# SPDX-License-Identifier: Apache-2.0
#

list(APPEND BOARD_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/)

zephyr_syscall_include_directories(include)

zephyr_include_directories(include)

add_subdirectory(drivers)
