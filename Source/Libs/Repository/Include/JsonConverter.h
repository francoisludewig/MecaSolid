#pragma once


#include "Vector.h"
#include "Solid/Solid.h"
#include "json/value.h"

using namespace Luga::Meca::Utils;
using namespace Luga::Meca::Solid;

namespace Luga {
    namespace Meca {
        namespace Repository {

            class JsonConverter {
            public:
                static Json::Value SolidToJson(const Solid::Solid &solid);

                static Solid::Solid JsonToBSolid(const Json::Value root);

            private:
                static Json::Value PointToJson(const Point &point);

                static Json::Value VectorToJson(const Vector &vector);

                static Json::Value QuaternionToJson(const Quaternion &quaternion);

                static Json::Value MatrixToJson(const Matrix &matrix);

                static Json::Value BasisToJson(const Basis &basis);

                static Point JsonToPoint(const Json::Value root);

                static Vector JsonToVector(const Json::Value root);

                static Quaternion JsonToQuaternion(const Json::Value root);

                static Matrix JsonToMatrix(const Json::Value root);

                static Basis JsonToBasis(const Json::Value root);

            };
        }
    }
}