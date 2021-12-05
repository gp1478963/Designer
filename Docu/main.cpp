#include "docu_singleton.h"
#include "docu_int2type.h"
#include "parallel_task.h"
#include "docu_thread_pool.h"
class MyClass
{
public:
	MyClass(){}
	void test_debug()
	{
		std::cout << "hello world" << std::endl;
	}
	~MyClass()
	{
		std::cout << "hello world - destory" << std::endl;
	}
};
void test_iiu()
{
	/*deco::design_patern::SingleTon<MyClass>::Getinstance()->test_debug();
	deco::design_patern::SingleTon<MyClass>::Getinstance()->test_debug();*/

	deco::test::pr_1 pr;
	deco::test::Printf_Test<deco::test::pr_1, true > pre;
	pre.printf_La(pr);


}

class student {
  std::string name_;
  int age = 0;
};
class teacher {
  std::string name_;
  int age_;
};
template <typename Tp>
struct is_student{
  static const bool value = false;
};
template <>
struct is_student<student> {
  static const bool value = true;
};
void printf_ls(bool id_tra)
{
  if(id_tra)
    std::cout <<"student"<<std::endl;
}
void remove_file(const std::string& path_dir,const std::string& reg) {
	std::regex hit_file(reg);
    auto fs_ = std::filesystem::directory_iterator(path_dir);
	for (auto& fe : fs_) {
	  auto fp = fe.path();
	  auto fs_ = std::filesystem::directory_iterator(fe.path());
	  for (auto& fi : fs_)
	  {
		auto fp = fi.path();
		auto trmp = fp.filename();
		try
		{
		  if (trmp.string().find(reg) != std::string::npos) {
			_unlink(fp.string().c_str());
			std::cout << fp.string().c_str() << std::endl;
		  }	
		}
		catch (const std::exception&){}		
	  }
	}
}
int main()
{
  auto funcA = []() { std::cout << "printB" << std::endl; };
  auto funcB = [](){ std::cout << "printA" << std::endl; };
  docu::thread_pool::DocuThread dou_task;
  dou_task.Run();
  if (dou_task.CouldAddTask()) dou_task.AddTask(funcA);
   for(int i = 0 ; i < 1000000; i++) {}
  if(dou_task.CouldAddTask()) dou_task.AddTask(funcB);
 // while(1);
  //system("pause");
  for (int i = 0; i < 1000000; i++) {}
  if (dou_task.CouldAddTask()) dou_task.AddTask(funcB);
  if (dou_task.CouldAddTask()) dou_task.AddTask(funcA);
  for (int i = 0; i < 1000000; i++) {}
  if (dou_task.CouldAddTask()) dou_task.AddTask(funcB);
  // while(1);
   //system("pause");
  for (int i = 0; i < 1000000; i++) {}
  if (dou_task.CouldAddTask()) dou_task.AddTask(funcB);
  dou_task.stop();
 // system("pause");
  //while(1);
  for (int i = 0; i < 1000000; i++) {}
  return 0;
}