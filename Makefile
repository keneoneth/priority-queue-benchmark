# TEST Candidates
# A) std::priority_queue
# B) boost::pairing_heap
# C) pairing_heap_priqueue
# D) skiplist_priqueue

# TEST I: add random elements one by one
# TESTID:
# i) 1k elements
# ii) 10k elements
# iii) 100k elements
# iv) 1M elements
# v) 10M elements
# vi) 100M elements


# TEST II: find the shortest path in graph
# TESTID:
# i) 1k elements
# ii) 10k elements
# iii) 100k elements
# iv) 1M elements
# v) 10M elements
# vi) 100M elements


### note:
# if needed to access local boost library, export BOOST_PATH={PATH_TO_BOOST_LIB}

testmain:
	@if (test $(cand) && test $(type) && test $(id)); then \
		g++ -Ofast testmain.cc -o testmain -DTCAND=$(cand) -DTCAND_$(cand) -DTTYPE=$(type) -DTTYPE_$(type) -DTID=$(id) -I $(BOOST_PATH) -DTID_$(id); \
	else \
		echo "arg cand/type/id is missing"; \
		exit 1; \
	fi

run : testmain
	./testmain

clean:
	@[ -f testmain ] && rm testmain || true