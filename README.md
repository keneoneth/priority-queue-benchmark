# priority-queue-benchmark
Creating benchmark cases to quantify the performance of different implementations of priority queues

## setup
export BOOST_PATH={PATH_TO_BOOST_LIB}
install pandas and pytest in Python

## test run
```pytest testrun.py::test_single -s``` running single trial test
```pytest testrun.py::test_simple_I -s``` running simple cases in TEST I
```pytest testrun.py::test_simple_II -s``` running simple cases in TEST II
```pytest testrun.py::test_I -s``` slower, running all cases in TEST I
```pytest testrun.py::test_II -s``` slower, running all cases in TEST II
```pytest testrun.py::test_all -s``` slower, running all cases available

test result csv is generated to the results folder

## TEST Candidates
### A) std::priority_queue
### B) boost::pairing_heap
### C) pairing_heap_priqueue
### D) skiplist_priqueue

## TEST I: add random elements one by one
### TESTID:
#### i) 1k elements
#### ii) 10k elements
#### iii) 100k elements
#### iv) 1M elements
#### v) 10M elements
#### vi) 100M elements


## TEST II: find the shortest path in graph
### TESTID:
#### i) 1k elements
#### ii) 10k elements
#### iii) 100k elements
#### iv) 1M elements
#### v) 10M elements
#### vi) 100M elements

## TEST Results
### hardware: 16 x 11th Gen Intel(R) Core(TM) i7-11700F @ 2.50GHz CPU Cores

#### test_simple_I_result.csv

|cand|type|id |size   |elapsed_time_us|elapsed_time_ms|
|----|----|---|-------|---------------|---------------|
|A   |I   |i  |1000   |177            |0.177          |
|A   |I   |ii |10000  |2236           |2.236          |
|A   |I   |iii|100000 |20647          |20.647         |
|A   |I   |iv |1000000|128734         |128.734        |
|B   |I   |i  |1000   |178            |0.178          |
|B   |I   |ii |10000  |2640           |2.64           |
|B   |I   |iii|100000 |34240          |34.24          |
|B   |I   |iv |1000000|1165609        |1165.609       |
|C   |I   |i  |1000   |84             |0.084          |
|C   |I   |ii |10000  |2752           |2.752          |
|C   |I   |iii|100000 |22767          |22.767         |
|C   |I   |iv |1000000|719029         |719.029        |
|D   |I   |i  |1000   |174            |0.174          |
|D   |I   |ii |10000  |6636           |6.636          |
|D   |I   |iii|100000 |48999          |48.999         |
|D   |I   |iv |1000000|1336234        |1336.234       |

#### test_simple_II_result.csv

|cand|type|id |size   |elapsed_time_us|elapsed_time_ms|
|----|----|---|-------|---------------|---------------|
|A   |II  |i  |1000   |1910           |1.91           |
|A   |II  |ii |10000  |21657          |21.657         |
|A   |II  |iii|100000 |587565         |587.565        |
|B   |II  |i  |1000   |5045           |5.045          |
|B   |II  |ii |10000  |23726          |23.726         |
|B   |II  |iii|100000 |704064         |704.064        |
|C   |II  |i  |1000   |1500           |1.5            |
|C   |II  |ii |10000  |23736          |23.736         |
|C   |II  |iii|100000 |630090         |630.09         |
|D   |II  |i  |1000   |5127           |5.127          |
|D   |II  |ii |10000  |25901          |25.901         |
|D   |II  |iii|100000 |768271         |768.271        |
