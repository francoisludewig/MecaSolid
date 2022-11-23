//
// Created by fld on 23/11/22.
//

#include <gtest/gtest.h>
#include <cmath>
#include "Solid/Solid.h"
#include "SolidRepository.h"

TEST(SolidRepository, SolidToJson) {
    Luga::Meca::Solid::Solid solid;
    Vector velocity(M_PI, 0, 0);
    solid.Velocity(velocity);
    solid.UpdatePosition(1);
    Luga::Meca::Repository::SolidRepository repo;
    auto str = repo.SaveSolid(solid);
    std::cout << str << std::endl;
    ASSERT_EQ(str , "{\"angularVelocity\":{\"x\":0.0,\"y\":0.0,\"z\":0.0},\"basis\":{\"id\":61,\"orientation\":{\"i\":0.0,\"j\":0.0,\"k\":0.0,\"r\":1.0},\"origin\":{\"x\":3.1415926535897931,\"y\":0.0,\"z\":0.0}},\"force\":{\"x\":0.0,\"y\":0.0,\"z\":0.0},\"inertia\":{\"0-0\":1.0,\"0-1\":0.0,\"0-2\":0.0,\"1-0\":0.0,\"1-1\":1.0,\"1-2\":0.0,\"2-0\":0.0,\"2-1\":0.0,\"2-2\":1.0},\"momentum\":{\"x\":0.0,\"y\":0.0,\"z\":0.0},\"velocity\":{\"x\":3.1415926535897931,\"y\":0.0,\"z\":0.0}}\n");
}

TEST(SolidRepository, JsonToSolid) {
    Luga::Meca::Solid::Solid expectedSolid;
    Vector velocity(M_PI, 0, 0);
    expectedSolid.Velocity(velocity);
    expectedSolid.UpdatePosition(1);

    std::string jsonStr = "{\"angularVelocity\":{\"x\":0.0,\"y\":0.0,\"z\":0.0},\"basis\":{\"id\":61,\"orientation\":{\"i\":0.0,\"j\":0.0,\"k\":0.0,\"r\":1.0},\"origin\":{\"x\":3.1415926535897931,\"y\":0.0,\"z\":0.0}},\"force\":{\"x\":0.0,\"y\":0.0,\"z\":0.0},\"inertia\":{\"0-0\":1.0,\"0-1\":0.0,\"0-2\":0.0,\"1-0\":0.0,\"1-1\":1.0,\"1-2\":0.0,\"2-0\":0.0,\"2-1\":0.0,\"2-2\":1.0},\"momentum\":{\"x\":0.0,\"y\":0.0,\"z\":0.0},\"velocity\":{\"x\":3.1415926535897931,\"y\":0.0,\"z\":0.0}}\n";
    Luga::Meca::Repository::SolidRepository repo;
    auto solid = repo.LoadSolid(jsonStr);
    ASSERT_EQ(expectedSolid.B().Origin().CoordinateX(), solid.B().Origin().CoordinateX());
}