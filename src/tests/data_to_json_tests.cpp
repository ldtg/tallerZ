//
// Created by darius on 18/06/17.
//

#include <gtest/gtest.h>
#include "Data_to_json.h"
#include "Json_to_Data.h"

TEST(data_to_json, to_json){
  Data_to_json dtoj;
  dtoj.store_data();
}

TEST(json_to_data, from_json){
  Json_to_Data jtod;
  Data data = jtod.load_file();
  std::cout << "fin";
}