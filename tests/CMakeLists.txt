
add_executable(linkedlisttests linkedlisttest.c)
target_link_libraries(linkedlisttests utils)

add_executable(binarytreetests binarytreetest.c)
target_link_libraries(binarytreetests utils)

add_test(NAME binarytreetests COMMAND binarytreetests)
add_test(NAME linkedlisttests COMMAND linkedlisttests)
