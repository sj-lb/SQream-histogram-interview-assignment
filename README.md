# SQream interview histogram assignment
this code processes a text file and produces a histogram of the letters within.
the assignment had two stages:
1. basic code that produces the histogram.
2. multithreaded code that produces the histogram using 10 threads.

the test provided here checks the time it took the code to run and prints the histogram.

# Instructions
to compile the basic histogram test:

`$ make hist`

to run the basic histogram test:

`$ ./hist <path/to/dictionary>`


to compile the multithreaded histogram test:

`make mt_hist`

to run the simple histogram test:

`$ ./mt_hist <path/to/dictionary>`

# Notes
1. in my tests, the single threaded version takes approximately 260ms to process '/usr/share/dict/words', while the multithreaded version takes about 100ms.
