
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(LLVM_LINK_COMPONENTS Support)

add_llvm_executable(expressions
  expr.h
  expr.cpp
  ../lexer.cc # Required due to a dependency on 'lang::kindToString'.
  analysis.h
  transformation.h
  expression_parser.h
  ranges.h    # Header file not required.
  ranges.cpp  # Source file not required.
  expressions.cc)

target_compile_options(expressions PRIVATE -fno-exceptions -fno-rtti)

target_include_directories(expressions PRIVATE
   ${CMAKE_CURRENT_SOURCE_DIR}/../../../..
   "${CMAKE_SOURCE_DIR}/llvm-project/llvm/include"
   "${CMAKE_BINARY_DIR}/llvm-project/llvm/include")

install(TARGETS expressions RUNTIME DESTINATION bin)
