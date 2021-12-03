#pragma once
#include "docu_inc.h"
namespace deco {
namespace parallel {
class parallel_task{

};


inline void TransfromTest_(){
  std::vector<int> v_ori{20,50,8,77,54};
  //std::vector<int> v_new(v_ori.size());
  std::vector<int> v_new;
  std::transform(std::begin(v_ori), std::end(v_ori), std::back_inserter(v_new), [](int val){ return val / 10; });
  std::for_each(v_new.begin(), v_new.end(), [](int val){ std::cout << val << std::endl; });
}
inline void AccmulateTest_() {
  std::vector<int> v_nums{10,20,30,40};
  std::cout << std::accumulate(v_nums.begin(), v_nums.end(), 20,
   [](int nums, int num2){ return nums + num2 / 10;}) << std::endl;
}
inline void CopyTest_() {
  std::vector<int> v_nums{10,20,70,4,55,78,99};
  std::vector<int> v_res_than_;
  int num_sip = 50;
  std::copy_if(v_nums.begin(), v_nums.end(), std::back_inserter(v_res_than_), [num_sip](int val){ return val >= num_sip? true: false; });
  std::copy(v_res_than_.begin(), v_res_than_.end(), std::ostream_iterator <int>{std::cout, " "});
}
}//end parallel deco
}//end namespace deco


