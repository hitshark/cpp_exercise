#include <iostream>

enum class dpu : int {
  DPUV1 = 0,
  DPUV2
};

template<dpu ver>
class Layer {
public:
  void read() { std::cout << "normal read" << std::endl; }
  void write() { std::cout << "normal write" << std::endl; }
};

template <>
void Layer<dpu::DPUV1>::read() {std::cout << "int: read" << std::endl; }

int main()
{
  Layer<dpu::DPUV1> flr;
  Layer<dpu::DPUV2> ilr;

  flr.read();
  ilr.read();

  return 0;
}
