//
// Created by jack on 19/11/23.
//

#ifndef LEVELDB_UTILS_H
#define LEVELDB_UTILS_H

#include <iostream>

template<typename T>
void printLog(T t) {
  std::cout << t << std::endl;
}

template<typename T, typename... Args>
void printLog(T t, Args... args) {
  std::cout << t;
  printLog(args...);
}

#endif  // LEVELDB_UTILS_H
