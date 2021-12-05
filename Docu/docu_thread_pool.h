#pragma once
#include "docu_inc.h"
namespace docu {
namespace thread_pool {
class DocuThread final { //单个线程
   using TaskType = std::function<void()>;
 public:
   DocuThread() 
     :m_status_(false),
      is_stop(false),
      task(nullptr){
   }
   ~DocuThread(){
     
   }
   bool AddTask(TaskType&& task_) {
      if(CouldAddTask()) {
        std::unique_lock<std::mutex> un_lock(m_mutex);
        task = new TaskType(std::move(task_));
        m_exec_task.notify_one();
        return true;
      }
      return false;
   }
   void Run() {
     auto func_ = [this]() {
       while (!is_stop) {
       std::unique_lock<std::mutex> un_lock(m_mutex);
       while(this->task == nullptr || is_stop == true)
         m_exec_task.wait(un_lock);
      if (!is_stop) {
        m_status_ = true;
        (*this->task)();
        InternalDeleteTask();
        m_status_ = false;
        //un_lock.unlock();
      }
       }
     };
     m_thread_ = std::move( std::thread(func_) );
     m_thread_.detach();
   }
   bool  CouldAddTask() { return !m_status_ ; }
   void stop() {
     is_stop = true;
   }
 private:
   void InternalDeleteTask() {
     delete task;
     task = nullptr;
 }
 private:
  std::thread m_thread_;
  std::function<void()>* task;
  bool m_status_;
  bool is_stop;
  std::mutex m_mutex;
  std::condition_variable m_exec_task;
};
class ThreadPool {
  public:
  private:
  
};
} //end namespace thread_pool
} //end namespace docu
