The executable is not able to load the dynamic library at run-time?
1. Look if the location of the .so file is in /etc/ld.so.conf or in any file
    under /etc/ld.so.conf.d/.
2. If so, update the dynamic linker cache calling ldconfig.