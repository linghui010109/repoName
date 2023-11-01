all: main.cpp
	g++ -o test main.cpp -O3 -std=c++11
debug: main.cpp
	g++ -o test main.cpp -g -std=c++11
report: Report.tex
	pdflatex Report.tex
clean:

	rm -f test Report.pdf
