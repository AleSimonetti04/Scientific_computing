#include <iostream>

int main(int argc, const char *argv[])
{
std::cout << "Numero di parametri: " << argc << "\n";
for (int i = 0; i < argc; i++) {
std::cout << "Parametro " << i << " = " << argv[i] << "\n";
}
return 0;
}