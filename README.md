# CPUInformation1
This project consists of code for reading processor information on a Linux machine from the file “/proc/cpuinfo”.  The integration of a QObject based C++ class into QML has been done by using Object and List Property Types and registering a QObject-derived class as an instantiable QML object type. 

The main issue is to provide a model to the QML ListView, which is in C++ code a QList of QObject-derived class pointers.

Although the code does NOT display any user interface to give the desired results, it compiles.
