projet_histogrammes: main.cpp
	mkdir -p build/ && cd build/ && cmake .. && make && cd .. && cp build/projet_histogrammes . && echo "Compiled --> \"./projet_histogrammes [args...]\""
