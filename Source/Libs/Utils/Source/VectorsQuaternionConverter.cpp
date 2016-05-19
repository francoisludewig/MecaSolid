
#include <iostream>
#include <cmath>
#include "../Include/Utils/VectorsQuaternionConverter.h"
#include "../Include/Utils/Vector3D.h"
#include "../Include/Utils/Quaternion.h"

#define precision 1E-15

using namespace std;

namespace Luga {
	namespace Meca {
		namespace Utils{

			VectorsQuaternionConverter::VectorsQuaternionConverter(){

			}

			VectorsQuaternionConverter::~VectorsQuaternionConverter(){

			}


			void VectorsQuaternionConverter::ConvertQuaternionIntoVectors(const Quaternion& q, Vector3D& e1, Vector3D& e2, Vector3D& e3) const{
				e1.SetValue(1 - 2*q.Q2()*q.Q2() - 2*q.Q3()*q.Q3(),
						2*q.Q1()*q.Q2() + 2*q.Q3()*q.Q0(),
						2*q.Q1()*q.Q3() - 2*q.Q2()*q.Q0());

				e2.SetValue(2*q.Q1()*q.Q2() - 2*q.Q3()*q.Q0(),
						1 - 2*q.Q1()*q.Q1() - 2*q.Q3()*q.Q3(),
						2*q.Q2()*q.Q3() + 2*q.Q1()*q.Q0());


				e3.SetValue(2*q.Q1()*q.Q3() + 2*q.Q2()*q.Q0(),
						2*q.Q2()*q.Q3() - 2*q.Q1()*q.Q0(),
						1 - 2*q.Q2()*q.Q2() - 2*q.Q1()*q.Q1());
			}

			void VectorsQuaternionConverter::ConvertVectorsIntoQuaternion(const Vector3D& e1,const Vector3D& e2,const Vector3D& e3, Quaternion& q) const{
				double q0,q1,q2,q3;
				if(-(e2.Y()+e3.Z()-e1.X()-1) < 0)
					q1 = 0.;
				else
					q1 = sqrt(-(e2.Y()+e3.Z()-e1.X()-1)/4.);

				if(-(-e2.Y()+e3.Z()+e1.X()-1) < 0)
					q2 = 0.;
				else
					q2 = sqrt(-(-e2.Y()+e3.Z()+e1.X()-1)/4.);

				if(-(e2.Y()-e3.Z()+e1.X()-1) < 0)
					q3 = 0.;
				else
					q3 = sqrt(-(e2.Y()-e3.Z()+e1.X()-1)/4.);

				if(1.-q1*q1-q2*q2-q3*q3 >= 0)
					q0 = sqrt(1.-q1*q1-q2*q2-q3*q3);
				else
					q0 = 0.;

				// Cancel quadratic relative errors
				double maxq = q0*q0;
				if(q1 > maxq)maxq = q1*q1;
				if(q2 > maxq)maxq = q2*q2;
				if(q3 > maxq)maxq = q3*q3;
				double error = maxq * pow(10,-14);
				if(q0*q0 < error)q0 = 0.;
				if(q1*q1 < error)q1 = 0.;
				if(q2*q2 < error)q2 = 0.;
				if(q3*q3 < error)q3 = 0.;
				// Sign correction
				if(e2.Z()-e3.Y() < 0) q1*=-1;
				if(e3.X()-e1.Z() < 0) q2*=-1;
				if(e1.Y()-e2.Z() < 0) q3*=-1;

				q.SetValue(q0,q1,q2,q3);
			}

		}
	}
}
