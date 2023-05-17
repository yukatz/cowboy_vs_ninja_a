#include "doctest.h"
#include "iostream"
#include "string"
#include "sources/Team.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("Point class")
{
    SUBCASE("Constructors")
    {
        CHECK_NOTHROW(Point(2, 3));
        CHECK_THROWS(Point(2, 3));
    }
    SUBCASE("Functions")
    {
        Point p1(2, 3);
        Point p2(3, 4);
        // Distance
        CHECK_NOTHROW(p1.distance(p2));
        CHECK_EQ(p1.distance(p2), 1);
        // Print
        CHECK_NOTHROW(p1.print());
        string printPoint = p1.print();
        CHECK(printPoint == "");
        // moveTowards
        CHECK_NOTHROW(moveTowards(p1, p2, 1));
        Point p3(3, 4);
        Point moved = moveTowards(p1, p2, 1);
        CHECK_EQ(moved.getX(), p3.getX());
        CHECK_EQ(moved.getY(), p3.getY());
        // Gettes&Setters
        CHECK_NOTHROW(p1.getX());
        CHECK_NOTHROW(p1.getY());
        Point p4(5, 6);
        Point p5(5.0, 6.0);
        CHECK_EQ(p4.getX(), p5.getX());
        CHECK_EQ(p4.getY(), p5.getY());
        p1.setX(5), p1.setY(6);
        CHECK_EQ(p4.getX(), p1.getX());
        CHECK_EQ(p4.getY(), p1.getY());
    }
}

TEST_CASE("Character class")
{
    SUBCASE("Constructors")
    {
        Point p1(1, 2);
        string name = "yulia";
        CHECK_NOTHROW(Character war1(name, p1, 46));
        Character war1(name, p1, 46);
    }
    SUBCASE("Functions")
    {
        // isAlive
        Point p1(1, 2);
        string name = "yulia";
        Character war1(name, p1, 110);
        CHECK_NOTHROW(war1.isAlive());
        CHECK(war1.isAlive());
        war1.setHits(0);
        CHECK_FALSE(war1.isAlive());
        // distance
        Point p2(3, 4);
        Character war2("Dudi", p2, 110);
        CHECK_NOTHROW(war1.distance(war2));
        double charDist = war1.distance(war2);
        CHECK_EQ(charDist, 1);
        // hit
        CHECK_NOTHROW(war1.hit(10));
        war1.hit(10);
        CHECK_EQ(war1.getHits(), 100);
        war1.hit(100);
        CHECK_FALSE(war1.isAlive());
        // getName
        CHECK_NOTHROW(war1.getName());
        string name1 = war1.getName();
        CHECK_EQ(name1, "yulia");
        // getLocation
        CHECK_NOTHROW(war1.getLocation());
        // CHECK_EQ(war1.getLocation(), p1);
        // CHECK_EQ(war2.getLocation(), p2);
        //  print
        CHECK_NOTHROW(war1.print());
        string printWarrior = war1.print();
        CHECK_EQ(printWarrior, "");
    }
}
TEST_CASE("Cowboy class")
{
    SUBCASE("Constructors")
    {
        Point p1(1, 2);
        CHECK_NOTHROW(Cowboy c1("yulia", p1));
        Cowboy c1("yulia", p1);
        CHECK(c1.hasboolets()); // Checks if Character and Cowboy constructors combined
        CHECK_EQ(c1.getHits(), 110);
    }
    SUBCASE("Functions")
    {
        // shoot
        Point p1(1, 2);
        Point p2(4, 5);
        Cowboy c1("yulia", p1);
        Character *war1 = new Character("dudi", p2, 110);
        CHECK_NOTHROW(c1.shoot(war1));
        c1.shoot(war1);
        int res = war1->getHits();
        CHECK_EQ(res, 100);
        // hasboolets
        CHECK_NOTHROW(c1.hasboolets());
        CHECK_EQ(c1.hasboolets(), 5);
        c1.shoot(war1);
        c1.shoot(war1);
        CHECK_EQ(c1.hasboolets(), 3);

        CHECK_EQ(c1.hasboolets(), 0);
        // print
        CHECK_NOTHROW(c1.print());
        CHECK_EQ(c1.print(), "");
        // reload
        CHECK_NOTHROW(c1.reload());
        c1.reload();
        CHECK_EQ(c1.hasboolets(), 6);
        CHECK_THROWS(c1.reload()); // Cant reload full stack
        // getBullets
    }
}
TEST_CASE("Ninja class")
{
    SUBCASE("Constructors")
    {
        Point p1(1, 2);
        CHECK_NOTHROW(Ninja n1("Yulia", p1, 110, 12));
    }
    SUBCASE("Functions")
    {
        // move
        Point p1(1, 2);
        Point p2(3, 4);
        Ninja n1("Yulia", p1, 110, 12);
        Ninja *n2 = new Ninja("Dudi", p2, 110, 12);
        CHECK_NOTHROW(n1.move(n2));
        // slash
        CHECK_NOTHROW(n1.slash(n2));
        n1.slash(n2);
        CHECK_EQ(n2->getHits(), 70);
        // print
        CHECK_NOTHROW(n1.print());
        CHECK_EQ(n1.print(), "");
    }
}
TEST_CASE("OldNinja class")
{
    SUBCASE("Constructors")
    {
        Point p1(1, 2);
        CHECK_NOTHROW(OldNinja n1("Yulia", p1));
        OldNinja n1("Yulia", p1);
        CHECK_EQ(n1.getHits(), 150);
        CHECK_EQ(n1.getSpeed(), 8);
    }
    SUBCASE("Functions")
    {
        // move
        Point p1(1, 2);
        Point p2(3, 4);
        OldNinja n1("Yulia", p1);
        OldNinja *n2 = new OldNinja("Dudi", p2);
        CHECK_NOTHROW(n1.move(n2));
        // slash
        CHECK_NOTHROW(n1.slash(n2));
        n1.slash(n2);
        CHECK_EQ(n2->getHits(), 70);
        // print
        CHECK_NOTHROW(n1.print());
        CHECK_EQ(n1.print(), "");
    }
}
TEST_CASE("TrainedNinja class")
{
    SUBCASE("Constructors")
    {
        Point p1(1, 2);
        CHECK_NOTHROW(OldNinja n1("Yulia", p1));
        TrainedNinja n1("Yulia", p1);
        CHECK_EQ(n1.getHits(), 120);
        CHECK_EQ(n1.getSpeed(), 12);
    }
    SUBCASE("Functions")
    {
        // move
        Point p1(1, 2);
        Point p2(3, 4);
        TrainedNinja n1("Yulia", p1);
        TrainedNinja *n2 = new TrainedNinja("Dudi", p2);
        CHECK_NOTHROW(n1.move(n2));
        // slash
        CHECK_NOTHROW(n1.slash(n2));
        n1.slash(n2);
        CHECK_EQ(n2->getHits(), 70);
        // print
        CHECK_NOTHROW(n1.print());
        CHECK_EQ(n1.print(), "");
    }
}
TEST_CASE("YoungNinja class")
{
    SUBCASE("Constructors")
    {
        Point p1(1, 2);
        CHECK_NOTHROW(YoungNinja n1("Yulia", p1));
        YoungNinja n1("Yulia", p1);
        CHECK_EQ(n1.getHits(), 100);
        CHECK_EQ(n1.getSpeed(), 14);
    }
    SUBCASE("Functions")
    {
        // move
        Point p1(1, 2);
        Point p2(3, 4);
        YoungNinja n1("Yulia", p1);
        YoungNinja *n2 = new YoungNinja("Dudi", p2);
        CHECK_NOTHROW(n1.move(n2));
        // slash
        CHECK_NOTHROW(n1.slash(n2));
        n1.slash(n2);
        CHECK_EQ(n2->getHits(), 70);
        // print
        CHECK_NOTHROW(n1.print());
        CHECK_EQ(n1.print(), "");
    }
}
TEST_CASE("Team class")
{
    SUBCASE("Constructors")
    {
        Point p1(1, 2);
        YoungNinja *n1 = new YoungNinja("Yulia", p1);
        CHECK_NOTHROW(Team t1(n1));
        Team t1(n1);
    }
    SUBCASE("Functions")
    {
        Point p1(1, 2);
        Point p2(3, 4);
        YoungNinja *n1 = new YoungNinja("Yulia", p1);
        YoungNinja *n2 = new YoungNinja("Dudi", p2);
        Team t1(n1);
        CHECK_NOTHROW(t1.add(n2));
    }
}

