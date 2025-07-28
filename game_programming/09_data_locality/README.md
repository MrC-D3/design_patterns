Build the project with debug info and optmization (i.e. -g -O3 flags), then:
    valgrind --tool=cachegrind <program_name>
To enable analysis on L1 cache misses:
    valgrind --tool=cachegrind --cache-sim=yes <program_name>

The previous output is a file named cachegrind.out.<process_pid>, then:
    cg_annotate cachegrind.out.<process_pid>

Glossary:
    Ir : Instructions read.
    D1mr : Data L1 cache miss read (the data to read was not in cache L1).
    D1mw : Data L1 cache miss write.

Note:
    a program must do lots of CPU-intensive operations to not see mainly system
    functions data in the report.
