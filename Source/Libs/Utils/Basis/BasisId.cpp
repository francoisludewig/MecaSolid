
#include "../Basis/BasisId.h"

#include <iostream>
#include <cmath>

#define precision 1E-15

namespace Luga {
	namespace Meca {
		namespace Utils{

			BasisId::BasisId():id(-1){

			}

			BasisId::~BasisId(){

			}

			void BasisId::Id(const int & id){
				this->id = id;
			}

			int BasisId::Id() const{
				return id;
			}

			std::ostream & operator << (std::ostream & out, const BasisId & a){
				out << a.Id();
				return out;
			}

			std::istream & operator >> (std::istream & in, BasisId & a){
				int id_tmp;
				in >> id_tmp;
				a.Id(id_tmp);
				return in;
			}

		}
	}
}
