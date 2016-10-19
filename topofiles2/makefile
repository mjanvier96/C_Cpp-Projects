dfstest: graph.c graphio.c dfs.c dfstest.c
	clang -g -O0 -o dfstest graph.c graphio.c dfs.c dfstest.c

testdfstest: dfstest
	./dfstest

topocycle: graph.c graphio.c dfs.c topocycle.c topocycletest.c
	clang -g -O0 -o topocycle graph.c graphio.c dfs.c topocycle.c topocycletest.c

testtopocycle: topocycle
	 ./topocycletest

graphiotest: graph.c graphiotest.c
	clang -g -O0 -o graphiotest graphiotest.c graph.c graphio.c

testgraphio: graphiotest
	./graphiotest
