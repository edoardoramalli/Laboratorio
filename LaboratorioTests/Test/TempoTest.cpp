//
// Created by Edoardo Ramalli on 25/07/16.
//

#include "gtest/gtest.h"

#include "../../Laboratorio/Tempo.h"

class TempoTestSuite : public ::testing::Test {
public:
    Tempo t;

    virtual void setUp() {
        t.setTime(12, 13, 14);
    }


};

TEST(TempoTestSuite, DefaultConstructor) {
    Tempo def;
    ASSERT_EQ(full24, def.getFormat());
    ASSERT_EQ(empty, def.getMeridian());
}


TEST(TempoTestSuite, Constructor) {
    Tempo t(12, 11, 10, full24);
    ASSERT_EQ(12, t.getOra());
    ASSERT_EQ(11, t.getMinuto());
    ASSERT_EQ(10, t.getSecondo());

    Tempo s(2, 30, 0, full12, AM);
    ASSERT_EQ(2, s.getOra());
    ASSERT_EQ(AM, s.getMeridian());
}

TEST(TempoTestSuite, SettingTimeandFormat) {
    Tempo t(12, 11, 10, full24);
    t.setFormat(small12);
    ASSERT_EQ(PM, t.getMeridian());
    ASSERT_EQ(12, t.getOra());

    t.setFormat(small24);
    t.setTime(0, 12, 0, empty);
    t.setFormat(full12);
    ASSERT_EQ(AM, t.getMeridian());
    ASSERT_EQ(12, t.getOra());
    ASSERT_EQ(12, t.getMinuto());
}

TEST(TempoTestSuite, TestSum) {
    Tempo t1(19, 57, 37, full24);
    Tempo t2(7, 20, 40, small12, AM);
    Tempo t3 = t1 + t2;
    ASSERT_EQ(18, t3.getMinuto());
    ASSERT_EQ(17, t3.getSecondo());
    ASSERT_EQ(3, t3.getOra());
    ASSERT_EQ(AM, t2.getMeridian());
    ASSERT_EQ(small12, t2.getFormat());
    ASSERT_EQ(full24, t1.getFormat());

    t2.setTime(7, 20, 40, PM);
    t3 = t1 + t2;
    t3.setFormat(small12);
    ASSERT_EQ(3, t3.getOra());
    ASSERT_EQ(PM, t3.getMeridian());
}

