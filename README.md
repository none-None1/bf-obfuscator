# Brainfuck code is very hard to read, but this tool makes it even harder.

For example, this is a Hello World program in Brainfuck, it might not be easy to read, but with a little thinking you probably can

```python
++++++++[>++++++++<-]>++++++++.>++++++++++++[>++++++++<-]>+++++.+++++++..+++.>++++[>++++++++<-]>.<<<<+++++++++++++++.>>.+++.------.--------.>>+.
```

The code below is the code above obfuscated by this tool, it is complicated, has a lot of redundant characters, and is almost impossible to read, but still prints 'Hello World!'.

```python
+++v++Mg++nB+++------qL-VgUQ-+b++++-Q-----+hJVg+x++++jg+[>+++---jhd---------gtc-a-m+z+F+r++h+z++++++++++-P--h--It-K-ginT-H-rqkm-ea---Z-t-X---++Bj+J+w+>>>l><jf<<<+++++++++++++f+++D<-][..,,,]>+++e+t+H++++Yi++++++++r+-j---------xo----N--k--+Z+++tX++++zwWt.>++++K+W+S+i+d+++k+[>+++c++b++E+K<-]-h--yE-A--Ea++++DL+h+++C+++-gu-U------M----OhnL---++U++e+E++++++T+Ws++h+y+++++--Xiq---------H-----LA--RL--Y-T-R---apz-+++B+++GEiMOQvN++++++++++>P+Q+w++S++++----W+++lht++++++cs+M+f++++YmaW---n----------H--I--J---ryy++Z+++++Dx+bJg++U-----+XX.+++NbDXP+nKM++V+..+u+eU+L.>+F+Uf++F[>+n+w+++Rr++LO+k<FL-]>f.<lU<<FnRU<AI+L+++D++m++j++LN++UI++C+.>V>.+t++p.--H-a--q----++++y+u+++RCSudW++>>>>>>Sh<<N<<<<+-A-is---V--c----N--X-------Smr-ug-+++++cR+C+++++++qg++++A+++---n-wS--.-KX-Y-+--C----MAsEM.q>>+.[+uN+++++++++++++T+++LJ++++----][,Y,M.D+-.,+-...-D.][O-M,.-.v..,..]
```

### How to use?

To use this tool, build it with CMake.

Then set the include directory and the library directory.

Use the 'obfuscate' function to do the obfuscating.

```c++
#include "bf-obfuscator.h"
#include <iostream>
int main(){
    std::string bf = "++++++++[>++++++++<-]>++++++++.>++++++++++++[>++++++++<-]>+++++.+++++++..+++.>++++[>++++++++<-]>.<<<<+++++++++++++++.>>.+++.------.--------.>>+.";
    std::cout<< obfuscate(
        bf, // Brainfuck code
        20, // Obfuscate times, recommend >=20
        20, // Obfuscate level, recommend >=20
        REDUNDANT_ALL // Obfuscate techniques to be used, REDUNDANT_ALL is recommended
    );
    return 0;
}
```

There is also a simple commandline tool, but it is not very good, and it doesn't close the files it opened, so you cannot set the input file the same as the output file, or the tool will do nothing, so using the C++ function instead is recommended.
