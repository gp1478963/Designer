#pragma once
#include "docu_inc.h"
namespace deco {
namespace design_patern {
template <typename _Tp>
class SingleTon final{
public:		
			static _Tp* Getinstance()
			{
				//保证线程安全
				std::lock_guard<std::mutex> l_m(m_mute_) ;
				if (p_instance_ == nullptr)
				{
					//创建单例
					p_instance_ = std::make_shared<_Tp>();
				}
				return p_instance_.get();
			}
		private:
			SingleTon() {}
			~SingleTon() {}
			SingleTon(const SingleTon<_Tp>&) = delete;

			SingleTon<_Tp>* operator=(const SingleTon<_Tp>&) = delete;

		private:
			static std::shared_ptr<_Tp> p_instance_;
			static std::mutex m_mute_;
		};
		template <typename _Tp>
		std::shared_ptr<_Tp> SingleTon<_Tp>::p_instance_ = nullptr;
		template <typename _Tp>
		std::mutex SingleTon<_Tp>::m_mute_;

	}//end namespace design_patern
}//end namespace deco