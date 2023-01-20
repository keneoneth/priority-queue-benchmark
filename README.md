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


#### test_II_result.csv

|cand|type|id |size     |elapsed_time_us|elapsed_time_ms|elapsed_time_s       |
|----|----|---|---------|---------------|---------------|---------------------|
|A   |II  |i  |1000     |2796           |2.796          |0.002796             |
|A   |II  |ii |10000    |26610          |26.61          |0.026609999999999998 |
|A   |II  |iii|100000   |671316         |671.316        |0.671316             |
|A   |II  |iv |1000000  |12028611       |12028.611      |12.028611000000001   |
|A   |II  |v  |10000000 |194705660      |194705.66      |194.70566            |
|B   |II  |i  |1000     |1661           |1.661          |0.001661             |
|B   |II  |ii |10000    |23183          |23.183         |0.023183             |
|B   |II  |iii|100000   |718671         |718.671        |0.7186710000000001   |
|B   |II  |iv |1000000  |13216956       |13216.956      |13.216956            |
|B   |II  |v  |10000000 |237320606      |237320.606     |237.320606           |
|C   |II  |i  |1000     |2899           |2.899          |0.002899             |
|C   |II  |ii |10000    |24506          |24.506         |0.024506             |
|C   |II  |iii|100000   |652191         |652.191        |0.6521910000000001   |
|C   |II  |iv |1000000  |13669629       |13669.629      |13.669629            |
|C   |II  |v  |10000000 |223100297      |223100.297     |223.10029699999998   |
|D   |II  |i  |1000     |4539           |4.539          |0.004539             |
|D   |II  |ii |10000    |34646          |34.646         |0.034646             |
|D   |II  |iii|100000   |653931         |653.931        |0.653931             |
|D   |II  |iv |1000000  |12903201       |12903.201      |12.903201            |
|D   |II  |v  |10000000 |239291950      |239291.95      |239.29195            |

