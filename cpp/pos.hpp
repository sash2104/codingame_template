#pragma once

#include <iostream>
#include <string>
#include <cmath>

class Pos
{
  public:
    float x;
    float y;
    Pos()
      : x(0), y(0) {}
    Pos(float x, float y)
      : x(x), y(y) {}

    friend std::ostream& operator<< (std::ostream &out, const Pos& p)
    {
      out << "(" << p.x << "," << p.y << ")";
      return out;
    }

    // += -=
    Pos& operator+= (const Pos &other)
    {
      this->x += other.x;
      this->y += other.y;
      return *this;
    }

    Pos& operator-= (const Pos &other)
    {
      this->x -= other.x;
      this->y -= other.y;
      return *this;
    }

    // + - * /
    Pos operator+ (const Pos &other)
    {
      return Pos(this->x+other.x, this->y+other.y);
    }

    Pos operator- (const Pos &other)
    {
      return Pos(this->x-other.x, this->y-other.y);
    }

    Pos operator* (const Pos &other)
    {
      return Pos(this->x*other.x, this->y*other.y);
    }

    Pos operator* (float a)
    {
      return Pos(this->x*a, this->y*a);
    }

    Pos operator/ (float a)
    {
      return Pos(this->x/a, a*this->y/a);
    }

    Pos pfloor ()
    {
      return Pos(floor(this->x), floor(this->y));
    }

    Pos pceil ()
    {
      return Pos(ceil(this->x), ceil(this->y));
    }

    Pos pround ()
    {
      return Pos(round(this->x), round(this->y));
    }

    Pos round_edge (const Pos &topleft, const Pos &bottomright)
    {
      if (this->x < topleft.x) { this->x = topleft.x; }
      if (this->y < topleft.y) { this->y = topleft.y; }
      if (this->x > bottomright.x) { this->x = bottomright.x; }
      if (this->y > bottomright.y) { this->y = bottomright.y; }
      return *this;
    }

    // euclidian distance
    float distance (const Pos &other)
    {
      float dx = this->x-other.x;
      float dy = this->y-other.y;
      return sqrt(dx*dx+dy*dy);
    }

    Pos towards(const Pos &other, float d)
    {
      float d_o = distance(other);
      if (d_o < d)
        return Pos(other.x, other.y);
      Pos towards_pos = Pos((d*other.x+(d_o-d)*this->x)/d_o, (d*other.y+(d_o-d)*this->y)/d_o);
      return towards_pos.pfloor();
    }
};
