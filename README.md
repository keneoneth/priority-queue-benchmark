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

|cand|type|id |size     |elapsed_time_us|elapsed_time_ms|elapsed_time_s|
|----|----|---|---------|---------------|---------------|--------------|
|A   |I   |i  |1000     |55             |0.055          |0.0001        |
|A   |I   |ii |10000    |2362           |2.362          |0.0024        |
|A   |I   |iii|100000   |12765          |12.765         |0.0128        |
|A   |I   |iv |1000000  |118329         |118.329        |0.1183        |
|A   |I   |v  |10000000 |1830664        |1830.664       |1.8307        |
|A   |I   |vi |100000000|26980494       |26980.494      |26.9805       |
|B   |I   |i  |1000     |167            |0.167          |0.0002        |
|B   |I   |ii |10000    |2491           |2.491          |0.0025        |
|B   |I   |iii|100000   |32491          |32.491         |0.0325        |
|B   |I   |iv |1000000  |1092296        |1092.296       |1.0923        |
|B   |I   |v  |10000000 |25379497       |25379.497      |25.3795       |
|B   |I   |vi |100000000|563079244      |563079.244     |563.0792      |
|C   |I   |i  |1000     |92             |0.092          |0.0001        |
|C   |I   |ii |10000    |1304           |1.304          |0.0013        |
|C   |I   |iii|100000   |17832          |17.832         |0.0178        |
|C   |I   |iv |1000000  |958796         |958.796        |0.9588        |
|C   |I   |v  |10000000 |19544056       |19544.056      |19.5441       |
|C   |I   |vi |100000000|367442111      |367442.111     |367.4421      |
|D   |I   |i  |1000     |163            |0.163          |0.0002        |
|D   |I   |ii |10000    |5546           |5.546          |0.0055        |
|D   |I   |iii|100000   |49966          |49.966         |0.05          |
|D   |I   |iv |1000000  |1486540        |1486.54        |1.4865        |
|D   |I   |v  |10000000 |29545471       |29545.471      |29.5455       |
|D   |I   |vi |100000000|695342947      |695342.947     |695.3429      |


#### test_II_result.csv

|cand|type|id |size     |elapsed_time_us|elapsed_time_ms|elapsed_time_s|
|----|----|---|---------|---------------|---------------|--------------|
|A   |II  |i  |1000     |3815           |3.815          |0.0038        |
|A   |II  |ii |10000    |21626          |21.626         |0.0216        |
|A   |II  |iii|100000   |648841         |648.841        |0.6488        |
|A   |II  |iv |1000000  |11440601       |11440.601      |11.4406       |
|A   |II  |v  |10000000 |197466643      |197466.643     |197.4666      |
|B   |II  |i  |1000     |1548           |1.548          |0.0015        |
|B   |II  |ii |10000    |41349          |41.349         |0.0413        |
|B   |II  |iii|100000   |636757         |636.757        |0.6368        |
|B   |II  |iv |1000000  |11476479       |11476.479      |11.4765       |
|B   |II  |v  |10000000 |217450688      |217450.688     |217.4507      |
|C   |II  |i  |1000     |3041           |3.041          |0.003         |
|C   |II  |ii |10000    |28246          |28.246         |0.0282        |
|C   |II  |iii|100000   |696461         |696.461        |0.6965        |
|C   |II  |iv |1000000  |10939139       |10939.139      |10.9391       |
|C   |II  |v  |10000000 |206034888      |206034.888     |206.0349      |
|D   |II  |i  |1000     |5445           |5.445          |0.0054        |
|D   |II  |ii |10000    |23252          |23.252         |0.0233        |
|D   |II  |iii|100000   |663265         |663.265        |0.6633        |
|D   |II  |iv |1000000  |12138649       |12138.649      |12.1386       |
|D   |II  |v  |10000000 |233552213      |233552.213     |233.5522      |
