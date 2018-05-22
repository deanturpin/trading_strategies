all: prices.csv prospects.csv

JOBS=4
CXX=clang++
flags=-g -Weffc++ -Wall -Wextra -pedantic -pedantic-errors -std=c++14 --coverage
%.o: %.cpp
	$(CXX) $(flags) -o $@ $<

# Don't let make remove intermediate files
objects = $(patsubst %.cpp, %.o, $(wildcard *.cpp))
.PRECIOUS: $(objects)

source:
	$(MAKE) --jobs $(JOBS) $(objects)

prices.csv: pairs.csv pairs_short.csv
	bin/prices2.py > $@

%.csv: %.o
	./$< > $@

.PHONY: refresh.csv review.csv purge.csv consolidate.csv index.html

refresh.csv: refresh.o prices.csv
	./$< > $@

review.csv: review.o refresh.o
	./$< > $@

purge.csv: purge.o review.csv
	./$< > $@

consolidate.csv: consolidate.o purge.csv prospects.csv
	./$< > $@

prospects.csv: prospects.o prices.csv
	./$< > $@

index.html: index.o consolidate.csv review.csv
	./$< > $@

endofsession:
	cp consolidate.csv positions.csv

update:
	rm -f prices.csv
	$(MAKE)

stats:
	bin/generate_stats.sh

gitpull:
	git pull --quiet

clean:
	rm -f *.o prices.csv

cron:
	watch -d -n 60 $(MAKE) update

docs:
	dot -T svg doc/handt.dot > doc/handt.svg

unit_test: source
	$(MAKE) --silent --directory test
