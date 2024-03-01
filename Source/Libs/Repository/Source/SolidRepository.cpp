//
// Created by fld on 23/11/22.
//


#include "../Include/SolidRepository.h"
#include "../Include/JsonConverter.h"
#include <json/json.h>
#include <string>
#include <fstream>

namespace Luga {
    namespace Meca {
        namespace Repository {

            std::string SolidRepository::SaveSolid(const Solid::Solid &solid, const std::string  filepath) {
                Json::Value root = JsonConverter::SolidToJson(solid);
                Json::FastWriter fastWriter;
                std::ofstream file_id;
                file_id.open(filepath);
                file_id << fastWriter.write(root);
                return fastWriter.write(root);
            }

            Solid::Solid SolidRepository::LoadSolid(const std::string  filepath) {
                std::ifstream f(filepath);
                Json::Value root;
                f >> root;
                return JsonConverter::JsonToBSolid(root);
            }

        }
    }
}
