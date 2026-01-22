#pragma once
#include <iostream>

#define ENGINE_LOG(x) std::cout << "[Engine] " << x << std::endl
#define ENGINE_WARN(x) std::cout << "[Warn] " << x << std::endl
#define ENGINE_ERROR(x) std::cerr << "[Error] " << x << std::endl
