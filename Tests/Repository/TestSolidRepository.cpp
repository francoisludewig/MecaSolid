//
// Created by utilisateur on 01-03-24.
//

#include <gtest/gtest.h>
#include <cmath>
#include <filesystem>
#include <fstream>
#include "Solid/Solid.h"
#include "SolidRepository.h"


void RemoveFile(const std::string &fileName) {
    int status = remove(fileName.c_str());
    if (status == 0)
        std::cout << "\nFile Deleted Successfully!";
    else
        std::cout << "\nError Occurred while deleting file : " + fileName;
}

std::string GetResourceDirectory() {
    std::filesystem::path cwd = std::filesystem::current_path();
    return cwd.string() + "/../../Tests/Repository/Resources/";
}

TEST(SolidRepository, SolidToJson) {
    // Build Solid to save
    Luga::Meca::Solid::Solid solid;
    Vector velocity(M_PI, 0, 0);
    solid.Velocity(velocity);
    solid.UpdatePosition(1);

    // Save Solid
    Luga::Meca::Repository::SolidRepository repo;
    std::string fileName = GetResourceDirectory() + "solid.json";
    repo.SaveSolid(solid, fileName);

    ASSERT_TRUE(std::filesystem::exists(fileName));
    std::string str;
    {
        std::ifstream fread(fileName);
        fread >> str;
    }
    str+="\n";
    
    /* Build string to test without id depending on test execution order */
    auto begin = str.substr(0, str.find("\"id\":"));
    auto end = str.substr(str.find("\"id\":"));
    auto end_without_id = end.substr(end.find(","));

    ASSERT_EQ(begin,
              "{\"angularVelocity\":{\"x\":0.0,\"y\":0.0,\"z\":0.0},\"basis\":{");
    ASSERT_EQ(end_without_id,
              ",\"orientation\":{\"i\":0.0,\"j\":0.0,\"k\":0.0,\"r\":1.0},\"origin\":{\"x\":3.1415926535897931,\"y\":0.0,\"z\":0.0}},\"force\":{\"x\":0.0,\"y\":0.0,\"z\":0.0},\"inertia\":{\"0-0\":1.0,\"0-1\":0.0,\"0-2\":0.0,\"1-0\":0.0,\"1-1\":1.0,\"1-2\":0.0,\"2-0\":0.0,\"2-1\":0.0,\"2-2\":1.0},\"momentum\":{\"x\":0.0,\"y\":0.0,\"z\":0.0},\"velocity\":{\"x\":3.1415926535897931,\"y\":0.0,\"z\":0.0}}\n");
    RemoveFile(fileName.c_str());
}


TEST(SolidRepository, JsonToSolid) {
    Luga::Meca::Solid::Solid expectedSolid;
    Vector velocity(M_PI, 0, 0);
    expectedSolid.Velocity(velocity);
    expectedSolid.UpdatePosition(1);

    Luga::Meca::Repository::SolidRepository repo;
    auto solid = repo.LoadSolid(GetResourceDirectory() + "solidToRead.json");
    ASSERT_EQ(expectedSolid.B().Origin().CoordinateX(), solid.B().Origin().CoordinateX());
}