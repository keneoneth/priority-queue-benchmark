# priority-queue-benchmark
Creating benchmark cases to quantify the performance of different implementations of priority queues

## Setup
- export BOOST_PATH={PATH_TO_BOOST_LIB}
- install pandas and pytest in Python
- GCC compiler

## Test Run
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

#### test_I_result.csv

|cand|type|id |size     |elapsed_time_us|elapsed_time_ms|elapsed_time_s       |
|----|----|---|---------|---------------|---------------|---------------------|
|A   |I   |i  |1000     |57             |0.057          |5.7e-05              |
|A   |I   |ii |10000    |2213           |2.213          |0.002213             |
|A   |I   |iii|100000   |8945           |8.945          |0.008945             |
|A   |I   |iv |1000000  |102020         |102.02         |0.10202              |
|A   |I   |v  |10000000 |1840619        |1840.619       |1.840619             |
|A   |I   |vi |100000000|28821900       |28821.9        |28.821900000000003   |
|B   |I   |i  |1000     |542            |0.542          |0.0005420000000000001|
|B   |I   |ii |10000    |2415           |2.415          |0.002415             |
|B   |I   |iii|100000   |36515          |36.515         |0.036515             |
|B   |I   |iv |1000000  |1246041        |1246.041       |1.246041             |
|B   |I   |v  |10000000 |27575036       |27575.036      |27.575036            |
|B   |I   |vi |100000000|569914777      |569914.777     |569.914777           |
|C   |I   |i  |1000     |311            |0.311          |0.000311             |
|C   |I   |ii |10000    |1784           |1.784          |0.001784             |
|C   |I   |iii|100000   |20957          |20.957         |0.020957             |
|C   |I   |iv |1000000  |873443         |873.443        |0.873443             |
|C   |I   |v  |10000000 |18223503       |18223.503      |18.223503            |
|C   |I   |vi |100000000|368076687      |368076.687     |368.076687           |
|D   |I   |i  |1000     |231            |0.231          |0.000231             |
|D   |I   |ii |10000    |2416           |2.416          |0.0024159999999999997|
|D   |I   |iii|100000   |33896          |33.896         |0.033896             |
|D   |I   |iv |1000000  |1355690        |1355.69        |1.35569              |
|D   |I   |v  |10000000 |29055886       |29055.886      |29.055885999999997   |
|D   |I   |vi |100000000|680102502      |680102.502     |680.102502           |


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
