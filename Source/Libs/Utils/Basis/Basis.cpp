
#include "../Basis/Basis.h"

#include <iostream>
#include <cmath>

#define precision 1E-15

namespace Luga {
	namespace Meca {
		namespace Utils{


			int Basis::instanceCount = 0;

			Basis::Basis():origin(),axisX(1,0,0),axisY(0,1,0),axisZ(0,0,1),orientation(){
				id = instanceCount;
				instanceCount++;
			}

			Basis::Basis(Point o, Quaternion q):origin(o),orientation(q){
				vQc.ConvertQuaternionIntoVectors(q,axisX,axisY,axisZ);
				id = instanceCount;
				instanceCount++;
			}

			Basis::~Basis(){

			}

			int Basis::ID() const{
				return id;
			}


			Point Basis::Origin() const{
				return origin;
			}

			Vector Basis::AxisX() const{
				return axisX;
			}

			Vector Basis::AxisY() const{
				return axisY;
			}

			Vector Basis::AxisZ() const{
				return axisZ;
			}

			Quaternion Basis::Orientation() const{
				return orientation;
			}

			void Basis::Origin(Point & o){
				this->origin = o;
			}

			void Basis::Orientation(Quaternion & q){
				this->orientation = q;
				vQc.ConvertQuaternionIntoVectors(q,axisX,axisY,axisZ);
			}

			void Basis::AxisX(Vector & e1){
				e1.Normalize();
				this->axisX = e1;
				this->ConstructAxisYAndZFromX();
			}

			void Basis::Local(Vector & a) const{
				if(a.Id() == -1){
					double x,y,z;
					x = a*axisX;
					y = a*axisY;
					z = a*axisZ;
					a.SetComponants(x,y,z);
					a.Id(id);
				}
			}

			void Basis::Global(Vector & a) const{
				a = a.ComponantX()*axisX + a.ComponantY()*axisY + a.ComponantZ()*axisZ;
				a.Id(-1);
			}

			Point Basis::Local(const Point & a) const{
				Vector v = a-origin;
				return Point(axisX*v,axisY*v,axisZ*v);
			}

			Point Basis::Global(const Point & a) const{
				Point b = origin;
				b += a.CoordinateX()*axisX + a.CoordinateY()*axisY + a.CoordinateZ()*axisZ;
				return b;
			}

			void Basis::Rotate(Quaternion const & q){
				this->orientation *= q;
				vQc.ConvertQuaternionIntoVectors(this->orientation,axisX,axisY,axisZ);
			}

			void Basis::Translate(Vector const & o){
				this->origin += o;
			}

			void Basis::LoadFromIstream(std::istream & in){
				in >> origin;
				in >> orientation;
				vQc.ConvertQuaternionIntoVectors(orientation,axisX,axisY,axisZ);
			}

			Basis Basis::operator*(Quaternion const & q) const{
				Basis b = *this;
				b.Rotate(q);
				return b;
			}

			Basis Basis::operator+(Vector const & o) const{
				Basis b = *this;
				b.Translate(o);
				return b;
			}

			void Basis::operator*=(Quaternion const& q){
				this->Rotate(q);
			}

			void Basis::operator+=(Vector const& o){
				this->Translate(o);
			}

			void Basis::ConstructAxisYAndZFromX(){
				if((axisX.ComponantX() != 0 || axisX.ComponantY() != 0) || (axisX.ComponantX() != 0 || axisX.ComponantZ() != 0)  || (axisX.ComponantY() != 0 || axisX.ComponantZ() != 0)){
					axisY.ComponantX(axisX.ComponantY()*axisX.ComponantZ());
					axisY.ComponantY(axisX.ComponantX()*axisX.ComponantZ());
					axisY.ComponantZ(-2*axisX.ComponantX()*axisX.ComponantY());
				}
				else{
					if(axisX.ComponantX() == 0 || axisX.ComponantY() == 0){
						axisY.ComponantX(axisX.ComponantZ());
						axisY.ComponantY(0);
						axisY.ComponantZ(0);
					}
					else if(axisX.ComponantX() == 0 || axisX.ComponantZ() == 0){
						axisY.ComponantX(0);
						axisY.ComponantY(0);
						axisY.ComponantZ(axisX.ComponantY());
					}
					else if(axisX.ComponantY() == 0 || axisX.ComponantZ() == 0){
						axisY.ComponantX(0);
						axisY.ComponantY(axisX.ComponantX());
						axisY.ComponantZ(0);
					}
				}
				axisY.Normalize();
				axisZ = axisX^axisY;
			  	vQc.ConvertVectorsIntoQuaternion(axisX,axisY,axisZ,orientation);
			}

			std::ostream & operator << (std::ostream & out, Basis const& a){
				out << a.Origin() << " " << a.Orientation();
				return out;
			}

			std::istream & operator >> (std::istream & in, Basis & a){
				a.LoadFromIstream(in);
				return in;
			}

		}
	}
}
