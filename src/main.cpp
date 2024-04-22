//
// Created by jack on 16/11/23.
//
#include "leveldb/db.h"

#include <thread>
#include <unistd.h>
#include <string>
#include "utils.h"

int main() {
  leveldb::DB *db;
  leveldb::Options options;
  options.create_if_missing = true;
  leveldb::Status status = leveldb::DB::Open(options, TEST_DB_DIR, &db);
  std::shared_ptr<leveldb::DB> db_ptr(db);

  leveldb::ReadOptions readOptions;
  leveldb::WriteOptions writeOptions;
  writeOptions.sync = true;
  std::string value;
  // db_ptr->Put(writeOptions, "key1", "keyvalue");
  auto s = db_ptr->Get(readOptions, "key1", &value);
  if (s.ok()) {
    std::cout << value << std::endl;
  }
  for (int i = 0; i < INT_MAX; i++) {
    std::string key = "writeOptionswriteOptionswriteOptionswriteOptionswriteOptionswriteOptionswriteOptionswriteOptionskey";
    key.append(std::to_string(i));
    db_ptr->Put(writeOptions, key, key);
  }

  return 0;
}
