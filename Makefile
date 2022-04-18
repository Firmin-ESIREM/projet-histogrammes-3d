projet_histogrammes_3d: main.cpp
	mkdir -p build/ && cd build/ && cmake .. && make && cd .. && cp build/projet_histogrammes_3d . && echo "Compiled --> \"./projet_histogrammes_3d [args...]\""
