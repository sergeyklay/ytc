#include <iostream>

#include "ytc/configmap.hpp"

int main(int argc, char** argv) {
  if (argc < 2) {
    std::cerr << "Usage: " << std::endl;
    std::cerr << "  " << argv[0] << " <file path> " << std::endl;
    return 1;
  }

  YAML::Node doc = YAML::LoadFile(std::string(argv[1]));
  ConfigMapPtr cptr = std::make_shared<ConfigMap>();

  auto retval = YAML::convert<ConfigMapPtr>::decode(doc, cptr);
  if (!retval) {
    std::cerr << "Unable to decode yaml file" << std::endl;
    return 1;
  }

  std::cerr << "convert_result: " << retval << std::endl;
  return 0;
}
