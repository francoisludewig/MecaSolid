//
// Created by fld on 23/11/22.
//

#include "../Include/SolidRepository.h"
#include <string>

namespace Luga {
    namespace Meca {
        namespace Repository {

            std::string SolidRepository::SaveSolid(const Solid::Solid &solid) {
                Json::Value root;
                root["basis"] = BasisToJson(solid.B());
                root["velocity"] = VectorToJson(solid.Velocity());
                root["angularVelocity"] = VectorToJson(solid.AngularVelocity());
                root["force"] = VectorToJson(solid.Force());
                root["momentum"] = VectorToJson(solid.Momentum());
                root["inertia"] = MatrixToJson(solid.Inertia());
                Json::FastWriter fastWriter;
                return fastWriter.write(root);
            }

            Solid::Solid SolidRepository::LoadSolid(const std::string &jsonStr) {
                Json::Value root;
                Json::Reader reader;
                bool parsingSuccessful = reader.parse(jsonStr, root);
                if (parsingSuccessful) {
                    Luga::Meca::Solid::Solid solid;
                    auto basis = JsonToBasis(root["basis"]);
                    solid.B(basis);
                    auto velocity = JsonToVector(root["velocity"]);
                    solid.Velocity(velocity);
                    auto angularVelocity = JsonToVector(root["angularVelocity"]);
                    solid.AngularVelocity(angularVelocity);
                    auto force = JsonToVector(root["force"]);
                    solid.Force(force);
                    auto momentum = JsonToVector(root["momentum"]);
                    solid.Momentum(momentum);
                    auto inertia = JsonToMatrix(root["inertia"]);
                    solid.Inertia(inertia);
                    return solid;
                }
                return Solid::Solid();
            }

            Json::Value SolidRepository::PointToJson(const Point &point) {
                Json::Value root;
                root["x"] = point.CoordinateX();
                root["y"] = point.CoordinateY();
                root["z"] = point.CoordinateZ();
                return root;
            }

            Point SolidRepository::JsonToPoint(const Json::Value root) {
                Point point(root["x"].asDouble(), root["y"].asDouble(), root["z"].asDouble());
                return point;
            }

            Json::Value SolidRepository::VectorToJson(const Vector &vector) {
                Json::Value root;
                root["x"] = vector.ComponantX();
                root["y"] = vector.ComponantY();
                root["z"] = vector.ComponantZ();
                return root;
            }

            Vector SolidRepository::JsonToVector(const Json::Value root) {
                Vector vector(root["x"].asDouble(), root["y"].asDouble(), root["z"].asDouble());
                return vector;
            }

            Json::Value SolidRepository::QuaternionToJson(const Quaternion &quaternion) {
                Json::Value root;
                root["i"] = quaternion.ComponantI();
                root["j"] = quaternion.ComponantJ();
                root["k"] = quaternion.ComponantK();
                root["r"] = quaternion.ComponantReal();
                return root;
            }

            Quaternion SolidRepository::JsonToQuaternion(const Json::Value root) {
                Quaternion quaternion(root["r"].asDouble(), root["i"].asDouble(), root["j"].asDouble(),
                                      root["k"].asDouble());
                return quaternion;
            }

            Json::Value SolidRepository::MatrixToJson(const Matrix &matrix) {
                Json::Value root;
                root["0-0"] = matrix.Element(0, 0);
                root["0-1"] = matrix.Element(0, 1);
                root["0-2"] = matrix.Element(0, 2);
                root["1-0"] = matrix.Element(1, 0);
                root["1-1"] = matrix.Element(1, 1);
                root["1-2"] = matrix.Element(1, 2);
                root["2-0"] = matrix.Element(2, 0);
                root["2-1"] = matrix.Element(2, 1);
                root["2-2"] = matrix.Element(2, 2);
                return root;
            }

            Matrix SolidRepository::JsonToMatrix(const Json::Value root) {
                Matrix matrix(root["0-0"].asDouble(), root["0-1"].asDouble(), root["0-2"].asDouble(),
                              root["1-0"].asDouble(), root["1-1"].asDouble(), root["1-2"].asDouble(),
                              root["2-0"].asDouble(), root["2-1"].asDouble(), root["2-2"].asDouble());
                return matrix;
            }

            Json::Value SolidRepository::BasisToJson(const Basis &basis) {
                Json::Value root;
                root["id"] = basis.ID();
                root["origin"] = PointToJson(basis.Origin());
                root["orientation"] = QuaternionToJson(basis.Orientation());
                return root;
            }

            Basis SolidRepository::JsonToBasis(const Json::Value root) {
                Basis basis(JsonToPoint(root["origin"]), JsonToQuaternion(root["orientation"]));
                return basis;
            }

        }
    }
}
