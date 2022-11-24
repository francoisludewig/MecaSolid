#pragma once

#include <jsoncpp/json/json.h>
#include "Vector.h"
#include "Solid/Solid.h"

using namespace Luga::Meca::Utils;
using namespace Luga::Meca::Solid;

namespace Luga {
    namespace Meca {
        namespace Repository {

            class SolidRepository {
            public:
                SolidRepository() {}
                ~SolidRepository() {}

                std::string SaveSolid(const Solid::Solid& solid, const std::string  filepath);
                Solid::Solid LoadSolid(const std::string  filepath);
            private:
                Json::Value PointToJson(const Point & point);
                Json::Value VectorToJson(const Vector & vector);
                Json::Value QuaternionToJson(const Quaternion & quaternion);
                Json::Value MatrixToJson(const Matrix & matrix);
                Json::Value BasisToJson(const Basis & basis);

                Point JsonToPoint(const Json::Value root);

                Vector JsonToVector(const Json::Value root);

                Quaternion JsonToQuaternion(const Json::Value root);

                Matrix JsonToMatrix(const Json::Value root);

                Basis JsonToBasis(const Json::Value root);
            };

        }
    }
}