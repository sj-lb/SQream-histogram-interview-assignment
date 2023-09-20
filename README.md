# the project's makefile is simplistic and assumes all files are saved
# in the same directory.

# to compile the first assignment:
`$ make hist`

# to run the first assignment:
`$ ./hist <path/to/dictionary>`

# to compile the second assignment:
`make mt_hist`

# to run the second assignment:
`$ ./mt_hist <path/to/dictionary>`

# NOTES
1. in my tests, the single threaded version takes approximately 260ms to process
   '/usr/share/dict/words', while the multithreaded version takes about 100ms.