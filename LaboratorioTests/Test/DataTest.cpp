//
// Created by Edoardo Ramalli on 26/07/16.
//

#include "gtest/gtest.h"

#include "../../Laboratorio/Data.h"

class DataTestSuite : public ::testing::Test {
public:
    Data t;

    virtual void setUp() {
        t.setDay(25,12,2000,EUlong);
    }

};

TEST(DataTestSuite,DefaultConstrucotr){
    Data d;
    ASSERT_EQ(2016,d.getAnno());
    ASSERT_EQ(9,d.getMese()); //potrebbe cambiare
    ASSERT_EQ(EUlong,d.getFormat());
    ASSERT_EQ(true,d.isLeapyear());
}

TEST(DataTestSuite,Constructor) {
    Data d(19, 9, 1996, USAlong);
    ASSERT_EQ("Giovedì", d.getDayofweek());
    ASSERT_EQ(19, d.getGiorno());
    ASSERT_EQ(1996, d.getAnno());
    ASSERT_EQ(9, d.getMese());
    ASSERT_TRUE(d.isLeapyear());
    ASSERT_EQ(USAlong, d.getFormat());

    Data d2 (29,2,2017,EUlong);
    ASSERT_FALSE(d2.isLeapyear());
    ASSERT_EQ(EUlong, d2.getFormat());
    ASSERT_EQ(1,d2.getGiorno());
    ASSERT_EQ(2,d2.getMese());
    ASSERT_EQ(2017,d2.getAnno());
    ASSERT_EQ("Mercoledì",d2.getDayofweek());

    Data d3 (31,13,1940,USAlong);
    ASSERT_EQ(31,d3.getGiorno());
    ASSERT_EQ(1,d3.getMese());
    ASSERT_EQ(1940,d3.getAnno());

}

    TEST(DataTestSuite,SetDay){
    Data d;
    d.setDay(26,7,2016,EUshort);
    ASSERT_EQ(26,d.getGiorno());
    ASSERT_EQ(7,d.getMese());
    ASSERT_EQ(2016,d.getAnno());
    ASSERT_EQ(EUshort,d.getFormat());
    ASSERT_TRUE(d.isLeapyear());
    ASSERT_EQ("Martedì",d.getDayofweek());

    d.setDay(30,2,2010,EUlong);
    ASSERT_EQ(1,d.getGiorno());
    ASSERT_EQ(2,d.getMese());
    ASSERT_FALSE(d.isLeapyear());
    ASSERT_EQ(EUlong, d.getFormat());

    d.setDay(31,11,1980,USAshort);
    ASSERT_EQ(1,d.getGiorno());
    ASSERT_EQ(11,d.getMese());
    ASSERT_EQ(1980,d.getAnno());
    ASSERT_EQ(USAshort,d.getFormat());
    ASSERT_TRUE(d.isLeapyear());
    ASSERT_EQ("Sabato",d.getDayofweek());
}

    TEST(DataTestSuite,InequalityTest){
    Data d1(12,12,2012,EUlong);
    Data d2 (12,12,2011,EUlong);
    ASSERT_TRUE(d2<=d1);

    d2.setDay(12,11,2012,EUshort);
    ASSERT_TRUE(d2<=d1);

    d2.setDay(10,12,2012,USAlong);
    ASSERT_TRUE(d2<=d1);

    d2.setDay(12,12,2012,USAshort);
    ASSERT_TRUE(d2<=d1);

    d2.setDay(13,12,2012,USAlong);
    ASSERT_FALSE(d2<=d1);


}
    TEST(DataTestSuite,DifferenceTest){
    Data d1(12,4,2000,EUlong);
    Data d2(12,4,1998,EUlong);
    ASSERT_EQ(731,d1-d2);

    d1.setDay(1,1,2000,USAlong);
    d2.setDay(31,12,2000,USAshort);
    ASSERT_EQ(365,d1-d2);
    ASSERT_EQ(365,d2-d1);

    d1.setDay(1,1,1998,EUlong);
    d2.setDay(25,7,2006,EUshort);
    ASSERT_EQ(3127,d2-d1);

    d2.setDay(2,1,1998,EUlong);
    ASSERT_EQ(1,d1-d2);

    d1.setDay(19,9,1996,EUlong);
    Data d3(19,9,2016,USAshort);
    ASSERT_EQ(7305,d3-d1);
}