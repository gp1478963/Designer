#pragma once
#include "docu_inc.h"
namespace deco {
namespace test {
template<bool bool2Type> 
struct _Int2Type
{enum { value = bool2Type };};
template<typename _Tp,bool flag>
class Printf_Test{
 public:
  Printf_Test() {}
  void printf_La( _Tp& class_tp, _Int2Type<true>) { class_tp.printf_q(); }
  void printf_La( _Tp& class_tp, _Int2Type<false>){ class_tp.printf_l(); }
  void printf_La( _Tp& class_tp) { printf_La(class_tp, _Int2Type<flag>()); }
  ~Printf_Test(){}
};

class pr_1{
 public:
  pr_1(){}
  void printf_q() { std::cout << "printf_q" << std::endl; }
  ~pr_1(){}
};
}//end namespace deco
}//end namespace test