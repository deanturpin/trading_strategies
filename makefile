all: tmp analysis tmp/haveanicedaytrader tmp/coins.txt

CXX = g++-8
cflags = --std=c++17 --all-warnings --extra-warnings --pedantic-errors \
	 -Werror -Wshadow -Wfloat-equal -Weffc++ -Wdelete-non-virtual-dtor \
	 -O3

tmp/%.o: %.cpp
	$(CXX) -c -o $@ $< $(cflags)

tmp:
	 mkdir -p $@
	./get_prices.py

tmp/coins.txt: tmp
	./get_coins.py > $@

analysis:
	 mkdir -p $@

objects:
	make -j $(shell nproc) tmp/trade.o tmp/backtest.o tmp/report.o \
	tmp/main.o tmp/strategy.o tmp/detailed_report.o tmp/strategy_report.o \
	tmp/unit_test.o

# Generate documentation
readme = readme.md
tmp/haveanicedaytrader: objects
	$(CXX) -o $@ tmp/*.o -lstdc++fs -lpthread
	cat template.md > $(readme)
	./$@ >> $(readme)
	head -60 readme.md

# All intermediate files are stored in tmp and analysis, so just remove them
clean:
	rm -rf tmp analysis

cleanobjects:
	rm -rf tmp/*.o
