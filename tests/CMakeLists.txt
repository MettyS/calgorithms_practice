
add_executable(linkedlisttests linkedlisttest.c)
target_link_libraries(linkedlisttests utils)

add_executable(binarytreetests binarytreetest.c)
target_link_libraries(binarytreetests utils)

add_executable(adjacencymatrixtests adjacencymatrixtest.c)
target_link_libraries(adjacencymatrixtests utils)

add_executable(binaryheaptests binaryheaptest.c)
target_link_libraries(binaryheaptests utils)

add_test(NAME binarytreetests COMMAND binarytreetests)
add_test(NAME linkedlisttests COMMAND linkedlisttests)
add_test(NAME adjacencymatrixtests COMMAND adjacencymatrixtests)
add_test(NAME binaryheaptests COMMAND binaryheaptests)
