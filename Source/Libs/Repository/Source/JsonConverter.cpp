//
// Created by fld on 24/11/22.
//


#include "../Include/JsonConverter.h"
#include <string>

namespace Luga {
    namespace Meca {
        namespace Repository {

            Json::Value JsonConverter::PointToJson(const Point &point) {
                Json::Value root;
                root["x"] = point.CoordinateX();
                root["y"] = point.CoordinateY();
                root["z"] = point.CoordinateZ();
                return root;
            }

            Point JsonConverter::JsonToPoint(const Json::Value root) {
                Point point(root["x"].asDouble(), root["y"].asDouble(), root["z"].asDouble());
                return point;
            }

            Json::Value JsonConverter::VectorToJson(const Vector &vector) {
                Json::Value root;
                root["x"] = vector.ComponantX();
                root["y"] = vector.ComponantY();
                root["z"] = vector.ComponantZ();
                return root;
            }

            Vector JsonConverter::JsonToVector(const Json::Value root) {
                Vector vector(root["x"].asDouble(), root["y"].asDouble(), root["z"].asDouble());
                return vector;
            }

            Json::Value JsonConverter::QuaternionToJson(const Quaternion &quaternion) {
                Json::Value root;
                root["i"] = quaternion.ComponantI();
                root["j"] = quaternion.ComponantJ();
                root["k"] = quaternion.ComponantK();
                root["r"] = quaternion.ComponantReal();
                return root;
            }

            Quaternion JsonConverter::JsonToQuaternion(const Json::Value root) {
                Quaternion quaternion(root["r"].asDouble(), root["i"].asDouble(), root["j"].asDouble(),
                                      root["k"].asDouble());
                return quaternion;
            }

            Json::Value JsonConverter::MatrixToJson(const Matrix &matrix) {
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

            Matrix JsonConverter::JsonToMatrix(const Json::Value root) {
                Matrix matrix(root["0-0"].asDouble(), root["0-1"].asDouble(), root["0-2"].asDouble(),
                              root["1-0"].asDouble(), root["1-1"].asDouble(), root["1-2"].asDouble(),
                              root["2-0"].asDouble(), root["2-1"].asDouble(), root["2-2"].asDouble());
                return matrix;
            }

            Json::Value JsonConverter::BasisToJson(const Basis &basis) {
                Json::Value root;
                root["id"] = basis.ID();
                root["origin"] = PointToJson(basis.Origin());
                root["orientation"] = QuaternionToJson(basis.Orientation());
                return root;
            }

            Basis JsonConverter::JsonToBasis(const Json::Value root) {
                Basis basis(JsonToPoint(root["origin"]), JsonToQuaternion(root["orientation"]));
                return basis;
            }


            Json::Value JsonConverter::SolidToJson(const Solid::Solid &solid) {
                Json::Value root;
                root["basis"] = JsonConverter::BasisToJson(solid.B());
                root["velocity"] = JsonConverter::VectorToJson(solid.Velocity());
                root["angularVelocity"] = JsonConverter::VectorToJson(solid.AngularVelocity());
                root["force"] = JsonConverter::VectorToJson(solid.Force());
                root["momentum"] = JsonConverter::VectorToJson(solid.Momentum());
                root["inertia"] = JsonConverter::MatrixToJson(solid.Inertia());
                return root;
            }

            Solid::Solid JsonConverter::JsonToBSolid(const Json::Value root) {
                Luga::Meca::Solid::Solid solid;
                auto basis = JsonConverter::JsonToBasis(root["basis"]);
                solid.B(basis);
                auto velocity = JsonConverter::JsonToVector(root["velocity"]);
                solid.Velocity(velocity);
                auto angularVelocity = JsonConverter::JsonToVector(root["angularVelocity"]);
                solid.AngularVelocity(angularVelocity);
                auto force = JsonConverter::JsonToVector(root["force"]);
                solid.Force(force);
                auto momentum = JsonConverter::JsonToVector(root["momentum"]);
                solid.Momentum(momentum);
                auto inertia = JsonConverter::JsonToMatrix(root["inertia"]);
                solid.Inertia(inertia);
                return solid;
            }

        }
    }
}