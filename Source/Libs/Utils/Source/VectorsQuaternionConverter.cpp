
#include <Utils/Vector.h>
#include <iostream>
#include <cmath>
#include "../Include/Utils/VectorsQuaternionConverter.h"
#include "../Include/Utils/Quaternion.h"

#define precision 1E-15

namespace Luga {
	namespace Meca {
		namespace Utils{

			VectorsQuaternionConverter::VectorsQuaternionConverter(){

			}

			VectorsQuaternionConverter::~VectorsQuaternionConverter(){

			}


			void VectorsQuaternionConverter::ConvertQuaternionIntoVectors(const Quaternion& q, Vector& e1, Vector& e2, Vector& e3) const{
				e1.SetComponants(1 - 2*q.ComponantJ()*q.ComponantJ() - 2*q.ComponantK()*q.ComponantK(),
						2*q.ComponantI()*q.ComponantJ() + 2*q.ComponantK()*q.ComponantReal(),
						2*q.ComponantI()*q.ComponantK() - 2*q.ComponantJ()*q.ComponantReal());

				e2.SetComponants(2*q.ComponantI()*q.ComponantJ() - 2*q.ComponantK()*q.ComponantReal(),
						1 - 2*q.ComponantI()*q.ComponantI() - 2*q.ComponantK()*q.ComponantK(),
						2*q.ComponantJ()*q.ComponantK() + 2*q.ComponantI()*q.ComponantReal());


				e3.SetComponants(2*q.ComponantI()*q.ComponantK() + 2*q.ComponantJ()*q.ComponantReal(),
						2*q.ComponantJ()*q.ComponantK() - 2*q.ComponantI()*q.ComponantReal(),
						1 - 2*q.ComponantJ()*q.ComponantJ() - 2*q.ComponantI()*q.ComponantI());
			}

			void VectorsQuaternionConverter::ConvertVectorsIntoQuaternion(const Vector& e1,const Vector& e2,const Vector& e3, Quaternion& q) const{
				double q0,q1,q2,q3;
				if(-(e2.ComponantY()+e3.ComponantZ()-e1.ComponantX()-1) < 0)
					q1 = 0.;
				else
					q1 = sqrt(-(e2.ComponantY()+e3.ComponantZ()-e1.ComponantX()-1)/4.);

				if(-(-e2.ComponantY()+e3.ComponantZ()+e1.ComponantX()-1) < 0)
					q2 = 0.;
				else
					q2 = sqrt(-(-e2.ComponantY()+e3.ComponantZ()+e1.ComponantX()-1)/4.);

				if(-(e2.ComponantY()-e3.ComponantZ()+e1.ComponantX()-1) < 0)
					q3 = 0.;
				else
					q3 = sqrt(-(e2.ComponantY()-e3.ComponantZ()+e1.ComponantX()-1)/4.);

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
				if(e2.ComponantZ()-e3.ComponantY() < 0) q1*=-1;
				if(e3.ComponantX()-e1.ComponantZ() < 0) q2*=-1;
				if(e1.ComponantY()-e2.ComponantZ() < 0) q3*=-1;

				q.SetComponants(q0,q1,q2,q3);
			}

		}
	}
}
