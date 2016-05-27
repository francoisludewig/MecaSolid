
#include <iostream>
#include <cmath>
#include "../Include/Utils/BasisId.h"

#define precision 1E-15

using namespace std;

namespace Luga {
	namespace Meca {
		namespace Utils{

			BasisId::BasisId():id(-1){

			}

			BasisId::~BasisId(){

			}

			void BasisId::Id(int id){
				this->id = id;
			}

			int BasisId::Id() const{
				return id;
			}

			ostream & operator << (ostream & out, BasisId const& a){
				out << a.Id();
				return out;
			}

			istream & operator >> (istream & in, BasisId & a){
				int id_tmp;
				in >> id_tmp;
				a.Id(id_tmp);
				return in;
			}

		}
	}
}
